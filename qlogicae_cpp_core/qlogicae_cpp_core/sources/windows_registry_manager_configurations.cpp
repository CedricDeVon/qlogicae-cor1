#include "pch.hpp"

#include "../includes/windows_registry_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
	WindowsRegistryManagerConfigurations
		WindowsRegistryManagerConfigurations
			::initial_configurations =
				[]()
				{
					WindowsRegistryManagerConfigurations
						configurations;

					configurations
						.root_key = 
							HKEY_CURRENT_USER;

					configurations
						.sub_key =
							L"Software\\App";

					configurations
						.name_key =
							L"Data";

					return
						configurations;
				}();

	WindowsRegistryManagerConfigurations
		WindowsRegistryManagerConfigurations
			::default_configurations =
				WindowsRegistryManagerConfigurations
					::initial_configurations;
}
