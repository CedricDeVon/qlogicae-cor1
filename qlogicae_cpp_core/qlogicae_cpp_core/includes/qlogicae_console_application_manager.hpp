#pragma once

#include "abstract_class.hpp"
#include "qlogicae_console_application_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
    class
		QLogicaeConsoleApplicationManager :
			public AbstractClass<QLogicaeConsoleApplicationManagerConfigurations>
    {
    public:		
		QLogicaeConsoleApplicationManager();
    };
}
