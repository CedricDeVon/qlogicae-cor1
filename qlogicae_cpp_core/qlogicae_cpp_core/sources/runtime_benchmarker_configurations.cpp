#include "pch.hpp"

#include "../includes/runtime_benchmarker_configurations.hpp"

namespace
	QLogicae::Cor::V1
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
