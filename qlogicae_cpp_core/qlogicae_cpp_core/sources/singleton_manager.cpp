#include "pch.hpp"

#include "../includes/singleton_manager.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{               
	SingletonManager
		::SingletonManager()
    {
        construct();
    }

    SingletonManager
		::~SingletonManager()
    {
        destruct();
    }

    bool
        SingletonManager
			::construct()
    {       
		QLOGICAE_COR_V1__BASE__HPP_CPP__THREAD_SAFETY_GUARD_TEMPLATE
		(
			QLOGICAE_COR_V1__BASE__HPP_CPP__MUTEX_LAYER_1
		);			

		return
			true;
    }

    bool
        SingletonManager
			::destruct()
    {       
		QLOGICAE_COR_V1__BASE__HPP_CPP__THREAD_SAFETY_GUARD_TEMPLATE
		(
			QLOGICAE_COR_V1__BASE__HPP_CPP__MUTEX_LAYER_1
		);			

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
		QLOGICAE_COR_V1__BASE__HPP_CPP__THREAD_SAFETY_GUARD_TEMPLATE
		(
			QLOGICAE_COR_V1__BASE__HPP_CPP__MUTEX_LAYER_1
		);	

		configurations =
			new_configurations;		

		return
			true;
    }

    bool
        SingletonManager
			::reset()
    {       
		QLOGICAE_COR_V1__BASE__HPP_CPP__THREAD_SAFETY_GUARD_TEMPLATE
		(
			QLOGICAE_COR_V1__BASE__HPP_CPP__MUTEX_LAYER_1
		);	

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
		QLOGICAE_COR_V1__BASE__HPP_CPP__THREAD_SAFETY_GUARD_TEMPLATE
		(
			QLOGICAE_COR_V1__BASE__HPP_CPP__MUTEX_LAYER_1
		);

		static SingletonManager
			singleton;

		return
			singleton;
	}
}
