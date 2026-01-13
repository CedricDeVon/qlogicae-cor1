#pragma once

#include "error_manager.hpp"

namespace QLogicaeCppCore
{
    struct TimeManagerConfigurations
    {
        bool
            is_enabled =
                default_is_enabled;

        static bool
            initial_is_enabled;

        static bool
            default_is_enabled;

        static bool
            cache_is_enabled;



        static bool
            cache_boolean_1;

        static TimeManagerConfigurations
            cache_configurations;


        
        static bool
            construct(
                const TimeManagerConfigurations&
                    configurations = {}
            );

        static bool
            destruct(
                const TimeManagerConfigurations&
                    configurations = {}
            );

        static bool
            setup(
                const TimeManagerConfigurations&
                    configurations = {}
            );

        static bool
            reset(
                const TimeManagerConfigurations&
                    configurations = {}
            );

        static bool
            setup_caches(
                const TimeManagerConfigurations&
                    configurations = {}
            );

        static bool
            setup_defaults(
                const TimeManagerConfigurations&
                    configurations = {}
            );

        static bool
            reset_caches(
                const TimeManagerConfigurations&
                    configurations = {}
            );

        static bool
            reset_defaults(
                const TimeManagerConfigurations&
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
