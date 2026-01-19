#include "pch.hpp"

#include "../includes/function_wrapper_configurations.hpp"

namespace
	QLogicaeCppCore
{
	FunctionWrapperConfigurations
		FunctionWrapperConfigurations
			::initial_configurations =
				[]()
				{
					FunctionWrapperConfigurations
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

	FunctionWrapperConfigurations
		FunctionWrapperConfigurations
			::default_configurations =
				FunctionWrapperConfigurations
					::initial_configurations;
}

