#pragma once

#include "error_manager.hpp"

namespace QLogicaeCppCore
{
    struct TimeDelayClockConfigurations
    {        
        static bool
            cache_boolean_1;

        static TimeDelayClockConfigurations
            cache_configurations;


        
        static bool
            construct(
                const TimeDelayClockConfigurations&
                    configurations = {}
            );

        static bool
            destruct(
                const TimeDelayClockConfigurations&
                    configurations = {}
            );

        static bool
            setup(
                const TimeDelayClockConfigurations&
                    configurations = {}
            );

        static bool
            reset(
                const TimeDelayClockConfigurations&
                    configurations = {}
            );

        static bool
            setup_caches(
                const TimeDelayClockConfigurations&
                    configurations = {}
            );

        static bool
            setup_defaults(
                const TimeDelayClockConfigurations&
                    configurations = {}
            );

        static bool
            reset_caches(
                const TimeDelayClockConfigurations&
                    configurations = {}
            );

        static bool
            reset_defaults(
                const TimeDelayClockConfigurations&
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
