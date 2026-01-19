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
						.is_method_execution_enabled =
							true;
					
					configurations
						.is_error_handling_enabled =
							true;

					configurations
						.is_thread_safety_override_enabled =
							false;

					configurations
						.is_method_execution_thread_safety_enabled =
							true;

					configurations
						.is_error_handling_thread_safety_enabled =
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
