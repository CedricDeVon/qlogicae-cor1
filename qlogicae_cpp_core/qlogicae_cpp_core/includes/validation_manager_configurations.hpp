#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{
	struct
		ValidationManagerConfigurations :
			AbstractConfigurations<ValidationManagerConfigurations>
	{
	public:	
		static ValidationManagerConfigurations
			initial_configurations;

		static ValidationManagerConfigurations
			default_configurations;
	};
}
