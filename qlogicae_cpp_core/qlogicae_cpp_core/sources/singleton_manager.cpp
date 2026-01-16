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
		::SingletonManager()
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
			ErrorManager::singleton
				.handle_error_outputs(
					exception
				);
		}		
	}

	bool
		SingletonManager
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
		SingletonManager
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
		SingletonManager
			::setup(
				const SingletonManagerConfigurations&
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
		SingletonManager
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
