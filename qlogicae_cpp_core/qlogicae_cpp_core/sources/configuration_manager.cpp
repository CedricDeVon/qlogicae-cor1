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
		::ConfigurationManager()
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
			ErrorManager::singleton
				.handle_error_outputs(
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
			ErrorManager::singleton
				.handle_error_outputs(
					exception
				);
		}		
	}

	bool
		ConfigurationManager
			::construct()
	{
		try
		{
			return
				true;
		}
		catch
		(
			const std::exception&
				exception
		)
		{
			return
				ErrorManager::singleton
					.handle_error_outputs(
						exception
				);
		}
	}

	bool
		ConfigurationManager
			::destruct()
	{
		try
		{
			return
				true;
		}
		catch
		(
			const std::exception&
				exception
		)
		{
			return
				ErrorManager::singleton
					.handle_error_outputs(
						exception
				);
		}
	}

	bool
		ConfigurationManager
			::setup(
				const ConfigurationManagerConfigurations&
					new_configurations
			)
	{
		try
		{
			configurations =
				new_configurations;

			return
				true;
		}
		catch
		(
			const std::exception&
				exception
		)
		{
			return
				ErrorManager::singleton
					.handle_error_outputs(
						exception
				);
		}
	}

	bool
		ConfigurationManager
			::reset()
	{
		try
		{
			configurations =
				{};

			return
				true;
		}
		catch
		(
			const std::exception&
				exception
		)
		{
			return
				ErrorManager::singleton
					.handle_error_outputs(
						exception
				);
		}
	}   
}
