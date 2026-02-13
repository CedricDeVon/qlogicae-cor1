#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{    
    struct
		AsynchronousManagerConfigurations :
			AbstractConfigurations<AsynchronousManagerConfigurations>
    {
	public:
		static AsynchronousManagerConfigurations
			initial_configurations;

		static AsynchronousManagerConfigurations
			default_configurations;

		AsynchronousManagerConfigurations();
    };    
}

