#pragma once

#include "error_manager.hpp"
#include "singleton_manager.hpp"
#include "temperature_manager_configurations.hpp"

namespace QLogicaeCppCore
{
    class TemperatureManagerUtilities
    {
    public:
        static bool
            cache_boolean_1;

        static TemperatureManagerUtilities&
            singleton;

        TemperatureManagerUtilities();

        ~TemperatureManagerUtilities();

        TemperatureManagerUtilities(
            const TemperatureManagerUtilities&
                instance
        ) = delete;

        TemperatureManagerUtilities(
            TemperatureManagerUtilities&&
                instance
        ) noexcept = delete;

        TemperatureManagerUtilities& operator = (
            TemperatureManagerUtilities&&
                instance
            ) = delete;

        TemperatureManagerUtilities& operator = (
            const TemperatureManagerUtilities&
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

        void
            _handle_construct();

        void
            _handle_destruct();

        void
            _handle_setup();

        void
            _handle_reset();
    };
}
