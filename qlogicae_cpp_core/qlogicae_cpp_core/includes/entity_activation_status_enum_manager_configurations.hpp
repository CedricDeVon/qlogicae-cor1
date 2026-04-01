#pragma once

#include "abstract_configurations.hpp"
#include "entity_activation_status.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
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
