#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{
    struct
		RuntimeBenchmarkerConfigurations :
			AbstractConfigurations<RuntimeBenchmarkerConfigurations>
    {
		static RuntimeBenchmarkerConfigurations
			initial_configurations;

		static RuntimeBenchmarkerConfigurations
			default_configurations;
    };
}
