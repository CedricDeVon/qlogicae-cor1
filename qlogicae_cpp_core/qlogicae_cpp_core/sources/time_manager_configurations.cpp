#include "pch.hpp"

#include "../includes/time_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
	TimeManagerConfigurations
		::TimeManagerConfigurations() :
			AbstractConfigurations<TimeManagerConfigurations>()
	{
		time_zone =
			TimeZone::UTC;
	}

	TimeManagerConfigurations
		TimeManagerConfigurations
			::initial_configurations;

	TimeManagerConfigurations
		TimeManagerConfigurations
			::default_configurations =
				TimeManagerConfigurations
					::initial_configurations;
}
