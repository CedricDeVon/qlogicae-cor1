#pragma once

#include "value_cache.hpp"
#include "instance_manager.hpp"
#include "exception_manager_configurations.hpp"
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
        ) = delete;

        ConfigurationsManager(
            ConfigurationsManager&&
                instance
        ) noexcept = delete;

        ConfigurationsManager&
            operator = (
                ConfigurationsManager&&
                    instance
            ) = delete;

        ConfigurationsManager&
            operator = (
                const ConfigurationsManager&
                    instance
            ) = delete;

        static ConfigurationsManagerConfigurations
            configurations_manager_configurations_cache_1;

        static ConfigurationsManager&
            instance;

        bool
            construct();

        bool
            construct(
                const ConfigurationsManagerConfigurations&
                    new_configurations
            );

        void
            _construct();

        bool
            destruct();

        void
            _destruct();
    };
}
