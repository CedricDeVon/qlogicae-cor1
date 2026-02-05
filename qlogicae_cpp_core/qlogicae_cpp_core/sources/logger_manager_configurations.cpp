#include "pch.hpp"

#include "../includes/logger_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{   
	LoggerManagerConfigurations
		::LoggerManagerConfigurations() :
			AbstractConfigurations<LoggerManagerConfigurations>()
	{
		
	}

	LoggerManagerConfigurations
		LoggerManagerConfigurations
			::initial_configurations;

	LoggerManagerConfigurations
		LoggerManagerConfigurations
			::default_configurations =
				LoggerManagerConfigurations
					::initial_configurations;
}
