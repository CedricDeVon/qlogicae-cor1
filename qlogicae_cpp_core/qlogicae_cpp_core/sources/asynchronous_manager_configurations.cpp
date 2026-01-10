#include "pch.hpp"

#include "../includes/asynchronous_manager_configurations.hpp"

namespace QLogicaeCppCore
{
    bool
        AsynchronousManagerConfigurations::initial_is_enabled =
            true;

    bool
        AsynchronousManagerConfigurations::default_is_enabled =
            AsynchronousManagerConfigurations::initial_is_enabled;

    bool
        AsynchronousManagerConfigurations::cache_is_enabled =
            AsynchronousManagerConfigurations::initial_is_enabled;
    


    bool
        AsynchronousManagerConfigurations::cache_boolean_1 =
            false;

    AsynchronousManagerConfigurations
        AsynchronousManagerConfigurations::cache;



    bool
        AsynchronousManagerConfigurations::construct()
    {
        _handle_construct();

        return
            cache_boolean_1;
    }

    bool
        AsynchronousManagerConfigurations::destruct()
    {
        _handle_destruct();

        return
            cache_boolean_1;
    }

    bool
        AsynchronousManagerConfigurations::setup(
            const AsynchronousManagerConfigurations&
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
        AsynchronousManagerConfigurations::setup()
    {
        cache =
            {};

        _handle_setup();

        return
            cache_boolean_1;
    }

    bool
        AsynchronousManagerConfigurations::reset()
    {
        _handle_reset();

        return
            cache_boolean_1;
    }

    void
        AsynchronousManagerConfigurations::_handle_construct()
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
        AsynchronousManagerConfigurations::_handle_destruct()
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
        AsynchronousManagerConfigurations::_handle_setup()
    {
        try
        {
            default_is_enabled =
                cache_is_enabled =
                cache.is_enabled;

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
        AsynchronousManagerConfigurations::_handle_reset()
    {
        try
        {
            default_is_enabled =
                cache_is_enabled =
                initial_is_enabled;

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
