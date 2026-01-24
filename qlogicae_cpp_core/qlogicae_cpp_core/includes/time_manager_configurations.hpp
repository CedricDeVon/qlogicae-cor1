#pragma once

#include "time_zone.hpp"
#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{
	struct
		TimeManagerConfigurations :
			AbstractConfigurations<TimeManagerConfigurations>
	{
	public:
		TimeZone
			time_zone =
				default_configurations.time_zone;



		static TimeManagerConfigurations
			initial_configurations;

		static TimeManagerConfigurations
			default_configurations;
	};
}

