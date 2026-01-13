#pragma once

#include "error_manager.hpp"

namespace QLogicaeCppCore
{
    struct IntervalClockConfigurations
    {
        std::function<bool(size_t)>
            callback =
                default_callback;
        
        std::chrono::milliseconds
            delay_in_milliseconds =
                default_delay_in_milliseconds;
        
        size_t
            maximum_interval_count =
                default_maximum_interval_count;
        
        bool
            is_executed_immediately =
                default_is_executed_immediately;



        static std::function<bool(size_t)>
            initial_callback;

        static std::chrono::milliseconds
            initial_delay_in_milliseconds;

        static size_t
            initial_maximum_interval_count;

        static bool
            initial_is_executed_immediately;



        static std::function<bool(size_t)>
            default_callback;

        static std::chrono::milliseconds
            default_delay_in_milliseconds;

        static size_t
            default_maximum_interval_count;

        static bool
            default_is_executed_immediately;



        static std::function<bool(size_t)>
            cache_callback;

        static std::chrono::milliseconds
            cache_delay_in_milliseconds;

        static size_t
            cache_maximum_interval_count;

        static bool
            cache_is_executed_immediately;



        static bool
            cache_boolean_1;

        static IntervalClockConfigurations
            cache_configurations;


        
        static bool
            construct(
                const IntervalClockConfigurations&
                    configurations = {}
            );

        static bool
            destruct(
                const IntervalClockConfigurations&
                    configurations = {}
            );

        static bool
            setup(
                const IntervalClockConfigurations&
                    configurations = {}
            );

        static bool
            reset(
                const IntervalClockConfigurations&
                    configurations = {}
            );

        static bool
            setup_caches(
                const IntervalClockConfigurations&
                    configurations = {}
            );

        static bool
            setup_defaults(
                const IntervalClockConfigurations&
                    configurations = {}
            );

        static bool
            reset_caches(
                const IntervalClockConfigurations&
                    configurations = {}
            );

        static bool
            reset_defaults(
                const IntervalClockConfigurations&
                    configurations = {}
            );

        static void
            _handle_construct();

        static void
            _handle_destruct();

        static void
            _handle_setup();

        static void
            _handle_reset();

        static void
            _handle_setup_caches();

        static void
            _handle_setup_defaults();

        static void
            _handle_reset_caches();

        static void
            _handle_reset_defaults();
    };
}
