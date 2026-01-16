#include "pch.hpp"

#include "../includes/gmail_manager_configurations.hpp"

namespace QLogicaeCppCore
{
    bool
        GmailManagerConfigurations::initial_is_enabled =
            true;

    bool
        GmailManagerConfigurations::default_is_enabled =
            GmailManagerConfigurations::initial_is_enabled;

    bool
        GmailManagerConfigurations::cache_is_enabled =
            GmailManagerConfigurations::initial_is_enabled;




    bool
        GmailManagerConfigurations::cache_boolean_1 =
            false;

    GmailManagerConfigurations
        GmailManagerConfigurations::cache_configurations;



    
    bool
        GmailManagerConfigurations::construct(
            const GmailManagerConfigurations&
                configurations
        )
    {
        cache_configurations =
            configurations;

        _handle_construct();

        return
            cache_boolean_1;
    }

    bool
        GmailManagerConfigurations::destruct(
            const GmailManagerConfigurations&
                configurations
        )
    {
        cache_configurations =
            configurations;

        _handle_destruct();

        return
            cache_boolean_1;
    }

    bool
        GmailManagerConfigurations::setup(
            const GmailManagerConfigurations&
                configurations
        )
    {
        cache_configurations =
            configurations;

        _handle_setup();

        return
            cache_boolean_1;
    }

    bool
        GmailManagerConfigurations::reset(
            const GmailManagerConfigurations&
                configurations
        )
    {
        cache_configurations =
            configurations;

        _handle_reset();

        return
            cache_boolean_1;
    }
    
    bool
        GmailManagerConfigurations::setup_caches(
            const GmailManagerConfigurations&
                configurations
        )
    {
        cache_configurations =
            configurations;

        _handle_setup_caches();

        return
            cache_boolean_1;
    }
    
    bool
        GmailManagerConfigurations::setup_defaults(
            const GmailManagerConfigurations&
                configurations
        )
    {
        cache_configurations =
            configurations;

        _handle_setup_defaults();

        return
            cache_boolean_1;
    }
    
    bool
        GmailManagerConfigurations::reset_caches(
            const GmailManagerConfigurations&
                configurations
        )
    {
        cache_configurations =
            configurations;

        _handle_reset_caches();

        return
            cache_boolean_1;
    }
    
    bool
        GmailManagerConfigurations::reset_defaults(
            const GmailManagerConfigurations&
                configurations
        )
    {
        cache_configurations =
            configurations;

        _handle_reset_defaults();

        return
            cache_boolean_1;
    }

    void
        GmailManagerConfigurations::_handle_construct()
    {
        try
        {
            cache_boolean_1 =
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            cache_boolean_1 =
                false;

            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        GmailManagerConfigurations::_handle_destruct()
    {
        try
        {
            cache_boolean_1 =
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            cache_boolean_1 =
                false;

            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        GmailManagerConfigurations::_handle_setup()
    {
        try
        {
            _handle_setup_caches();
            _handle_setup_defaults();

            cache_boolean_1 =
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            cache_boolean_1 =
                false;

            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        GmailManagerConfigurations::_handle_reset()
    {
        try
        {
            _handle_reset_caches();
            _handle_reset_defaults();

            cache_boolean_1 =
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            cache_boolean_1 =
                false;

            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }
    
    void
        GmailManagerConfigurations::_handle_setup_caches()
    {
        try
        {  
            cache_is_enabled =
                cache_configurations.is_enabled;

            cache_boolean_1 =
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            cache_boolean_1 =
                false;

            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        GmailManagerConfigurations::_handle_setup_defaults()
    {
        try
        {         
            default_is_enabled =
                cache_configurations.is_enabled;

            cache_boolean_1 =
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            cache_boolean_1 =
                false;

            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }
    
    void
        GmailManagerConfigurations::_handle_reset_caches()
    {
        try
        {           
            cache_is_enabled =
                initial_is_enabled;

            cache_boolean_1 =
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            cache_boolean_1 =
                false;

            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        GmailManagerConfigurations::_handle_reset_defaults()
    {
        try
        {            
            default_is_enabled =
                initial_is_enabled;

            cache_boolean_1 =
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            cache_boolean_1 =
                false;

            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }
}
