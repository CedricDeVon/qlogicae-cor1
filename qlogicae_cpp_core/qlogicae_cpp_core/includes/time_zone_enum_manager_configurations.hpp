#pragma once

#include "time_zone.hpp"
#include "abstract_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
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
