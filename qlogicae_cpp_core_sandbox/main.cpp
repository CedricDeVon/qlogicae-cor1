#include "pch.hpp"

#include "main.hpp"


class WebApi
{
public:
	struct Config
	{
		std::string base_url;

		long connect_timeout_seconds = 10;
		long request_timeout_seconds = 30;

		int max_retries = 3;
		long retry_initial_delay_ms = 1000;

		bool follow_redirects = true;
		bool enable_http2 = true;

		std::vector<std::string> default_headers;
		std::string bearer_token;

		int circuit_breaker_threshold = 5;
		long circuit_breaker_cooldown_ms = 10000;

		std::string pinned_cert_file;
		std::string trusted_ca_bundle_file;

		std::function<void(const std::string&)> log_info;
		std::function<void(const std::string&)> log_error;

		bool wait_forever = false;
		bool suppress_exceptions = false;
		bool capture_body = true;
		bool capture_headers = true;
		bool capture_telemetry = true;

		bool default_idempotent = true;
	};

	struct Telemetry
	{
		double total_time{};
		double dns_time{};
		double connect_time{};
		double tls_time{};
		double start_transfer_time{};
	};

	struct Response
	{
		long status_code{};
		std::string body;
		std::multimap<std::string, std::string> headers;
		Telemetry telemetry;
	};

public:
	explicit WebApi(Config config)
		: config_(std::move(config))
	{
		initialize_global();
		init_pool(8);
	}

	~WebApi()
	{
		for (auto* h : curl_pool_)
			curl_easy_cleanup(h);
	}

	WebApi(const WebApi&) = delete;
	WebApi& operator=(const WebApi&) = delete;

	Response get(const std::string& path, std::atomic<bool>* cancel_token = nullptr)
	{
		return request("GET", path, "", cancel_token);
	}

	Response post(const std::string& path, const std::string& body,
		std::atomic<bool>* cancel_token = nullptr)
	{
		return request("POST", path, body, cancel_token, false); 
	}

	Response put(const std::string& path, const std::string& body,
		std::atomic<bool>* cancel_token = nullptr)
	{
		return request("PUT", path, body, cancel_token); 
	}

	Response del(const std::string& path, std::atomic<bool>* cancel_token = nullptr)
	{
		return request("DELETE", path, "", cancel_token); 
	}

	Response head(const std::string& path, std::atomic<bool>* cancel_token = nullptr)
	{
		return request("HEAD", path, "", cancel_token, true);
	}

	Response options(const std::string& path, std::atomic<bool>* cancel_token = nullptr)
	{
		return request("OPTIONS", path, "", cancel_token, true);
	}

	Response raw(const std::string& method,
		const std::string& path,
		const std::string& body = "",
		std::atomic<bool>* cancel_token = nullptr,
		bool idempotent = false)
	{
		return request(method, path, body, cancel_token, idempotent);
	}

private:
	Config config_;
	std::vector<CURL*> curl_pool_;
	std::mutex pool_mutex_;
	size_t pool_next_{ 0 };
	std::mutex cb_mutex_;
	int failure_count_{ 0 };
	std::chrono::steady_clock::time_point last_failure_{};

	static void initialize_global()
	{
		static std::once_flag flag;
		std::call_once(flag, []() { curl_global_init(CURL_GLOBAL_DEFAULT); });
	}

	void init_pool(size_t size)
	{
		curl_pool_.reserve(size);
		for (size_t i = 0; i < size; ++i)
		{
			CURL* h = curl_easy_init();
			if (h) curl_pool_.push_back(h);
		}
	}

	CURL* acquire_handle()
	{
		std::lock_guard lock(pool_mutex_);
		CURL* h = curl_pool_[pool_next_];
		pool_next_ = (pool_next_ + 1) % curl_pool_.size();
		curl_easy_reset(h);

		if (!config_.trusted_ca_bundle_file.empty())
			curl_easy_setopt(h, CURLOPT_CAINFO, config_.trusted_ca_bundle_file.c_str());

		if (!config_.pinned_cert_file.empty())
			curl_easy_setopt(h, CURLOPT_PINNEDPUBLICKEY, config_.pinned_cert_file.c_str());

		return h;
	}

