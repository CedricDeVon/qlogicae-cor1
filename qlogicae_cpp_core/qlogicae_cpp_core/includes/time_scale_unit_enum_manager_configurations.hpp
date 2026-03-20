#pragma once

#include "time_scale_unit.hpp"
#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
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
