#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
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

