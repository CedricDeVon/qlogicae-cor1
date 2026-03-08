#include "pch.hpp"

#include "../includes/qlogicae_desktop_application_manager.hpp"

namespace
	QLogicaeCppCore
{        
	QLogicaeDesktopApplicationManager&
		QLogicaeDesktopApplicationManager
			::singleton = 
				SingletonManager
					::get_singleton<QLogicaeDesktopApplicationManager>();	


	
	QLogicaeDesktopApplicationManager
		::QLogicaeDesktopApplicationManager() :
			AbstractClass<QLogicaeDesktopApplicationManagerConfigurations>()
    {
        
    }
}
