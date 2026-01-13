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
        IntervalClockConfigurations::cache_configurations;


    
    bool
        IntervalClockConfigurations::construct(
            const IntervalClockConfigurations&
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
        IntervalClockConfigurations::destruct(
            const IntervalClockConfigurations&
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
        IntervalClockConfigurations::setup(
            const IntervalClockConfigurations&
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
        IntervalClockConfigurations::reset(
            const IntervalClockConfigurations&
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
        IntervalClockConfigurations::setup_caches(
            const IntervalClockConfigurations&
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
        IntervalClockConfigurations::setup_defaults(
            const IntervalClockConfigurations&
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
        IntervalClockConfigurations::reset_caches(
            const IntervalClockConfigurations&
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
        IntervalClockConfigurations::reset_defaults(
            const IntervalClockConfigurations&
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
        IntervalClockConfigurations::_handle_reset()
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
        IntervalClockConfigurations::_handle_setup_caches()
    {
        try
        {            
            cache_callback =
                cache_configurations.callback;

            cache_delay_in_milliseconds =
                cache_configurations.delay_in_milliseconds;

            cache_maximum_interval_count =
                cache_configurations.maximum_interval_count;

            cache_is_executed_immediately =
                cache_configurations.is_executed_immediately;

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
        IntervalClockConfigurations::_handle_setup_defaults()
    {
        try
        {         
            default_callback =
                cache_configurations.callback;

            default_delay_in_milliseconds =
                cache_configurations.delay_in_milliseconds;

            default_maximum_interval_count =
                cache_configurations.maximum_interval_count;

            default_is_executed_immediately =
                cache_configurations.is_executed_immediately;

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
        IntervalClockConfigurations::_handle_reset_caches()
    {
        try
        {            
            cache_callback =
                initial_callback;

            cache_delay_in_milliseconds =
                initial_delay_in_milliseconds;

            cache_maximum_interval_count =
                initial_maximum_interval_count;

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

    void
        IntervalClockConfigurations::_handle_reset_defaults()
    {
        try
        {            
            default_callback =
                initial_callback;

            default_delay_in_milliseconds =
                initial_delay_in_milliseconds;

            default_maximum_interval_count =
                initial_maximum_interval_count;

            default_is_executed_immediately =
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
