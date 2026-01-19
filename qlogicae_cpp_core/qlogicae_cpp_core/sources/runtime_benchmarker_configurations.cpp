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

					configurations
						.is_feature_handling_enabled =
							true;
					
					configurations
						.is_error_handling_enabled =
							true;

					configurations
						.is_thread_safety_override_enabled =
							false;

					configurations
						.is_feature_handling_thread_safety_enabled =
							false;

					configurations
						.is_utility_handling_thread_safety_enabled =
							true;

					configurations
						.is_error_handling_thread_safety_enabled =
							true;

					return
						configurations;
				}();

	RuntimeBenchmarkerConfigurations
		RuntimeBenchmarkerConfigurations
			::default_configurations =
				RuntimeBenchmarkerConfigurations
					::initial_configurations;
}

