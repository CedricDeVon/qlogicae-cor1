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
	
	ConfigurationManager
		::~ConfigurationManager()
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
}

