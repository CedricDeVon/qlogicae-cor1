#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
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

