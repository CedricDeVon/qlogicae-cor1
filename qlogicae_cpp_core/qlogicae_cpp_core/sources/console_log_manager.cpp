#include "pch.hpp"

#include "../includes/console_log_manager.hpp"

namespace
	QLogicaeCppCore
{        
	ConsoleLogManager&
		ConsoleLogManager
			::singleton = 
				SingletonManager
					::get_singleton<ConsoleLogManager>();	


	
	ConsoleLogManager
		::ConsoleLogManager() :
			AbstractClass<ConsoleLogManagerConfigurations>()
    {

    }
}

