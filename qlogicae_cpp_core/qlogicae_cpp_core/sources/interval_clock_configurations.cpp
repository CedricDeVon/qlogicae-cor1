#include "pch.hpp"

#include "../includes/interval_clock_configurations.hpp"

namespace
	QLogicaeCppCore
{   
	IntervalClockConfigurations
		::IntervalClockConfigurations() :
			AbstractConfigurations<IntervalClockConfigurations>()
	{
		is_feature_thread_safety_handling_enabled =
			true;

		callback =
			[](const size_t& current_iteration) { return true; };

		maximum_interval_count =
			1;

		delay_in_milliseconds =
			std::chrono::milliseconds{ 1000 };

		is_executed_immediately =
			true;
	}

	IntervalClockConfigurations
		IntervalClockConfigurations
			::initial_configurations;

	IntervalClockConfigurations
		IntervalClockConfigurations
			::default_configurations =
				IntervalClockConfigurations
					::initial_configurations;
}

