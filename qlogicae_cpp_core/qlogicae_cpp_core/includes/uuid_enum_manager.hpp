#pragma once

#include "uuid.hpp"
#include "enum_manager.hpp"
#include "abstract_class.hpp"
#include "uuid_enum_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
    class
		UuidEnumManager :
			public AbstractClass<UuidEnumManagerConfigurations>
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


