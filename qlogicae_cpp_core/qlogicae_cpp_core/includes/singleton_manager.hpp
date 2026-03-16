#pragma once

#include "singleton_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{        
    class
		SingletonManager
    {
    public:     
		SingletonManagerConfigurations
			configurations;

		boost::mutex
			feature_handling_mutex_1;
     
		SingletonManager();

		~SingletonManager();

		bool
			construct();

		bool
			destruct();

		bool
			setup(
				const SingletonManagerConfigurations&
					new_configurations
			);

		bool
			reset();

		template <typename Type> static Type&
			get_singleton();

		static SingletonManager&
			get_this_singleton();		
    };

    template <typename Type> Type&
        SingletonManager
			::get_singleton()
    {						
        static Type
            singleton;		  

        return
            singleton;
    }    
}
