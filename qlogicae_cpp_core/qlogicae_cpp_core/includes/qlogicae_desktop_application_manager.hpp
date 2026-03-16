#pragma once

#include "abstract_class.hpp"
#include "qlogicae_desktop_application_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
    class
		QLogicaeDesktopApplicationManager :
			public AbstractClass<QLogicaeDesktopApplicationManagerConfigurations>
    {
    public:		
		QLogicaeDesktopApplicationManager();
    };
}
