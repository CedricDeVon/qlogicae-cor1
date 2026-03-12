#pragma once

#include "log_medium.hpp"
#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
	struct
		LogMediumEnumManagerConfigurations :
			AbstractConfigurations<LogMediumEnumManagerConfigurations>
	{
	public:	
		LogMedium
			type =
				default_configurations
					.type;

		static LogMediumEnumManagerConfigurations
			initial_configurations;

		static LogMediumEnumManagerConfigurations
			default_configurations;

		LogMediumEnumManagerConfigurations();
	};
}
