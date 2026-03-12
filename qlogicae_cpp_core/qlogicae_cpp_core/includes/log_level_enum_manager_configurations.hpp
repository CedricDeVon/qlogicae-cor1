#pragma once

#include "log_level.hpp"
#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
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
