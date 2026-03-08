#pragma once

#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "qlogicae_console_application_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    class
		QLogicaeConsoleApplicationManager :
			public AbstractClass<QLogicaeConsoleApplicationManagerConfigurations>
    {
    public:		
        static QLogicaeConsoleApplicationManager&
            singleton;

		QLogicaeConsoleApplicationManager();
    };
}
