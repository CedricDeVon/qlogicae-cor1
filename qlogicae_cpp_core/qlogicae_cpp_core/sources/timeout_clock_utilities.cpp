#include "pch.hpp"

#include "../includes/timeout_clock_utilities.hpp"

namespace QLogicaeCppCore
{
    bool
        TimeoutClockUtilities::cache_boolean_1 =
            false;

    TimeoutClockUtilities&
        TimeoutClockUtilities::singleton =
            SingletonManager::get_singleton<TimeoutClockUtilities>();


    
    TimeoutClockUtilities::TimeoutClockUtilities()
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

    TimeoutClockUtilities::~TimeoutClockUtilities()
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
        TimeoutClockUtilities::construct()
    {
        _handle_construct();

        return
            cache_boolean_1;
    }

    void
        TimeoutClockUtilities::_handle_construct()
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
        TimeoutClockUtilities::destruct()
    {
        _handle_destruct();

        return
            cache_boolean_1;
    }

    void
        TimeoutClockUtilities::_handle_destruct()
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
        TimeoutClockUtilities::setup(
            const TimeoutClockConfigurations&
                new_configurations
        )
    {
        TimeoutClockConfigurations::cache =
            new_configurations;

        _handle_setup();

        return
            cache_boolean_1;
    }

    bool
        TimeoutClockUtilities::setup()
    {
        TimeoutClockConfigurations::cache =
            {};

        _handle_setup();

        return
            cache_boolean_1;
    }

    void
        TimeoutClockUtilities::_handle_setup()
    {
        try
        {
            TimeoutClockConfigurations::_handle_setup();

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
        TimeoutClockUtilities::reset()
    {
        _handle_reset();

        return
            cache_boolean_1;
    }

    void
        TimeoutClockUtilities::_handle_reset()
    {
        try
        {
            TimeoutClockConfigurations::_handle_reset();

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
