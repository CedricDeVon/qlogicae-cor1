#include "pch.hpp"

#include "../includes/configurations_manager.hpp"

namespace QLogicaeCppCore
{
    ConfigurationsManager&
        ConfigurationsManager::instance =
            InstanceManager::instance.get_instance<ConfigurationsManager>();

    ConfigurationsManager::ConfigurationsManager()
    {
        _construct();
    }

    ConfigurationsManager::~ConfigurationsManager()
    {
        _destruct();
    }

    bool
        ConfigurationsManager::construct()
    {
        _construct();

        return _boolean_ouput_cache_1;
    }

    void
        ConfigurationsManager::_construct()
    {
        try
        {
            _boolean_ouput_cache_1 = true;
        }
        catch (...)
        {
            _boolean_ouput_cache_1 = false;
        }
    }

    bool
        ConfigurationsManager::destruct()
    {
        _destruct();

        return _boolean_ouput_cache_1;
    }

    void
        ConfigurationsManager::_destruct()
    {
        try
        {
            _boolean_ouput_cache_1 = true;
        }
        catch (...)
        {
            _boolean_ouput_cache_1 = false;
        }
    }
}
