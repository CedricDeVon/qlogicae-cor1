#pragma once

#include "enum_manager.hpp"
#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "windows_registry_root_path.hpp"
#include "windows_registry_root_path_enum_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    class
		WindowsRegistryRootPathEnumManager :
			public AbstractClass<WindowsRegistryRootPathEnumManagerConfigurations>
    {
    public:
        static WindowsRegistryRootPathEnumManager&
            singleton;

		WindowsRegistryRootPathEnumManager();

		~WindowsRegistryRootPathEnumManager();

		bool
			construct();

		bool
			destruct();

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
