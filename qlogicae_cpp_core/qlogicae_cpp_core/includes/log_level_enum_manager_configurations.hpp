#pragma once

#include "log_level.hpp"
#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{
	struct
		LogLevelEnumManagerConfigurations :
			AbstractConfigurations<LogLevelEnumManagerConfigurations>
	{
	public:	
		LogLevel
			type =
				default_configurations
					.type;

		static LogLevelEnumManagerConfigurations
			initial_configurations;

		static LogLevelEnumManagerConfigurations
			default_configurations;

		LogLevelEnumManagerConfigurations();
	};
}
