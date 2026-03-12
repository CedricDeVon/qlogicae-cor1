#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
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

		RuntimeExecutionManagerConfigurations();
    };    
}

