#pragma once

#include "text_case.hpp"
#include "abstract_configurations.hpp"
#include "windows_environment_variable.hpp"

namespace
	QLogicaeCppCore
{
	struct
		WindowsEnvironmentVariableManagerConfigurations :
			AbstractConfigurations<WindowsEnvironmentVariableManagerConfigurations>
	{
	public:	
		WindowsEnvironmentVariable
			type =
				default_configurations
					.type;

		static WindowsEnvironmentVariableManagerConfigurations
			initial_configurations;

		static WindowsEnvironmentVariableManagerConfigurations
			default_configurations;

		WindowsEnvironmentVariableManagerConfigurations();
	};
}
