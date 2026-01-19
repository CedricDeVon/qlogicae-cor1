#pragma once

#include "abstract_class.hpp"
#include "temperature_unit.hpp"
#include "singleton_manager.hpp"
#include "temperature_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    class
		TemperatureManager :
			public AbstractClass<TemperatureManagerConfigurations>
    {
    public:
        static TemperatureManager&
            singleton;

		TemperatureManager();

		~TemperatureManager();

		bool
			construct();

		bool
			destruct();

		long double
			convert_unit(
				const long double&
					value,
				const TemperatureUnit&
					original_unit,
				const TemperatureUnit&
					target_unit
			);

		double
			convert_unit(
				const double&
					value,
				const TemperatureUnit&
					original_unit,
				const TemperatureUnit&
					target_unit
			);

		float
			convert_unit(
				const float&
					value,
				const TemperatureUnit&
					original_unit,
				const TemperatureUnit&
					target_unit
			);

		long double
			convert_unit(
				const long double&
					value
			);

		double
			convert_unit(
				const double&
					value
			);

		float
			convert_unit(
				const float&
					value
			);
    };
}
