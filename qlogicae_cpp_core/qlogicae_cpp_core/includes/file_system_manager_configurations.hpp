#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{
    struct
		FileSystemManagerConfigurations :
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



		static FileSystemManagerConfigurations
			initial_configurations;

		static FileSystemManagerConfigurations
			default_configurations;
    };
}
