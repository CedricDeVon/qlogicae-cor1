#include "pch.hpp"

#include "../includes/runtime_execution_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    RuntimeExecutionManagerConfigurations
		RuntimeExecutionManagerConfigurations
			::initial_configurations =
				[]()
				{
					RuntimeExecutionManagerConfigurations
						configurations;

					return
						configurations;
				}();

	RuntimeExecutionManagerConfigurations
		RuntimeExecutionManagerConfigurations
			::default_configurations =
				RuntimeExecutionManagerConfigurations
					::initial_configurations;
}

