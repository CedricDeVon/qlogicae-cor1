#pragma once

#include "abstract_class.hpp"
#include "temperature_unit.hpp"
#include "temperature_manager_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
    class
		TemperatureManager :
			public AbstractClass<TemperatureManagerConfigurations>
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
