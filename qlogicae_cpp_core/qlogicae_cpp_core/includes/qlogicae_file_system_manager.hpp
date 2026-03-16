#pragma once

#include "abstract_class.hpp"
#include "qlogicae_file_system_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
    class
		QLogicaeFileSystemManager :
			public AbstractClass<QLogicaeFileSystemManagerConfigurations>
    {
    public:
		QLogicaeFileSystemManager();
    };
}

