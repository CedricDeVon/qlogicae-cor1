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
		
		static boost::asio::io_context io_context;

		static boost::asio::strand<decltype(io_context.get_executor())> async_strand;

		static boost::asio::executor_work_guard<boost::asio::io_context::executor_type> async_work_guard;

		static std::vector<std::thread> thread_workers;

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
