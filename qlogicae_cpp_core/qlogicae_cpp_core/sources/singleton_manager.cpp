#include "pch.hpp"

#include "../includes/singleton_manager.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{               
	SingletonManager
		::SingletonManager()
    {
        
    }

    SingletonManager
		::~SingletonManager()
    {
        
    }

    bool
        SingletonManager
			::construct()
    {       
		boost::unique_lock<boost::mutex>
			mutex_lock;
		if (configurations.is_thread_safety_enabled_for_utility_handling())
		{
			mutex_lock =
				boost::unique_lock<boost::mutex>
				(
					feature_handling_mutex_1
				);
		}			

		return
			true;
    }

    bool
        SingletonManager
			::destruct()
    {       
		boost::unique_lock<boost::mutex>
			mutex_lock;
		if (configurations.is_thread_safety_enabled_for_utility_handling())
		{
			mutex_lock =
				boost::unique_lock<boost::mutex>
				(
					feature_handling_mutex_1
				);
		}			

		return
			true;
    }

	bool
        SingletonManager
			::setup(
				const SingletonManagerConfigurations&
					new_configurations
			)
    {        
		boost::unique_lock<boost::mutex>
			mutex_lock;
		if (configurations.is_thread_safety_enabled_for_utility_handling())
		{
			mutex_lock =
				boost::unique_lock<boost::mutex>
				(
					feature_handling_mutex_1
				);
		}	

		configurations =
			new_configurations;		

		return
			true;
    }

    bool
        SingletonManager
			::reset()
    {       
		boost::unique_lock<boost::mutex>
			mutex_lock;
		if (configurations.is_thread_safety_enabled_for_utility_handling())
		{
			mutex_lock =
				boost::unique_lock<boost::mutex>
				(
					feature_handling_mutex_1
				);
		}			

		SingletonManagerConfigurations
			new_configurations;

		configurations =
			new_configurations;

		return
			true;
    }

	SingletonManagerConfigurations
		SingletonManager
			::configurations;

	boost::mutex
		SingletonManager
			::feature_handling_mutex_1;
	
	SingletonManager&
		SingletonManager
			::get_this_singleton()
	{		
		boost::unique_lock<boost::mutex>
			mutex_lock;
		if (configurations.is_thread_safety_enabled_for_feature_handling())
		{
			mutex_lock =
				boost::unique_lock<boost::mutex>
				(
					feature_handling_mutex_1
				);
		}

		static SingletonManager
			singleton;

		return
			singleton;
	}
}
