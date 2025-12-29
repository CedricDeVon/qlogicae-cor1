#include "pch.hpp"

#include "../includes/instance_manager.hpp"

namespace QLogicaeCppCore
{
    InstanceManager&
        InstanceManager::instance =
            InstanceManager::get_instance_manager();
    
    InstanceManager::InstanceManager()
    {
        
    }

    InstanceManager::~InstanceManager()
    {
        _destruct();
    }

    bool
        InstanceManager::construct()
    {        
        _construct();

        return ValueCache::boolean_1;
    }

    void
        InstanceManager::_construct()
    {
        try
        {
            ValueCache::boolean_1 =
                true;
        }
        catch (...)
        {
            ValueCache::boolean_1 =
                false;
        }
    }

    bool
        InstanceManager::destruct()
    {
        _destruct();

        return ValueCache::boolean_1;
    }

    void
        InstanceManager::_destruct()
    {
        try
        {
            ValueCache::boolean_1 =
                true;
        }
        catch (...)
        {
            ValueCache::boolean_1 =
                false;
        }
    }

    InstanceManager&
        InstanceManager::get_instance_manager()
    {
        static InstanceManager instance;

        ValueCache::boolean_1 =
            true;

        return instance;
    }
}
