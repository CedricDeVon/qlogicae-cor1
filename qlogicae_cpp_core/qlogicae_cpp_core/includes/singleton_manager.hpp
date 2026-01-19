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
        static Type
            singleton;		  

        return
            singleton;
    }    
}
