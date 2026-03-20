#pragma once

#include "text_case.hpp"
#include "abstract_configurations.hpp"
#include "windows_environment_variable.hpp"

namespace
	QLogicae::Cor::V1
{
	struct
		WindowsEnvironmentVariableManagerConfigurations :
			AbstractConfigurations<WindowsEnvironmentVariableManagerConfigurations>
	{
	public:	
		WindowsEnvironmentVariable
			type =
				WindowsEnvironmentVariable
					::USER;

		WindowsEnvironmentVariableManagerConfigurations();
	};
}
