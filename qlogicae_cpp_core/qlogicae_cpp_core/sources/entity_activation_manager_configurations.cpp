#include "pch.hpp"

#include "../includes/entity_activation_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{	
	EntityActivationManagerConfigurations
		::EntityActivationManagerConfigurations() :
			AbstractConfigurations<EntityActivationManagerConfigurations>()
	{
		
	}

	EntityActivationManagerConfigurations
		EntityActivationManagerConfigurations
			::initial_configurations;

	EntityActivationManagerConfigurations
		EntityActivationManagerConfigurations
			::default_configurations =
				EntityActivationManagerConfigurations
					::initial_configurations;
}
