#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{    
    struct
		ConfigurationManagerConfigurations :
			AbstractConfigurations<ConfigurationManagerConfigurations>
    {
	public:
		static ConfigurationManagerConfigurations
			initial_configurations;

		static ConfigurationManagerConfigurations
			default_configurations;

		ConfigurationManagerConfigurations();
    };    
}
