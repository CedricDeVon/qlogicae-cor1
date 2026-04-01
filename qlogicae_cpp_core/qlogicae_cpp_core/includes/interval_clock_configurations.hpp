#pragma once

#include "abstract_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
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

