#include "pch.hpp"

#include "../includes/qlogicae_console_application_manager.hpp"

namespace
	QLogicaeCppCore
{        
	QLogicaeConsoleApplicationManager&
		QLogicaeConsoleApplicationManager
			::singleton = 
				SingletonManager
					::get_singleton<QLogicaeConsoleApplicationManager>();	


	
	QLogicaeConsoleApplicationManager
		::QLogicaeConsoleApplicationManager() :
			AbstractClass<QLogicaeConsoleApplicationManagerConfigurations>()
    {
        
    }
}
