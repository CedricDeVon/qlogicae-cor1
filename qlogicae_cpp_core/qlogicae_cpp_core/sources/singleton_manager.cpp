#include "pch.hpp"

#include "../includes/singleton_manager.hpp"

namespace
	QLogicaeCppCore
{               
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
		static SingletonManager
			singleton;

		return
			singleton;
	}
}

