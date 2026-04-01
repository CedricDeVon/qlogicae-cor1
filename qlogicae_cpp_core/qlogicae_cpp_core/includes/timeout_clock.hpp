#pragma once

#include "abstract_class.hpp"
#include "timeout_clock_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
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

		boost::mutex
			feature_handling_mutex_2;

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
