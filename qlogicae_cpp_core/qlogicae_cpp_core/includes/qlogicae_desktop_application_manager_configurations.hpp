#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{    
    struct
		QLogicaeDesktopApplicationManagerConfigurations :
			AbstractConfigurations<QLogicaeDesktopApplicationManagerConfigurations>
    {
	public:
		static QLogicaeDesktopApplicationManagerConfigurations
			initial_configurations;

		static QLogicaeDesktopApplicationManagerConfigurations
			default_configurations;

		QLogicaeDesktopApplicationManagerConfigurations();
    };    
}
