#include "pch.hpp"

#include "../includes/singleton_manager.hpp"

namespace
	QLogicaeCppCore
{               
	boost::mutex
		SingletonManager
			::feature_handling_mutex_2;

    SingletonManager&
        SingletonManager
			::singleton =
				SingletonManager
					::get_this_singleton();

	SingletonManager
		::SingletonManager() :
			AbstractClass<SingletonManagerConfigurations>()
	{
			
	}

	SingletonManager&
		SingletonManager
			::get_this_singleton()
	{
		boost::unique_lock<boost::mutex>
			mutex_lock;
		if
		(
			SingletonManagerConfigurations
				::default_configurations
					.is_thread_safety_enabled_for_feature_handling()
		)
		{
			mutex_lock =
				boost::unique_lock<boost::mutex>
				(
					feature_handling_mutex_2
				);
		}

		static SingletonManager
			singleton;

		return
			singleton;
	}
}
