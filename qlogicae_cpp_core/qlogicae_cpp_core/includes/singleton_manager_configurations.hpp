#pragma once

namespace QLogicaeCppCore
{   
    struct SingletonManagerConfigurations
    {
        static bool
            cache_boolean_1;

        static SingletonManagerConfigurations
            cache;



        static bool
            construct();

        static bool
            destruct();

        static bool
            setup();

        static bool
            setup(
                const SingletonManagerConfigurations&
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
