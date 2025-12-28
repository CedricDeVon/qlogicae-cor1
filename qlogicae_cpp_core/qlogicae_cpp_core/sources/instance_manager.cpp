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

        return boolean_cache_1;
    }

    void
        InstanceManager::_construct()
    {
        try
        {
            boolean_cache_1 =
                true;
        }
        catch (...)
        {
            boolean_cache_1 =
                false;
        }
    }

    bool
        InstanceManager::destruct()
    {
        _destruct();

        return boolean_cache_1;
    }

    void
        InstanceManager::_destruct()
    {
        try
        {
            boolean_cache_1 =
                true;
        }
        catch (...)
        {
            boolean_cache_1 =
                false;
        }
    }

    InstanceManager&
        InstanceManager::get_instance_manager()
    {
        static InstanceManager instance;

        boolean_cache_1 =
            true;

        return instance;
    }
}
