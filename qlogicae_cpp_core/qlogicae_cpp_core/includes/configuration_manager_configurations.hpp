#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{    
    struct
		ConfigurationManagerConfigurations :
			AbstractConfigurations
    {
		bool
			is_enabled =
				default_configurations
					.is_enabled;

		bool
			is_thread_safety_enabled =
				default_configurations
					.is_thread_safety_enabled;



		static ConfigurationManagerConfigurations
			initial_configurations;

		static ConfigurationManagerConfigurations
			default_configurations;
    };    
}
