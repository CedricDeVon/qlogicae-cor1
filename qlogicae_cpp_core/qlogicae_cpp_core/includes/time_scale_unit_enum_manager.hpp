#pragma once

#include "enum_manager.hpp"
#include "abstract_class.hpp"
#include "time_scale_unit.hpp"
#include "singleton_manager.hpp"
#include "time_scale_unit_enum_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
    class
		TimeScaleUnitEnumManager :
			public AbstractClass<TimeScaleUnitEnumManagerConfigurations>
    {
    public:
		TimeScaleUnitEnumManager();

		std::string
			convert_enum_to_string(
				const TimeScaleUnit&
					value
			);

		std::string
			convert_enum_to_string();

		TimeScaleUnit
			convert_string_to_enum(
				const std::string&
					value
			);

		TimeScaleUnit
			convert_string_to_enum();
    };
}


