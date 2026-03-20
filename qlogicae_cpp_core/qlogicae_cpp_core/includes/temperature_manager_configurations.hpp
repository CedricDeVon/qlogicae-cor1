#pragma once

#include "temperature_unit.hpp"
#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
	struct
		TemperatureManagerConfigurations :
			AbstractConfigurations<TemperatureManagerConfigurations>
	{
	public:
		TemperatureUnit
			original_unit =
				TemperatureUnit::FAHRENHEIT;

		TemperatureUnit
			target_unit =
				TemperatureUnit::CELSIUS;

		TemperatureManagerConfigurations();
	};
}

