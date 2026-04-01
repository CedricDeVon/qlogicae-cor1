#pragma once

#include "abstract_class.hpp"
#include "qlogicae_application_manager_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
    class
		QLogicaeApplicationManager :
			public AbstractClass<QLogicaeApplicationManagerConfigurations>
    {
    public:
		QLogicaeApplicationManager();
    };
}
