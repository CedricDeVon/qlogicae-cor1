#include "pch.hpp"

#include "../includes/log_medium_enum_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{   
	LogMediumEnumManagerConfigurations
		::LogMediumEnumManagerConfigurations() :
			AbstractConfigurations<LogMediumEnumManagerConfigurations>()
	{
		type =
			LogMedium
				::ALL;
	}

	LogMediumEnumManagerConfigurations
		LogMediumEnumManagerConfigurations
			::initial_configurations;

	LogMediumEnumManagerConfigurations
		LogMediumEnumManagerConfigurations
			::default_configurations =
				LogMediumEnumManagerConfigurations
					::initial_configurations;
}
