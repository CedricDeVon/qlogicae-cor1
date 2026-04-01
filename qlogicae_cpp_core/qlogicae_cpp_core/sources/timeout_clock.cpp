#include "pch.hpp"

#include "../includes/timeout_clock.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
    TimeoutClock
		::TimeoutClock() :
			AbstractClass<TimeoutClockConfigurations>()
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

	TimeoutClock
		::~TimeoutClock()
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
        TimeoutClock
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
						feature_handling_mutex_1
					);
			}			

			is_executed_immediately_async.store(configurations.is_executed_immediately);
			is_flag_stopped_async.store(false);
			is_cancelled_async.store(false);

			start();

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
        TimeoutClock
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
						feature_handling_mutex_1
					);
			}			
			
			cancel();

			return
				cancel();
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
		TimeoutClock
			::start()
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
						feature_handling_mutex_2
					);
			}			
			
			if (thread_1.joinable())
			{
				thread_1.request_stop();
				thread_1.join();
			}

			auto local_callback = configurations.callback;
			auto local_delay = configurations.delay_in_milliseconds;
			bool execute_immediately = configurations.is_executed_immediately || local_delay.count() == 0;

			thread_1 = std::jthread([local_callback, local_delay, execute_immediately](std::stop_token stop_token)
				{
					if (!execute_immediately)
					{
						std::this_thread::sleep_for(local_delay);
					}

					if (stop_token.stop_requested())
					{
						return;
					}

					try
					{
						local_callback();
					}
					catch (...)
					{
					}
				});

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
		TimeoutClock
			::cancel()
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
						feature_handling_mutex_2
					);
			}			
			
			is_cancelled_async.store(true);
			is_flag_stopped_async.store(true);

			if (thread_1.joinable())
			{
				thread_1.request_stop();
				if (std::this_thread::get_id() != thread_1.get_id())
				{
					thread_1.join();
				}
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
		TimeoutClock
			::restart()
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
			
			cancel();

			is_flag_stopped_async
				.store(false);
			is_cancelled_async
				.store(false);
			is_executed_immediately_async
				.store(
					configurations.is_executed_immediately
				);
			
			return
				start();
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
		TimeoutClock
			::is_cancelled()
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
			
			return
				is_cancelled_async.load();
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
