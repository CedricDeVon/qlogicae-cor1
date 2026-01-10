#include "pch.hpp"

#include "../includes/file_system_manager_configurations.hpp"

namespace QLogicaeCppCore
{    
    bool
        FileSystemManagerConfigurations::cache_boolean_1 =
            false;

    FileSystemManagerConfigurations
        FileSystemManagerConfigurations::cache;



    bool
        FileSystemManagerConfigurations::construct()
    {
        _handle_construct();

        return
            cache_boolean_1;
    }

    bool
        FileSystemManagerConfigurations::destruct()
    {
        _handle_destruct();

        return
            cache_boolean_1;
    }

    bool
        FileSystemManagerConfigurations::setup(
            const FileSystemManagerConfigurations&
                    new_configurations
        )
    {
        cache =
            new_configurations;

        _handle_setup();

        return
            cache_boolean_1;
    }

    bool
        FileSystemManagerConfigurations::setup()
    {
        cache =
            {};

        _handle_setup();

        return
            cache_boolean_1;
    }

    bool
        FileSystemManagerConfigurations::reset()
    {
        _handle_reset();

        return
            cache_boolean_1;
    }

    void
        FileSystemManagerConfigurations::_handle_construct()
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

    void
        FileSystemManagerConfigurations::_handle_destruct()
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

    void
        FileSystemManagerConfigurations::_handle_setup()
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

    void
        FileSystemManagerConfigurations::_handle_reset()
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
    };
}
