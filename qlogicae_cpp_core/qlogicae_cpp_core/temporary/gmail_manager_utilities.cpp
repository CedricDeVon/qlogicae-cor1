#include "pch.hpp"

#include "../includes/gmail_manager_utilities.hpp"

namespace QLogicaeCppCore
{    
    CURL*
        GmailManagerUtilities::_cache_curl =
            nullptr;

    std::string
        GmailManagerUtilities::_cache_subject =
            "";

    curl_mime*
        GmailManagerUtilities::_cache_mime_mixed =
            nullptr;

    std::string
        GmailManagerUtilities::_cache_html_body =
            "";

    std::string
        GmailManagerUtilities::_cache_plain_body =
            "";

    std::string
        GmailManagerUtilities::_cache_smtp_server =
            "";

    boost::mutex
        GmailManagerUtilities::_cache_mutex;

    curl_mime*
        GmailManagerUtilities::_cache_mime_related =
            nullptr;

    curl_mimepart*
        GmailManagerUtilities::_cache_html_part =
            nullptr;

    curl_mimepart*
        GmailManagerUtilities::_cache_plain_part =
            nullptr;

    std::string
        GmailManagerUtilities::_cache_sender_address =
            "";

    struct curl_slist*
        GmailManagerUtilities::_cache_headers =
            nullptr;

    struct curl_slist*
        GmailManagerUtilities::_cache_recipients =
            nullptr;

    std::vector<std::string>
        GmailManagerUtilities::_cache_to_recipients =
            {};

    std::vector<std::string>
        GmailManagerUtilities::_cache_cc_recipients =
            {};

    std::vector<std::string>
        GmailManagerUtilities::_cache_bcc_recipients =
            {};

    std::function<std::string()>
        GmailManagerUtilities::_cache_password_provider =
            []() { return ""; };

    std::map<std::string, std::string>
        GmailManagerUtilities::_cache_custom_headers =
            {};

    bool
        GmailManagerUtilities::_cache_boolean_1 =
            false;

    GmailManagerUtilities&
        GmailManagerUtilities::singleton =
            SingletonManager::get_singleton<GmailManagerUtilities>();



    GmailManagerUtilities::GmailManagerUtilities()
    {
        try
        {
            _manage_construct();
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    GmailManagerUtilities::~GmailManagerUtilities()
    {
        try
        {
            _manage_destruct();
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    bool
        GmailManagerUtilities::construct()
    {
        _manage_construct();

        return
            GmailManagerUtilities::_cache_boolean_1;
    }

    void
        GmailManagerUtilities::_manage_construct()
    {
        try
        {
            GmailManagerUtilities::_cache_boolean_1 =
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    bool
        GmailManagerUtilities::destruct()
    {
        _manage_destruct();

        return
            GmailManagerUtilities::_cache_boolean_1;
    }

    void
        GmailManagerUtilities::_manage_destruct()
    {
        try
        {
            GmailManagerUtilities::_cache_boolean_1 =
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    bool
        GmailManagerUtilities::setup()
    {
        _manage_setup();

        return
            GmailManagerUtilities::_cache_boolean_1;
    }

    void
        GmailManagerUtilities::_manage_setup()
    {
        try
        {
            GmailManagerUtilities::_cache_boolean_1 =
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    bool
        GmailManagerUtilities::reset()
    {
        _manage_reset();

        return
            GmailManagerUtilities::_cache_boolean_1;
    }

    void
        GmailManagerUtilities::_manage_reset()
    {
        try
        {
            GmailManagerUtilities::_cache_boolean_1 =
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }
}

