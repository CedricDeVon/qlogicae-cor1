#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
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

