#pragma once

#include "log_level.hpp"
#include "abstract_configurations.hpp"

namespace
	QLOGICAE_COR1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
	struct
		LogLevelEnumManagerConfigurations :
			QLOGICAE_COR1__BASE__HPP_CPP__ABSTRACT_CONFIGURATIONS_NAME<LogLevelEnumManagerConfigurations>
	{
	public:	
		LogLevel
			type =
				LogLevel
					::INFO;

		LogLevelEnumManagerConfigurations();
	};
}
