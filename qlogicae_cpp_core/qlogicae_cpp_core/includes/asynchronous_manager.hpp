#pragma once

#include "error_manager.hpp"
#include "singleton_manager.hpp"
#include "asynchronous_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{    
    class
		AsynchronousManager
    {
    public:                        
		boost::mutex
			cache_mutex_1;

		AsynchronousManagerConfigurations
			configurations;
		
		static std::shared_ptr<boost::asio::thread_pool>
			main_thread_pool;

		static std::shared_ptr<boost::asio::thread_pool>
			temporary_thread_pool;

        static AsynchronousManager&
            singleton;

        AsynchronousManager();

        ~AsynchronousManager();

        bool
            construct();

        bool
            destruct();

        bool
            setup(
                const AsynchronousManagerConfigurations&
					new_configurations =
						{}
            );

        bool
            reset();

        bool
            begin_one_thread(
                const std::function<void()>&
                    callback
            );

		bool
			complete_all_threads();
    };   
}
