#include "pch.hpp"

#include "../includes/time_manager_configurations.hpp"

namespace QLogicaeCppCore
{
    bool
        TimeManagerConfigurations::initial_is_enabled =
            true;

    bool
        TimeManagerConfigurations::default_is_enabled =
            TimeManagerConfigurations::initial_is_enabled;

    bool
        TimeManagerConfigurations::cache_is_enabled =
            TimeManagerConfigurations::initial_is_enabled;
    


    bool
        TimeManagerConfigurations::cache_boolean_1 =
            false;

    TimeManagerConfigurations
        TimeManagerConfigurations::cache_configurations;


    
    bool
        TimeManagerConfigurations::construct(
            const TimeManagerConfigurations&
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
        TimeManagerConfigurations::destruct(
            const TimeManagerConfigurations&
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
        TimeManagerConfigurations::setup(
            const TimeManagerConfigurations&
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
        TimeManagerConfigurations::reset(
            const TimeManagerConfigurations&
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
        TimeManagerConfigurations::setup_caches(
            const TimeManagerConfigurations&
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
        TimeManagerConfigurations::setup_defaults(
            const TimeManagerConfigurations&
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
        TimeManagerConfigurations::reset_caches(
            const TimeManagerConfigurations&
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
        TimeManagerConfigurations::reset_defaults(
            const TimeManagerConfigurations&
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
        TimeManagerConfigurations::_handle_construct()
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
        TimeManagerConfigurations::_handle_destruct()
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
        TimeManagerConfigurations::_handle_setup()
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
        TimeManagerConfigurations::_handle_reset()
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
        TimeManagerConfigurations::_handle_setup_caches()
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
        TimeManagerConfigurations::_handle_setup_defaults()
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
        TimeManagerConfigurations::_handle_reset_caches()
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
        TimeManagerConfigurations::_handle_reset_defaults()
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
