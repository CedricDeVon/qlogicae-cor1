#pragma once

#include "log_format.hpp"
#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{
	struct
		LogFormatEnumManagerConfigurations :
			AbstractConfigurations<LogFormatEnumManagerConfigurations>
	{
	public:	
		LogFormat
			type =
				default_configurations
					.type;

		static LogFormatEnumManagerConfigurations
			initial_configurations;

		static LogFormatEnumManagerConfigurations
			default_configurations;

		LogFormatEnumManagerConfigurations();
	};
}
