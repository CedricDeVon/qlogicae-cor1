#pragma once

#include "time_format.hpp"
#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{
	struct
		TimeFormatEnumManagerConfigurations :
			AbstractConfigurations<TimeFormatEnumManagerConfigurations>
	{
	public:	
		TimeFormat
			type =
				default_configurations
					.type;

		static TimeFormatEnumManagerConfigurations
			initial_configurations;

		static TimeFormatEnumManagerConfigurations
			default_configurations;

		TimeFormatEnumManagerConfigurations();
	};
}
