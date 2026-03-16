#include "pch.hpp"

#include "../includes/time_format_enum_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{   
	TimeFormatEnumManagerConfigurations
		::TimeFormatEnumManagerConfigurations() :
			AbstractConfigurations<TimeFormatEnumManagerConfigurations>()
	{
		type =
			TimeFormat
				::FULL_TIMESTAMP;
	}

	TimeFormatEnumManagerConfigurations
		TimeFormatEnumManagerConfigurations
			::initial_configurations;

	TimeFormatEnumManagerConfigurations
		TimeFormatEnumManagerConfigurations
			::default_configurations =
				TimeFormatEnumManagerConfigurations
					::initial_configurations;
}
