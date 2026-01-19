#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{
	struct
		TimeManagerConfigurations :
			AbstractConfigurations<TimeManagerConfigurations>
	{
	public:
		static TimeManagerConfigurations
			initial_configurations;

		static TimeManagerConfigurations
			default_configurations;
	};
}
