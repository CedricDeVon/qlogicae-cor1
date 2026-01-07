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



    TemperatureManagerConfigurations
        TemperatureManagerConfigurations::cache;
}

