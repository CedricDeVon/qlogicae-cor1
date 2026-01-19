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
		static IntervalClockConfigurations
			initial_configurations;

		static IntervalClockConfigurations
			default_configurations;
    };
}
