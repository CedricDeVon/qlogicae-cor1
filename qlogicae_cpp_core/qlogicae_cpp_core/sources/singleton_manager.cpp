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
		try
		{
			construct();
		}
		catch
		(
			const std::exception&
				exception
		)
		{
			handle_error_outputs(
				exception
			);
		}		
	}

	SingletonManager
		::~SingletonManager()
	{
		try
		{
			destruct();
		}
		catch
		(
			const std::exception&
				exception
		)
		{
			handle_error_outputs(
				exception
			);
		}		
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

