#pragma once

#include "time_zone.hpp"
#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{
	struct
		TimeZoneEnumManagerConfigurations :
			AbstractConfigurations<TimeZoneEnumManagerConfigurations>
	{
	public:	
		TimeZone
			type =
				default_configurations
					.type;

		static TimeZoneEnumManagerConfigurations
			initial_configurations;

		static TimeZoneEnumManagerConfigurations
			default_configurations;

		TimeZoneEnumManagerConfigurations();
	};
}
