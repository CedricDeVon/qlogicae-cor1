#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{
	struct
		TemperatureManagerConfigurations :
			AbstractConfigurations<TemperatureManagerConfigurations>
	{
	public:
		static TemperatureManagerConfigurations
			initial_configurations;

		static TemperatureManagerConfigurations
			default_configurations;
	};
}
