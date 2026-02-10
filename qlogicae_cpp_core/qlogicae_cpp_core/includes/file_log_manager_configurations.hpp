#pragma once

#include "log_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    struct
		FileLogManagerConfigurations :
			LogManagerConfigurations
    {
	public:
		static FileLogManagerConfigurations
			initial_configurations;

		static FileLogManagerConfigurations
			default_configurations;

		FileLogManagerConfigurations();
    };
}
