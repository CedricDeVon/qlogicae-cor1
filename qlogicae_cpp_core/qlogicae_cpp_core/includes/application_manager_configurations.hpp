#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{    
    struct
		ApplicationManagerConfigurations :
			AbstractConfigurations<ApplicationManagerConfigurations>
    {
		static ApplicationManagerConfigurations
			initial_configurations;

		static ApplicationManagerConfigurations
			default_configurations;
    };    
}
