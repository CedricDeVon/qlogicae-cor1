#pragma once

#include "enum_manager.hpp"
#include "abstract_class.hpp"
#include "windows_environment_variable.hpp"
#include "windows_environment_variable_enum_manager_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
    class
		WindowsEnvironmentVariableEnumManager :
			public AbstractClass<WindowsEnvironmentVariableEnumManagerConfigurations>
    {
    public:
		WindowsEnvironmentVariableEnumManager();

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
