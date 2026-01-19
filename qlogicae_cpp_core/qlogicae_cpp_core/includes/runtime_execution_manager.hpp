#pragma once

#include "time_scale_unit.hpp"
#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "runtime_execution_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    class
		RuntimeExecutionManager :
			public AbstractClass<RuntimeExecutionManagerConfigurations>
    {
    public:
		double
			cycles_per_microsecond;

		static RuntimeExecutionManager&
			singleton;

		RuntimeExecutionManager();

		~RuntimeExecutionManager();

		bool
			construct();

		bool
			destruct();

		bool
			delay_execution(			
				const double&
					value,
				const TimeScaleUnit&
					time_scale_unit
			);

		bool
			calibrate();

		bool
			real_time_stamp_counter(			
				const double&
					microseconds
			);

		bool
			query_performance_counter(			
				const double&
					microseconds
			);
	};
}
