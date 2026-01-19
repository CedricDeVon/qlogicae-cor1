#pragma once

#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "gmail_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    class
		GmailManager :
			public AbstractClass<GmailManagerConfigurations>
    {
    public:
		static GmailManager&
			singleton;

		GmailManager();

		~GmailManager();

		bool
			construct();

		bool
			destruct();
	};
}

/*
* 
* static CURL* _cache_curl;

        static std::string _cache_subject;

        static curl_mime* _cache_mime_mixed;

        static std::string _cache_html_body;

        static std::string _cache_plain_body;

        static std::string _cache_smtp_server;

        static boost::mutex _cache_mutex;

        static curl_mime* _cache_mime_related;

        static curl_mimepart* _cache_html_part;

        static curl_mimepart* _cache_plain_part;

        static std::string _cache_sender_address;

        static struct curl_slist* _cache_headers;

        static struct curl_slist* _cache_recipients;

        static std::vector<std::string> _cache_to_recipients;

        static std::vector<std::string> _cache_cc_recipients;

        static std::vector<std::string> _cache_bcc_recipients;

        static std::function<std::string()> _cache_password_provider;

        static std::map<std::string, std::string> _cache_custom_headers;

        static GmailManager&
            singleton;

        GmailManager();
        
        GmailManager(
            const std::string_view& sender_address,
            const std::function<std::string()>& password_provider,
            const std::vector<std::string>& to_recipients,
            const std::vector<std::string>& cc_recipients,
            const std::vector<std::string>& bcc_recipients,
            const std::string_view& smtp_server
        );

        ~GmailManager();

        GmailManager(
            const GmailManager& instance
        ) = delete;

        GmailManager(
            GmailManager&& instance
        ) = delete;

        GmailManager& operator = (
            const GmailManager& instance
        ) = delete;

        GmailManager& operator = (
            GmailManager&& instance
        ) = delete;

        bool construct();

        bool destruct();

        bool setup(
            const std::string_view& sender_address,
            const std::function<std::string()>& password_provider,
            const std::vector<std::string>& to_recipients,
            const std::vector<std::string>& cc_recipients,
            const std::vector<std::string>& bcc_recipients,
            const std::string_view& smtp_server
        );

        bool setup();

        bool reset();

        bool set_subject(            
            const std::string_view& subject
        );

        bool set_html_body(            
            const std::string_view& html
        );

        bool set_plain_body(            
            const std::string_view& plain
        );

        bool set_header(                         
            const std::string_view& key,
            const std::string_view& value
        );

        bool attach_inline_image(             
            const std::string_view& file_path,
            const std::string_view& content_id,
            const std::string_view& mime_type
        );

        bool attach_file(             
            const std::string_view& file_path,
            const std::string_view& mime_type,
            const std::string_view& filename
        );

        std::string send_email();

        void _manage_cleanup();

        void _manage_reset_mime();

        void _manage_finalize_body();

        void _manage_configure_smtp();

        void _manage_prepare_headers();

        void _manage_prepare_recipients();
* 
*/ 