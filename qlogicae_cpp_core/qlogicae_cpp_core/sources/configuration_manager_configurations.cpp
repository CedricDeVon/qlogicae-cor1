#include "pch.hpp"

#include "../includes/configuration_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    ConfigurationManagerConfigurations
		ConfigurationManagerConfigurations
			::initial_configurations =
				[]()
				{
					ConfigurationManagerConfigurations
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

	ConfigurationManagerConfigurations
		ConfigurationManagerConfigurations
			::default_configurations =
				ConfigurationManagerConfigurations
					::initial_configurations;
}

