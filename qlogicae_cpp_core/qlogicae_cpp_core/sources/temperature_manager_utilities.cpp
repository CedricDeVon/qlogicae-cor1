#include "pch.hpp"

#include "../includes/temperature_manager_utilities.hpp"

namespace QLogicaeCppCore
{
    bool
        TemperatureManagerUtilities::cache_boolean_1 =
            false;

    TemperatureManagerUtilities&
        TemperatureManagerUtilities::singleton =
            SingletonManager::get_singleton<TemperatureManagerUtilities>();

    TemperatureManagerUtilities::TemperatureManagerUtilities()
    {
        _handle_construct();
    }

    TemperatureManagerUtilities::~TemperatureManagerUtilities()
    {
        _handle_destruct();
    }

    bool
        TemperatureManagerUtilities::construct()
    {
        _handle_construct();

        return
            cache_boolean_1;
    }

    bool
        TemperatureManagerUtilities::destruct()
    {
        _handle_destruct();

        return
            cache_boolean_1;
    }

    bool
        TemperatureManagerUtilities::setup(
            const TemperatureManagerConfigurations&
            new_configurations
        )
    {
        TemperatureManagerConfigurations::cache =
            new_configurations;

        _handle_setup();

        return
            cache_boolean_1;
    }

    bool
        TemperatureManagerUtilities::setup()
    {
        TemperatureManagerConfigurations::cache =
        {};

        _handle_setup();

        return
            cache_boolean_1;
    }

    bool
        TemperatureManagerUtilities::reset()
    {
        _handle_reset();

        return
            cache_boolean_1;
    }

    void
        TemperatureManagerUtilities::_handle_construct()
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

    void
        TemperatureManagerUtilities::_handle_destruct()
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

    void
        TemperatureManagerUtilities::_handle_setup()
    {
        try
        {
            TemperatureManagerConfigurations::_handle_setup();

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

    void
        TemperatureManagerUtilities::_handle_reset()
    {
        try
        {
            TemperatureManagerConfigurations::_handle_reset();

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

