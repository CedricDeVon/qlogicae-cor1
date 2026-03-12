#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
{    
    struct
		QLogicaeConsoleApplicationManagerConfigurations :
			AbstractConfigurations<QLogicaeConsoleApplicationManagerConfigurations>
    {
	public:
		static QLogicaeConsoleApplicationManagerConfigurations
			initial_configurations;

		static QLogicaeConsoleApplicationManagerConfigurations
			default_configurations;

		QLogicaeConsoleApplicationManagerConfigurations();
    };    
}
