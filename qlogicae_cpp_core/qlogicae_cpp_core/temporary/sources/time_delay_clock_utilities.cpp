#include "pch.hpp"

#include "../includes/time_delay_clock_utilities.hpp"

namespace QLogicaeCppCore
{
    bool
        TimeDelayClockUtilities::cache_boolean_1 =
            false;

    TimeDelayClockUtilities&
        TimeDelayClockUtilities::singleton =
            SingletonManager::get_singleton<TimeDelayClockUtilities>();


    
    TimeDelayClockUtilities::TimeDelayClockUtilities()
    {
        try
        {
            _handle_construct();
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

    TimeDelayClockUtilities::~TimeDelayClockUtilities()
    {
        try
        {
            _handle_destruct();
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
        TimeDelayClockUtilities::construct()
    {
        _handle_construct();

        return
            cache_boolean_1;
    }

    void
        TimeDelayClockUtilities::_handle_construct()
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
            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    bool
        TimeDelayClockUtilities::destruct()
    {
        _handle_destruct();

        return
            cache_boolean_1;
    }

    void
        TimeDelayClockUtilities::_handle_destruct()
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
            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    bool
        TimeDelayClockUtilities::setup(
            const TimeDelayClockConfigurations&
                new_configurations
        )
    {
        TimeDelayClockConfigurations::cache =
            new_configurations;

        _handle_setup();

        return
            cache_boolean_1;
    }

    bool
        TimeDelayClockUtilities::setup()
    {
        TimeDelayClockConfigurations::cache =
            {};

        _handle_setup();

        return
            cache_boolean_1;
    }

    void
        TimeDelayClockUtilities::_handle_setup()
    {
        try
        {
            TimeDelayClockConfigurations::_handle_setup();

            cache_boolean_1 =
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
        TimeDelayClockUtilities::reset()
    {
        _handle_reset();

        return
            cache_boolean_1;
    }

    void
        TimeDelayClockUtilities::_handle_reset()
    {
        try
        {
            TimeDelayClockConfigurations::_handle_reset();

            cache_boolean_1 =
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
