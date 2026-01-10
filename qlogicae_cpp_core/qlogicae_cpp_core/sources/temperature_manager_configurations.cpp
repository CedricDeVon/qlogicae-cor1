#include "pch.hpp"

#include "../includes/temperature_manager_configurations.hpp"

namespace QLogicaeCppCore
{
    double
        TemperatureManagerConfigurations::initial_value =
            0.0;

    TemperatureUnitType
        TemperatureManagerConfigurations::initial_from_unit_type =
            TemperatureUnitType::CELSIUS;

    TemperatureUnitType
        TemperatureManagerConfigurations::initial_to_unit_type =
            TemperatureUnitType::CELSIUS;

    bool
        TemperatureManagerConfigurations::initial_is_enabled =
            true;



    double
        TemperatureManagerConfigurations::default_value =
            TemperatureManagerConfigurations::initial_value;

    TemperatureUnitType
        TemperatureManagerConfigurations::default_from_unit_type =
            TemperatureManagerConfigurations::initial_from_unit_type;

    TemperatureUnitType
        TemperatureManagerConfigurations::default_to_unit_type =
            TemperatureManagerConfigurations::initial_to_unit_type;

    bool
        TemperatureManagerConfigurations::default_is_enabled =
            TemperatureManagerConfigurations::initial_is_enabled;




    double
        TemperatureManagerConfigurations::cache_value =
            TemperatureManagerConfigurations::initial_value;

    TemperatureUnitType
        TemperatureManagerConfigurations::cache_from_unit_type =
            TemperatureManagerConfigurations::initial_from_unit_type;

    TemperatureUnitType
        TemperatureManagerConfigurations::cache_to_unit_type =
            TemperatureManagerConfigurations::initial_to_unit_type;

    bool
        TemperatureManagerConfigurations::cache_is_enabled =
            TemperatureManagerConfigurations::initial_is_enabled;



    bool
        TemperatureManagerConfigurations::cache_boolean_1 =
            false;

    TemperatureManagerConfigurations
        TemperatureManagerConfigurations::cache;



    bool
        TemperatureManagerConfigurations::construct()
    {
        _handle_construct();

        return
            cache_boolean_1;
    }

    bool
        TemperatureManagerConfigurations::destruct()
    {
        _handle_destruct();

        return
            cache_boolean_1;
    }

    bool
        TemperatureManagerConfigurations::setup(
            const TemperatureManagerConfigurations&
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
        TemperatureManagerConfigurations::setup()
    {
        cache =
            {};

        _handle_setup();

        return
            cache_boolean_1;
    }

    bool
        TemperatureManagerConfigurations::reset()
    {
        _handle_reset();

        return
            cache_boolean_1;
    }

    void
        TemperatureManagerConfigurations::_handle_construct()
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
        TemperatureManagerConfigurations::_handle_destruct()
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
        TemperatureManagerConfigurations::_handle_setup()
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
            cache_boolean_1 =
                false;

            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        TemperatureManagerConfigurations::_handle_reset()
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
            cache_boolean_1 =
                false;

            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }
}
