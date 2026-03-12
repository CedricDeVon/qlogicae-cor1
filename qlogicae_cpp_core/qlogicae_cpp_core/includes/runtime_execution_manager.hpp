#pragma once

#include "abstract_class.hpp"
#include "time_scale_unit.hpp"
#include "singleton_manager.hpp"
#include "runtime_execution_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
    class
		RuntimeExecutionManager :
			public AbstractClass<RuntimeExecutionManagerConfigurations>
    {
    public:
		double
			cycles_per_microsecond;

		std::atomic<bool>
			is_calibrated;

		std::atomic<double>
			cached_frequency;

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
			delay_execution_in_years(			
				const double&
					value
			);

		bool
			delay_execution_in_months(			
				const double&
					value
			);

		bool
			delay_execution_in_weeks(			
				const double&
					value
			);

		bool
			delay_execution_in_days(			
				const double&
					value
			);

		bool
			delay_execution_in_hours(			
				const double&
					value
			);

		bool
			delay_execution_in_minutes(			
				const double&
					value
			);

		bool
			delay_execution_in_seconds(
				const double&
					value
			);

		bool
			delay_execution_in_milliseconds(
				const double&
					value
			);

		bool
			delay_execution_in_microseconds(
				const double&
					value
			);

		bool
			delay_execution_in_nanoseconds(
				const double&
					value
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

