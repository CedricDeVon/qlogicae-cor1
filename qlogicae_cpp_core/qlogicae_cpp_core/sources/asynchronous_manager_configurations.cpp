#include "pch.hpp"

#include "../includes/asynchronous_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
	AsynchronousManagerConfigurations
		::AsynchronousManagerConfigurations() :
			AbstractConfigurations<AsynchronousManagerConfigurations>()
	{
		is_feature_thread_safety_handling_enabled =
			true;
	}

    AsynchronousManagerConfigurations
		AsynchronousManagerConfigurations
			::initial_configurations;

	AsynchronousManagerConfigurations
		AsynchronousManagerConfigurations
			::default_configurations =
				AsynchronousManagerConfigurations
					::initial_configurations;
}
