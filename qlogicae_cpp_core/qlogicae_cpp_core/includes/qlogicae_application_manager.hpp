#pragma once

#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "qlogicae_application_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    class
		QLogicaeApplicationManager :
			public AbstractClass<QLogicaeApplicationManagerConfigurations>
    {
    public:
        static QLogicaeApplicationManager&
            singleton;

		QLogicaeApplicationManager();
    };
}

