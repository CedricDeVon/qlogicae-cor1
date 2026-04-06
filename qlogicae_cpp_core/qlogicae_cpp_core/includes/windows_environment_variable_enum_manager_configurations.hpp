#pragma once

#include "abstract_configurations.hpp"
#include "windows_environment_variable.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
	struct
		WindowsEnvironmentVariableEnumManagerConfigurations :
			QLOGICAE_COR_V1__BASE__HPP_CPP__ABSTRACT_CONFIGURATIONS_NAME<WindowsEnvironmentVariableEnumManagerConfigurations>
	{
	public:	
		WindowsEnvironmentVariable
			type =
				WindowsEnvironmentVariable
					::USER;

		WindowsEnvironmentVariableEnumManagerConfigurations();
	};
}
