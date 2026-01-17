#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{
    struct
		FunctionWrapperConfigurations :
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



		static FunctionWrapperConfigurations
			initial_configurations;

		static FunctionWrapperConfigurations
			default_configurations;
    };
}
