#pragma once

#include "log_output.hpp"
#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
	struct
		LogOutputEnumManagerConfigurations :
			AbstractConfigurations<LogOutputEnumManagerConfigurations>
	{
	public:	
		LogOutput
			type =
				default_configurations
					.type;

		static LogOutputEnumManagerConfigurations
			initial_configurations;

		static LogOutputEnumManagerConfigurations
			default_configurations;

		LogOutputEnumManagerConfigurations();
	};
}
