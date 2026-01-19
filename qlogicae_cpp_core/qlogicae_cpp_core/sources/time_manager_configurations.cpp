#include "pch.hpp"

#include "../includes/time_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
	TimeManagerConfigurations
		TimeManagerConfigurations
			::initial_configurations =
				[]()
				{
					TimeManagerConfigurations
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

	TimeManagerConfigurations
		TimeManagerConfigurations
			::default_configurations =
				TimeManagerConfigurations
					::initial_configurations;
}

