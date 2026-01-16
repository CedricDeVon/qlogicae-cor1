#include "pch.hpp"

#include "../includes/runtime_benchmarker_configurations.hpp"

namespace
	QLogicaeCppCore
{
	RuntimeBenchmarkerConfigurations
		RuntimeBenchmarkerConfigurations
			::initial_configurations =
				{
					.is_enabled =
						true,

					.is_thread_safety_enabled =
						false,
				};

	RuntimeBenchmarkerConfigurations
		RuntimeBenchmarkerConfigurations
			::default_configurations =
				RuntimeBenchmarkerConfigurations
					::initial_configurations;
}
