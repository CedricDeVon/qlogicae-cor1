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
				LogLevel
					::INFO;

		LogLevelEnumManagerConfigurations();
	};
}
