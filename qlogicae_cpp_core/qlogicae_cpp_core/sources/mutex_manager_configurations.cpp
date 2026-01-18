#include "pch.hpp"

#include "../includes/mutex_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{   
	MutexManagerConfigurations
		MutexManagerConfigurations
			::initial_configurations =
				[]()
				{
					MutexManagerConfigurations
						configurations;

					configurations
						.name =
							"static";

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

	MutexManagerConfigurations
		MutexManagerConfigurations
			::default_configurations =
				MutexManagerConfigurations
					::initial_configurations;
}
