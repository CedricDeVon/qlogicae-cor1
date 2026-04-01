#pragma once

#include "abstract_class.hpp"
#include "state_manager_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
    class
		StateManager :
			public AbstractClass<StateManagerConfigurations>
    {
    public:		
		StateManager();
    };
}
