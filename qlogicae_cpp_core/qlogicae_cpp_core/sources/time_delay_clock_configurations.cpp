#include "pch.hpp"

#include "../includes/time_delay_clock_configurations.hpp"

namespace QLogicaeCppCore
{	
	bool
        TimeDelayClockConfigurations::cache_boolean_1 =
            false;

    TimeDelayClockConfigurations
        TimeDelayClockConfigurations::cache_configurations;



    
    bool
        TimeDelayClockConfigurations::construct(
            const TimeDelayClockConfigurations&
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
        TimeDelayClockConfigurations::destruct(
            const TimeDelayClockConfigurations&
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
        TimeDelayClockConfigurations::setup(
            const TimeDelayClockConfigurations&
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
        TimeDelayClockConfigurations::reset(
            const TimeDelayClockConfigurations&
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
        TimeDelayClockConfigurations::setup_caches(
            const TimeDelayClockConfigurations&
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
        TimeDelayClockConfigurations::setup_defaults(
            const TimeDelayClockConfigurations&
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
        TimeDelayClockConfigurations::reset_caches(
            const TimeDelayClockConfigurations&
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
        TimeDelayClockConfigurations::reset_defaults(
            const TimeDelayClockConfigurations&
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
        TimeDelayClockConfigurations::_handle_construct()
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
        TimeDelayClockConfigurations::_handle_destruct()
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
        TimeDelayClockConfigurations::_handle_setup()
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
        TimeDelayClockConfigurations::_handle_reset()
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
        TimeDelayClockConfigurations::_handle_setup_caches()
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
        TimeDelayClockConfigurations::_handle_setup_defaults()
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
        TimeDelayClockConfigurations::_handle_reset_caches()
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
        TimeDelayClockConfigurations::_handle_reset_defaults()
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
}
