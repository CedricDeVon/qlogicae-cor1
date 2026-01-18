#include "pch.hpp"

#include "../includes/singleton_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{   
	SingletonManagerConfigurations
		SingletonManagerConfigurations
			::initial_configurations =
				[]()
				{
					SingletonManagerConfigurations
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

	SingletonManagerConfigurations
		SingletonManagerConfigurations
			::default_configurations =
				SingletonManagerConfigurations
					::initial_configurations;
}

