#include "pch.hpp"

#include "../includes/interval_clock_configurations.hpp"

namespace QLogicaeCppCore
{
    std::function<bool(size_t)>
        _initial_callback =
            [](size_t current_interval) { return true; };

    std::chrono::milliseconds
        _initial_delay_in_milliseconds
            { 1000 };

    size_t
        _initial_maximum_interval_count =
            1;

    bool
        _initial_is_executed_immediately =
            true;



    std::function<bool(size_t)>
        IntervalClockConfigurations::default_callback =
            IntervalClockConfigurations::initial_callback;

    std::chrono::milliseconds
        IntervalClockConfigurations::default_delay_in_milliseconds =
            IntervalClockConfigurations::initial_delay_in_milliseconds;

    size_t
        IntervalClockConfigurations::default_maximum_interval_count =
            IntervalClockConfigurations::initial_maximum_interval_count;

    bool
        IntervalClockConfigurations::default_is_executed_immediately =
            IntervalClockConfigurations::initial_is_executed_immediately;



    std::function<bool(size_t)>
        IntervalClockConfigurations::cache_callback =
            IntervalClockConfigurations::initial_callback;

    std::chrono::milliseconds
        IntervalClockConfigurations::cache_delay_in_milliseconds =
            IntervalClockConfigurations::initial_delay_in_milliseconds;

    size_t
        IntervalClockConfigurations::cache_maximum_interval_count =
            IntervalClockConfigurations::initial_maximum_interval_count;

    bool
        IntervalClockConfigurations::cache_is_executed_immediately =
            IntervalClockConfigurations::initial_is_executed_immediately;



    bool
        IntervalClockConfigurations::cache_boolean_1 =
            false;

    IntervalClockConfigurations
        IntervalClockConfigurations::cache;



    bool
        IntervalClockConfigurations::construct()
    {
        _handle_construct();

        return
            cache_boolean_1;
    }

    bool
        IntervalClockConfigurations::destruct()
    {
        _handle_destruct();

        return
            cache_boolean_1;
    }

    bool
        IntervalClockConfigurations::setup(
            const IntervalClockConfigurations&
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
        IntervalClockConfigurations::setup()
    {
        cache =
            {};

        _handle_setup();

        return
            cache_boolean_1;
    }

    bool
        IntervalClockConfigurations::reset()
    {
        _handle_reset();

        return
            cache_boolean_1;
    }

    void
        IntervalClockConfigurations::_handle_construct()
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
        IntervalClockConfigurations::_handle_destruct()
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
        IntervalClockConfigurations::_handle_setup()
    {
        try
        {
            default_callback =
                cache_callback =
                cache.callback;

            default_delay_in_milliseconds =
                cache_delay_in_milliseconds =
                cache.delay_in_milliseconds;

            default_maximum_interval_count =
                cache_maximum_interval_count =
                cache.maximum_interval_count;

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
        IntervalClockConfigurations::_handle_reset()
    {
        try
        {
            default_callback =
                cache_callback =
                initial_callback;

            default_delay_in_milliseconds =
                cache_delay_in_milliseconds =
                initial_delay_in_milliseconds;

            default_maximum_interval_count =
                cache_maximum_interval_count =
                initial_maximum_interval_count;

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
