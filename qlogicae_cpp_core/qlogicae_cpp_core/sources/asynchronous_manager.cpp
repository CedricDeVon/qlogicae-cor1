#include "pch.hpp"

#include "../includes/asynchronous_manager.hpp"

namespace
	QLogicaeCppCore
{        
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
			main_thread_pool =
                std::make_shared<boost::asio::thread_pool>(
                    std::thread::hardware_concurrency()
                );

			temporary_thread_pool =
				nullptr;

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
                unique_lock(cache_mutex_1);

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
			::complete_all_threads()
    {
        try
        {
            if (!configurations.is_enabled)
            {
                return
					false;
            }

            {
                boost::unique_lock<boost::mutex>
                    unique_lock(
						cache_mutex_1
                    );

				temporary_thread_pool =
					main_thread_pool;

				main_thread_pool.reset();
			}

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
}
