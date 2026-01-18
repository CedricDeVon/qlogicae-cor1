#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{   
    struct
		SingletonManagerConfigurations :
			AbstractConfigurations<SingletonManagerConfigurations>
    {
		static SingletonManagerConfigurations
			initial_configurations;

		static SingletonManagerConfigurations
			default_configurations;
    };    
}
