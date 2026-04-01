#pragma once

#include "abstract_class.hpp"
#include "qlogicae_service_application_manager_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
    class
		QLogicaeServiceApplicationManager :
			public AbstractClass<QLogicaeServiceApplicationManagerConfigurations>
    {
    public:		
		QLogicaeServiceApplicationManager();
    };
}
