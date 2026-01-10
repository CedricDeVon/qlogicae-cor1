#pragma once

#include "error_manager.hpp"
#include "temperature_unit_type.hpp"

namespace QLogicaeCppCore
{
    struct TemperatureManagerConfigurations
    {
        double
            value =
                default_value;
        
        TemperatureUnitType
            from_unit_type =
                default_from_unit_type;

        TemperatureUnitType
            to_unit_type =
                default_to_unit_type;

        bool
            is_enabled =
                default_is_enabled;
     


        static double
            initial_value;

        static TemperatureUnitType
            initial_from_unit_type;

        static TemperatureUnitType
            initial_to_unit_type;

        static bool
            initial_is_enabled;



        static double
            default_value;

        static TemperatureUnitType
            default_from_unit_type;

        static TemperatureUnitType
            default_to_unit_type;

        static bool
            default_is_enabled;



        static double
            cache_value;

        static TemperatureUnitType
            cache_from_unit_type;

        static TemperatureUnitType
            cache_to_unit_type;

        static bool
            cache_is_enabled;



        static bool
            cache_boolean_1;

        static TemperatureManagerConfigurations
            cache;



        static bool
            construct();

        static bool
            destruct();

        static bool
            setup();

        static bool
            setup(
                const TemperatureManagerConfigurations&
                    new_configurations
            );

        static bool
            reset();

        static void
            _handle_construct();

        static void
            _handle_destruct();

        static void
            _handle_setup();

        static void
            _handle_reset();
    };
}
