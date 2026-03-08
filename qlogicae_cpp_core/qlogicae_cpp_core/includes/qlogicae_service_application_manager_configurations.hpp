#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{    
    struct
		QLogicaeServiceApplicationManagerConfigurations :
			AbstractConfigurations<QLogicaeServiceApplicationManagerConfigurations>
    {
	public:
		static QLogicaeServiceApplicationManagerConfigurations
			initial_configurations;

		static QLogicaeServiceApplicationManagerConfigurations
			default_configurations;

		QLogicaeServiceApplicationManagerConfigurations();
    };    
}
