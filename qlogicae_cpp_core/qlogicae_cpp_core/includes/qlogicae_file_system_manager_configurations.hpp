#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
{    
    struct
		QLogicaeFileSystemManagerConfigurations :
			AbstractConfigurations<QLogicaeFileSystemManagerConfigurations>
    {
	public:
		static QLogicaeFileSystemManagerConfigurations
			initial_configurations;

		static QLogicaeFileSystemManagerConfigurations
			default_configurations;

		QLogicaeFileSystemManagerConfigurations();
    };    
}

