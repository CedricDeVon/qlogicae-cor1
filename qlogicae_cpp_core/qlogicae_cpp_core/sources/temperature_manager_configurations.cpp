#include "pch.hpp"

#include "../includes/temperature_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
	TemperatureManagerConfigurations
		::TemperatureManagerConfigurations() :
			AbstractConfigurations<TemperatureManagerConfigurations>()
	{
		original_unit =
			TemperatureUnit::FAHRENHEIT;

		target_unit =
			TemperatureUnit::CELSIUS;
	}

	TemperatureManagerConfigurations
		TemperatureManagerConfigurations
			::initial_configurations;

	TemperatureManagerConfigurations
		TemperatureManagerConfigurations
			::default_configurations =
				TemperatureManagerConfigurations
					::initial_configurations;
}

