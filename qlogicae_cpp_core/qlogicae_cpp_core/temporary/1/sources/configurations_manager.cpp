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
        ConfigurationsManagerConfigurations::cache =
            {};

        _destruct();
    }

    bool
        ConfigurationsManager::construct()
    {
        ConfigurationsManagerConfigurations::cache =
            {};

        _construct();

        return ValueCache::boolean_1;
    }

    bool
        ConfigurationsManager::construct(
            const ConfigurationsManagerConfigurations&
            new_configurations
        )
    {
        ConfigurationsManagerConfigurations::cache =
            new_configurations;

        _construct();

        return ValueCache::boolean_1;
    }

    void
        ConfigurationsManager::_construct()
    {
        try
        {                        
            ValueCache::boolean_1 = true;
        }
        catch (...)
        {
            ValueCache::boolean_1 = false;
        }
    }

    bool
        ConfigurationsManager::destruct()
    {
        _destruct();

        return ValueCache::boolean_1;
    }

    void
        ConfigurationsManager::_destruct()
    {
        try
        {
            ValueCache::boolean_1 = true;
        }
        catch (...)
        {
            ValueCache::boolean_1 = false;
        }
    }
}
