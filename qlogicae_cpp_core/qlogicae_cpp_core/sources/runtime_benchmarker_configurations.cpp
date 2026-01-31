#include "pch.hpp"

#include "../includes/runtime_benchmarker_configurations.hpp"

namespace
	QLogicaeCppCore
{
	RuntimeBenchmarkerConfigurations
		::RuntimeBenchmarkerConfigurations() :
			AbstractConfigurations<RuntimeBenchmarkerConfigurations>()
	{
		
	}

	RuntimeBenchmarkerConfigurations
		RuntimeBenchmarkerConfigurations
			::initial_configurations;

	RuntimeBenchmarkerConfigurations
		RuntimeBenchmarkerConfigurations
			::default_configurations =
				RuntimeBenchmarkerConfigurations
					::initial_configurations;
}
