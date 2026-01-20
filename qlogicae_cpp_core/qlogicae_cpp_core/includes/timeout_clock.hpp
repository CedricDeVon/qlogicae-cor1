#pragma once

#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "timeout_clock_configurations.hpp"

namespace
	QLogicaeCppCore
{
	class
		TimeoutClock :
			public AbstractClass<TimeoutClockConfigurations>
	{
	public:
		std::jthread
			thread_1;

		std::mutex
			mutex_1;

		std::atomic<bool>
			is_flag_stopped_async
				{ false };

		std::atomic<bool>
			is_cancelled_async
				{ false };

		std::atomic<bool>
			is_executed_immediately_async
				{ false };

		static TimeoutClock&
			singleton;

		TimeoutClock();

		~TimeoutClock();

		bool
			construct();

		bool
			destruct();

		bool
			start();

		bool
			cancel();

		bool
			restart();

		bool
			is_cancelled();
	};
}
