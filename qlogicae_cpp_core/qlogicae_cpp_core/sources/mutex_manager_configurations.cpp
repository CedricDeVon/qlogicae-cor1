#include "pch.hpp"

#include "../includes/mutex_manager_configurations.hpp"

namespace QLogicaeCppCore
{   
    void*
        MutexManagerConfigurations::initial_pointer =
            nullptr;

    std::string
        MutexManagerConfigurations::initial_name =
            "static";



    std::string
        MutexManagerConfigurations::default_name =
            MutexManagerConfigurations::initial_name;

    void*
        MutexManagerConfigurations::default_pointer =
            MutexManagerConfigurations::initial_pointer;



    std::string
        MutexManagerConfigurations::cache_name =
            MutexManagerConfigurations::initial_name;

    void*
        MutexManagerConfigurations::cache_pointer =
            MutexManagerConfigurations::initial_pointer;



    bool
        MutexManagerConfigurations::cache_boolean_1 =
            false;

    MutexManagerConfigurations
        MutexManagerConfigurations::cache;



    bool
        MutexManagerConfigurations::construct()
    {
        _handle_construct();

        return
            cache_boolean_1;
    }

    bool
        MutexManagerConfigurations::destruct()
    {
        _handle_destruct();

        return
            cache_boolean_1;
    }

    bool
        MutexManagerConfigurations::setup(
            const MutexManagerConfigurations&
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
        MutexManagerConfigurations::setup()
    {
        cache =
            {};

        _handle_setup();

        return
            cache_boolean_1;
    }

    bool
        MutexManagerConfigurations::reset()
    {
        _handle_reset();

        return
            cache_boolean_1;
    }

    void
        MutexManagerConfigurations::_handle_construct()
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
        MutexManagerConfigurations::_handle_destruct()
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
        MutexManagerConfigurations::_handle_setup()
    {
        try
        {
            default_pointer =
                cache_pointer =
                cache.pointer;

            default_name =
                cache_name =
                cache.name;

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
        MutexManagerConfigurations::_handle_reset()
    {
        try
        {
            default_pointer =
                cache_pointer =
                initial_pointer;

            default_name =
                cache_name =
                initial_name;

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
