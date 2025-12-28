#pragma once

#include "instance_manager.hpp"
#include "configurations_manager_configurations.hpp"

namespace QLogicaeCppCore
{
    class ConfigurationsManager
    {
    public:
        ConfigurationsManager();

        ~ConfigurationsManager();

        ConfigurationsManager(
            const ConfigurationsManager&
            instance
        ) =
            delete;

        ConfigurationsManager(
            ConfigurationsManager&&
            instance
        ) noexcept =
            delete;

        ConfigurationsManager&
            operator = (
                ConfigurationsManager&&
                instance
                ) =
            delete;

        ConfigurationsManager&
            operator = (
                const ConfigurationsManager&
                instance
                ) =
            delete;

        static ConfigurationsManager&
            instance;

        static ConfigurationsManagerConfigurations
            configurations;

        static bool
            _boolean_ouput_cache_1; // is_successful

        bool
            construct();

        void
            _construct();

        bool
            destruct();

        void
            _destruct();
    };
}
