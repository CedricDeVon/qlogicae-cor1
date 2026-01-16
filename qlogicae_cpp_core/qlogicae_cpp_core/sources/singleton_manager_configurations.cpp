#include "pch.hpp"

#include "../includes/singleton_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{   
	SingletonManagerConfigurations
		SingletonManagerConfigurations
			::initial_configurations =
				{
					.is_enabled =
						true,

					.is_thread_safety_enabled =
						false,
				};

	SingletonManagerConfigurations
		SingletonManagerConfigurations
			::default_configurations =
				SingletonManagerConfigurations
					::initial_configurations;
}
