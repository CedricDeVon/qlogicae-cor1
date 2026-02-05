#include "pch.hpp"

#include "../includes/timeout_clock_configurations.hpp"

namespace QLogicaeCppCore
{	
	TimeoutClockConfigurations
		::TimeoutClockConfigurations() :
			AbstractConfigurations<TimeoutClockConfigurations>()
	{
		is_feature_thread_safety_handling_enabled =
			true;

		callback =
			[]() {};

		delay_in_milliseconds =
			std::chrono::milliseconds{ 1000 };

		is_executed_immediately =
			true;
	}

	TimeoutClockConfigurations
		TimeoutClockConfigurations
			::initial_configurations;

	TimeoutClockConfigurations
		TimeoutClockConfigurations
			::default_configurations =
				TimeoutClockConfigurations
					::initial_configurations;
}

