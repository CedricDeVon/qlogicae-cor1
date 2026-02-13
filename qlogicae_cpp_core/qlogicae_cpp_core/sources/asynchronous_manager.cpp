#include "pch.hpp"

#include "../includes/asynchronous_manager.hpp"

namespace
	QLogicaeCppCore
{        
	boost::asio::io_context
		AsynchronousManager::io_context;

	boost::asio::strand<decltype(AsynchronousManager::io_context.get_executor())>
		AsynchronousManager::io_strand(
			AsynchronousManager::io_context.get_executor());

	boost::asio::executor_work_guard<boost::asio::io_context::executor_type>
		AsynchronousManager::work_guard =
			boost::asio::make_work_guard(
				AsynchronousManager::io_context
			);

	std::vector<std::thread>
		AsynchronousManager::thread_workers;

	std::shared_ptr<boost::asio::thread_pool>
		AsynchronousManager
			::main_thread_pool =
				nullptr;

	std::shared_ptr<boost::asio::thread_pool>
		AsynchronousManager
			::temporary_thread_pool =
				nullptr;

    AsynchronousManager&
        AsynchronousManager
			::singleton =
				SingletonManager
					::get_singleton<AsynchronousManager>();



    AsynchronousManager
		::AsynchronousManager() :
			AbstractClass<AsynchronousManagerConfigurations>()
    {
        try
        {
            construct();
        }
        catch
        (
            const std::exception&
                exception
        )
        {
			handle_error_outputs(
				exception
			);
        }
    }

    AsynchronousManager
		::~AsynchronousManager()
    {
        try
        {
            destruct();
        }
        catch
        (
            const std::exception&
                exception
        )
        {
			handle_error_outputs(
				exception
			);
        }
    }

    bool
        AsynchronousManager
			::construct()
    {
        try
        {			
			if
			(
				configurations
					.is_runtime_execution_disabled_for_utility_handling()
			)
			{
				return
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_utility_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						utility_handling_mutex_1
					);
			}			

			begin_io_workers();

			return
				true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
			return
				handle_error_outputs(
					exception
				);
        }
    }

    bool
        AsynchronousManager
			::destruct()
    {
        try
        {		
			if
			(
				configurations
					.is_runtime_execution_disabled_for_utility_handling()
			)
			{
				return
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_utility_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						utility_handling_mutex_1
					);
			}			

			return
				complete_io_workers() ||
				complete_all_threads();
        }
        catch
        (
            const std::exception&
                exception
        )
        {
			return
				handle_error_outputs(
					exception
				);
        }
    }

    bool
		AsynchronousManager
			::begin_one_thread(
				const std::function<void()>&
					callback
			)
    {
        try
        {
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling() ||				
				(
					configurations
						.is_edge_case_enabled_for_feature_handling() &&
					(
						callback == nullptr
					)
				)
			)
			{
				return
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_feature_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}

            if (main_thread_pool == nullptr)
            {
                main_thread_pool =
                    std::make_shared<boost::asio::thread_pool>(
                        std::thread::hardware_concurrency()
                    );
            }

            boost::asio::post(
                *main_thread_pool,
                [this, callback]()
                {
                    try
                    {
                        callback();
                    }
                    catch
                    (
                        const std::exception&
                            exception
                    )
                    {
						handle_error_outputs(
							exception
						);
                    }
                }
            );

            return
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            return
				handle_error_outputs(
					exception
				);
        }        
    }
	
    bool
		AsynchronousManager
			::begin_io_workers()
    {
        try
        {
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling()
			)
			{
				return
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_feature_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}
		
			size_t
				count =
					std::thread::hardware_concurrency() * 2;
			while (--count)
			{
				thread_workers.emplace_back(
					[]
					{
						io_context.run();
					}
				);
			}

			return
				true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            return
				handle_error_outputs(
					exception
				);
        }
    }

    bool
		AsynchronousManager
			::complete_all_threads()
    {
        try
        {
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling()
			)
			{
				return
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_utility_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}

			temporary_thread_pool =
				main_thread_pool;

			main_thread_pool.reset();

			if (temporary_thread_pool)
			{
				temporary_thread_pool->join();
            }

			return
				true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            return
				handle_error_outputs(
					exception
				);
        }
    }

    bool
		AsynchronousManager
			::complete_io_workers()
    {
        try
        {
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling()
			)
			{
				return
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_utility_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}
		
			work_guard.reset();
			io_context.stop();
			for
			(
				auto&
					thread_worker :
					thread_workers
			)
			{
				if (thread_worker.joinable())
				{
					thread_worker.join();
				}
			}					
			thread_workers.clear();

			return
				true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            return
				handle_error_outputs(
					exception
				);
        }
    }

	bool
		AsynchronousManager
			::co_spawn_strand_async(
				const std::function<void()>&
					implementation_method
		)
	{
		try
        {
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling() ||				
				(
					configurations
						.is_edge_case_enabled_for_feature_handling() &&
					(
						implementation_method == nullptr
					)
				)
			)
			{
				return
					false;
			}
        
			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_feature_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}

			boost::asio::co_spawn(
				io_strand,
				[this, implementation_method]()
					-> boost::asio::awaitable<void>
				{
					try
					{
						implementation_method();

						co_return;
					}
					catch
					(
						const std::exception&
							exception
					)
					{
						handle_error_outputs(
							exception
						);

						co_return;
					}						
				},
				boost::asio::detached
			);

			return
				true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            return
				handle_error_outputs(
					exception
				);
        }
	}

	bool
		AsynchronousManager
			::post_thread_async(
				const std::function<void()>&
					implementation_method
		)
	{
		try
        {   
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling() ||				
				(
					configurations
						.is_edge_case_enabled_for_feature_handling() &&
					(
						implementation_method == nullptr
					)
				)
			)
			{
				return
					false;
			}
        
			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_feature_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}

            if (main_thread_pool == nullptr)
            {
                main_thread_pool =
                    std::make_shared<boost::asio::thread_pool>(
                        std::thread::hardware_concurrency()
                    );
            }

			boost::asio::post(
                *main_thread_pool,
                [this, implementation_method]()
				{
					try
					{
						implementation_method();
                    }
                    catch
                    (
                        const std::exception&
                            exception
                    )
                    {
						handle_error_outputs(
							exception
						);
                    }
                }
            );

			return
				true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            return
				handle_error_outputs(
					exception
				);
        }
	}

	
	bool
		AsynchronousManager
			::dispatch_thread_async(
				const std::function<void()>&
					implementation_method
		)
	{
		try
        {       
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling() ||				
				(
					configurations
						.is_edge_case_enabled_for_feature_handling() &&
					(
						implementation_method == nullptr
					)
				)
			)
			{
				return
					false;
			}
     
			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_feature_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}

            if (main_thread_pool == nullptr)
            {
                main_thread_pool =
                    std::make_shared<boost::asio::thread_pool>(
                        std::thread::hardware_concurrency()
                    );
            }

			boost::asio::dispatch(
                *main_thread_pool,
                [this, implementation_method]()
				{
					try
					{
						implementation_method();
                    }
                    catch
                    (
                        const std::exception&
                            exception
                    )
                    {
						handle_error_outputs(
							exception
						);
                    }
                }
            );

			return
				true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            return
				handle_error_outputs(
					exception
				);
        }
	}
}
