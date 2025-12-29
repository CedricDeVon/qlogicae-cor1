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

        return ValueCache::boolean_1;
    }

    void
        ConstantsManager::_construct()
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
        ConstantsManager::destruct()
    {
        _destruct();

        return ValueCache::boolean_1;
    }

    void
        ConstantsManager::_destruct()
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
