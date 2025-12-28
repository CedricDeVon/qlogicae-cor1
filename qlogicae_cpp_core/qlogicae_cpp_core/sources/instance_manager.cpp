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

        return _boolean_ouput_cache_1;
    }

    void
        InstanceManager::_construct()
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
        InstanceManager::destruct()
    {
        _destruct();
        
        return _boolean_ouput_cache_1;        
    }

    void
        InstanceManager::_destruct()
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

    InstanceManager&
        InstanceManager::get_instance_manager()
    {
        static InstanceManager instance;
        _boolean_ouput_cache_1 = true;

        return instance;
    }
}
