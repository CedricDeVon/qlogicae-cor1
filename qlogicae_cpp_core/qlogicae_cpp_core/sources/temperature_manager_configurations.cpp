#include "pch.hpp"

#include "../includes/temperature_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    TemperatureManagerConfigurations
		TemperatureManagerConfigurations
			::initial_configurations =
				[]()
				{
					TemperatureManagerConfigurations
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

	TemperatureManagerConfigurations
		TemperatureManagerConfigurations
			::default_configurations =
				TemperatureManagerConfigurations
					::initial_configurations;
}
