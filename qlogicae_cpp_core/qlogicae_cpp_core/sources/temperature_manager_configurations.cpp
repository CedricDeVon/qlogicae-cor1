#include "pch.hpp"

#include "../includes/temperature_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    TemperatureManagerConfigurations
		TemperatureManagerConfigurations
			::initial_configurations =
				[]()
				{
					TemperatureManagerConfigurations
						configurations;

					configurations
						.original_unit =
							TemperatureUnit::FAHRENHEIT;
					
					configurations
						.target_unit =
							TemperatureUnit::CELSIUS;

					return
						configurations;
				}();

	TemperatureManagerConfigurations
		TemperatureManagerConfigurations
			::default_configurations =
				TemperatureManagerConfigurations
					::initial_configurations;
}

