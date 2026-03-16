#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
{    
    struct
		EntityActivationManagerConfigurations :
			AbstractConfigurations<EntityActivationManagerConfigurations>
    {
	public:
		static EntityActivationManagerConfigurations
			initial_configurations;

		static EntityActivationManagerConfigurations
			default_configurations;

		EntityActivationManagerConfigurations();
    };    
}
