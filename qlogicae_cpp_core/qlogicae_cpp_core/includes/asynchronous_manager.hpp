#pragma once

#include "abstract_class.hpp"
#include "asynchronous_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
	class
		AsynchronousManager :
			public AbstractClass<AsynchronousManagerConfigurations>
    {
    public:                        		
		static boost::asio::io_context
			io_context;

		static boost::asio::strand<decltype(io_context.get_executor())>
			io_strand;

		static boost::asio::executor_work_guard<boost::asio::io_context::executor_type>
			work_guard;

		static std::vector<std::thread>
			thread_workers;

		static std::shared_ptr<boost::asio::thread_pool>
			main_thread_pool;

		static std::shared_ptr<boost::asio::thread_pool>
			temporary_thread_pool;

		boost::mutex
			feature_handling_mutex_2;

		AsynchronousManager();

		~AsynchronousManager();

		bool
			construct();

		bool
			destruct();

		bool
			begin_io_workers();

		bool
			complete_io_workers();

		bool
			complete_all_threads();

        bool
            begin_one_thread(
                const std::function<void()>&
                    callback
			);

		template <typename ReturnType> bool
			post_thread_async(
				const std::function<ReturnType()>&
					implementation_method,
				const std::function<void(const ReturnType& result)>&
					callback_method
			);
		
		template <typename ReturnType> bool
			post_thread_async(
				const std::function<ReturnType()>&
					implementation_method,
				const std::function<void()>&
					callback_method
			);

		template <typename ReturnType> std::future<ReturnType>
			post_thread_await(
				const std::function<ReturnType()>&
					implementation_method
			);

		bool
			post_thread_async(
				const std::function<void()>&
					implementation_method
			);

		template <typename ReturnType> bool
			dispatch_thread_async(
				const std::function<ReturnType()>&
					implementation_method,
				const std::function<void(const ReturnType& result)>&
					callback_method
			);
		
		template <typename ReturnType> bool
			dispatch_thread_async(
				const std::function<ReturnType()>&
					implementation_method,
				const std::function<void()>&
					callback_method
			);

		template <typename ReturnType> std::future<ReturnType>
			dispatch_thread_await(
				const std::function<ReturnType()>&
					implementation_method
			);

		bool
			dispatch_thread_async(
				const std::function<void()>&
					implementation_method
			);

		template <typename ReturnType> bool
			co_spawn_strand_async(
				const std::function<ReturnType()>&
					implementation_method,
				const std::function<void(const ReturnType& result)>&
					callback_method
			);
		
		template <typename ReturnType> bool
			co_spawn_strand_async(
				const std::function<ReturnType()>&
					implementation_method,
				const std::function<void()>&
					callback_method
			);

		template <typename ReturnType> std::future<ReturnType>
			co_spawn_strand_await(
				const std::function<ReturnType()>&
					implementation_method
			);

		bool
			co_spawn_strand_async(
				const std::function<void()>&
					implementation_method
			);	
    };   

	template <typename ReturnType> std::future<ReturnType>
		AsynchronousManager
			::co_spawn_strand_await(
				const std::function<ReturnType()>&
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
					{};
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

			if constexpr (std::is_void_v<ReturnType>)
			{
				std::future<void> future =
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
						boost::asio::use_future
					);

				return
					future;
			}
			else
			{
				std::future<ReturnType> future =
					boost::asio::co_spawn(
						io_strand,
						[this, implementation_method]()
							-> boost::asio::awaitable<ReturnType>
						{
							try
							{
								co_return
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

								co_return
									ReturnType{};
							}								
						},
						boost::asio::use_future
					);

				return
					future;
			}
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

            return
				std::future<ReturnType>();
        }
	}

	template <typename ReturnType> bool
		AsynchronousManager
			::co_spawn_strand_async(
				const std::function<ReturnType()>&
					implementation_method,
				const std::function<void(const ReturnType& result)>&
					callback_method
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
						implementation_method == nullptr ||
						callback_method == nullptr
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
				[this, implementation_method, callback_method]()
					-> boost::asio::awaitable<void>
				{
					try
					{
						callback_method(
							implementation_method()
						);

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

	template <typename ReturnType> bool
		AsynchronousManager
			::co_spawn_strand_async(
				const std::function<ReturnType()>&
					implementation_method,
				const std::function<void()>&
					callback_method
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
						implementation_method == nullptr ||
						callback_method == nullptr
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

			if constexpr
			(
				std::is_void_v<ReturnType>
			)
			{
				boost::asio::co_spawn(
					io_strand,
					[this, implementation_method, callback_method]()
						-> boost::asio::awaitable<void>
					{
						try
						{
							implementation_method();
							callback_method();

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
			}
			else
			{
				boost::asio::co_spawn(
					io_strand,
					[this, implementation_method, callback_method]()
						-> boost::asio::awaitable<void>
					{
						try
						{
							(void) implementation_method();
							callback_method();

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


	template <typename ReturnType> std::future<ReturnType>
		AsynchronousManager
			::post_thread_await(
				const std::function<ReturnType()>&
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
					std::future<ReturnType>();
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

			std::promise<ReturnType> promise;
			std::future<ReturnType> future =
				promise.get_future();

			if constexpr (std::is_void_v<ReturnType>)
			{
				boost::asio::post(
					*main_thread_pool,
					[this, implementation_method, promise = std::move(promise)]() mutable
					{
						try
						{
							implementation_method();

							promise.set_value();
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
					future;
			}
			else
			{
				boost::asio::post(
					*main_thread_pool,
					[this, implementation_method, promise = std::move(promise)]() mutable
					{
						try
						{
							promise.set_value(
								implementation_method()
							);
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
					future;
			}
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

            return
				std::future<ReturnType>();
        }
	}

	template <typename ReturnType> bool
		AsynchronousManager
			::post_thread_async(
				const std::function<ReturnType()>&
					implementation_method,
				const std::function<void(const ReturnType& result)>&
					callback_method
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
						implementation_method == nullptr ||
						callback_method == nullptr
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
				[this, implementation_method, callback_method]()
				{
					try
					{
						callback_method(
							implementation_method()
						);
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

	template <typename ReturnType> bool
		AsynchronousManager
			::post_thread_async(
				const std::function<ReturnType()>&
					implementation_method,
				const std::function<void()>&
					callback_method
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
						implementation_method == nullptr ||
						callback_method == nullptr
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

			if constexpr
			(
				std::is_void_v<ReturnType>
			)
			{				
				boost::asio::post(
					*main_thread_pool,
					[this, implementation_method, callback_method]()
					{
						try
						{
							implementation_method();
							callback_method();
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
			}
			else
			{
				boost::asio::post(
					*main_thread_pool,
					[this, implementation_method, callback_method]()
					{
						try
						{
							(void)implementation_method();
							callback_method();
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

	template <typename ReturnType> std::future<ReturnType>
		AsynchronousManager
			::dispatch_thread_await(
				const std::function<ReturnType()>&
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
					std::future<ReturnType>();
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

			std::promise<ReturnType> promise;
			std::future<ReturnType> future =
				promise.get_future();

			if constexpr (std::is_void_v<ReturnType>)
			{
				boost::asio::dispatch(
					*main_thread_pool,
					[this, implementation_method, promise = std::move(promise)]() mutable
					{
						try
						{
							implementation_method();

							promise.set_value();
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
					future;
			}
			else
			{
				boost::asio::dispatch(
					*main_thread_pool,
					[this, implementation_method, promise = std::move(promise)]() mutable
					{
						try
						{
							promise.set_value(
								implementation_method()
							);
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
					future;
			}
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

            return
				std::future<ReturnType>();
        }
	}

	template <typename ReturnType> bool
		AsynchronousManager
			::dispatch_thread_async(
				const std::function<ReturnType()>&
					implementation_method,
				const std::function<void(const ReturnType& result)>&
					callback_method
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
						implementation_method == nullptr ||
						callback_method == nullptr
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
				[this, implementation_method, callback_method]()
				{
					try
					{
						callback_method(
							implementation_method()
						);
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

	template <typename ReturnType> bool
		AsynchronousManager
			::dispatch_thread_async(
				const std::function<ReturnType()>&
					implementation_method,
				const std::function<void()>&
					callback_method
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
						implementation_method == nullptr ||
						callback_method == nullptr
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

			if constexpr
			(
				std::is_void_v<ReturnType>
			)
			{				
				boost::asio::dispatch(
					*main_thread_pool,
					[this, implementation_method, callback_method]()
					{
						try
						{
							implementation_method();
							callback_method();
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
			}
			else
			{
				boost::asio::dispatch(
					*main_thread_pool,
					[this, implementation_method, callback_method]()
					{
						try
						{
							(void)implementation_method();
							callback_method();
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
}
