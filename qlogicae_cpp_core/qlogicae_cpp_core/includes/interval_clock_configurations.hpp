#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
{   
    struct
		IntervalClockConfigurations :
			AbstractConfigurations<IntervalClockConfigurations>
    {
	public:
		std::function<bool(const size_t& current_iteration)>
			callback =
				[](const size_t& current_iteration) { return true; };

		size_t
			maximum_interval_count =
				1;

		std::chrono::milliseconds
			delay_in_milliseconds =
				std::chrono::milliseconds{ 1000 };

		bool
			is_executed_immediately =
				true;

		IntervalClockConfigurations();
    };
}

