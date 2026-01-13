#pragma once

#include "error_manager_configurations.hpp"
#include "singleton_manager_configurations.hpp"

namespace QLogicaeCppCore
{        
    class SingletonManager
    {
    public:          
        static bool
            cache_boolean_1;

		static boost::mutex
			cache_mutex_1;

        static std::string
            cache_error_log;

        static fast_io::native_io_observer
            cache_fast_io_error_console_output_type;

        static SingletonManager&
            singleton;



        SingletonManager();

        ~SingletonManager();

        SingletonManager(
            const SingletonManager&
                instance
        ) = delete;

        SingletonManager(
            SingletonManager&&
                instance
        ) noexcept = delete;

        SingletonManager&
            operator = (
                SingletonManager&&
                    instance
        ) = delete;

        SingletonManager&
            operator = (
                const SingletonManager&
                    instance
        ) = delete;
        
        bool
            construct(
                const SingletonManagerConfigurations&
                    configurations = {}
            );

        bool
            destruct(
                const SingletonManagerConfigurations&
                    configurations = {}
            );

        bool
            setup(
                const SingletonManagerConfigurations&
                    configurations = {}
            );

        bool
            reset(
                const SingletonManagerConfigurations&
                    configurations = {}
            );

        bool
            handle_error(
                const std::exception&
                    exception,
                const SingletonManagerConfigurations&
                    configurations = {}
            );
        void
            _handle_construct();

        void
            _handle_destruct();

        void
            _handle_setup();

        void
            _handle_reset();

        void
            _handle_error();

        void
            _handle_error_asynchronously();

        void
            _handle_error_synchronously();

        template <typename Type> static Type&
            get_singleton(
                const SingletonManagerConfigurations&
                    configurations = {}
            );

        static SingletonManager&
            get_this_singleton(
                const SingletonManagerConfigurations&
                    configurations = {}
            );
    };

    template <typename Type> Type&
        SingletonManager::get_singleton(
            const SingletonManagerConfigurations&
                configurations
        )
    {
		{
			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations
					.is_thread_safety_enabled)
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						cache_mutex_1
					);
			}

			SingletonManagerConfigurations
				::cache_configurations =
					configurations;
			SingletonManagerConfigurations
				::_handle_setup_caches();
		}
        
        static Type
            singleton;

		{
			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations
					.is_thread_safety_enabled)
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						cache_mutex_1
					);
			}

			SingletonManagerConfigurations
				::cache_configurations =
					{};
			SingletonManagerConfigurations
				::_handle_setup_caches();
		}        

        return
            singleton;
    }    
}
