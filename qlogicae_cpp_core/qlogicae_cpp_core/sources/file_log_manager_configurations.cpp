#include "pch.hpp"

#include "../includes/file_log_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{       
	FileLogManagerConfigurations
		::FileLogManagerConfigurations() :
			LogManagerConfigurations()
	{
		
	}

	FileLogManagerConfigurations
		FileLogManagerConfigurations
			::initial_configurations;

	FileLogManagerConfigurations
		FileLogManagerConfigurations
			::default_configurations =
				FileLogManagerConfigurations
					::initial_configurations;
}
