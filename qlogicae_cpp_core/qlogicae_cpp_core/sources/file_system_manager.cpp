#include "pch.hpp"

#include "../includes/file_system_manager.hpp"

namespace QLogicaeCppCore
{
    bool
        FileSystemManager::cache_boolean_1 =
            false;

    FileSystemManager&
        FileSystemManager::singleton =
            SingletonManager::get_singleton<FileSystemManager>();

    FileSystemManager::FileSystemManager()
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
            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }        
    }

    FileSystemManager::~FileSystemManager()
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
            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }        
    }

    bool
        FileSystemManager::construct()
    {
        _handle_construct();

        return
            cache_boolean_1;
    }

    void
        FileSystemManager::_handle_construct()
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
        FileSystemManager::destruct()
    {
        _handle_destruct();

        return
            cache_boolean_1;
    }

    void
        FileSystemManager::_handle_destruct()
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
        FileSystemManager::setup(
            const FileSystemManagerConfigurations&
                    new_configurations
        )
    {        
        FileSystemManagerConfigurations::cache =
            new_configurations;

        _handle_setup();

        return
            cache_boolean_1;
    }

    bool
        FileSystemManager::setup()
    {
        FileSystemManagerConfigurations::cache =
            {};

        _handle_setup();

        return
            cache_boolean_1;
    }

    void
        FileSystemManager::_handle_setup()
    {
        try
        {
            FileSystemManagerUtilities::singleton
                ._handle_setup();
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
        FileSystemManager::reset()
    {
        _handle_reset();

        return
            cache_boolean_1;
    }

    void
        FileSystemManager::_handle_reset()
    {
        try
        {
            FileSystemManagerUtilities::singleton
                ._handle_reset();
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
