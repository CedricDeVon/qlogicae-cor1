#pragma once

#include "error_manager.hpp"
#include "singleton_manager.hpp"
#include "gmail_manager_configurations.hpp"

namespace QLogicaeCppCore
{
    class GmailManagerUtilities
    {
    public:
        static CURL*
            _cache_curl;

        static std::string
            _cache_subject;

        static curl_mime*
            _cache_mime_mixed;

        static std::string
            _cache_html_body;

        static std::string
            _cache_plain_body;

        static std::string
            _cache_smtp_server;

        static boost::mutex
            _cache_mutex;

        static curl_mime*
            _cache_mime_related;

        static curl_mimepart*
            _cache_html_part;

        static curl_mimepart*
            _cache_plain_part;

        static std::string
            _cache_sender_address;

        static struct curl_slist*
            _cache_headers;

        static struct curl_slist*
            _cache_recipients;

        static std::vector<std::string>
            _cache_to_recipients;

        static std::vector<std::string>
            _cache_cc_recipients;

        static std::vector<std::string>
            _cache_bcc_recipients;

        static std::function<std::string()>
            _cache_password_provider;

        static std::map<std::string, std::string>
            _cache_custom_headers;

        static bool
            _cache_boolean_1;

        static GmailManagerUtilities&
            singleton;

        GmailManagerUtilities();

        ~GmailManagerUtilities();

        GmailManagerUtilities(
            const GmailManagerUtilities&
                instance
        ) = delete;

        GmailManagerUtilities(
            GmailManagerUtilities&&
                instance
        ) noexcept = delete;

        GmailManagerUtilities& operator = (
            GmailManagerUtilities&&
                instance
            ) = delete;

        GmailManagerUtilities& operator = (
            const GmailManagerUtilities&
                instance
            ) = delete;

        bool
            construct();

        bool
            destruct();

        bool
            setup();

        bool
            reset();

        void
            _manage_construct();

        void
            _manage_destruct();

        void
            _manage_setup();

        void
            _manage_reset();
    };
}
