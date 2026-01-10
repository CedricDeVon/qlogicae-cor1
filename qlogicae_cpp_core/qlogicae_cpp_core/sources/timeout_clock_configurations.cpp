#include "pch.hpp"

#include "../includes/timeout_clock_configurations.hpp"

namespace QLogicaeCppCore
{	
    std::function<void()>
        TimeoutClockConfigurations::initial_callback =
            []() {};

    std::chrono::milliseconds
        TimeoutClockConfigurations::initial_delay_in_milliseconds
            { 1000 };

    bool
        TimeoutClockConfigurations::initial_is_executed_immediately =
            false;



    std::function<void()>
        TimeoutClockConfigurations::default_callback =
            TimeoutClockConfigurations::initial_callback;

    std::chrono::milliseconds
        TimeoutClockConfigurations::default_delay_in_milliseconds =
            TimeoutClockConfigurations::initial_delay_in_milliseconds;

    bool
        TimeoutClockConfigurations::default_is_executed_immediately =
            TimeoutClockConfigurations::initial_is_executed_immediately;



    std::function<void()>
        TimeoutClockConfigurations::cache_callback =
            TimeoutClockConfigurations::initial_callback;

    std::chrono::milliseconds
        TimeoutClockConfigurations::cache_delay_in_milliseconds =
            TimeoutClockConfigurations::initial_delay_in_milliseconds;

    bool
        TimeoutClockConfigurations::cache_is_executed_immediately =
            TimeoutClockConfigurations::initial_is_executed_immediately;



    
    bool
        TimeoutClockConfigurations::cache_boolean_1 =
            false;

    TimeoutClockConfigurations
        TimeoutClockConfigurations::cache;



    bool
        TimeoutClockConfigurations::construct()
    {
        _handle_construct();

        return
            cache_boolean_1;
    }

    bool
        TimeoutClockConfigurations::destruct()
    {
        _handle_destruct();

        return
            cache_boolean_1;
    }

    bool
        TimeoutClockConfigurations::setup(
            const TimeoutClockConfigurations&
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
        TimeoutClockConfigurations::setup()
    {
        cache =
            {};

        _handle_setup();

        return
            cache_boolean_1;
    }

    bool
        TimeoutClockConfigurations::reset()
    {
        _handle_reset();

        return
            cache_boolean_1;
    }

    void
        TimeoutClockConfigurations::_handle_construct()
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
        TimeoutClockConfigurations::_handle_destruct()
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
        TimeoutClockConfigurations::_handle_setup()
    {
        try
        {
            default_callback =
                cache_callback =
                cache.callback;

            default_delay_in_milliseconds =
                cache_delay_in_milliseconds =
                cache.delay_in_milliseconds;

            default_is_executed_immediately =
                cache_is_executed_immediately =
                cache.is_executed_immediately;

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
        TimeoutClockConfigurations::_handle_reset()
    {
        try
        {
            default_callback =
                cache_callback =
                initial_callback;

            default_delay_in_milliseconds =
                cache_delay_in_milliseconds =
                initial_delay_in_milliseconds;

            default_is_executed_immediately =
                cache_is_executed_immediately =
                initial_is_executed_immediately;

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
