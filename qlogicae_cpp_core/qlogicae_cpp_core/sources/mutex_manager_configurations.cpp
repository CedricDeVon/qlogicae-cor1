#include "pch.hpp"

#include "../includes/mutex_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{   
	MutexManagerConfigurations
		::MutexManagerConfigurations() :
			AbstractConfigurations<MutexManagerConfigurations>()
	{
		is_feature_thread_safety_handling_enabled =
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
