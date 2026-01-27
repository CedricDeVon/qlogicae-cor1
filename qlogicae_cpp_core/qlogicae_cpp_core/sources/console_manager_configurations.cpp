#include "pch.hpp"

#include "../includes/console_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
	ConsoleManagerConfigurations
		ConsoleManagerConfigurations
			::initial_configurations =
				[]()
				{
					ConsoleManagerConfigurations
						configurations;

					return
						configurations;
				}();

	ConsoleManagerConfigurations
		ConsoleManagerConfigurations
			::default_configurations =
				ConsoleManagerConfigurations
					::initial_configurations;
}
