#include "pch.hpp"

#include "../includes/qlogicae_service_application_manager.hpp"

namespace
	QLogicaeCppCore
{        
	QLogicaeServiceApplicationManager&
		QLogicaeServiceApplicationManager
			::singleton = 
				SingletonManager
					::get_singleton<QLogicaeServiceApplicationManager>();	


	
	QLogicaeServiceApplicationManager
		::QLogicaeServiceApplicationManager() :
			AbstractClass<QLogicaeServiceApplicationManagerConfigurations>()
    {
        
    }
}
