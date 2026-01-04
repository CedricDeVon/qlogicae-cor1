#include "pch.hpp"

#include "../includes/instance_manager.hpp"

namespace QLogicaeCppCore
{    
    InstanceManager&
        InstanceManager::instance =
            InstanceManager::get_instance_manager();



    InstanceManager::InstanceManager()
    {
        _construct();
    }

    InstanceManager::~InstanceManager()
    {
        _destruct();
    }

    bool
        InstanceManager::construct()
    {
        _construct();

        return true;
    }

    void
        InstanceManager::_construct()
    {
        try
        {
            ValueCache::boolean_1 = true;
        }
        catch (...)
        {
            
        }
    }

    bool
        InstanceManager::destruct()
    {
        _destruct();

        return true;
    }

    void
        InstanceManager::_destruct()
    {
        try
        {
            ValueCache::boolean_1 = true;
        }
        catch (...)
        {
            
        }
    }

    bool
        InstanceManager::setup()
    {
        _setup();

        return true;
    }

    void
        InstanceManager::_setup()
    {
        try
        {
            ValueCache::boolean_1 = true;
        }
        catch (...)
        {
            
        }
    }

    bool
        InstanceManager::reset()
    {
        _reset();

        return true;
    }

    void
        InstanceManager::_reset()
    {
        try
        {
            ValueCache::boolean_1 = true;
        }
        catch (...)
        {
            
        }
    }

    InstanceManager&
        InstanceManager::get_instance_manager()
    {
        static InstanceManager
            instance;

        return instance;
    }
}
