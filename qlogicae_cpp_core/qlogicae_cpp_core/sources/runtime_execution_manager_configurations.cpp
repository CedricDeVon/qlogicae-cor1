#include "pch.hpp"

#include "../includes/runtime_execution_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    RuntimeExecutionManagerConfigurations
		RuntimeExecutionManagerConfigurations
			::initial_configurations =
				[]()
				{
					RuntimeExecutionManagerConfigurations
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

	RuntimeExecutionManagerConfigurations
		RuntimeExecutionManagerConfigurations
			::default_configurations =
				RuntimeExecutionManagerConfigurations
					::initial_configurations;
}
