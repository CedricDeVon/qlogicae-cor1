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
        _construct();
    }

    TemperatureManagerUtilities::~TemperatureManagerUtilities()
    {
        _destruct();
    }

    bool
        TemperatureManagerUtilities::construct()
    {
        _construct();

        return
            cache_boolean_1;
    }

    bool
        TemperatureManagerUtilities::destruct()
    {
        _destruct();

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

        _setup();

        return
            cache_boolean_1;
    }

    bool
        TemperatureManagerUtilities::setup()
    {
        TemperatureManagerConfigurations::cache =
            {};

        _setup();

        return
            cache_boolean_1;
    }

    bool
        TemperatureManagerUtilities::reset()
    {
        _reset();

        return
            cache_boolean_1;
    }

    void
        TemperatureManagerUtilities::_construct()
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
        TemperatureManagerUtilities::_destruct()
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
        TemperatureManagerUtilities::_setup()
    {
        try
        {
            TemperatureManagerConfigurations::default_value =
                TemperatureManagerConfigurations::cache_value =
                TemperatureManagerConfigurations::cache.value;

            TemperatureManagerConfigurations::default_is_enabled =
                TemperatureManagerConfigurations::cache_is_enabled =
                TemperatureManagerConfigurations::cache.is_enabled;

            TemperatureManagerConfigurations::default_from_unit_type =
                TemperatureManagerConfigurations::cache_from_unit_type =
                TemperatureManagerConfigurations::cache.from_unit_type;

            TemperatureManagerConfigurations::default_to_unit_type =
                TemperatureManagerConfigurations::cache_to_unit_type =
                TemperatureManagerConfigurations::cache.to_unit_type;

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
        TemperatureManagerUtilities::_reset()
    {
        try
        {
            TemperatureManagerConfigurations::default_value =
                TemperatureManagerConfigurations::cache_value =
                TemperatureManagerConfigurations::initial_value;

            TemperatureManagerConfigurations::default_is_enabled =
                TemperatureManagerConfigurations::cache_is_enabled =
                TemperatureManagerConfigurations::initial_is_enabled;

            TemperatureManagerConfigurations::default_from_unit_type =
                TemperatureManagerConfigurations::cache_from_unit_type =
                TemperatureManagerConfigurations::initial_from_unit_type;

            TemperatureManagerConfigurations::default_to_unit_type =
                TemperatureManagerConfigurations::cache_to_unit_type =
                TemperatureManagerConfigurations::initial_to_unit_type;

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

