#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
{    
    struct
		AsynchronousBatchManagerConfigurations :
			AbstractConfigurations<AsynchronousBatchManagerConfigurations>
    {
	public:
		static AsynchronousBatchManagerConfigurations
			initial_configurations;

		static AsynchronousBatchManagerConfigurations
			default_configurations;

		AsynchronousBatchManagerConfigurations();
    };    
}

