#pragma once

#include "abstract_configurations.hpp"
#include "windows_environment_variable.hpp"

namespace
	QLogicae::Cor::V1
{
	struct
		WindowsEnvironmentVariableEnumManagerConfigurations :
			AbstractConfigurations<WindowsEnvironmentVariableEnumManagerConfigurations>
	{
	public:	
		WindowsEnvironmentVariable
			type =
				default_configurations
					.type;

		static WindowsEnvironmentVariableEnumManagerConfigurations
			initial_configurations;

		static WindowsEnvironmentVariableEnumManagerConfigurations
			default_configurations;

		WindowsEnvironmentVariableEnumManagerConfigurations();
	};
}
