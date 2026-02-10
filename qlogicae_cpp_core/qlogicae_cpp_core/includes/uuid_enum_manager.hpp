#pragma once

#include "uuid.hpp"
#include "enum_manager.hpp"
#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "uuid_enum_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    class
		UuidEnumManager :
			public AbstractClass<UuidEnumManagerConfigurations>
    {
    public:
        static UuidEnumManager&
            singleton;

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


