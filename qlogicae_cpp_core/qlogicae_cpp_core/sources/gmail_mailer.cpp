#include "pch.hpp"

#include "../includes/gmail_manager.hpp"

namespace
	QLogicaeCppCore
{  
	GmailManager&
        GmailManager
			::singleton =
				SingletonManager
					::get_singleton<GmailManager>();



	GmailManager
		::GmailManager() :
			AbstractClass<GmailManagerConfigurations>()
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

    GmailManager
		::~GmailManager()
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
        GmailManager
			::construct()
    {
        try
        {			
			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_utility_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						method_handling_layer_mutex_1
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

    bool
        GmailManager
			::destruct()
    {
        try
        {		
			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_utility_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						method_handling_layer_mutex_1
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
}

/*

GmailMailer::GmailMailer()
	{
		Result<bool> result;

		construct(result);
	}

	GmailMailer::GmailMailer(
		const std::string_view& sender_address,
		const std::function<std::string()>& password_provider,
		const std::vector<std::string>& to_recipients,
		const std::vector<std::string>& cc_recipients,
		const std::vector<std::string>& bcc_recipients,
		const std::string_view& smtp_server
	)
	{
		Result<bool> result;

		construct(
			result,
			sender_address,
			password_provider,
			to_recipients,
			cc_recipients,
			bcc_recipients,
			smtp_server
		);
	}

	GmailMailer::~GmailMailer()
	{
		Result<bool> result;

		destruct(result);
	}

	void GmailMailer::construct(
		Result<bool>& result
	)
	{
		construct(
			result,
			"",
			[]() { return ""; },
			{},
			{},
			{},
			""
		);
	}

	void GmailMailer::construct(
		Result<bool>& result,
		const std::string_view& sender_address,
		const std::function<std::string()>& password_provider,
		const std::vector<std::string>& to_recipients,
		const std::vector<std::string>& cc_recipients,
		const std::vector<std::string>& bcc_recipients,
		const std::string_view& smtp_server
	)
	{
		_curl = nullptr;
		_mime_mixed = nullptr;
		_mime_related = nullptr;
		_html_part = nullptr;
		_plain_part = nullptr;
		_sender_address = sender_address;
		_password_provider = password_provider;
		_smtp_server = smtp_server;
		_recipients = nullptr;
		_headers = nullptr;
		_to_recipients = to_recipients;
		_cc_recipients = cc_recipients;
		_bcc_recipients = bcc_recipients;

		if (sender_address.empty() || !password_provider)
		{
			result.set_to_bad_status_with_value(
				false
			);
			return;
		}
		if (to_recipients.empty())
		{
			result.set_to_bad_status_with_value(
				false
			);
			return;
		}

		curl_global_init(CURL_GLOBAL_DEFAULT);
		construct(result);

		result.set_to_good_status_with_value(
			true
		);
	}

	void GmailMailer::destruct(
		Result<bool>& result
	)
	{
		_cleanup(result);
		curl_global_cleanup();

		result.set_to_good_status_with_value(
			true
		);
	}

	void GmailMailer::set_subject(
		Result<bool>& result,
		const std::string_view& subject
	)
	{
		std::scoped_lock lock(_access_mutex);

		this->_subject = subject;

		result.set_to_good_status_with_value(
			true
		);
	}

	void GmailMailer::set_html_body(
		Result<bool>& result,
		const std::string_view& html
	)
	{
		std::scoped_lock lock(_access_mutex);

		_html_body = html;

		result.set_to_good_status_with_value(
			true
		);
	}

	void GmailMailer::set_plain_body(
		Result<bool>& result,
		const std::string_view& plain
	)
	{
		std::scoped_lock lock(_access_mutex);

		_plain_body = plain;

		result.set_to_good_status_with_value(
			true
		);
	}

	void GmailMailer::set_header(
		Result<bool>& result,
		const std::string_view& key,
		const std::string_view& value)
	{
		std::scoped_lock lock(_access_mutex);

		_custom_headers[std::string(key)] = std::string(value);

		result.set_to_good_status_with_value(
			true
		);
	}

	void GmailMailer::attach_inline_image(
		Result<bool>& result,
		const std::string_view& file_path,
		const std::string_view& content_id,
		const std::string_view& mime_type)
	{
		std::scoped_lock lock(_access_mutex);

		if (!std::filesystem::exists(file_path))
		{
			result.set_to_bad_status_with_value(
				false
			);
			return;
		}

		curl_mimepart* part =
			curl_mime_addpart(_mime_related);

		curl_mime_filedata(
			part, std::string(file_path).c_str()
		);

		curl_mime_type(
			part, std::string(mime_type).c_str()
		);

		curl_mime_encoder(
			part, "base64"
		);

		curl_mime_filename(
			part, std::string(file_path).c_str()
		);

		std::string header =
			"Content-ID: <" +
			std::string(content_id) +
			">";

		struct curl_slist* header_list =
			curl_slist_append(
				nullptr,
				header.c_str()
			);

		curl_mime_headers(part, header_list, 1);

		result.set_to_good_status_with_value(
			true
		);
	}

	void GmailMailer::attach_file(
		Result<bool>& result,
		const std::string_view& file_path,
		const std::string_view& mime_type,
		const std::string_view& filename)
	{
		std::scoped_lock lock(_access_mutex);

		if (!std::filesystem::exists(file_path))
		{
			result.set_to_bad_status_with_value(
				false
			);
			return;
		}

		curl_mimepart* part = curl_mime_addpart(_mime_mixed);

		curl_mime_filedata(
			part, std::string(file_path).c_str()
		);

		curl_mime_type(
			part, std::string(mime_type).c_str()
		);

		curl_mime_encoder(
			part, "base64"
		);

		curl_mime_filename(
			part, std::string(filename).c_str()
		);

		std::string header =
			"Content-Disposition: attachment; filename=\"" + std::string(filename) + "\"";
		struct curl_slist* header_list =
			curl_slist_append(
				nullptr, header.c_str()
			);

		curl_mime_headers(
			part, header_list, 1
		);

		result.set_to_good_status_with_value(
			true
		);
	}

	void GmailMailer::send_email(
		Result<std::string>& result
	)
	{
		Result<bool> boolean_result;

		std::scoped_lock lock(_access_mutex);

		_reset_mime(boolean_result);
		_prepare_headers(boolean_result);
		_finalize_body(boolean_result);
		CURLcode curlcode_result = curl_easy_perform(_curl);
		if (curlcode_result != CURLE_OK)
		{
			result.set_to_bad_status_with_value(
				curl_easy_strerror(
					curlcode_result
				)
			);
			return;
		}

		result.set_to_good_status_with_value(
			""
		);
	}

	void GmailMailer::_finalize_body(
		Result<bool>& result
	)
	{
		if (!_plain_body.empty())
		{
			_plain_part = curl_mime_addpart(_mime_related);
			curl_mime_data(_plain_part, _plain_body.c_str(), CURL_ZERO_TERMINATED);
			curl_mime_type(_plain_part, "text/plain");
		}
		if (!_html_body.empty())
		{
			_html_part = curl_mime_addpart(_mime_related);
			curl_mime_data(_html_part, _html_body.c_str(), CURL_ZERO_TERMINATED);
			curl_mime_type(_html_part, "text/html");
		}
		curl_mimepart* part = curl_mime_addpart(_mime_mixed);
		curl_mime_subparts(part, _mime_related);
		curl_mime_type(part, "multipart/alternative");
		curl_easy_setopt(_curl, CURLOPT_MIMEPOST, _mime_mixed);

		result.set_to_good_status_with_value(
			true
		);
	}

	void GmailMailer::_reset_mime(
		Result<bool>& result
	)
	{
		if (_mime_mixed)
		{
			curl_mime_free(_mime_mixed);
			_mime_mixed = curl_mime_init(_curl);
		}
		if (_mime_related)
		{
			curl_mime_free(_mime_related);
			_mime_related = curl_mime_init(_curl);
		}

		result.set_to_good_status_with_value(
			true
		);
	}

	void GmailMailer::_cleanup(
		Result<bool>& result
	)
	{
		if (_headers)
		{
			curl_slist_free_all(_headers);
			_headers = nullptr;
		}

		if (_recipients)
		{
			curl_slist_free_all(_recipients);
			_recipients = nullptr;
		}

		if (_curl)
		{
			curl_easy_cleanup(_curl);
			_curl = nullptr;
		}

		_mime_mixed = nullptr;
		_mime_related = nullptr;

		result.set_to_good_status_with_value(
			true
		);
	}

	void GmailMailer::_configure_smtp(
		Result<bool>& result
	)
	{
		std::string full_url = "smtps://" + _smtp_server;
		curl_easy_setopt(_curl, CURLOPT_URL, full_url.c_str());
		curl_easy_setopt(_curl, CURLOPT_USE_SSL, CURLUSESSL_ALL);
		curl_easy_setopt(_curl, CURLOPT_USERNAME, _sender_address.c_str());
		std::string password = _password_provider();
		curl_easy_setopt(_curl, CURLOPT_PASSWORD, password.c_str());
		curl_easy_setopt(_curl, CURLOPT_MAIL_FROM,
			("<" + _sender_address + ">").c_str());
		curl_easy_setopt(_curl, CURLOPT_VERBOSE, 0L);
		curl_easy_setopt(_curl, CURLOPT_SSL_VERIFYPEER, 1L);
		curl_easy_setopt(_curl, CURLOPT_SSL_VERIFYHOST, 2L);

		result.set_to_good_status_with_value(
			true
		);
	}

	void GmailMailer::_prepare_recipients(
		Result<bool>& result
	)
	{
		auto append = [this](const std::vector<std::string>& list)
			{
				for (const std::string& item : list)
				{
					_recipients = curl_slist_append(
						_recipients,
						("<" + item + ">").c_str());
				}
			};
		append(_to_recipients);
		append(_cc_recipients);
		append(_bcc_recipients);
		curl_easy_setopt(
			_curl, CURLOPT_MAIL_RCPT, _recipients
		);

		result.set_to_good_status_with_value(
			true
		);
	}

	void GmailMailer::_prepare_headers(
		Result<bool>& result
	)
	{
		_headers = curl_slist_append(
			_headers,
			("Subject: " + _subject).c_str()
		);

		_headers = curl_slist_append(
			_headers,
			std::string("From: <" + _sender_address + ">").c_str()
		);

		for (const std::string& recipient : _to_recipients)
		{
			_headers = curl_slist_append(
				_headers,
				("To: <" + recipient + ">").c_str());
		}
		for (const std::string& cc : _cc_recipients)
		{
			_headers = curl_slist_append(
				_headers,
				("Cc: <" + cc + ">").c_str());
		}
		for (const auto& pair : _custom_headers)
		{
			_headers = curl_slist_append(
				_headers,
				(pair.first + ": " + pair.second).c_str());
		}

		curl_easy_setopt(_curl, CURLOPT_HTTPHEADER, _headers);

		result.set_to_good_status_with_value(
			true
		);
	}

*/
 