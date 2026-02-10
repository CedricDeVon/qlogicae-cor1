#pragma once

#include "log_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    struct
		ConsoleLogManagerConfigurations :
			LogManagerConfigurations
    {
	public:
		static ConsoleLogManagerConfigurations
			initial_configurations;

		static ConsoleLogManagerConfigurations
			default_configurations;

		ConsoleLogManagerConfigurations();
    };
}
