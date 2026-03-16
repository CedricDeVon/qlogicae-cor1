#pragma once

#include "abstract_class.hpp"
#include "state_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
    class
		StateManager :
			public AbstractClass<StateManagerConfigurations>
    {
    public:		
		StateManager();
    };
}
