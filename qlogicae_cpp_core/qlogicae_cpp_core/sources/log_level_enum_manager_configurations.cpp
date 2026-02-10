#include "pch.hpp"

#include "../includes/log_level_enum_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{   
	LogLevelEnumManagerConfigurations
		::LogLevelEnumManagerConfigurations() :
			AbstractConfigurations<LogLevelEnumManagerConfigurations>()
	{
		type =
			LogLevel
				::INFO;
	}

	LogLevelEnumManagerConfigurations
		LogLevelEnumManagerConfigurations
			::initial_configurations;

	LogLevelEnumManagerConfigurations
		LogLevelEnumManagerConfigurations
			::default_configurations =
				LogLevelEnumManagerConfigurations
					::initial_configurations;
}
