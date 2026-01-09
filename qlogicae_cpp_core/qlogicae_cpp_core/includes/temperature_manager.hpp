#pragma once

#include "error_manager.hpp"
#include "singleton_manager.hpp"
#include "temperature_unit_type.hpp"
#include "temperature_manager_utilities.hpp"
#include "temperature_manager_configurations.hpp"

namespace QLogicaeCppCore
{
    class TemperatureManager
    {
    public:
        static bool
            cache_boolean_1;

        static TemperatureManager&
            singleton;

        TemperatureManager();
        
        ~TemperatureManager();
        
        TemperatureManager(
            const TemperatureManager&
                instance
        ) = delete;
        
        TemperatureManager(
            TemperatureManager&&
                instance
        ) noexcept = delete;
        
        TemperatureManager& operator = (
            TemperatureManager&&
                instance
        ) = delete;
        
        TemperatureManager& operator = (
            const TemperatureManager&
                instance
        ) = delete;

        bool
            construct();

        bool
            destruct();

        bool
            setup(
                const TemperatureManagerConfigurations&
                    new_configurations
            );

        bool
            setup();

        bool
            reset();

        double
            calculate(
                const double&
                    value,
                const TemperatureUnitType&
                    from_unit_type,
                const TemperatureUnitType&
                    to_unit_type
            );

        double
            calculate(
                const double&
                    value
            );

        double
            calculate(
                const TemperatureManagerConfigurations&
                    new_configurations
            );

        void
            _construct();

        void
            _destruct();

        void
            _setup();

        void
            _reset();

        void
            _calculate();
    };
}
