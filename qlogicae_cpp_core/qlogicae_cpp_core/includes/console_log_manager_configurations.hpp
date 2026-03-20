#pragma once

#include "log_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
    struct
		ConsoleLogManagerConfigurations :
			LogManagerConfigurations<ConsoleLogManagerConfigurations>
    {
	public:
		ConsoleLogManagerConfigurations();
    };
}

