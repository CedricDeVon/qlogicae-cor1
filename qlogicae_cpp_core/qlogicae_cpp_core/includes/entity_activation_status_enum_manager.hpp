#pragma once

#include "abstract_class.hpp"
#include "entity_activation_status.hpp"
#include "entity_activation_status_enum_manager_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
    class
		EntityActivationStatusEnumManager :
			public AbstractClass<EntityActivationStatusEnumManagerConfigurations>
    {
    public:
		EntityActivationStatusEnumManager();

		std::string
			convert_enum_to_string(
				const EntityActivationStatus&
					value
			);

		std::string
			convert_enum_to_string();

		EntityActivationStatus
			convert_string_to_enum(
				const std::string&
					value
			);

		EntityActivationStatus
			convert_string_to_enum();
    };
}
