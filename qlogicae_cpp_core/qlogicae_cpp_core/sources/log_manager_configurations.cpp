#include "pch.hpp"

#include "../includes/log_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{       
	LogManagerConfigurations
		::LogManagerConfigurations() :
			AbstractConfigurations<LogManagerConfigurations>()
	{
		
	}

	LogManagerConfigurations
		LogManagerConfigurations
			::initial_configurations;

	LogManagerConfigurations
		LogManagerConfigurations
			::default_configurations =
				LogManagerConfigurations
					::initial_configurations;
}
