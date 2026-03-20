#pragma once

#include "abstract_configurations.hpp"
#include "entity_activation_status.hpp"

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
				EntityActivationStatus
					::ACTIVE;

		EntityActivationStatusEnumManagerConfigurations();
	};
}
