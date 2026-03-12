#include "pch.hpp"

#include "../includes/interval_clock.hpp"

namespace
	QLogicae::Cor::V1
{
    IntervalClock
		::IntervalClock() :
			AbstractClass<IntervalClockConfigurations>()
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

    IntervalClock
		::~IntervalClock()
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
        IntervalClock
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

			is_cancelled_async.store(false);
			is_paused_async.store(false);
			is_running_async.store(false);
			execution_count_async.store(0);

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
        IntervalClock
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

			if (thread_1.joinable())
			{
				thread_1.join();
			}

			is_cancelled_async.store(false);
			is_paused_async.store(false);
			is_running_async.store(false);
			execution_count_async.store(0);

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
		IntervalClock
			::start()
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
						configurations.maximum_interval_count == 0 ||
						configurations.delay_in_milliseconds.count() == 0
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
						feature_handling_mutex_2
					);
			}			

			if (is_running_async.load())
			{
				return true;
			}


			if (thread_1.joinable())
			{
				thread_1.join();
			}

			is_cancelled_async.store(false);
			is_paused_async.store(false);
			is_running_async.store(true);
			execution_count_async.store(0);

			thread_1 = std::thread(
				&IntervalClock::run_interval,
				this
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
		IntervalClock
			::stop()
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

			is_cancelled_async.store(true);
			is_running_async.store(false);
			is_paused_async.store(false);
			condition_variable.notify_all();

			if (thread_1.joinable() && !is_running_async.load())
			{
				thread_1.join();
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
		IntervalClock
			::pause()
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

			is_paused_async.store(true);

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
		IntervalClock
			::resume()
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

			if (is_paused_async.load())
			{
				is_paused_async.store(false);
				condition_variable.notify_all();
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
		IntervalClock
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
			is_paused_async.store(false);
			is_running_async.store(false);
			condition_variable.notify_all();

			if (thread_1.joinable())
			{
				thread_1.join();
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
		IntervalClock
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

			execution_count_async.store(0);
			is_cancelled_async.store(false);
			is_paused_async.store(false);
			is_running_async.store(true);

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
		IntervalClock
			::is_paused()
	{
		return
			is_paused_async
				.load();
	}

	bool
		IntervalClock
			::is_running()
	{
		return
			is_running_async
				.load();
	}

	bool
		IntervalClock
			::is_cancelled()
	{
		return
			is_cancelled_async
				.load();
	}

	size_t
		IntervalClock
			::get_execution_count()
	{
		return
			execution_count_async
				.load();
	}

	bool
		IntervalClock
			::run_interval()
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
						feature_handling_mutex_3
					);
			}			

			if (!is_running_async.load())
			{
				is_running_async.store(true);
				is_cancelled_async.store(false);
			}

			if (configurations.is_executed_immediately &&
				!is_cancelled_async.load())
			{
				size_t current = ++execution_count_async;

				bool should_continue = false;
				try
				{
					should_continue = configurations.callback(current);
				}
				catch (...)
				{
					should_continue = false;
				}

				if (!should_continue)
				{
					is_running_async.store(false);
					condition_variable.notify_all();

					return
						true;
				}

				if (configurations.maximum_interval_count &&
					execution_count_async.load() >= configurations.maximum_interval_count)
				{
					is_running_async.store(false);
					condition_variable.notify_all();

					return
						true;
				}
			}

			while (!is_cancelled_async.load() && is_running_async.load())
			{
				std::unique_lock<std::mutex> lock(
					mutex_1
				);

				if (is_paused_async.load())
				{
					condition_variable.wait(lock, [this]() {
						return !is_paused_async.load() || is_cancelled_async.load();
						});
				}

				if (is_cancelled_async.load() || !is_running_async.load())
				{
					break;
				}

				auto start = std::chrono::steady_clock::now();
				lock.unlock();

				size_t current = ++execution_count_async;

				bool should_continue = false;
				try
				{
					should_continue = configurations.callback(current);
				}
				catch (...)
				{
					should_continue = false;
				}

				if (!should_continue)
				{
					is_running_async.store(false);
					condition_variable.notify_all();

					return
						true;
				}

				if (configurations.maximum_interval_count &&
					execution_count_async.load() >= configurations.maximum_interval_count)
				{
					is_running_async.store(false);
					condition_variable.notify_all();

					return
						true;
				}

				auto end = std::chrono::steady_clock::now();
				auto elapsed =
					std::chrono::duration_cast<std::chrono::milliseconds>(
						end - start
					);
				auto delay =
					configurations.delay_in_milliseconds > elapsed ?
					configurations.delay_in_milliseconds - elapsed :
					std::chrono::milliseconds(0);

				for (std::chrono::milliseconds waited(0);
					waited < delay && !is_cancelled_async.load() && is_running_async.load();
					)
				{
					auto to_wait = std::min<std::chrono::milliseconds>(
						std::chrono::milliseconds(50),
						delay - waited
					);

					std::this_thread::sleep_for(to_wait);
					waited += to_wait;
				}
			}

			is_running_async.store(false);
			condition_variable.notify_all();

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

