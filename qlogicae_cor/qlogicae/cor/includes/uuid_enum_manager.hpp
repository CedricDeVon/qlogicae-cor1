#pragma once

#include "uuid.hpp"
#include "enum_manager.hpp"
#include "abstract_class.hpp"
#include "uuid_enum_manager_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
    class
		UuidEnumManager :
			public QLOGICAE_COR_V1__BASE__HPP_CPP__ABSTRACT_CLASS_NAME<UuidEnumManagerConfigurations>
    {
    public:
		UuidEnumManager();

		std::string
			convert_enum_to_string(
				const Uuid&
					value
			);

		std::string
			convert_enum_to_string();

		Uuid
			convert_string_to_enum(
				const std::string&
					value
			);

		Uuid
			convert_string_to_enum();
    };
}
