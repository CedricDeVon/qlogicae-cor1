#pragma once

#include "error_manager.hpp"

namespace QLogicaeCppCore
{   
    struct MutexManagerConfigurations
    {
        void*
            pointer =
                default_pointer;

        std::string
            name =
                default_name;

        bool
            is_enabled =
                default_is_enabled;



        static void*
            initial_pointer;

        static std::string
            initial_name;

        static bool
            initial_is_enabled;



        static std::string
            default_name;

        static void*
            default_pointer;

        static bool
            default_is_enabled;



        static std::string
            cache_name;

        static void*
            cache_pointer;

        static bool
            cache_is_enabled;



        static bool
            cache_boolean_1;

        static MutexManagerConfigurations
            cache_configurations;


        
        static bool
            construct(
                const MutexManagerConfigurations&
                    configurations = {}
            );

        static bool
            destruct(
                const MutexManagerConfigurations&
                    configurations = {}
            );

        static bool
            setup(
                const MutexManagerConfigurations&
                    configurations = {}
            );

        static bool
            reset(
                const MutexManagerConfigurations&
                    configurations = {}
            );

        static bool
            setup_caches(
                const MutexManagerConfigurations&
                    configurations = {}
            );

        static bool
            setup_defaults(
                const MutexManagerConfigurations&
                    configurations = {}
            );

        static bool
            reset_caches(
                const MutexManagerConfigurations&
                    configurations = {}
            );

        static bool
            reset_defaults(
                const MutexManagerConfigurations&
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
