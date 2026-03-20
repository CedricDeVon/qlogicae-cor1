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
				LogOutput
					::ALL;

		LogOutputEnumManagerConfigurations();
	};
}
