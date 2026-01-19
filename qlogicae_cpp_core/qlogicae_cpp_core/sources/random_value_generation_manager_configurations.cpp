#include "pch.hpp"

#include "../includes/random_value_generation_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
	RandomValueGenerationManagerConfigurations
		RandomValueGenerationManagerConfigurations
			::initial_configurations =
				[]()
				{
					RandomValueGenerationManagerConfigurations
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

	RandomValueGenerationManagerConfigurations
		RandomValueGenerationManagerConfigurations
			::default_configurations =
				RandomValueGenerationManagerConfigurations
					::initial_configurations;
}
