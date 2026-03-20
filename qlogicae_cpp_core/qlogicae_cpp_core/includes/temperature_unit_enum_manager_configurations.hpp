#pragma once

#include "temperature_unit.hpp"
#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
	struct
		TemperatureUnitEnumManagerConfigurations :
			AbstractConfigurations<TemperatureUnitEnumManagerConfigurations>
	{
	public:	
		TemperatureUnit
			type =
				TemperatureUnit
					::CELSIUS;

		TemperatureUnitEnumManagerConfigurations();
	};
}
