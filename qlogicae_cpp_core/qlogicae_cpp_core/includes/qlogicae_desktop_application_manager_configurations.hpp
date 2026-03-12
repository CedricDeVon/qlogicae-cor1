#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
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
