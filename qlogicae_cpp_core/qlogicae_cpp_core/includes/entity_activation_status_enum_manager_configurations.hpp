#pragma once

#include "entity_activation_status.hpp"
#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
	struct
		EntityActivationStatusEnumManagerConfigurations :
			AbstractConfigurations<EntityActivationStatusEnumManagerConfigurations>
	{
	public:	
		EntityActivationStatus
			type =
				default_configurations
					.type;

		static EntityActivationStatusEnumManagerConfigurations
			initial_configurations;

		static EntityActivationStatusEnumManagerConfigurations
			default_configurations;

		EntityActivationStatusEnumManagerConfigurations();
	};
}
