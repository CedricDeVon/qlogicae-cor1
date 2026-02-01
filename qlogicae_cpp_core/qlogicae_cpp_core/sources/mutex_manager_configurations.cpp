#include "pch.hpp"

#include "../includes/mutex_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{   
	MutexManagerConfigurations
		::MutexManagerConfigurations() :
			AbstractConfigurations<MutexManagerConfigurations>()
	{
		is_feature_handling_thread_safety_enabled =
			true;

		name =
			"static";
	}

	MutexManagerConfigurations
		MutexManagerConfigurations
			::initial_configurations;

	MutexManagerConfigurations
		MutexManagerConfigurations
			::default_configurations =
				MutexManagerConfigurations
					::initial_configurations;
}
