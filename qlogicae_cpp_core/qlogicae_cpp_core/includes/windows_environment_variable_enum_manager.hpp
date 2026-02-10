#pragma once

#include "enum_manager.hpp"
#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "windows_environment_variable.hpp"
#include "windows_environment_variable_enum_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    class
		WindowsEnvironmentVariableEnumManager :
			public AbstractClass<WindowsEnvironmentVariableEnumManagerConfigurations>
    {
    public:
        static WindowsEnvironmentVariableEnumManager&
            singleton;

		WindowsEnvironmentVariableEnumManager();

		~WindowsEnvironmentVariableEnumManager();

		bool
			construct();

		bool
			destruct();

		std::string
			convert_enum_to_string(
				const WindowsEnvironmentVariable&
					value
			);

		std::string
			convert_enum_to_string();

		WindowsEnvironmentVariable
			convert_string_to_enum(
				const std::string&
					value
			);

		WindowsEnvironmentVariable
			convert_string_to_enum();
    };
}
