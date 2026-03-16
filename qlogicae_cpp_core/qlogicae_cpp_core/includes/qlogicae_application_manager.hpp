#pragma once

#include "abstract_class.hpp"
#include "qlogicae_application_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
    class
		QLogicaeApplicationManager :
			public AbstractClass<QLogicaeApplicationManagerConfigurations>
    {
    public:
		QLogicaeApplicationManager();
    };
}

