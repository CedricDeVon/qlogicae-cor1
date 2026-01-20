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
