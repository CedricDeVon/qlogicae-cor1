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

    AsynchronousManager&
        AsynchronousManager::singleton =
            SingletonManager::get_singleton<AsynchronousManager>();

	std::shared_ptr<boost::asio::thread_pool>
		AsynchronousManager
			::main_thread_pool =
				nullptr;

	std::shared_ptr<boost::asio::thread_pool>
		AsynchronousManager
			::temporary_thread_pool =
				nullptr;



    AsynchronousManager
		::AsynchronousManager()
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
			ErrorManager::singleton
				.handle_error_outputs(
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
			ErrorManager::singleton
				.handle_error_outputs(
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
			if (main_thread_pool == nullptr)
			{
				main_thread_pool =
					std::make_shared<boost::asio::thread_pool>(
						std::thread::hardware_concurrency()
					);
			}

			temporary_thread_pool =
				nullptr;

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
				ErrorManager::singleton
					.handle_error_outputs(
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
				ErrorManager::singleton
					.handle_error_outputs(
						exception
				);
        }
    }

    bool
        AsynchronousManager
			::setup(
				const AsynchronousManagerConfigurations&
					new_configurations
			)
    {
        try
        {
			configurations =
				new_configurations;

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
				ErrorManager::singleton
					.handle_error_outputs(
						exception
				);
        }
    }

    bool
        AsynchronousManager
			::reset()
    {
        try
        {
			configurations =
				{};

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
				ErrorManager::singleton
					.handle_error_outputs(
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
			if (!configurations.is_enabled)
			{
				return
					false;
			}

            boost::unique_lock<boost::mutex>
                unique_lock(
					mutex_1
				);

            if (main_thread_pool == nullptr)
            {
                main_thread_pool =
                    std::make_shared<boost::asio::thread_pool>(
                        std::thread::hardware_concurrency()
                    );
            }

            boost::asio::post(
                *main_thread_pool,
                [callback]()
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
						ErrorManager::singleton
							.handle_error_outputs(
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
				ErrorManager::singleton
					.handle_error_outputs(
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
			boost::unique_lock<boost::mutex>
				unique_lock(
					mutex_1
				);
		
			size_t
				count =
					std::thread::hardware_concurrency() + 1;
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
				ErrorManager::singleton
					.handle_error_outputs(
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
			boost::unique_lock<boost::mutex>
				unique_lock(
					mutex_1
				);

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
				ErrorManager::singleton
					.handle_error_outputs(
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
			boost::unique_lock<boost::mutex>
				unique_lock(
					mutex_1
				);
		
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
				ErrorManager::singleton
					.handle_error_outputs(
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
				!configurations
					.is_enabled
			)
            {
                return
					false;
            }			

			boost::unique_lock<boost::mutex>
				unique_lock(
					mutex_1
				);

			boost::asio::co_spawn(
				io_strand,
				[implementation_method]()
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
						ErrorManager::singleton
							.handle_error_outputs(
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
				ErrorManager::singleton
					.handle_error_outputs(
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
				!configurations
					.is_enabled
			)
            {
                return
					false;
            }			

			boost::unique_lock<boost::mutex>
				unique_lock(
					mutex_1
				);

            if (main_thread_pool == nullptr)
            {
                main_thread_pool =
                    std::make_shared<boost::asio::thread_pool>(
                        std::thread::hardware_concurrency()
                    );
            }

			boost::asio::post(
                *main_thread_pool,
                [implementation_method]()
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
						ErrorManager::singleton
							.handle_error_outputs(
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
				ErrorManager::singleton
					.handle_error_outputs(
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
				!configurations
					.is_enabled
			)
            {
                return
					false;
            }			

			boost::unique_lock<boost::mutex>
				unique_lock(
					mutex_1
				);

            if (main_thread_pool == nullptr)
            {
                main_thread_pool =
                    std::make_shared<boost::asio::thread_pool>(
                        std::thread::hardware_concurrency()
                    );
            }

			boost::asio::dispatch(
                *main_thread_pool,
                [implementation_method]()
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
						ErrorManager::singleton
							.handle_error_outputs(
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
				ErrorManager::singleton
					.handle_error_outputs(
						exception
				);
        }
	}
}
