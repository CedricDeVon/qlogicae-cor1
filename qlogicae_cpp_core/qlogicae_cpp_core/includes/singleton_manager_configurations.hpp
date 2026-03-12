#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
{   
    struct
		SingletonManagerConfigurations :
			AbstractConfigurations<SingletonManagerConfigurations>
    {
	public:
		static SingletonManagerConfigurations
			initial_configurations;

		static SingletonManagerConfigurations
			default_configurations;

		SingletonManagerConfigurations();
    };    
}
