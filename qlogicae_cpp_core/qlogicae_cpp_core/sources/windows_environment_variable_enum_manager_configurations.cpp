#include "pch.hpp"

#include "../includes/windows_environment_variable_enum_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{   
	WindowsEnvironmentVariableEnumManagerConfigurations
		::WindowsEnvironmentVariableEnumManagerConfigurations() :
			AbstractConfigurations<WindowsEnvironmentVariableEnumManagerConfigurations>()
	{
		type =
			WindowsEnvironmentVariable
				::USER;
	}

	WindowsEnvironmentVariableEnumManagerConfigurations
		WindowsEnvironmentVariableEnumManagerConfigurations
			::initial_configurations;

	WindowsEnvironmentVariableEnumManagerConfigurations
		WindowsEnvironmentVariableEnumManagerConfigurations
			::default_configurations =
				WindowsEnvironmentVariableEnumManagerConfigurations
					::initial_configurations;
}
