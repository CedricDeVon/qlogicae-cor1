#pragma once

#include "abstract_class.hpp"
#include "temperature_unit.hpp"
#include "singleton_manager.hpp"
#include "temperature_unit_enum_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
    class
		TemperatureUnitEnumManager :
			public AbstractClass<TemperatureUnitEnumManagerConfigurations>
    {
    public:
        static TemperatureUnitEnumManager&
            singleton;

		TemperatureUnitEnumManager();

		std::string
			convert_enum_to_string(
				const TemperatureUnit&
					value
			);

		std::string
			convert_enum_to_string();

		TemperatureUnit
			convert_string_to_enum(
				const std::string&
					value
			);

		TemperatureUnit
			convert_string_to_enum();
    };
}

