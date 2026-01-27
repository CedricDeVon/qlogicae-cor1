#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{
    struct
		ConsoleManagerConfigurations :
			AbstractConfigurations<ConsoleManagerConfigurations>
    {
	public:			
		static ConsoleManagerConfigurations
			initial_configurations;

		static ConsoleManagerConfigurations
			default_configurations;
    };
}
