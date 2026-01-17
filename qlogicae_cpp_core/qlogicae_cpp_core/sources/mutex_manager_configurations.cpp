#include "pch.hpp"

#include "../includes/mutex_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{   
	MutexManagerConfigurations
		MutexManagerConfigurations
			::initial_configurations =
				{
					.name =
						"static",	
				
					.is_enabled =
						true,

					.is_thread_safety_enabled =
						false,
				};

	MutexManagerConfigurations
		MutexManagerConfigurations
			::default_configurations =
				MutexManagerConfigurations
					::initial_configurations;
}
