#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{
    struct
		LogManagerConfigurations :
			AbstractConfigurations<LogManagerConfigurations>
    {
	public:
		static LogManagerConfigurations
			initial_configurations;

		static LogManagerConfigurations
			default_configurations;

		LogManagerConfigurations();
    };
}
