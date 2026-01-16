#include "pch.hpp"

#include "../includes/application_manager.hpp"

namespace QLogicaeCppCore
{
    ApplicationManager&
        ApplicationManager
			::singleton =
				SingletonManager
					::get_singleton<ApplicationManager>();



    ApplicationManager
		::ApplicationManager()
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

    ApplicationManager
		::~ApplicationManager()
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
		ApplicationManager
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
		ApplicationManager
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
		ApplicationManager
			::setup()
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
		ApplicationManager
			::reset()
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
}
