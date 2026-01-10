#pragma once

#include "error_manager.hpp"

namespace QLogicaeCppCore
{    
    struct AsynchronousManagerConfigurations
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

        static AsynchronousManagerConfigurations
            cache;



        static bool
            construct();

        static bool
            destruct();

        static bool
            setup();

        static bool
            setup(
                const AsynchronousManagerConfigurations&
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
