#include "pch.hpp"

#include "../includes/qlogicae_console_application_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
	QLogicaeConsoleApplicationManagerConfigurations
		::QLogicaeConsoleApplicationManagerConfigurations() :
			AbstractConfigurations<QLogicaeConsoleApplicationManagerConfigurations>()
	{
		
	}

	QLogicaeConsoleApplicationManagerConfigurations
		QLogicaeConsoleApplicationManagerConfigurations
			::initial_configurations;

	QLogicaeConsoleApplicationManagerConfigurations
		QLogicaeConsoleApplicationManagerConfigurations
			::default_configurations =
				QLogicaeConsoleApplicationManagerConfigurations
					::initial_configurations;
}
