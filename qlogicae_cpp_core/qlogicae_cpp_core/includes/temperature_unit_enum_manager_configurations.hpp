#pragma once

#include "temperature_unit.hpp"
#include "abstract_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
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
