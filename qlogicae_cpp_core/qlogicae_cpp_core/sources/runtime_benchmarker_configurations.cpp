#include "pch.hpp"

#include "../includes/runtime_benchmarker_configurations.hpp"

namespace
	QLogicaeCppCore
{
	RuntimeBenchmarkerConfigurations
		RuntimeBenchmarkerConfigurations
			::initial_configurations =
				[]()
				{
					RuntimeBenchmarkerConfigurations
						configurations;

					return
						configurations;
				}();

	RuntimeBenchmarkerConfigurations
		RuntimeBenchmarkerConfigurations
			::default_configurations =
				RuntimeBenchmarkerConfigurations
					::initial_configurations;
}

