#include "pch.hpp"

#include "../includes/time_scale_unit_enum_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{   
	TimeScaleUnitEnumManagerConfigurations
		::TimeScaleUnitEnumManagerConfigurations() :
			AbstractConfigurations<TimeScaleUnitEnumManagerConfigurations>()
	{
		type =
			TimeScaleUnit
				::SECONDS;
	}

	TimeScaleUnitEnumManagerConfigurations
		TimeScaleUnitEnumManagerConfigurations
			::initial_configurations;

	TimeScaleUnitEnumManagerConfigurations
		TimeScaleUnitEnumManagerConfigurations
			::default_configurations =
				TimeScaleUnitEnumManagerConfigurations
					::initial_configurations;
}
