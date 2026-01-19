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
						.is_feature_handling_enabled =
							true;
					
					configurations
						.is_error_handling_enabled =
							true;

					configurations
						.is_thread_safety_override_enabled =
							false;

					configurations
						.is_feature_handling_thread_safety_enabled =
							true;

					configurations
						.is_utility_handling_thread_safety_enabled =
							true;

					configurations
						.is_error_handling_thread_safety_enabled =
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

