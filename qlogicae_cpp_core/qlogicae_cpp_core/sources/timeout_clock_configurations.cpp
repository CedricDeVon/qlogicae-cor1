#include "pch.hpp"

#include "../includes/timeout_clock_configurations.hpp"

namespace QLogicaeCppCore
{
	TimeoutClockConfigurations
		TimeoutClockConfigurations
			::initial_configurations =
				[]()
				{
					TimeoutClockConfigurations
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
							[]() {};

					configurations
						.delay_in_milliseconds =
							std::chrono::milliseconds{ 1000 };

					configurations
						.is_executed_immediately =
							true;

					return
						configurations;
				}();

	TimeoutClockConfigurations
		TimeoutClockConfigurations
			::default_configurations =
				TimeoutClockConfigurations
					::initial_configurations;
}
