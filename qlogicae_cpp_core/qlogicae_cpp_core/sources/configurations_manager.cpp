#include "pch.hpp"

#include "../includes/configurations_manager.hpp"

namespace QLogicaeCppCore
{
    ConfigurationsManager&
        ConfigurationsManager::instance =
            InstanceManager::instance.get_instance<ConfigurationsManager>();

    ConfigurationsManager::ConfigurationsManager()
    {
        
    }

    ConfigurationsManager::~ConfigurationsManager()
    {
        configurations_manager_configurations_cache_1 =
            configurations_manager_configurations_default;

        _destruct();
    }

    bool
        ConfigurationsManager::construct()
    {
        configurations_manager_configurations_cache_1 =
            configurations_manager_configurations_default;

        _construct();

        return boolean_cache_1;
    }

    bool
        ConfigurationsManager::construct(
            const ConfigurationsManagerConfigurations&
                new_configurations
        )
    {        
        configurations_manager_configurations_cache_1 =
            new_configurations;

        _construct();

        return boolean_cache_1;
    }

    void
        ConfigurationsManager::_construct()
    {
        try
        {            
            ExceptionManagerConfigurations::is_enabled_cache =
                configurations_manager_configurations_cache_1
                    .exception_manager_configurations
                        .is_enabled_cache;

            ExceptionManagerConfigurations::is_console_output_enabled_cache =
                configurations_manager_configurations_cache_1
                    .exception_manager_configurations
                        .is_console_output_enabled_cache;

            ExceptionManagerConfigurations::is_file_output_enabled_cache =
                configurations_manager_configurations_cache_1
                    .exception_manager_configurations
                        .is_file_output_enabled_cache;

            ExceptionManagerConfigurations::is_exception_throwing_enabled_cache =
                configurations_manager_configurations_cache_1
                    .exception_manager_configurations
                        .is_exception_throwing_enabled_cache;

            boolean_cache_1 = true;
        }
        catch (...)
        {
            boolean_cache_1 = false;
        }
    }

    bool
        ConfigurationsManager::destruct()
    {
        _destruct();

        return boolean_cache_1;
    }

    void
        ConfigurationsManager::_destruct()
    {
        try
        {
            boolean_cache_1 = true;
        }
        catch (...)
        {
            boolean_cache_1 = false;
        }
    }
}
