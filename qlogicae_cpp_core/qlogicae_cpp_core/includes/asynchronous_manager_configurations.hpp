#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{    
    struct
		AsynchronousManagerConfigurations :
			AbstractConfigurations<AsynchronousManagerConfigurations>
    {
		static AsynchronousManagerConfigurations
			initial_configurations;

		static AsynchronousManagerConfigurations
			default_configurations;
    };    
}
