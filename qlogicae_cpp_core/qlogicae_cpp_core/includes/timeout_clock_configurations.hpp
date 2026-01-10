#pragma once

#include "error_manager.hpp"

namespace QLogicaeCppCore
{    
    struct TimeoutClockConfigurations
    {
        std::function<void()>
            callback =
                default_callback;

        std::chrono::milliseconds
            delay_in_milliseconds =
                default_delay_in_milliseconds;

        bool
            is_executed_immediately =
                default_is_executed_immediately;



        static std::function<void()>
            initial_callback;

        static std::chrono::milliseconds
            initial_delay_in_milliseconds;

        static bool
            initial_is_executed_immediately;



        static std::function<void()>
            default_callback;

        static std::chrono::milliseconds
            default_delay_in_milliseconds;

        static bool
            default_is_executed_immediately;



        static std::function<void()>
            cache_callback;

        static std::chrono::milliseconds
            cache_delay_in_milliseconds;

        static bool
            cache_is_executed_immediately;



        static bool
            cache_boolean_1;

        static TimeoutClockConfigurations
            cache;



        static bool
            construct();

        static bool
            destruct();

        static bool
            setup();

        static bool
            setup(
                const TimeoutClockConfigurations&
                    new_configurations
            );

        static bool
            reset();

        static void
            _handle_construct();

        static void
            _handle_destruct();

        static void
            _handle_setup();

        static void
            _handle_reset();
    };
}
