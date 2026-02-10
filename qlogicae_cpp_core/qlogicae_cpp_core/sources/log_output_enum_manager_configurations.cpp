#include "pch.hpp"

#include "../includes/log_output_enum_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{   
	LogOutputEnumManagerConfigurations
		::LogOutputEnumManagerConfigurations() :
			AbstractConfigurations<LogOutputEnumManagerConfigurations>()
	{
		type =
			LogOutput
				::ALL;
	}

	LogOutputEnumManagerConfigurations
		LogOutputEnumManagerConfigurations
			::initial_configurations;

	LogOutputEnumManagerConfigurations
		LogOutputEnumManagerConfigurations
			::default_configurations =
				LogOutputEnumManagerConfigurations
					::initial_configurations;
}
