#pragma once

#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "gmail_api_manager_configurations.hpp"

namespace
	QLogicaeCppCore
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

		static GmailApiManager&
			singleton;

		GmailApiManager();

		~GmailApiManager();

		bool
			construct();

		bool
			destruct();

        void set_subject(
			const std::string&
				subject
			);

        void set_html_body(
			const std::string&
				html
			);

        void set_plain_body(
			const std::string&
				plain
			);

        void set_header(
            const std::string&
				key,
            const std::string&
				value
        );

        void attach_inline_image(
            const std::string&
				file_path,
            const std::string&
				content_id,
            const std::string&
				mime_type
        );

        void attach_file(
            const std::string&
				file_path,
            const std::string&
				mime_type,
            const std::string&
				filename
        );

        bool send_email(
            std::string& error_message
        );

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
