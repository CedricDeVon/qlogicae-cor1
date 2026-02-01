#include "pch.hpp"

#include "../includes/windows_registry_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{	
	WindowsRegistryManagerConfigurations
		::WindowsRegistryManagerConfigurations() :
			AbstractConfigurations<WindowsRegistryManagerConfigurations>()
	{
		root_key = 
			HKEY_CURRENT_USER;

		sub_key =
			L"Software\\App";

		name_key =
			L"Data";
	}

	WindowsRegistryManagerConfigurations
		WindowsRegistryManagerConfigurations
			::initial_configurations;

	WindowsRegistryManagerConfigurations
		WindowsRegistryManagerConfigurations
			::default_configurations =
				WindowsRegistryManagerConfigurations
					::initial_configurations;
}
