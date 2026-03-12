#include "pch.hpp"

#include "../includes/gmail_api_manager.hpp"

namespace
	QLogicae::Cor::V1
{
    GmailApiManager
		::GmailApiManager() :
			AbstractClass<GmailApiManagerConfigurations>()
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

	GmailApiManager
		::~GmailApiManager()
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
        GmailApiManager
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

			static std::once_flag curl_init_flag;

			std::call_once(
				curl_init_flag,
				[]()
				{
					curl_global_init(CURL_GLOBAL_DEFAULT);
				}
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

    bool
        GmailApiManager
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

			cleanup();
			curl_global_cleanup();

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
		GmailApiManager
			::setup(
				const GmailApiManagerConfigurations&
					new_configurations
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
						new_configurations.sender_address.empty() ||
						new_configurations.password_provider == nullptr ||
						new_configurations.to_recipients.empty()
					)
				)
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

			configurations =
				new_configurations;

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
		GmailApiManager
			::attach_inline_image(
				const std::string&
					file_path,
				const std::string&
					content_id,
				const std::string&
					mime_type
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
						file_path.empty() ||
						content_id.empty() ||
						mime_type.empty() ||
						!std::filesystem::exists(file_path)
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

			curl_mimepart* part = curl_mime_addpart(mime_related);
			curl_mime_filedata(part, file_path.c_str());
			curl_mime_type(part, mime_type.c_str());
			curl_mime_encoder(part, "base64");
			curl_mime_filename(part, file_path.c_str());

			std::string header = "Content-ID: <" + content_id + ">";
			struct curl_slist* header_list = curl_slist_append(nullptr, header.c_str());
			curl_mime_headers(part, header_list, 1);

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
		GmailApiManager
			::attach_file(
				const std::string&
					file_path,
				const std::string&
					mime_type,
				const std::string&
					filename
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
						file_path.empty() ||
						mime_type.empty() ||
						filename.empty() ||
						!std::filesystem::exists(file_path)
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

			curl_mimepart* part = curl_mime_addpart(mime_mixed);
			curl_mime_filedata(part, file_path.c_str());
			curl_mime_type(part, mime_type.c_str());
			curl_mime_encoder(part, "base64");
			curl_mime_filename(part, filename.c_str());

			std::string header =
				"Content-Disposition: attachment; filename=\"" + filename + "\"";
			struct curl_slist* header_list = curl_slist_append(nullptr, header.c_str());
			curl_mime_headers(part, header_list, 1);

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

	GmailApiManagerResponse
		GmailApiManager
			::send_email()
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
					{};
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

			GmailApiManagerResponse
				response;

			if (!reset_mime())
			{
				response.error_message =
					"reset_mime() failed";

				return
					response;	
			}
	
            if (!prepare_headers())
			{
				response.error_message =
					"prepare_headers() failed";

				return
					response;					
			}

            if (!finalize_body())
			{
				response.error_message =
					"finalize_body() failed";

				return
					response;					
			}

            CURLcode result = curl_easy_perform(curl);

            if (result != CURLE_OK)
            {
				response.error_message =
					curl_easy_strerror(result);
            }

			return
				response;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
			return
				handle_error_outputs<GmailApiManagerResponse>(
					exception
				);
        }
	}

	bool
		GmailApiManager
			::cleanup()
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

			if (headers)
			{
				curl_slist_free_all(headers);
				headers = nullptr;
			}

			if (recipients)
			{
				curl_slist_free_all(recipients);
				recipients = nullptr;
			}

			if (curl)
			{
				curl_easy_cleanup(curl);
				curl = nullptr;
			}

			mime_mixed = nullptr;
			mime_related = nullptr;

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
		GmailApiManager
			::reset_mime()
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

			if (mime_mixed)
			{
				curl_mime_free(mime_mixed);
				mime_mixed = curl_mime_init(curl);
			}

			if (mime_related)
			{
				curl_mime_free(mime_related);
				mime_related = curl_mime_init(curl);
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
		GmailApiManager
			::finalize_body()
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

			if (configurations.plain_body.empty() ||
				configurations.html_body.empty())
			{
				return
					false;
			}
			
			plain_part = curl_mime_addpart(mime_related);
			curl_mime_data(plain_part, configurations.plain_body.c_str(), CURL_ZERO_TERMINATED);
			curl_mime_type(plain_part, "text/plain");

			html_part = curl_mime_addpart(mime_related);
			curl_mime_data(html_part, configurations.html_body.c_str(), CURL_ZERO_TERMINATED);
			curl_mime_type(html_part, "text/html");
			
			curl_mimepart* part = curl_mime_addpart(mime_mixed);
			curl_mime_subparts(part, mime_related);
			curl_mime_type(part, "multipart/alternative");
			curl_easy_setopt(curl, CURLOPT_MIMEPOST, mime_mixed);

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
		GmailApiManager
			::configure_smtp()
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
						feature_handling_mutex_1
					);
			}			

			std::string full_url = "smtps://" + configurations.smtp_server;
			curl_easy_setopt(curl, CURLOPT_URL, full_url.c_str());
			curl_easy_setopt(curl, CURLOPT_USE_SSL, CURLUSESSL_ALL);
			curl_easy_setopt(curl, CURLOPT_USERNAME, configurations.sender_address.c_str());
			std::string password = configurations.password_provider();
			curl_easy_setopt(curl, CURLOPT_PASSWORD, password.c_str());
			curl_easy_setopt(curl, CURLOPT_MAIL_FROM,
				("<" + configurations.sender_address + ">").c_str());
			curl_easy_setopt(curl, CURLOPT_VERBOSE, 0L);
			curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 1L);
			curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 2L);

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
		GmailApiManager
			::prepare_headers()
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

			headers = curl_slist_append(
                headers,
                ("Subject: " + configurations.subject).c_str());
            headers = curl_slist_append(
                headers,
                ("From: <" + configurations.sender_address + ">").c_str());

            for (const std::string& recipient : configurations.to_recipients)
            {
                headers = curl_slist_append(
                    headers,
                    ("To: <" + recipient + ">").c_str());
            }
            for (const std::string& cc : configurations.cc_recipients)
            {
                headers = curl_slist_append(
                    headers,
                    ("Cc: <" + cc + ">").c_str());
            }
            for (const auto& pair : configurations.custom_headers)
            {
                headers = curl_slist_append(
                    headers,
                    (pair.first + ": " + pair.second).c_str());
            }
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

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
		GmailApiManager
			::prepare_recipients()
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
						feature_handling_mutex_1
					);
			}			

			auto append = [this](const std::vector<std::string>& list)
				{
					for (const std::string& item : list)
					{
						recipients = curl_slist_append(
							recipients,
							("<" + item + ">").c_str());
					}
				};

			append(configurations.to_recipients);
			append(configurations.cc_recipients);
			append(configurations.bcc_recipients);
			curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);

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
