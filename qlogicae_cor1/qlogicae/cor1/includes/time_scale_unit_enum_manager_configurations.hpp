#pragma once

#if QLOGICAE_COR1__BASE__HPP_CPP__IS_COMPILATION_CONDITIONS_ENABLED_TEMPLATE( \
		FULL \
	)

#include "time_scale_unit.hpp"
#include "abstract_configurations.hpp"

namespace
	QLOGICAE_COR1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
	struct
		TimeScaleUnitEnumManagerConfigurations :
			QLOGICAE_COR1__BASE__HPP_CPP__ABSTRACT_CONFIGURATIONS_NAME<TimeScaleUnitEnumManagerConfigurations>
	{
	public:	
		TimeScaleUnit
			type =
				TimeScaleUnit
					::SECONDS;

		TimeScaleUnitEnumManagerConfigurations();
	};
}

#endif
