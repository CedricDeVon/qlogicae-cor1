#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{    
    struct
		AsynchronousManagerConfigurations :
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



		static AsynchronousManagerConfigurations
			initial_configurations;

		static AsynchronousManagerConfigurations
			default_configurations;
    };    
}
