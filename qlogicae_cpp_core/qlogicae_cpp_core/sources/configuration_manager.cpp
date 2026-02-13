#include "pch.hpp"

#include "../includes/configuration_manager.hpp"

namespace
	QLogicaeCppCore
{        
	ConfigurationManager&
		ConfigurationManager
			::singleton = 
				SingletonManager
					::get_singleton<ConfigurationManager>();	


	
	ConfigurationManager
		::ConfigurationManager() :
			AbstractClass<ConfigurationManagerConfigurations>()
    {
		
    }
}
