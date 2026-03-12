#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
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

		ConsoleIoManagerConfigurations();
    };
}

