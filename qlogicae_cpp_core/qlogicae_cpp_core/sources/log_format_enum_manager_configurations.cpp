#include "pch.hpp"

#include "../includes/log_format_enum_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{   
	LogFormatEnumManagerConfigurations
		::LogFormatEnumManagerConfigurations() :
			AbstractConfigurations<LogFormatEnumManagerConfigurations>()
	{
		type =
			LogFormat
				::STANDARD;
	}

	LogFormatEnumManagerConfigurations
		LogFormatEnumManagerConfigurations
			::initial_configurations;

	LogFormatEnumManagerConfigurations
		LogFormatEnumManagerConfigurations
			::default_configurations =
				LogFormatEnumManagerConfigurations
					::initial_configurations;
}
