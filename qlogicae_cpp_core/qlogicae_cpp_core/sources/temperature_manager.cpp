#include "pch.hpp"

#include "../includes/temperature_manager.hpp"

namespace QLogicaeCppCore
{       
    TemperatureManager&
        TemperatureManager::singleton =
            SingletonManager::get_singleton<TemperatureManager>();

    TemperatureManager::TemperatureManager()
    {
        _construct();
    }

    TemperatureManager::~TemperatureManager()
    {
        _destruct();
    }

    bool
        TemperatureManager::construct()
    {
        _construct();

        return
            ValueCache::boolean_1;
    }

    bool
        TemperatureManager::destruct()
    {
        _destruct();

        return
            ValueCache::boolean_1;
    }

    bool
        TemperatureManager::setup(
            const TemperatureManagerConfigurations&
                new_configurations
        )
    {
        TemperatureManagerConfigurations::cache =
            new_configurations;

        _setup();

        return
            ValueCache::boolean_1;
    }

    bool
        TemperatureManager::setup()
    {
        TemperatureManagerConfigurations::cache =
            {};

        _setup();

        return
            ValueCache::boolean_1;
    }

    bool
        TemperatureManager::reset()
    {
        _reset();

        return
            ValueCache::boolean_1;
    }

    double
        TemperatureManager::calculate(
            const double&
                value,
            const TemperatureUnitType&
                from_unit_type,
            const TemperatureUnitType&
                to_unit_type
        )
    {
        TemperatureManagerConfigurations::cache_value =
            value;

        TemperatureManagerConfigurations::cache_from_unit_type =
            from_unit_type;

        TemperatureManagerConfigurations::cache_to_unit_type =
            to_unit_type;

        _calculate();

        return
            TemperatureManagerConfigurations::cache_value;
    }

    double
        TemperatureManager::calculate(
            const double&
                value
        )
    {
        TemperatureManagerConfigurations::cache_value =
            value;

        TemperatureManagerConfigurations::cache_from_unit_type =
            TemperatureManagerConfigurations::default_from_unit_type;

        TemperatureManagerConfigurations::cache_to_unit_type =
            TemperatureManagerConfigurations::default_to_unit_type;

        _calculate();

        return
            TemperatureManagerConfigurations::cache_value;
    }

    double
        TemperatureManager::calculate(
            const TemperatureManagerConfigurations&
                new_configurations
        )
    {
        TemperatureManagerConfigurations::cache_value =
            TemperatureManagerConfigurations::default_value;

        TemperatureManagerConfigurations::cache_from_unit_type =
            TemperatureManagerConfigurations::default_from_unit_type;

        TemperatureManagerConfigurations::cache_to_unit_type =
            TemperatureManagerConfigurations::default_to_unit_type;

        _calculate();

        return
            TemperatureManagerConfigurations::cache_value;
    }

    void
        TemperatureManager::_construct()
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

    void
        TemperatureManager::_destruct()
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

    void
        TemperatureManager::_setup()
    {
        try
        {
            TemperatureManagerUtilities::singleton
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

    void
        TemperatureManager::_reset()
    {
        try
        {
            TemperatureManagerUtilities::singleton
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

    void
        TemperatureManager::_calculate()
    {
        try
        {
            if (!TemperatureManagerConfigurations::cache_is_enabled)
            {                
                return;
            }

            switch (TemperatureManagerConfigurations::cache_from_unit_type)
            {
                case TemperatureUnitType::CELSIUS:
                {
                    break;
                }
                case TemperatureUnitType::FAHRENHEIT:
                {
                    TemperatureManagerConfigurations::cache_value =
                        (TemperatureManagerConfigurations::cache_value - 32.0) * 5.0 / 9.0;

                    break;
                }
                case TemperatureUnitType::KELVIN:
                {
                    TemperatureManagerConfigurations::cache_value =
                        TemperatureManagerConfigurations::cache_value - 273.15;

                    break;
                }
                default:
                {                    
                    break;
                }
            }

            switch (TemperatureManagerConfigurations::cache_to_unit_type)
            {
                case TemperatureUnitType::CELSIUS:
                {                    
                    break;
                }
                case TemperatureUnitType::FAHRENHEIT:
                {
                    TemperatureManagerConfigurations::cache_value =
                        (TemperatureManagerConfigurations::cache_value * 9.0 / 5.0) + 32.0;

                    break;
                }
                case TemperatureUnitType::KELVIN:
                {
                    TemperatureManagerConfigurations::cache_value =
                        TemperatureManagerConfigurations::cache_value + 273.15;

                    break;
                }
                default:
                {                    
                    break;
                }
            }
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
