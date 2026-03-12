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
				default_configurations
					.type;

		static TemperatureUnitEnumManagerConfigurations
			initial_configurations;

		static TemperatureUnitEnumManagerConfigurations
			default_configurations;

		TemperatureUnitEnumManagerConfigurations();
	};
}
