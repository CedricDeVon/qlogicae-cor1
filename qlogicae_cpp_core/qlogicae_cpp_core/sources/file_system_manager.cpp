#include "pch.hpp"

#include "../includes/file_system_manager.hpp"

namespace QLogicaeCppCore
{
    FileSystemManager&
        FileSystemManager::singleton =
            SingletonManager::get_singleton<FileSystemManager>();

    FileSystemManager::FileSystemManager()
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

    FileSystemManager::~FileSystemManager()
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
        FileSystemManager::construct()
    {
        _construct();

        return
            ValueCache::boolean_1;
    }

    void
        FileSystemManager::_construct()
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
        FileSystemManager::destruct()
    {
        _destruct();

        return
            ValueCache::boolean_1;
    }

    void
        FileSystemManager::_destruct()
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
        FileSystemManager::setup(
            const FileSystemManagerConfigurations&
                    new_configurations
        )
    {        
        FileSystemManagerConfigurations::cache =
            new_configurations;

        _setup();

        return
            ValueCache::boolean_1;
    }

    bool
        FileSystemManager::setup()
    {
        FileSystemManagerConfigurations::cache =
            {};

        _setup();

        return
            ValueCache::boolean_1;
    }

    void
        FileSystemManager::_setup()
    {
        try
        {
            FileSystemManagerUtilities::singleton
                ._setup();
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
        _reset();

        return
            ValueCache::boolean_1;
    }

    void
        FileSystemManager::_reset()
    {
        try
        {
            FileSystemManagerUtilities::singleton
                ._reset();
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
