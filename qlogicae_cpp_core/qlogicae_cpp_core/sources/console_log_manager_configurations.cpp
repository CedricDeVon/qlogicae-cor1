#include "pch.hpp"

#include "../includes/console_log_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{       
	ConsoleLogManagerConfigurations
		::ConsoleLogManagerConfigurations() :
			LogManagerConfigurations<ConsoleLogManagerConfigurations>()
	{
		
	}

	ConsoleLogManagerConfigurations
		ConsoleLogManagerConfigurations
			::initial_configurations;

	ConsoleLogManagerConfigurations
		ConsoleLogManagerConfigurations
			::default_configurations =
				ConsoleLogManagerConfigurations
					::initial_configurations;
}
