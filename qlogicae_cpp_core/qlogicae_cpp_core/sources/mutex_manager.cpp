#include "pch.hpp"

#include "../includes/mutex_manager.hpp"

namespace QLogicaeCppCore
{
    MutexManager&
        MutexManager::instance =
            InstanceManager::instance.get_instance<MutexManager>();

    MutexManager::MutexManager()
    {
        
    }

    MutexManager::~MutexManager()
    {
        destruct();
    }

    bool
        MutexManager::construct()
    {
        _construct();

        return boolean_cache_1;
    }

    void
        MutexManager::_construct()
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

    bool
        MutexManager::destruct()
    {
        _destruct();

        return boolean_cache_1;
    }

    void
        MutexManager::_destruct()
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
