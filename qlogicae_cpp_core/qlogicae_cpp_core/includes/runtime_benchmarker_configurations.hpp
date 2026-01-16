#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{
    struct
		RuntimeBenchmarkerConfigurations :
			AbstractConfigurations
    {
        bool
			is_enabled =
				default_configurations
					.is_enabled;

		bool
			is_thread_safety_enabled =
				default_configurations
					.is_thread_safety_enabled;



		static RuntimeBenchmarkerConfigurations
			initial_configurations;

		static RuntimeBenchmarkerConfigurations
			default_configurations;
    };
}
