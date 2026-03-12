#include "pch.hpp"

#include "../includes/windows_registry_root_path_enum_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{   
	WindowsRegistryRootPathEnumManagerConfigurations
		::WindowsRegistryRootPathEnumManagerConfigurations() :
			AbstractConfigurations<WindowsRegistryRootPathEnumManagerConfigurations>()
	{
		type =
			WindowsRegistryRootPath
				::HKCU;
	}

	WindowsRegistryRootPathEnumManagerConfigurations
		WindowsRegistryRootPathEnumManagerConfigurations
			::initial_configurations;

	WindowsRegistryRootPathEnumManagerConfigurations
		WindowsRegistryRootPathEnumManagerConfigurations
			::default_configurations =
				WindowsRegistryRootPathEnumManagerConfigurations
					::initial_configurations;
}
