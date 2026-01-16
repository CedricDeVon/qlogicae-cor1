#pragma once

#include "abstract_configurations.hpp"
#include "error_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{   
    struct
		SingletonManagerConfigurations :
			AbstractConfigurations
    {
		bool
			is_enabled =
				default_configurations
					.is_enabled;

		bool
			is_thread_safety_enabled =
				default_configurations
					.is_thread_safety_enabled;



		static SingletonManagerConfigurations
			initial_configurations;

		static SingletonManagerConfigurations
			default_configurations;
    };    
}
