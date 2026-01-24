#pragma once

#include "temperature_unit.hpp"
#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{
	struct
		TemperatureManagerConfigurations :
			AbstractConfigurations<TemperatureManagerConfigurations>
	{
	public:
		TemperatureUnit
			original_unit =
				default_configurations
					.original_unit;

		TemperatureUnit
			target_unit =
				default_configurations
					.target_unit;

		

		static TemperatureManagerConfigurations
			initial_configurations;

		static TemperatureManagerConfigurations
			default_configurations;
	};
}

