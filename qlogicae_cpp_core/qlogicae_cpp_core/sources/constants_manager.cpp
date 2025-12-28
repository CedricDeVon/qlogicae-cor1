#include "pch.hpp"

#include "../includes/constants_manager.hpp"

namespace QLogicaeCppCore
{
    ConstantsManager&
        ConstantsManager::instance =
            InstanceManager::instance.get_instance<ConstantsManager>();

    ConstantsManager::ConstantsManager()
    {
        
    }

    ConstantsManager::~ConstantsManager()
    {
        _destruct();
    }

    bool
        ConstantsManager::construct()
    {
        _construct();

        return boolean_cache_1;
    }

    void
        ConstantsManager::_construct()
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
        ConstantsManager::destruct()
    {
        _destruct();

        return boolean_cache_1;
    }

    void
        ConstantsManager::_destruct()
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
