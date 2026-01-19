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
			construct() override;

		bool
			destruct() override;

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
