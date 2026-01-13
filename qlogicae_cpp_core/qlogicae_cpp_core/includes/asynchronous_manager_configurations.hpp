#pragma once

#include "error_manager.hpp"

namespace QLogicaeCppCore
{    
    struct AsynchronousManagerConfigurations
    {
        bool
            is_enabled =
                default_is_enabled;        
		
        bool
            is_thread_safety_enabled =
                default_is_thread_safety_enabled;



        static bool
            initial_is_enabled;
        
		static bool
            default_is_enabled;

        static bool
            cache_is_enabled;

		static bool
            initial_is_thread_safety_enabled;

		static bool
			default_is_thread_safety_enabled;

		static bool
			cache_is_thread_safety_enabled;




        static bool
            cache_boolean_1;

		static boost::mutex
			cache_mutex_1;

        static AsynchronousManagerConfigurations
            cache_configurations;


        
        static bool
            construct(
                const AsynchronousManagerConfigurations&
                    configurations = {}
            );

        static bool
            destruct(
                const AsynchronousManagerConfigurations&
                    configurations = {}
            );

        static bool
            setup(
                const AsynchronousManagerConfigurations&
                    configurations = {}
            );

        static bool
            reset(
                const AsynchronousManagerConfigurations&
                    configurations = {}
            );

        static bool
            setup_caches(
                const AsynchronousManagerConfigurations&
                    configurations = {}
            );

        static bool
            setup_defaults(
                const AsynchronousManagerConfigurations&
                    configurations = {}
            );

        static bool
            reset_caches(
                const AsynchronousManagerConfigurations&
                    configurations = {}
            );

        static bool
            reset_defaults(
                const AsynchronousManagerConfigurations&
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
