#include "pch.hpp"

#include "../includes/temperature_unit_enum_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{   
	TemperatureUnitEnumManagerConfigurations
		::TemperatureUnitEnumManagerConfigurations() :
			AbstractConfigurations<TemperatureUnitEnumManagerConfigurations>()
	{
		type =
			TemperatureUnit
				::CELSIUS;
	}

	TemperatureUnitEnumManagerConfigurations
		TemperatureUnitEnumManagerConfigurations
			::initial_configurations;

	TemperatureUnitEnumManagerConfigurations
		TemperatureUnitEnumManagerConfigurations
			::default_configurations =
				TemperatureUnitEnumManagerConfigurations
					::initial_configurations;
}
