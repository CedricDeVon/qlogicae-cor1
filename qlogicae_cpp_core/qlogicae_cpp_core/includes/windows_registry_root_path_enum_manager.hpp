#pragma once

#include "enum_manager.hpp"
#include "abstract_class.hpp"
#include "windows_registry_root_path.hpp"
#include "windows_registry_root_path_enum_manager_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
    class
		WindowsRegistryRootPathEnumManager :
			public AbstractClass<WindowsRegistryRootPathEnumManagerConfigurations>
    {
    public:
		WindowsRegistryRootPathEnumManager();

		std::string
			convert_enum_to_string(
				const WindowsRegistryRootPath&
					value
			);

		std::string
			convert_enum_to_string();

		WindowsRegistryRootPath
			convert_string_to_enum(
				const std::string&
					value
			);

		WindowsRegistryRootPath
			convert_string_to_enum();
    };
}
