#pragma once

#include "time_zone.hpp"
#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
	struct
		TimeZoneEnumManagerConfigurations :
			AbstractConfigurations<TimeZoneEnumManagerConfigurations>
	{
	public:	
		TimeZone
			type =
				TimeZone
					::UTC;

		TimeZoneEnumManagerConfigurations();
	};
}
