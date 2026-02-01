#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{
	struct
		WindowsEnvironmentVariableManagerConfigurations :
			AbstractConfigurations<WindowsEnvironmentVariableManagerConfigurations>
	{
	public:	
		static WindowsEnvironmentVariableManagerConfigurations
			initial_configurations;

		static WindowsEnvironmentVariableManagerConfigurations
			default_configurations;

		WindowsEnvironmentVariableManagerConfigurations();
	};
}
