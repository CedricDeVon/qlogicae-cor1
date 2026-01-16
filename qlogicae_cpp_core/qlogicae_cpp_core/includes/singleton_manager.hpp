#pragma once

#include "error_manager.hpp"
#include "singleton_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{        
    class
		SingletonManager
    {
    public:          
		SingletonManagerConfigurations
			configurations;

		static SingletonManager&
			singleton;

        SingletonManager();

		~SingletonManager();

		bool
			construct();

		bool
			destruct();

		bool
			setup(
				const SingletonManagerConfigurations&
					new_configurations =
						{}
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
