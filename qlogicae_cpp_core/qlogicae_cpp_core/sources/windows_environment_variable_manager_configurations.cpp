#include "pch.hpp"

#include "../includes/windows_environment_variable_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
	WindowsEnvironmentVariableManagerConfigurations
		::WindowsEnvironmentVariableManagerConfigurations() :
			AbstractConfigurations<WindowsEnvironmentVariableManagerConfigurations>()
	{
		
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