	Response request(const std::string& method,
		const std::string& path,
		const std::string& body,
		std::atomic<bool>* cancel_token,
		std::optional<bool> idempotent_override = std::nullopt)
	{
		bool idempotent = idempotent_override.value_or(config_.default_idempotent);
		Response r{};
		try
		{
			r = perform_once(method, build_url(config_.base_url, path), body, cancel_token);
		}
		catch (...)
		{
			if (!config_.suppress_exceptions) throw;
			r.status_code = 0;
			if (config_.capture_body) r.body = "Request failed";
		}
		return r;
	}


	Response perform_once(const std::string& method, const std::string& url, const std::string& body, std::atomic<bool>* cancel_token)
	{
		Response r{};
		CURL* h = acquire_handle();

		curl_easy_setopt(h, CURLOPT_URL, url.c_str());
		curl_easy_setopt(h, CURLOPT_CUSTOMREQUEST, method.c_str());
		curl_easy_setopt(h, CURLOPT_FOLLOWLOCATION, config_.follow_redirects ? 1L : 0L);

		curl_easy_setopt(h, CURLOPT_CONNECTTIMEOUT, config_.wait_forever ? 0L : config_.connect_timeout_seconds);
		curl_easy_setopt(h, CURLOPT_TIMEOUT, config_.wait_forever ? 0L : config_.request_timeout_seconds);

		if (config_.enable_http2)
			curl_easy_setopt(h, CURLOPT_HTTP_VERSION, CURL_HTTP_VERSION_2TLS);

		std::string response_body;
		std::multimap<std::string, std::string> response_headers;

		if (config_.capture_body)
		{
			curl_easy_setopt(h, CURLOPT_WRITEFUNCTION, write_cb);
			curl_easy_setopt(h, CURLOPT_WRITEDATA, &response_body);
		}
		else
		{
			curl_easy_setopt(h, CURLOPT_NOBODY, 1L);
		}

		if (config_.capture_headers)
		{
			curl_easy_setopt(h, CURLOPT_HEADERFUNCTION, header_cb);
			curl_easy_setopt(h, CURLOPT_HEADERDATA, &response_headers);
		}

		struct curl_slist* header_list = nullptr;
		for (auto& hstr : config_.default_headers)
			header_list = curl_slist_append(header_list, hstr.c_str());

		if (!config_.bearer_token.empty())
		{
			std::string auth = "Authorization: Bearer " + config_.bearer_token;
			header_list = curl_slist_append(header_list, auth.c_str());
		}

		if (header_list) curl_easy_setopt(h, CURLOPT_HTTPHEADER, header_list);
		if (!body.empty())
		{
			curl_easy_setopt(h, CURLOPT_POSTFIELDS, body.c_str());
			curl_easy_setopt(h, CURLOPT_POSTFIELDSIZE, body.size());
		}

		CURLcode res = curl_easy_perform(h);
		if (header_list) curl_slist_free_all(header_list);

		curl_easy_getinfo(h, CURLINFO_RESPONSE_CODE, &r.status_code);

		if (config_.capture_body) r.body = std::move(response_body);
		if (config_.capture_headers) r.headers = std::move(response_headers);
		if (config_.capture_telemetry) populate_telemetry(h, r.telemetry);

		return r;
	}

	static size_t write_cb(void* ptr, size_t size, size_t nmemb, void* userdata)
	{
		auto* str = static_cast<std::string*>(userdata);
		str->append(static_cast<char*>(ptr), size * nmemb);
		return size * nmemb;
	}

