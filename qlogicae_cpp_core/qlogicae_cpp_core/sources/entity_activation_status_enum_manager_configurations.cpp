#include "pch.hpp"

#include "../includes/entity_activation_status_enum_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{   
	EntityActivationStatusEnumManagerConfigurations
		::EntityActivationStatusEnumManagerConfigurations() :
			AbstractConfigurations<EntityActivationStatusEnumManagerConfigurations>()
	{
		type =
			EntityActivationStatus
				::ACTIVE;
	}

	EntityActivationStatusEnumManagerConfigurations
		EntityActivationStatusEnumManagerConfigurations
			::initial_configurations;

	EntityActivationStatusEnumManagerConfigurations
		EntityActivationStatusEnumManagerConfigurations
			::default_configurations =
				EntityActivationStatusEnumManagerConfigurations
					::initial_configurations;
}
