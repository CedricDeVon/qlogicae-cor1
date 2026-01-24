#include "pch.hpp"

#include "../includes/mutex_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{   
	MutexManagerConfigurations
		MutexManagerConfigurations
			::initial_configurations =
				[]()
				{
					MutexManagerConfigurations
						configurations;

					configurations
						.is_feature_handling_thread_safety_enabled =
							true;

					configurations
						.name =
							"static";

					return
						configurations;
				}();

	MutexManagerConfigurations
		MutexManagerConfigurations
			::default_configurations =
				MutexManagerConfigurations
					::initial_configurations;
}

