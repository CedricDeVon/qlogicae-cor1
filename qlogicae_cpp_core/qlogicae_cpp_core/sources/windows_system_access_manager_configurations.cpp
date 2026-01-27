#include "pch.hpp"

#include "../includes/windows_system_access_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
	WindowsSystemAccessManagerConfigurations
		WindowsSystemAccessManagerConfigurations
			::initial_configurations =
				[]()
				{
					WindowsSystemAccessManagerConfigurations
						configurations;

					return
						configurations;
				}();

	WindowsSystemAccessManagerConfigurations
		WindowsSystemAccessManagerConfigurations
			::default_configurations =
				WindowsSystemAccessManagerConfigurations
					::initial_configurations;
}
