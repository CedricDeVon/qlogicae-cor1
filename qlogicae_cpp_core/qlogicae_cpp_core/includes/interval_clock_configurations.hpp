#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{   
    struct
		IntervalClockConfigurations :
			AbstractConfigurations<IntervalClockConfigurations>
    {
	public:
		std::function<bool(const size_t& current_iteration)>
			callback =
				default_configurations
					.callback;

		size_t
			maximum_interval_count =
				default_configurations
					.maximum_interval_count;

		std::chrono::milliseconds
			delay_in_milliseconds =
				default_configurations
					.delay_in_milliseconds;

		bool
			is_executed_immediately =
				default_configurations
					.is_executed_immediately;

		static IntervalClockConfigurations
			initial_configurations;

		static IntervalClockConfigurations
			default_configurations;

		IntervalClockConfigurations();
    };
}

