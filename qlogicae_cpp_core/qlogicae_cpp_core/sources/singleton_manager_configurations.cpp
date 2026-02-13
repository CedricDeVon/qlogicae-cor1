#include "pch.hpp"

#include "../includes/singleton_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{   
	SingletonManagerConfigurations
		::SingletonManagerConfigurations() :
			AbstractConfigurations<SingletonManagerConfigurations>()
	{
		
	}

	SingletonManagerConfigurations
		SingletonManagerConfigurations
			::initial_configurations;

	SingletonManagerConfigurations
		SingletonManagerConfigurations
			::default_configurations =
				SingletonManagerConfigurations
					::initial_configurations;
}

