#pragma once

#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "qlogicae_service_application_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    class
		QLogicaeServiceApplicationManager :
			public AbstractClass<QLogicaeServiceApplicationManagerConfigurations>
    {
    public:		
        static QLogicaeServiceApplicationManager&
            singleton;

		QLogicaeServiceApplicationManager();
    };
}
