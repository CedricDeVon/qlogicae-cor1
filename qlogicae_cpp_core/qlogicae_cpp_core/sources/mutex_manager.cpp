#include "pch.hpp"

#include "../includes/mutex_manager.hpp"

namespace QLogicaeCppCore
{
    MutexManager&
        MutexManager::instance =
            InstanceManager::instance.get_instance<MutexManager>();

    bool
        MutexManager::_boolean_ouput_cache_1 =
            false;

    void*
        MutexManager::_void_pointer_ouput_cache_1 =
            nullptr;

    std::string_view
        MutexManager::_string_view_ouput_cache_1 =
            "static";
 
    MutexManager::MutexManager()
    {        
        construct();
    }

    MutexManager::~MutexManager()
    {        
        destruct();
    }

    bool
        MutexManager::construct()
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
        MutexManager::_construct()
    {
        _boolean_ouput_cache_1 = true;
    }

    bool
        MutexManager::destruct()
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
        MutexManager::_destruct()
    {
        _boolean_ouput_cache_1 = true;
    }
}
