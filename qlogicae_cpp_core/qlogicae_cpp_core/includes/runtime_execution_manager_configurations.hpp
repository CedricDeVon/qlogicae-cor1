#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{    
    struct
		RuntimeExecutionManagerConfigurations :
			AbstractConfigurations<RuntimeExecutionManagerConfigurations>
    {
	public:
		static RuntimeExecutionManagerConfigurations
			initial_configurations;

		static RuntimeExecutionManagerConfigurations
			default_configurations;
    };    
}
