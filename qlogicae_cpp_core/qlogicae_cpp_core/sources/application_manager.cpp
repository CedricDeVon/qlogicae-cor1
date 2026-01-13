#include "pch.hpp"

#include "../includes/application_manager.hpp"

namespace QLogicaeCppCore
{
	bool
		ApplicationManager
			::cache_boolean_1 =
				false;

	boost::mutex
		ApplicationManager
			::cache_mutex_1;

    ApplicationManager&
        ApplicationManager
			::singleton =
				SingletonManager
					::get_singleton<ApplicationManager>();



    ApplicationManager::ApplicationManager()
    {
        try
        {
            _handle_construct();
        }
        catch
        (
            const std::exception&
                exception
        )
        {
			cache_boolean_1 =
				false;

            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }        
    }

    ApplicationManager
		::~ApplicationManager()
    {
        try
        {
            _handle_destruct();
        }
        catch
        (
            const std::exception&
                exception
        )
        {
			cache_boolean_1 =
				false;

            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }        
    }

    bool
        ApplicationManager
			::construct()
    {
        _handle_construct();

        return
            cache_boolean_1;
    }

    void
        ApplicationManager
			::_handle_construct()
    {
        try
        {
            cache_boolean_1 =
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
			cache_boolean_1 =
				false;

            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    bool
        ApplicationManager
			::destruct()
    {
        _handle_destruct();

        return
            cache_boolean_1;
    }

    void
        ApplicationManager
			::_handle_destruct()
    {
        try
        {
            cache_boolean_1 =
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
			cache_boolean_1 =
				false;

            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    bool
        ApplicationManager
			::setup()
    {
        _handle_setup();

        return
            cache_boolean_1;
    }

    void
        ApplicationManager
			::_handle_setup()
    {
        try
        {
            cache_boolean_1 =
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
			cache_boolean_1 =
				false;

            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    bool
        ApplicationManager
			::reset()
    {
        _handle_reset();

        return
            cache_boolean_1;
    }

    void
        ApplicationManager
			::_handle_reset()
    {
        try
        {
            cache_boolean_1 =
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
			cache_boolean_1 =
				false;

            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }
}
