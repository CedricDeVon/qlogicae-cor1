#include "pch.hpp"

#include "../includes/interval_clock_configurations.hpp"

namespace
	QLogicaeCppCore
{
    IntervalClockConfigurations
		IntervalClockConfigurations
			::initial_configurations =
				[]()
				{
					IntervalClockConfigurations
						configurations;

					configurations
						.is_feature_handling_enabled =
							true;
					
					configurations
						.is_error_handling_enabled =
							true;

					configurations
						.is_thread_safety_override_enabled =
							false;

					configurations
						.is_feature_handling_thread_safety_enabled =
							false;

					configurations
						.is_utility_handling_thread_safety_enabled =
							true;

					configurations
						.is_error_handling_thread_safety_enabled =
							true;

					configurations
						.callback =
							[](const size_t& current_iteration) { return true; };

					configurations
						.maximum_interval_count =
							1;

					configurations
						.delay_in_milliseconds =
							std::chrono::milliseconds{ 1000 };

					configurations
						.is_executed_immediately =
							true;

					return
						configurations;
				}();

	IntervalClockConfigurations
		IntervalClockConfigurations
			::default_configurations =
				IntervalClockConfigurations
					::initial_configurations;
}
