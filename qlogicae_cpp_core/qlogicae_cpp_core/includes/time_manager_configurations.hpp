#pragma once

#include "time_zone.hpp"
#include "abstract_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
	struct
		TimeManagerConfigurations :
			QLOGICAE_COR_V1__BASE__HPP_CPP__ABSTRACT_CONFIGURATIONS_NAME<TimeManagerConfigurations>
	{
	public:
		TimeZone
			time_zone =
				TimeZone::UTC;

		TimeManagerConfigurations();
	};
}
