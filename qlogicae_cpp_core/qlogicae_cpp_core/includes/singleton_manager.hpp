#pragma once

#include "abstract_class.hpp"
#include "singleton_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{        
    class
		SingletonManager :
			public AbstractClass<SingletonManagerConfigurations>
    {
    public:          
		static boost::mutex
			feature_handling_mutex_2;

		static SingletonManager&
			singleton;

		SingletonManager();

		~SingletonManager();

		bool
			construct();

		bool
			destruct();

		template <typename Type> static Type&
			get_singleton();

		static SingletonManager&
			get_this_singleton();		
    };

    template <typename Type> Type&
        SingletonManager
			::get_singleton()
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

        static Type
            singleton;		  

        return
            singleton;
    }    
}

