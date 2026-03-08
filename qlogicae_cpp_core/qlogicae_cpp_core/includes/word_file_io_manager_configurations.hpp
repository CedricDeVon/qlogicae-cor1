#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{    
    struct
		WordFileIoManagerConfigurations :
			AbstractConfigurations<WordFileIoManagerConfigurations>
    {
	public:
		static WordFileIoManagerConfigurations
			initial_configurations;

		static WordFileIoManagerConfigurations
			default_configurations;

		WordFileIoManagerConfigurations();
    };    
}
