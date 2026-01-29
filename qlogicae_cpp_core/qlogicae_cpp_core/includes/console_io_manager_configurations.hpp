#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{
    struct
		ConsoleIoManagerConfigurations :
			AbstractConfigurations<ConsoleIoManagerConfigurations>
    {
	public:			
		static ConsoleIoManagerConfigurations
			initial_configurations;

		static ConsoleIoManagerConfigurations
			default_configurations;
    };
}
