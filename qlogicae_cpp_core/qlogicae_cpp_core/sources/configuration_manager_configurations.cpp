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

					return
						configurations;
				}();

	ConfigurationManagerConfigurations
		ConfigurationManagerConfigurations
			::default_configurations =
				ConfigurationManagerConfigurations
					::initial_configurations;
}

