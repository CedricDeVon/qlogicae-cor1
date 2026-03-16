#include "pch.hpp"

#include "../includes/time_zone_enum_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{   
	TimeZoneEnumManagerConfigurations
		::TimeZoneEnumManagerConfigurations() :
			AbstractConfigurations<TimeZoneEnumManagerConfigurations>()
	{
		type =
			TimeZone
				::UTC;
	}

	TimeZoneEnumManagerConfigurations
		TimeZoneEnumManagerConfigurations
			::initial_configurations;

	TimeZoneEnumManagerConfigurations
		TimeZoneEnumManagerConfigurations
			::default_configurations =
				TimeZoneEnumManagerConfigurations
					::initial_configurations;
}
