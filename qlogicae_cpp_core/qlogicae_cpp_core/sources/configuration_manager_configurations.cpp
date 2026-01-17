#include "pch.hpp"

#include "../includes/configuration_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    ConfigurationManagerConfigurations
		ConfigurationManagerConfigurations
			::initial_configurations =
				{
					.is_enabled =
						true,

					.is_thread_safety_enabled =
						false,
				};

	ConfigurationManagerConfigurations
		ConfigurationManagerConfigurations
			::default_configurations =
				ConfigurationManagerConfigurations
					::initial_configurations;
}
