#pragma once

#include "abstract_configurations.hpp"
#include "windows_registry_root_path.hpp"

namespace
	QLogicaeCppCore
{
	struct
		WindowsRegistryRootPathEnumManagerConfigurations :
			AbstractConfigurations<WindowsRegistryRootPathEnumManagerConfigurations>
	{
	public:	
		WindowsRegistryRootPath
			type =
				default_configurations
					.type;

		static WindowsRegistryRootPathEnumManagerConfigurations
			initial_configurations;

		static WindowsRegistryRootPathEnumManagerConfigurations
			default_configurations;

		WindowsRegistryRootPathEnumManagerConfigurations();
	};
}