	static size_t header_cb(void* ptr, size_t size, size_t nmemb, void* userdata)
	{
		auto* headers = static_cast<std::multimap<std::string, std::string>*>(userdata);
		std::string line(static_cast<char*>(ptr), size * nmemb);
		auto colon = line.find(':');
		if (colon != std::string::npos)
		{
			std::string key = line.substr(0, colon);
			std::string value = line.substr(colon + 1);
			value.erase(0, value.find_first_not_of(" \t\r\n"));
			value.erase(value.find_last_not_of(" \t\r\n") + 1);
			headers->emplace(std::move(key), std::move(value));
		}
		return size * nmemb;
	}

	static void populate_telemetry(CURL* h, Telemetry& t)
	{
		curl_easy_getinfo(h, CURLINFO_TOTAL_TIME, &t.total_time);
		curl_easy_getinfo(h, CURLINFO_NAMELOOKUP_TIME, &t.dns_time);
		curl_easy_getinfo(h, CURLINFO_CONNECT_TIME, &t.connect_time);
		curl_easy_getinfo(h, CURLINFO_APPCONNECT_TIME, &t.tls_time);
		curl_easy_getinfo(h, CURLINFO_STARTTRANSFER_TIME, &t.start_transfer_time);
	}

	static std::string build_url(const std::string& base, const std::string& path)
	{
		if (path.empty()) return base;
		if (base.empty()) return path;
		bool base_slash = base.back() == '/';
		bool path_slash = path.front() == '/';
		if (base_slash && path_slash) return base + path.substr(1);
		if (!base_slash && !path_slash) return base + "/" + path;
		return base + path;
	}
};

void display_response(const WebApi::Response& response)
{
    std::cout << "Status Code: " << response.status_code << "\n\n";

    std::cout << "Headers:\n";
    for (const auto& [key, value] : response.headers)
    {
        std::cout << key << ": " << value << "\n";
    }
    std::cout << "\n";

    std::cout << "Body:\n";
    std::cout << response.body << "\n\n";

    const auto& t = response.telemetry;
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Telemetry (seconds):\n";
    std::cout << "  Total Time: " << t.total_time << "\n";
    std::cout << "  DNS Lookup: " << t.dns_time << "\n";
    std::cout << "  Connect: " << t.connect_time << "\n";
    std::cout << "  TLS Handshake: " << t.tls_time << "\n";
    std::cout << "  Start Transfer: " << t.start_transfer_time << "\n";
}

int main(int argc, char** argv)
{		    
	try
	{
		WebApi client(WebApi::Config{ .base_url = "https://dummy.restapiexample.com" });
		auto response = client.get("/api/v1/employees");
		display_response(response);
	}
	catch (const std::exception& ex)
	{
		std::cerr << "Error: " << ex.what() << "\n";
		return EXIT_FAILURE;
	}

    bool exit_code;
	std::cin >> exit_code;

    return 0;
}

namespace QLogicaeCppCoreSandbox
{

}


