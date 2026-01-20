#pragma once

#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "interval_clock_configurations.hpp"

namespace
	QLogicaeCppCore
{
    class
		IntervalClock :
			public AbstractClass<IntervalClockConfigurations>
    {
    public:
		std::thread
			thread_1;

		mutable std::mutex
			mutex_1;

		std::atomic<bool>
			is_paused_async { false };

		std::atomic<bool>
			is_running_async { false };

		std::atomic<bool>
			is_cancelled_async { false };

		std::atomic<size_t>
			execution_count_async { 0 };

		std::condition_variable
			condition_variable;

		static IntervalClock&
			singleton;

		IntervalClock();

		~IntervalClock();

		bool
			construct();

		bool
			destruct();

		bool
			start();

		bool
			stop();

		bool
			pause();

		bool
			resume();

		bool
			cancel();

		bool
			restart();

		bool
			is_paused();

		bool
			is_running();

		bool
			is_cancelled();

		size_t
			get_execution_count();

		bool
			run_interval();
		
	};
}
