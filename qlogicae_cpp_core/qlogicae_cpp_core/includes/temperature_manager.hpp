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

    };
}

/*

		bool
			construct();

		bool
			destruct();

		bool
			setup(
				const TemperatureManagerConfigurations&
					new_configurations
			);

		bool
			setup();

		bool
			reset();

		double
			calculate(
				const double&
					value,
				const TemperatureUnitType&
					from_unit_type,
				const TemperatureUnitType&
					to_unit_type
			);

		double
			calculate(
				const double&
					value
			);

		double
			calculate(
				const TemperatureManagerConfigurations&
					new_configurations
			);

		void
			_handle_construct();

		void
			_handle_destruct();

		void
			_handle_setup();

		void
			_handle_reset();

		void
			_handle_calculate();

*/ 