/*




class WebApi
{
public:
	struct Config
	{
		std::string base_url;

		long connect_timeout_seconds = 10;
		long request_timeout_seconds = 30;

		int max_retries = 3;
		long retry_initial_delay_ms = 1000;

		bool follow_redirects = true;
		bool enable_http2 = true;

		std::vector<std::string> default_headers;
		std::string bearer_token;

		int circuit_breaker_threshold = 5;
		long circuit_breaker_cooldown_ms = 10000;

		// Security options
		std::string pinned_cert_file;       // PEM file for cert pinning
		std::string trusted_ca_bundle_file; // Custom CA bundle

		// Logging/observability hooks
		std::function<void(const std::string&)> log_info;
		std::function<void(const std::string&)> log_error;
	};

	struct Telemetry
	{
		double total_time{};
		double dns_time{};
		double connect_time{};
		double tls_time{};
		double start_transfer_time{};
	};

	struct Response
	{
		long status_code{};
		std::string body;
		std::multimap<std::string, std::string> headers; // handle repeated headers
		Telemetry telemetry;
	};

	enum class ErrorType
	{
		Transport,
		Timeout,
		Http,
		Ssl,
		CircuitOpen
	};

	class Exception : public std::runtime_error
	{
	public:
		Exception(ErrorType type,
				  std::string message,
				  long status = 0,
				  CURLcode curl_code = CURLE_OK,
				  std::string body = {})
			: std::runtime_error(std::move(message)),
			  type_(type), status_(status),
			  curl_code_(curl_code), body_(std::move(body)) {}

		ErrorType type() const noexcept { return type_; }
		long status() const noexcept { return status_; }
		CURLcode curl_code() const noexcept { return curl_code_; }
		const std::string& body() const noexcept { return body_; }

	private:
		ErrorType type_;
		long status_;
		CURLcode curl_code_;
		std::string body_;
	};

public:
	explicit WebApi(Config config)
		: config_(std::move(config))
	{
		initialize_global();
		init_pool(8); // example: fixed pool of 8 persistent CURL handles
	}

	~WebApi()
	{
		for (auto* h : curl_pool_)
			curl_easy_cleanup(h);
	}

	WebApi(const WebApi&) = delete;
	WebApi& operator=(const WebApi&) = delete;

	Response get(const std::string& path,
				 std::atomic<bool>* cancel_token = nullptr)
	{
		return request("GET", path, "", true, cancel_token);
	}

	Response post(const std::string& path,
				  const std::string& body,
				  std::atomic<bool>* cancel_token = nullptr)
	{
		return request("POST", path, body, false, cancel_token);
	}

private:
	Config config_;
	std::vector<CURL*> curl_pool_;
	std::mutex pool_mutex_;
	size_t pool_next_{0};

	// circuit breaker state
	std::mutex cb_mutex_;
	int failure_count_{0};
	std::chrono::steady_clock::time_point last_failure_{};

	// ===============================
	// GLOBAL INITIALIZATION
	// ===============================
	static void initialize_global()
	{
		static std::once_flag flag;
		std::call_once(flag, []()
		{
			if (curl_global_init(CURL_GLOBAL_DEFAULT) != 0)
				throw std::runtime_error("curl_global_init failed");
		});
	}

	void init_pool(size_t size)
	{
		curl_pool_.reserve(size);
		for (size_t i = 0; i < size; ++i)
		{
			CURL* h = curl_easy_init();
			if (!h)
				throw std::runtime_error("curl_easy_init failed");
			curl_pool_.push_back(h);
		}
	}

	CURL* acquire_handle()
	{
		std::lock_guard lock(pool_mutex_);
		CURL* h = curl_pool_[pool_next_];
		pool_next_ = (pool_next_ + 1) % curl_pool_.size();
		curl_easy_reset(h);

		// Security options
		if (!config_.trusted_ca_bundle_file.empty())
			curl_easy_setopt(h, CURLOPT_CAINFO,
							 config_.trusted_ca_bundle_file.c_str());

		if (!config_.pinned_cert_file.empty())
			curl_easy_setopt(h, CURLOPT_PINNEDPUBLICKEY,
							 config_.pinned_cert_file.c_str());

		return h;
	}

	// ===============================
	// REQUEST
	// ===============================
	Response request(const std::string& method,
					 const std::string& path,
					 const std::string& body,
					 bool idempotent,
					 std::atomic<bool>* cancel_token)
	{
		enforce_circuit();

		std::string url = build_url(config_.base_url, path);

		int attempt = 0;
		long delay = config_.retry_initial_delay_ms;

		while (true)
		{
			try
			{
				auto r = perform_once(method, url, body, cancel_token);
				reset_failures();
				if (config_.log_info) config_.log_info("Request succeeded: " + url);
				return r;
			}
			catch (const Exception& ex)
			{
				register_failure();
				if (config_.log_error)
					config_.log_error("Request failed: " + url + " | " + ex.what());

				if (!should_retry(ex, attempt, idempotent))
					throw;

				long backoff = backoff_with_jitter(delay);
				std::this_thread::sleep_for(std::chrono::milliseconds(backoff));

				delay *= 2;
				++attempt;
			}
		}
	}

	Response perform_once(const std::string& method,
						  const std::string& url,
						  const std::string& body,
						  std::atomic<bool>* cancel_token)
	{
		CURL* h = acquire_handle();

		curl_easy_setopt(h, CURLOPT_URL, url.c_str());
		curl_easy_setopt(h, CURLOPT_CUSTOMREQUEST, method.c_str());
		curl_easy_setopt(h, CURLOPT_CONNECTTIMEOUT, config_.connect_timeout_seconds);
		curl_easy_setopt(h, CURLOPT_TIMEOUT, config_.request_timeout_seconds);
		curl_easy_setopt(h, CURLOPT_FOLLOWLOCATION, config_.follow_redirects ? 1L : 0L);

		if (config_.enable_http2)
			curl_easy_setopt(h, CURLOPT_HTTP_VERSION, CURL_HTTP_VERSION_2TLS);

		// Per-request cancellation
		std::atomic<bool> local_cancel{ false };
		if (!cancel_token) cancel_token = &local_cancel;

		// Setup XFERINFO for optional cancellation
		if (cancel_token)
		{
			curl_easy_setopt(h, CURLOPT_XFERINFOFUNCTION,
				[](void* clientp, curl_off_t, curl_off_t, curl_off_t, curl_off_t) -> int {
					auto* flag = static_cast<std::atomic<bool>*>(clientp);
					return flag->load() ? 1 : 0;
				});
			curl_easy_setopt(h, CURLOPT_XFERINFODATA, cancel_token);
		}

		curl_easy_setopt(h, CURLOPT_XFERINFOFUNCTION,
						 [](void* clientp, curl_off_t, curl_off_t, curl_off_t, curl_off_t) -> int {
							 auto* flag = static_cast<std::atomic<bool>*>(clientp);
							 return flag->load() ? 1 : 0;
						 });
		curl_easy_setopt(h, CURLOPT_XFERINFODATA, cancel_token);
		curl_easy_setopt(h, CURLOPT_NOPROGRESS, 1L);

		std::string response_body;
		std::multimap<std::string, std::string> response_headers;

		curl_easy_setopt(h, CURLOPT_WRITEFUNCTION, write_cb);
		curl_easy_setopt(h, CURLOPT_WRITEDATA, &response_body);

		curl_easy_setopt(h, CURLOPT_HEADERFUNCTION, header_cb);
		curl_easy_setopt(h, CURLOPT_HEADERDATA, &response_headers);

		// Headers
		struct curl_slist* header_list = nullptr;
		for (auto& hstr : config_.default_headers)
			header_list = curl_slist_append(header_list, hstr.c_str());

		if (!config_.bearer_token.empty())
		{
			std::string auth = "Authorization: Bearer " + config_.bearer_token;
			header_list = curl_slist_append(header_list, auth.c_str());
		}

		if (header_list)
			curl_easy_setopt(h, CURLOPT_HTTPHEADER, header_list);

		if (!body.empty())
		{
			curl_easy_setopt(h, CURLOPT_POSTFIELDS, body.c_str());
			curl_easy_setopt(h, CURLOPT_POSTFIELDSIZE, body.size());
		}

		CURLcode res = curl_easy_perform(h);

		if (header_list)
			curl_slist_free_all(header_list);

		if (res != CURLE_OK)
		{
			throw Exception(res == CURLE_OPERATION_TIMEDOUT ? ErrorType::Timeout : ErrorType::Transport,
							curl_easy_strerror(res), 0, res);
		}

		long status = 0;
		curl_easy_getinfo(h, CURLINFO_RESPONSE_CODE, &status);

		// Handle Retry-After
		auto it = response_headers.find("Retry-After");
		if (it != response_headers.end())
		{
			try { std::chrono::seconds delay(std::stoi(it->second)); std::this_thread::sleep_for(delay); }
			catch (...) {}
		}

		if (is_retryable_http(status))
			throw Exception(ErrorType::Http, "Retryable HTTP error", status, CURLE_OK, response_body);

		if (status >= 400)
			throw Exception(ErrorType::Http, "HTTP error", status, CURLE_OK, response_body);

		Response r;
		r.status_code = status;
		r.body = std::move(response_body);
		r.headers = std::move(response_headers);

		populate_telemetry(h, r.telemetry);
		return r;
	}

	// ===============================
	// UTILS
	// ===============================
	static size_t write_cb(void* ptr, size_t size, size_t nmemb, void* userdata)
	{
		auto* str = static_cast<std::string*>(userdata);
		str->append(static_cast<char*>(ptr), size * nmemb);
		return size * nmemb;
	}

	static size_t header_cb(void* ptr, size_t size, size_t nmemb, void* userdata)
	{
		auto* headers = static_cast<std::multimap<std::string, std::string>*>(userdata);
		std::string line(static_cast<char*>(ptr), size * nmemb);

		auto colon = line.find(':');
		if (colon != std::string::npos)
		{
			std::string key = line.substr(0, colon);
			std::string value = line.substr(colon + 1);
			value.erase(0, value.find_first_not_of(" \t\r\n"));
			value.erase(value.find_last_not_of(" \t\r\n") + 1);
			headers->emplace(std::move(key), std::move(value));
		}

		return size * nmemb;
	}

	static bool is_retryable_http(long status)
	{
		return status == 408 || status == 429 || (status >= 500 && status < 600);
	}

	static long backoff_with_jitter(long base)
	{
		static thread_local std::mt19937 gen{ std::random_device{}() };
		std::uniform_int_distribution<long> dist(base / 2, base);
		return dist(gen);
	}

	bool should_retry(const Exception& ex, int attempt, bool idempotent) const
	{
		if (attempt >= config_.max_retries) return false;
		if (!idempotent) return false;
		if (ex.type() == ErrorType::Timeout || ex.type() == ErrorType::Transport) return true;
		if (ex.type() == ErrorType::Http && is_retryable_http(ex.status())) return true;
		return false;
	}

	void enforce_circuit()
	{
		std::lock_guard lock(cb_mutex_);
		if (failure_count_ < config_.circuit_breaker_threshold) return;

		auto now = std::chrono::steady_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - last_failure_);
		if (elapsed.count() < config_.circuit_breaker_cooldown_ms)
			throw Exception(ErrorType::CircuitOpen, "Circuit breaker open");

		failure_count_ = 0;
	}

	void register_failure()
	{
		std::lock_guard lock(cb_mutex_);
		++failure_count_;
		last_failure_ = std::chrono::steady_clock::now();
	}

	void reset_failures()
	{
		std::lock_guard lock(cb_mutex_);
		failure_count_ = 0;
	}

	static void populate_telemetry(CURL* h, Telemetry& t)
	{
		curl_easy_getinfo(h, CURLINFO_TOTAL_TIME, &t.total_time);
		curl_easy_getinfo(h, CURLINFO_NAMELOOKUP_TIME, &t.dns_time);
		curl_easy_getinfo(h, CURLINFO_CONNECT_TIME, &t.connect_time);
		curl_easy_getinfo(h, CURLINFO_APPCONNECT_TIME, &t.tls_time);
		curl_easy_getinfo(h, CURLINFO_STARTTRANSFER_TIME, &t.start_transfer_time);
	}

	static std::string build_url(const std::string& base, const std::string& path)
	{
		if (path.empty()) return base;
		if (base.empty()) return path;

		bool base_slash = base.back() == '/';
		bool path_slash = path.front() == '/';
		if (base_slash && path_slash) return base + path.substr(1);
		if (!base_slash && !path_slash) return base + "/" + path;
		return base + path;
	}
};

. rewrite to include these options:
- to wait for a response forever
- do not throw any errors within the api, return the response

*/
 