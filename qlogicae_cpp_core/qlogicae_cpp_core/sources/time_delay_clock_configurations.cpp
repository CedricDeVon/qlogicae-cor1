#include "pch.hpp"

#include "../includes/time_delay_clock_configurations.hpp"

namespace QLogicaeCppCore
{	
	bool
        TimeDelayClockConfigurations::cache_boolean_1 =
            false;

    TimeDelayClockConfigurations
        TimeDelayClockConfigurations::cache;



    bool
        TimeDelayClockConfigurations::construct()
    {
        _handle_construct();

        return
            cache_boolean_1;
    }

    bool
        TimeDelayClockConfigurations::destruct()
    {
        _handle_destruct();

        return
            cache_boolean_1;
    }

    bool
        TimeDelayClockConfigurations::setup(
            const TimeDelayClockConfigurations&
                    new_configurations
        )
    {
        cache =
            new_configurations;

        _handle_setup();

        return
            cache_boolean_1;
    }

    bool
        TimeDelayClockConfigurations::setup()
    {
        cache =
            {};

        _handle_setup();

        return
            cache_boolean_1;
    }

    bool
        TimeDelayClockConfigurations::reset()
    {
        _handle_reset();

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
    };
}
