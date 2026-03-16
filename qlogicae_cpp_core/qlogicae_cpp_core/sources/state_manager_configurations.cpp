#include "pch.hpp"

#include "../includes/state_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
	StateManagerConfigurations
		::StateManagerConfigurations() :
			AbstractConfigurations<StateManagerConfigurations>()
	{
		
	}

	StateManagerConfigurations
		StateManagerConfigurations
			::initial_configurations;

	StateManagerConfigurations
		StateManagerConfigurations
			::default_configurations =
				StateManagerConfigurations
					::initial_configurations;
}
