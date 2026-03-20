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
				LogMedium
					::ALL;

		LogMediumEnumManagerConfigurations();
	};
}
