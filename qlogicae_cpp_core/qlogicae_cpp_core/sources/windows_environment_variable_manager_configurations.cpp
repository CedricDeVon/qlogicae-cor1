#include "pch.hpp"

#include "../includes/windows_environment_variable_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
	WindowsEnvironmentVariableManagerConfigurations
		::WindowsEnvironmentVariableManagerConfigurations() :
			AbstractConfigurations<WindowsEnvironmentVariableManagerConfigurations>()
	{
		type =
			WindowsEnvironmentVariable
				::USER;
	}

	WindowsEnvironmentVariableManagerConfigurations
		WindowsEnvironmentVariableManagerConfigurations
			::initial_configurations;

	WindowsEnvironmentVariableManagerConfigurations
		WindowsEnvironmentVariableManagerConfigurations
			::default_configurations =
				WindowsEnvironmentVariableManagerConfigurations
					::initial_configurations;
}
