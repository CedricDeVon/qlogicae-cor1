#include "pch.hpp"

#include "../includes/application_manager.hpp"

namespace QLogicaeCppCore
{
    ApplicationManager&
        ApplicationManager::singleton =
            SingletonManager::get_singleton<ApplicationManager>();

    ApplicationManager::ApplicationManager()
    {
        try
        {
            _construct();
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }        
    }

    ApplicationManager::~ApplicationManager()
    {
        try
        {
            _destruct();
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }        
    }

    bool
        ApplicationManager::construct()
    {
        _construct();

        return
            cache_boolean_1;
    }

    void
        ApplicationManager::_construct()
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
            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    bool
        ApplicationManager::destruct()
    {
        _destruct();

        return
            cache_boolean_1;
    }

    void
        ApplicationManager::_destruct()
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
            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    bool
        ApplicationManager::setup()
    {
        _setup();

        return
            cache_boolean_1;
    }

    void
        ApplicationManager::_setup()
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
            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    bool
        ApplicationManager::reset()
    {
        _reset();

        return
            cache_boolean_1;
    }

    void
        ApplicationManager::_reset()
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
            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }
}
