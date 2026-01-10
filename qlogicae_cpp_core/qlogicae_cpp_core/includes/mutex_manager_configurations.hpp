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



        static void*
            initial_pointer;

        static std::string
            initial_name;



        static std::string
            default_name;

        static void*
            default_pointer;



        static std::string
            cache_name;

        static void*
            cache_pointer;



        static bool
            cache_boolean_1;

        static MutexManagerConfigurations
            cache;



        static bool
            construct();

        static bool
            destruct();

        static bool
            setup();

        static bool
            setup(
                const MutexManagerConfigurations&
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
