#include "pch.hpp"

#include "../includes/asynchronous_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    AsynchronousManagerConfigurations
		AsynchronousManagerConfigurations
			::initial_configurations =
				[]()
				{
					AsynchronousManagerConfigurations
						configurations;

					configurations
						.is_feature_handling_thread_safety_enabled =
							true;

					return
						configurations;
				}();

	AsynchronousManagerConfigurations
		AsynchronousManagerConfigurations
			::default_configurations =
				AsynchronousManagerConfigurations
					::initial_configurations;
}

