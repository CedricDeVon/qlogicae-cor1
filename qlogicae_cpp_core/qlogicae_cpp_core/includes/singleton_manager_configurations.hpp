#pragma once

namespace QLogicaeCppCore
{   
    struct SingletonManagerConfigurations
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
			initial_is_thread_safety_enabled;



		static bool
			default_is_enabled;

		static bool
			default_is_thread_safety_enabled;



		static bool
			cache_is_enabled;

		static bool
			cache_is_thread_safety_enabled;



        static bool
            cache_boolean_1;

		static boost::mutex
			cache_mutex_1;

        static SingletonManagerConfigurations
            cache_configurations;


        
        static bool
            construct(
                const SingletonManagerConfigurations&
                    configurations = {}
            );

        static bool
            destruct(
                const SingletonManagerConfigurations&
                    configurations = {}
            );

        static bool
            setup(
                const SingletonManagerConfigurations&
                    configurations = {}
            );

        static bool
            reset(
                const SingletonManagerConfigurations&
                    configurations = {}
            );

        static bool
            setup_caches(
                const SingletonManagerConfigurations&
                    configurations = {}
            );

        static bool
            setup_defaults(
                const SingletonManagerConfigurations&
                    configurations = {}
            );

        static bool
            reset_caches(
                const SingletonManagerConfigurations&
                    configurations = {}
            );

        static bool
            reset_defaults(
                const SingletonManagerConfigurations&
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
