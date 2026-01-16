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
        TemperatureManagerConfigurations::cache_configurations;



    bool
        TemperatureManagerConfigurations::construct(
            const TemperatureManagerConfigurations&
                configurations
        )
    {
        cache_configurations =
            configurations;

        _handle_construct();

        return
            cache_boolean_1;
    }

    bool
        TemperatureManagerConfigurations::destruct(
            const TemperatureManagerConfigurations&
                configurations
        )
    {
        cache_configurations =
            configurations;

        _handle_destruct();

        return
            cache_boolean_1;
    }

    bool
        TemperatureManagerConfigurations::setup(
            const TemperatureManagerConfigurations&
                configurations
        )
    {
        cache_configurations =
            configurations;

        _handle_setup();

        return
            cache_boolean_1;
    }

    bool
        TemperatureManagerConfigurations::reset(
            const TemperatureManagerConfigurations&
                configurations
        )
    {
        cache_configurations =
            configurations;

        _handle_reset();

        return
            cache_boolean_1;
    }
    
    bool
        TemperatureManagerConfigurations::setup_caches(
            const TemperatureManagerConfigurations&
                configurations
        )
    {
        cache_configurations =
            configurations;

        _handle_setup_caches();

        return
            cache_boolean_1;
    }
    
    bool
        TemperatureManagerConfigurations::setup_defaults(
            const TemperatureManagerConfigurations&
                configurations
        )
    {
        cache_configurations =
            configurations;

        _handle_setup_defaults();

        return
            cache_boolean_1;
    }
    
    bool
        TemperatureManagerConfigurations::reset_caches(
            const TemperatureManagerConfigurations&
                configurations
        )
    {
        cache_configurations =
            configurations;

        _handle_reset_caches();

        return
            cache_boolean_1;
    }
    
    bool
        TemperatureManagerConfigurations::reset_defaults(
            const TemperatureManagerConfigurations&
                configurations
        )
    {
        cache_configurations =
            configurations;

        _handle_reset_defaults();

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
            _handle_setup_caches();
            _handle_setup_defaults();

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
            _handle_reset_caches();
            _handle_reset_defaults();

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
        TemperatureManagerConfigurations::_handle_setup_caches()
    {
        try
        {            
            cache_value =
                cache_configurations.value;

            cache_is_enabled =
                cache_configurations.is_enabled;

            cache_from_unit_type =
                cache_configurations.from_unit_type;

            cache_to_unit_type =
                cache_configurations.to_unit_type;

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
        TemperatureManagerConfigurations::_handle_setup_defaults()
    {
        try
        {         
            default_value =
                cache_configurations.value;

            default_is_enabled =
                cache_configurations.is_enabled;

            default_from_unit_type =
                cache_configurations.from_unit_type;

            default_to_unit_type =
                cache_configurations.to_unit_type;

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
        TemperatureManagerConfigurations::_handle_reset_caches()
    {
        try
        {            
            cache_value =
                initial_value;

            cache_is_enabled =
                initial_is_enabled;

            cache_from_unit_type =
                initial_from_unit_type;

            cache_to_unit_type =
                initial_to_unit_type;

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
        TemperatureManagerConfigurations::_handle_reset_defaults()
    {
        try
        {            
            default_value =
                initial_value;

            default_is_enabled =
                initial_is_enabled;

            default_from_unit_type =
                initial_from_unit_type;

            default_to_unit_type =
                initial_to_unit_type;

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
