#pragma once

#include "result.hpp"
#include "utilities.hpp"
#include "mutex_manager.hpp"

namespace QLogicaeCppCore
{
    class GmailMailer
    {
    public:
        GmailMailer();
        
        GmailMailer(
            const std::string_view& sender_address,
            const std::function<std::string()>& password_provider,
            const std::vector<std::string>& to_recipients,
            const std::vector<std::string>& cc_recipients,
            const std::vector<std::string>& bcc_recipients,
            const std::string_view& smtp_server
        );

        ~GmailMailer();

        GmailMailer(
            const GmailMailer& instance
        ) = delete;

        GmailMailer(
            GmailMailer&& instance
        ) = delete;

        GmailMailer& operator = (
            const GmailMailer& instance
        ) = delete;

        GmailMailer& operator = (
            GmailMailer&& instance
        ) = delete;

        void construct(
            Result<bool>& result
        );

        void construct(
            Result<bool>& result,
            const std::string_view& sender_address,
            const std::function<std::string()>& password_provider,
            const std::vector<std::string>& to_recipients,
            const std::vector<std::string>& cc_recipients,
            const std::vector<std::string>& bcc_recipients,
            const std::string_view& smtp_server
        );

        void destruct(
            Result<bool>& result
        );

        void set_subject(
            Result<bool>& result,
            const std::string_view& subject
        );

        void set_html_body(
            Result<bool>& result,
            const std::string_view& html
        );

        void set_plain_body(
            Result<bool>& result,
            const std::string_view& plain
        );

        void set_header(
            Result<bool>& result,             
            const std::string_view& key,
            const std::string_view& value
        );

        void attach_inline_image(
            Result<bool>& result, 
            const std::string_view& file_path,
            const std::string_view& content_id,
            const std::string_view& mime_type
        );

        void attach_file(
            Result<bool>& result, 
            const std::string_view& file_path,
            const std::string_view& mime_type,
            const std::string_view& filename
        );

        void send_email(
            Result<std::string>& result
        );

        CURL* _curl;

        std::string _subject;

        curl_mime* _mime_mixed;

        std::string _html_body;

        std::string _plain_body;

        std::string _smtp_server;

        std::mutex _access_mutex;

        curl_mime* _mime_related;

        curl_mimepart* _html_part;

        curl_mimepart* _plain_part;

        std::string _sender_address;

        struct curl_slist* _headers;

        struct curl_slist* _recipients;

        std::vector<std::string> _to_recipients;

        std::vector<std::string> _cc_recipients;

        std::vector<std::string> _bcc_recipients;

        std::function<std::string()> _password_provider;

        std::map<std::string, std::string> _custom_headers;

        void _cleanup(
            Result<bool>& result
        );

        void _reset_mime(
            Result<bool>& result
        );

        void _finalize_body(
            Result<bool>& result
        );

        void _configure_smtp(
            Result<bool>& result
        );

        void _prepare_headers(
            Result<bool>& result
        );

        void _prepare_recipients(
            Result<bool>& result
        );
    };
}

