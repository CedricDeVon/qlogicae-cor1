#pragma once

#include "abstract_class.hpp"
#include "qlogicae_service_application_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
    class
		QLogicaeServiceApplicationManager :
			public AbstractClass<QLogicaeServiceApplicationManagerConfigurations>
    {
    public:		
		QLogicaeServiceApplicationManager();
    };
}
