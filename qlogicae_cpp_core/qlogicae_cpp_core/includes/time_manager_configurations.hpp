#pragma once

#include "time_zone.hpp"
#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
	struct
		TimeManagerConfigurations :
			AbstractConfigurations<TimeManagerConfigurations>
	{
	public:
		TimeZone
			time_zone =
				TimeZone::UTC;

		TimeManagerConfigurations();
	};
}

