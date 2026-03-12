#include "pch.hpp"

#include "../includes/console_io_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
	ConsoleIoManagerConfigurations
		::ConsoleIoManagerConfigurations() :
			AbstractConfigurations<ConsoleIoManagerConfigurations>()
	{
		
	}

	ConsoleIoManagerConfigurations
		ConsoleIoManagerConfigurations
			::initial_configurations;

	ConsoleIoManagerConfigurations
		ConsoleIoManagerConfigurations
			::default_configurations =
				ConsoleIoManagerConfigurations
					::initial_configurations;
}
