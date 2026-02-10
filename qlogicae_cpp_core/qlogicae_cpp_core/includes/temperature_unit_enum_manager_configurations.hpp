#pragma once

#include "temperature_unit.hpp"
#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{
	struct
		TemperatureUnitEnumManagerConfigurations :
			AbstractConfigurations<TemperatureUnitEnumManagerConfigurations>
	{
	public:	
		TemperatureUnit
			type =
				default_configurations
					.type;

		static TemperatureUnitEnumManagerConfigurations
			initial_configurations;

		static TemperatureUnitEnumManagerConfigurations
			default_configurations;

		TemperatureUnitEnumManagerConfigurations();
	};
}
