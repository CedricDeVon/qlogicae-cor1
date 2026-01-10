#include "pch.hpp"

#include "../includes/interval_clock_utilities.hpp"

namespace QLogicaeCppCore
{
    bool
        IntervalClockUtilities::cache_boolean_1 =
            false;

    IntervalClockUtilities&
        IntervalClockUtilities::singleton =
            SingletonManager::get_singleton<IntervalClockUtilities>();


    
    IntervalClockUtilities::IntervalClockUtilities()
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

    IntervalClockUtilities::~IntervalClockUtilities()
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
        IntervalClockUtilities::construct()
    {
        _handle_construct();

        return
            cache_boolean_1;
    }

    void
        IntervalClockUtilities::_handle_construct()
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
        IntervalClockUtilities::destruct()
    {
        _handle_destruct();

        return
            cache_boolean_1;
    }

    void
        IntervalClockUtilities::_handle_destruct()
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
        IntervalClockUtilities::setup(
            const IntervalClockConfigurations&
                new_configurations
        )
    {
        IntervalClockConfigurations::cache =
            new_configurations;

        _handle_setup();

        return
            cache_boolean_1;
    }

    bool
        IntervalClockUtilities::setup()
    {
        IntervalClockConfigurations::cache =
            {};

        _handle_setup();

        return
            cache_boolean_1;
    }

    void
        IntervalClockUtilities::_handle_setup()
    {
        try
        {
            IntervalClockConfigurations::_handle_setup();

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
        IntervalClockUtilities::reset()
    {
        _handle_reset();

        return
            cache_boolean_1;
    }

    void
        IntervalClockUtilities::_handle_reset()
    {
        try
        {
            IntervalClockConfigurations::_handle_reset();

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
