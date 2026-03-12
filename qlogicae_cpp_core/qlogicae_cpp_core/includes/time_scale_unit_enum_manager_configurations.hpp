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
				default_configurations
					.type;

		static TimeScaleUnitEnumManagerConfigurations
			initial_configurations;

		static TimeScaleUnitEnumManagerConfigurations
			default_configurations;

		TimeScaleUnitEnumManagerConfigurations();
	};
}
