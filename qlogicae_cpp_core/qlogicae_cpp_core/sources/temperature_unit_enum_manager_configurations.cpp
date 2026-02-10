#include "pch.hpp"

#include "../includes/temperature_unit_enum_manager_configurations.hpp"

namespace
	QLogicaeCppCore
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
