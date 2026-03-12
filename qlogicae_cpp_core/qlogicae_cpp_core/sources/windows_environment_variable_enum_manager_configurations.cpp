#include "pch.hpp"

#include "../includes/windows_environment_variable_enum_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
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
