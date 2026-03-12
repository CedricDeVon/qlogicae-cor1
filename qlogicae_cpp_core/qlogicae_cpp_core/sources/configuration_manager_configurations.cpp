#include "pch.hpp"

#include "../includes/configuration_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
	ConfigurationManagerConfigurations
		::ConfigurationManagerConfigurations() :
			AbstractConfigurations<ConfigurationManagerConfigurations>()
	{
		
	}

	ConfigurationManagerConfigurations
		ConfigurationManagerConfigurations
			::initial_configurations;

	ConfigurationManagerConfigurations
		ConfigurationManagerConfigurations
			::default_configurations =
				ConfigurationManagerConfigurations
					::initial_configurations;
}

