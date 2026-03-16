#include "pch.hpp"

#include "../includes/runtime_execution_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
	RuntimeExecutionManagerConfigurations
		::RuntimeExecutionManagerConfigurations() :
			AbstractConfigurations<RuntimeExecutionManagerConfigurations>()
	{
		
	}

	RuntimeExecutionManagerConfigurations
		RuntimeExecutionManagerConfigurations
			::initial_configurations;

	RuntimeExecutionManagerConfigurations
		RuntimeExecutionManagerConfigurations
			::default_configurations =
				RuntimeExecutionManagerConfigurations
					::initial_configurations;
}

