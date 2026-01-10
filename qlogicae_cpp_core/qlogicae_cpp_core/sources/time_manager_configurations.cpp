#include "pch.hpp"

#include "../includes/time_manager_configurations.hpp"

namespace QLogicaeCppCore
{
    bool
        TimeManagerConfigurations::initial_is_enabled =
            true;

    bool
        TimeManagerConfigurations::default_is_enabled =
            TimeManagerConfigurations::initial_is_enabled;

    bool
        TimeManagerConfigurations::cache_is_enabled =
            TimeManagerConfigurations::initial_is_enabled;
    


    bool
        TimeManagerConfigurations::cache_boolean_1 =
            false;

    TimeManagerConfigurations
        TimeManagerConfigurations::cache;



    bool
        TimeManagerConfigurations::construct()
    {
        _handle_construct();

        return
            cache_boolean_1;
    }

    bool
        TimeManagerConfigurations::destruct()
    {
        _handle_destruct();

        return
            cache_boolean_1;
    }

    bool
        TimeManagerConfigurations::setup(
            const TimeManagerConfigurations&
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
        TimeManagerConfigurations::setup()
    {
        cache =
            {};

        _handle_setup();

        return
            cache_boolean_1;
    }

    bool
        TimeManagerConfigurations::reset()
    {
        _handle_reset();

        return
            cache_boolean_1;
    }

    void
        TimeManagerConfigurations::_handle_construct()
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
        TimeManagerConfigurations::_handle_destruct()
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
        TimeManagerConfigurations::_handle_setup()
    {
        try
        {
            TimeManagerConfigurations::default_is_enabled =
                TimeManagerConfigurations::cache_is_enabled =
                TimeManagerConfigurations::cache.is_enabled;

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
        TimeManagerConfigurations::_handle_reset()
    {
        try
        {
            TimeManagerConfigurations::default_is_enabled =
                TimeManagerConfigurations::cache_is_enabled =
                TimeManagerConfigurations::initial_is_enabled;

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
