#pragma once

#if QLOGICAE_COR1__BASE__HPP_CPP__IS_COMPILATION_CONDITIONS_ENABLED_TEMPLATE( \
		FULL \
	)

#include "text_case.hpp"
#include "abstract_configurations.hpp"
#include "windows_environment_variable.hpp"

namespace
	QLOGICAE_COR1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
	struct
		WindowsEnvironmentVariableManagerConfigurations :
			QLOGICAE_COR1__BASE__HPP_CPP__ABSTRACT_CONFIGURATIONS_NAME<WindowsEnvironmentVariableManagerConfigurations>
	{
	public:	
		WindowsEnvironmentVariable
			type =
				WindowsEnvironmentVariable
					::USER;

		WindowsEnvironmentVariableManagerConfigurations();
	};
}

#endif
