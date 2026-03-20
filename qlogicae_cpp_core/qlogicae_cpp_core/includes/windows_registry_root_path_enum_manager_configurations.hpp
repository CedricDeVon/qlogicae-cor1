#pragma once

#include "abstract_configurations.hpp"
#include "windows_registry_root_path.hpp"

namespace
	QLogicae::Cor::V1
{
	struct
		WindowsRegistryRootPathEnumManagerConfigurations :
			AbstractConfigurations<WindowsRegistryRootPathEnumManagerConfigurations>
	{
	public:	
		WindowsRegistryRootPath
			type =
				WindowsRegistryRootPath
					::HKCU;

		WindowsRegistryRootPathEnumManagerConfigurations();
	};
}
