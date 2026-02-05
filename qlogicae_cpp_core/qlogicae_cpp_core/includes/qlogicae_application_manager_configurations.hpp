#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{    
    struct
		QLogicaeApplicationManagerConfigurations :
			AbstractConfigurations<QLogicaeApplicationManagerConfigurations>
    {
	public:
		static QLogicaeApplicationManagerConfigurations
			initial_configurations;

		static QLogicaeApplicationManagerConfigurations
			default_configurations;

		QLogicaeApplicationManagerConfigurations();
    };    
}

