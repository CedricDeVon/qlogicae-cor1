#pragma once

#include "log_manager_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
    struct
		ConsoleLogManagerConfigurations :
			LogManagerConfigurations<ConsoleLogManagerConfigurations>
    {
	public:
		ConsoleLogManagerConfigurations();
    };
}
