#include "pch.hpp"

#include "../includes/application_manager.hpp"

namespace QLogicaeCppCore
{
    ApplicationManager&
        ApplicationManager::singleton =
            SingletonManager::get_singleton<ApplicationManager>();

    ApplicationManager::ApplicationManager()
    {
        _construct();
    }

    ApplicationManager::~ApplicationManager()
    {
        _destruct();
    }

    bool
        ApplicationManager::construct()
    {
        _construct();

        return
            ValueCache::boolean_1;
    }

    void
        ApplicationManager::_construct()
    {
        try
        {
            ValueCache::boolean_1 =
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
            ValueCache::boolean_1;
    }

    void
        ApplicationManager::_destruct()
    {
        try
        {
            ValueCache::boolean_1 =
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
            ValueCache::boolean_1;
    }

    void
        ApplicationManager::_setup()
    {
        try
        {
            ValueCache::boolean_1 =
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
            ValueCache::boolean_1;
    }

    void
        ApplicationManager::_reset()
    {
        try
        {
            ValueCache::boolean_1 =
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
