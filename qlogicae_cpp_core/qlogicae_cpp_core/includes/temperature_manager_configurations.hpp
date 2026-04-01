#pragma once

#include "temperature_unit.hpp"
#include "abstract_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
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
