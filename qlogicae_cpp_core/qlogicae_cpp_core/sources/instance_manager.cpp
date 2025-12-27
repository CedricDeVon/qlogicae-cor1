#include "pch.hpp"

#include "../includes/instance_manager.hpp"

namespace QLogicaeCppCore
{
    bool
        InstanceManager::_boolean_ouput_cache_1 =
            false;

    InstanceManager&
        InstanceManager::instance =
            InstanceManager::get_instance_manager();

    InstanceManager::InstanceManager()
    {
        construct();
    }

    InstanceManager::~InstanceManager()
    {
        destruct();
    }

    bool
        InstanceManager::construct()
    {
        try
        {
            _construct();
        }
        catch (...)
        {
            _boolean_ouput_cache_1 = false;
        }

        return _boolean_ouput_cache_1;
    }

    void
        InstanceManager::_construct()
    {
        _boolean_ouput_cache_1 = true;
    }

    bool
        InstanceManager::destruct()
    {
        try
        {
            _destruct();
        }
        catch (...)
        {
            _boolean_ouput_cache_1 = false;
        }

        return _boolean_ouput_cache_1;
    }

    void
        InstanceManager::_destruct()
    {
        _boolean_ouput_cache_1 = true;
    }

    InstanceManager&
        InstanceManager::get_instance_manager()
    {
        static InstanceManager instance;

        return instance;
    }

}
