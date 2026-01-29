#include "pch.hpp"

#include "../includes/console_io_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
	ConsoleIoManagerConfigurations
		ConsoleIoManagerConfigurations
			::initial_configurations =
				[]()
				{
					ConsoleIoManagerConfigurations
						configurations;

					return
						configurations;
				}();

	ConsoleIoManagerConfigurations
		ConsoleIoManagerConfigurations
			::default_configurations =
				ConsoleIoManagerConfigurations
					::initial_configurations;
}
