#include "pch.hpp"

#include "../includes/rest_api_manager.hpp"

namespace
	QLogicae::Cor::V1
{        
	RestApiManager
		::RestApiManager() :
			AbstractClass<RestApiManagerConfigurations>()
    {
		try
        {
            construct();
        }
        catch
        (
            const std::exception&
                exception
        )
        {
			handle_error_outputs(
				exception
			);
        }
	}        

	RestApiManager
		::~RestApiManager()
    {
		try
        {
            destruct();
        }
        catch
        (
            const std::exception&
                exception
        )
        {
			handle_error_outputs(
				exception
			);
        }
	}        

	bool
		RestApiManager
			::construct()
	{
		try
        {			
			if
			(
				configurations
					.is_runtime_execution_disabled_for_utility_handling()
			)
			{
				return
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_utility_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}			

			curl_global_init(
				CURL_GLOBAL_DEFAULT
			);

			size_t
				size =
					8; 

			curl_pool
				.reserve(
					size
				);

			for
			(
				size_t index = 0;
				index < size;
				++index
			)
			{
				CURL*
					curl_handler =
						curl_easy_init();

				if (curl_handler)
				{
					curl_pool
						.push_back(
							curl_handler
						);
				}
			}

			return
				true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
			return
				handle_error_outputs(
					exception
				);
        }
	}

	bool
		RestApiManager
			::destruct()
	{
		try
        {		
			if
			(
				configurations
					.is_runtime_execution_disabled_for_utility_handling()
			)
			{
				return
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_utility_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}			

			return
				true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
			return
				handle_error_outputs(
					exception
				);
        }
	}

	RestApiManagerResponse
		RestApiManager
			::execute_get_request(
				const std::string&
					path
			)
	{
		RestApiManagerResponse
			response;

		execute_request(
			response,
			"GET",
			path,
			""
		);

		return
			response;
	}

	RestApiManagerResponse
		RestApiManager
			::execute_post_request(
				const std::string&
					path,
				const std::string&
					body
			)
	{
		RestApiManagerResponse
			response;

		execute_request(
			response,
			"POST",
			path,
			body
		);

		return
			response;
	}

	RestApiManagerResponse
		RestApiManager
			::execute_put_request(
				const std::string&
					path,
				const std::string&
					body
			)
	{
		RestApiManagerResponse
			response;

		execute_request(
			response,
			"PUT",
			path,
			body
		);

		return
			response;
	}

	RestApiManagerResponse
		RestApiManager
			::execute_del_request(
				const std::string&
					path
			)
	{
		RestApiManagerResponse
			response;

		execute_request(
			response,
			"DELETE",
			path,
			""
		);

		return
			response;
	}

	RestApiManagerResponse
		RestApiManager
			::execute_head_request(
				const std::string&
					path
			)
	{
		RestApiManagerResponse
			response;

		execute_request(
			response,
			"HEAD",
			path,
			""
		);

		return
			response;
	}

	RestApiManagerResponse
		RestApiManager
			::execute_options_request(
				const std::string&
					path
			)
	{
		RestApiManagerResponse
			response;

		execute_request(
			response,
			"OPTIONS",
			path,
			""
		);

		return
			response;
	}

	RestApiManagerResponse
		RestApiManager
		::execute_raw_request(
			const std::string&
				method,
			const std::string&
				path,
			const std::string&
				body
		)
	{
		RestApiManagerResponse
			response;

		execute_request(
			response,
			method,
			path,
			body
		);

		return
			response;
	}

	bool	
		RestApiManager
			::execute_request(
				RestApiManagerResponse&
					response,
				const std::string&
					method,
				const std::string&
					path,
				const std::string&
					body
			)
	{
		try
		{
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling() ||
				(
					configurations
						.is_edge_case_enabled_for_feature_handling() &&
					(
						method.empty() ||
						path.empty() ||
						body.empty()
					)
				)
			)
			{
				return
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_feature_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}

			std::string url =
				setup_url(
					configurations
						.base_url,
					path
				);

			CURL* curl_handler = acquire_handle();

			curl_easy_setopt(curl_handler, CURLOPT_URL, url.c_str());
			curl_easy_setopt(curl_handler, CURLOPT_CUSTOMREQUEST, method.c_str());
			curl_easy_setopt(curl_handler, CURLOPT_FOLLOWLOCATION, configurations.follow_redirects ? 1L : 0L);

			curl_easy_setopt(curl_handler, CURLOPT_CONNECTTIMEOUT, configurations.wait_forever ? 0L : configurations.connect_timeout_seconds);
			curl_easy_setopt(curl_handler, CURLOPT_TIMEOUT, configurations.wait_forever ? 0L : configurations.request_timeout_seconds);

			if (configurations.enable_http2)
				curl_easy_setopt(curl_handler, CURLOPT_HTTP_VERSION, CURL_HTTP_VERSION_2TLS);

			std::string response_body;
			std::multimap<std::string, std::string> response_headers;

			if (configurations.capture_body)
			{
				curl_easy_setopt(
					curl_handler,
					CURLOPT_WRITEFUNCTION,
					[this](
						void*
							pointer,
						size_t
							size,
						size_t
							nmemb,
						void*
							userdata
					)
					{
						return write_cb(pointer, size, nmemb, userdata);
					}
				);
				curl_easy_setopt(curl_handler, CURLOPT_WRITEDATA, response_body);
			}
			else
			{
				curl_easy_setopt(curl_handler, CURLOPT_NOBODY, 1L);
			}

			if (configurations.capture_headers)
			{
				curl_easy_setopt(
					curl_handler,
					CURLOPT_HEADERFUNCTION,
					[this](
						void*
							pointer,
						size_t
							size,
						size_t
							nmemb,
						void*
							userdata
						)
					{
						return header_cb(pointer, size, nmemb, userdata);
					}
				);
				curl_easy_setopt(curl_handler, CURLOPT_HEADERDATA, response_headers);
			}

			struct curl_slist* header_list = nullptr;
			for (auto& hstr : configurations.default_headers)
				header_list = curl_slist_append(header_list, hstr.c_str());

			if (!configurations.bearer_token.empty())
			{
				std::string auth = "Authorization: Bearer " + configurations.bearer_token;
				header_list = curl_slist_append(header_list, auth.c_str());
			}

			if (header_list) curl_easy_setopt(curl_handler, CURLOPT_HTTPHEADER, header_list);
			if (!body.empty())
			{
				curl_easy_setopt(curl_handler, CURLOPT_POSTFIELDS, body.c_str());
				curl_easy_setopt(curl_handler, CURLOPT_POSTFIELDSIZE, body.size());
			}

			CURLcode res = curl_easy_perform(curl_handler);
			if (header_list) curl_slist_free_all(header_list);

			curl_easy_getinfo(curl_handler, CURLINFO_RESPONSE_CODE, &response.status_code);

			if (configurations.capture_body)
			{
				response.body = std::move(response_body);
			}
			if (configurations.capture_headers)
			{
				response.headers = std::move(response_headers);
			}
			if (configurations.capture_telemetry)
			{
				setup_telemetry(curl_handler, response);
			}

			return
				true;
		}
		catch
		(
			const std::exception&
				exception
		)
		{
			if (configurations.suppress_exceptions)
			{
				response.status_code = 0;
				response.body = (configurations.capture_body) ? "Request failed" : "";
				
				return
					true;
			};

			return
				handle_error_outputs(
					exception
				);				
		}
	}
		
	CURL*
		RestApiManager
			::acquire_handle()
	{
		try
		{
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling()
			)
			{
				return
					nullptr;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_feature_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_2
					);
			}

			CURL* curl_handler = curl_pool[pool_next];
			pool_next = (pool_next + 1) % curl_pool.size();
			curl_easy_reset(curl_handler);

			if (!configurations.trusted_ca_bundle_file.empty())
			{
				curl_easy_setopt(
					curl_handler,
					CURLOPT_CAINFO,
					configurations
						.trusted_ca_bundle_file.c_str()
				);
			}

			if (!configurations.pinned_cert_file.empty())
			{
				curl_easy_setopt(
					curl_handler,
					CURLOPT_PINNEDPUBLICKEY,
					configurations
						.pinned_cert_file.c_str()
				);
			}

			return
				curl_handler;
		}
		catch
		(
			const std::exception&
				exception
		)
		{
			handle_error_outputs(
				exception
			);

			return
				nullptr;				
		}
	}

	size_t
		RestApiManager
			::write_cb(
				void*
					pointer,
				size_t
					size,
				size_t
					nmemb,
				void*
					userdata
			)
	{
		try
		{
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling() ||				
				(
					configurations
						.is_edge_case_enabled_for_feature_handling() &&
					(
						pointer == nullptr ||
						size == 0 ||
						nmemb == 0 ||
						userdata == nullptr
					)
				)
			)
			{
				return
					0;
			}
		
			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_feature_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_3
					);
			}			

			auto* str = static_cast<std::string*>(userdata);
			str->append(static_cast<char*>(pointer), size * nmemb);

			return
				size * nmemb;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
			return
				handle_error_outputs<size_t>(
					exception
				);
        }	
	}

	size_t
		RestApiManager
			::header_cb(
				void*
					pointer,
				size_t
					size,
				size_t
					nmemb,
				void*
					userdata
			)
	{
		try
		{
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling() ||				
				(
					configurations
						.is_edge_case_enabled_for_feature_handling() &&
					(
						pointer == nullptr ||
						size == 0 ||
						nmemb == 0 ||
						userdata == nullptr
					)
				)
			)
			{
				return
					0;
			}
		
			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_feature_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_3
					);
			}			

			auto* headers = static_cast<std::multimap<std::string, std::string>*>(userdata);
			std::string line(static_cast<char*>(pointer), size * nmemb);
			auto colon = line.find(':');
			if (colon != std::string::npos)
			{
				std::string key = line.substr(0, colon);
				std::string value = line.substr(colon + 1);
				value.erase(0, value.find_first_not_of(" \t\r\n"));
				value.erase(value.find_last_not_of(" \t\r\n") + 1);
				headers->emplace(std::move(key), std::move(value));
			}

			return
				size * nmemb;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
			return
				handle_error_outputs<size_t>(
					exception
				);
        }	
	}

	bool
		RestApiManager
			::setup_telemetry(
				CURL*
					curl_handler,
				RestApiManagerResponse& 
					response
			)
	{
		try
		{
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling()
			)
			{
				return
					false;
			}
		
			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_feature_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_2
					);
			}			

			curl_easy_getinfo(
				curl_handler,
				CURLINFO_TOTAL_TIME,
				&response.total_timestamp_in_nanoseconds
			);
			curl_easy_getinfo(
				curl_handler,
				CURLINFO_NAMELOOKUP_TIME,
				&response.dns_timestamp_in_nanoseconds
			);
			curl_easy_getinfo(
				curl_handler,
				CURLINFO_CONNECT_TIME,
				&response.connect_timestamp_in_nanoseconds
			);
			curl_easy_getinfo(
				curl_handler,
				CURLINFO_APPCONNECT_TIME,
				&response.tls_timestamp_in_nanoseconds
			);
			curl_easy_getinfo(
				curl_handler,
				CURLINFO_STARTTRANSFER_TIME,
				&response.start_transfer_timestamp_in_nanoseconds
			);

			return
				true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
			return
				handle_error_outputs(
					exception
				);
        }
	}

	std::string
		RestApiManager
			::setup_url(
				const std::string&
					base,
				const std::string&
					path
			)
	{
		try
		{
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling() ||				
				(
					configurations
						.is_edge_case_enabled_for_feature_handling() &&
					(
						base.empty() ||
						path.empty()
					)
				)
			)
			{
				return
					"";
			}
		
			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_feature_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_2
					);
			}			

			bool
				base_slash =
					base.back() == '/';
			bool
				path_slash =
					path.front() == '/';

			if (base_slash && path_slash)
			{
				return
					base + path.substr(1);
			}

			if (!base_slash && !path_slash)
			{
				return
					base + "/" + path;
			}

			return
				base + path;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
			return
				handle_error_outputs<std::string>(
					exception
				);
        }
	}
}
