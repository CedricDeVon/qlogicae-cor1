#include "pch.hpp"

#include "../includes/application_manager.hpp"

namespace
	QLogicaeCppCore
{
    ApplicationManager&
        ApplicationManager
			::singleton =
				SingletonManager
					::get_singleton<ApplicationManager>();



    ApplicationManager
		::ApplicationManager() :
			AbstractClass<ApplicationManagerConfigurations>()
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
			handle_error_outputs(
				exception
			);
        }        
    }
}
