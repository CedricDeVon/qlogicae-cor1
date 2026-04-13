#pragma once

#include "abstract_class.hpp"
#include "temperature_unit.hpp"
#include "temperature_manager_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
    class
		TemperatureManager :
			public QLOGICAE_COR_V1__BASE__HPP_CPP__ABSTRACT_CLASS_NAME<TemperatureManagerConfigurations>
    {
    public:
		TemperatureManager();

		double
			convert_unit(
				const double&
					value,
				const TemperatureUnit&
					original_unit,
				const TemperatureUnit&
					target_unit
			);

		double
			convert_unit(
				const double&
					value
			);
    };
}
