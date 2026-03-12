#pragma once

#include "abstract_class.hpp"
#include "gmail_api_manager_response.hpp"
#include "gmail_api_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
    class
		GmailApiManager :
			public AbstractClass<GmailApiManagerConfigurations>
    {
    public:
		CURL*
			curl;

        curl_mime*
			mime_mixed;

        curl_mime*
			mime_related;

        curl_mimepart*
			html_part;

        curl_mimepart*
			plain_part;

        curl_slist*
			headers;

        curl_slist*
			recipients;

		boost::mutex
			feature_handling_mutex_2;

		GmailApiManager();

		~GmailApiManager();

		bool
			construct();

		bool
			destruct();

		bool
			setup(
				const GmailApiManagerConfigurations&
					new_configurations
			) override;

        bool
			attach_inline_image(
				const std::string&
					file_path,
				const std::string&
					content_id,
				const std::string&
					mime_type
        );

        bool
			attach_file(
				const std::string&
					file_path,
				const std::string&
					mime_type,
				const std::string&
					filename
        );

        GmailApiManagerResponse
			send_email();

		bool
			cleanup();

		bool
			reset_mime();

		bool
			setup();

		bool
			finalize_body();

		bool
			configure_smtp();

		bool
			prepare_headers();

		bool
			prepare_recipients();
	};
}
