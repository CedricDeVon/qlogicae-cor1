#include "pch.hpp"

#include "../includes/singleton_manager.hpp"

namespace QLogicaeCppCore
{    
    bool
        SingletonManager::cache_is_successful =
            false;  

    std::exception
        SingletonManager::cache_exception =
            {};

    SingletonManager&
        SingletonManager::singleton =
            SingletonManager::get_this_singleton();



    SingletonManager::SingletonManager()
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
            cache_exception =
                exception;

            _handle_error();
        }        
    }

    SingletonManager::~SingletonManager()
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
            cache_exception =
                exception;

            _handle_error();
        }
    }

    bool
        SingletonManager::construct()
    {
        _construct();

        return
            cache_is_successful;
    }

    void
        SingletonManager::_construct()
    {
        try
        {
            cache_is_successful =
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            cache_exception =
                exception;

            _handle_error();
        }
    }

    bool
        SingletonManager::destruct()
    {
        _destruct();

        return
            cache_is_successful;
    }

    void
        SingletonManager::_destruct()
    {
        try
        {
            cache_is_successful =
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            cache_exception =
                exception;

            _handle_error();
        }
    }

    bool
        SingletonManager::setup()
    {
        _setup();

        return
            cache_is_successful;
    }

    void
        SingletonManager::_setup()
    {
        try
        {
            cache_is_successful =
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            cache_exception =
                exception;

            _handle_error();
        }
    }

    bool
        SingletonManager::reset()
    {
        _reset();

        return cache_is_successful;
    }

    void
        SingletonManager::_reset()
    {
        try
        {
            cache_is_successful =
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            cache_exception =
                exception;

            _handle_error();
        }
    }

    bool
        SingletonManager::handle_error(
            const std::exception&
                exception
        )
    {
        cache_exception =
            exception;

        _handle_error();

        return
            cache_is_successful;
    }

    void
        SingletonManager::_handle_error()
    {
        try
        {
            std::cout << cache_exception.what() << "\n";

            cache_is_successful =
                false;
        }
        catch (...)
        {
            cache_is_successful =
                false;
        }
    }

    SingletonManager&
        SingletonManager::get_this_singleton()
    {
        static SingletonManager
            singleton;

        return
            singleton;
    }
}
