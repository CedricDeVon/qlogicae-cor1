#pragma once

#include "time_scale_unit.hpp"
#include "abstract_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
	struct
		TimeScaleUnitEnumManagerConfigurations :
			AbstractConfigurations<TimeScaleUnitEnumManagerConfigurations>
	{
	public:	
		TimeScaleUnit
			type =
				TimeScaleUnit
					::SECONDS;

		TimeScaleUnitEnumManagerConfigurations();
	};
}
