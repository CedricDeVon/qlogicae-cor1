#include "pch.hpp"

#include "../includes/constants_manager.hpp"

namespace QLogicaeCppCore
{
    ConstantsManager&
        ConstantsManager::instance =
        InstanceManager::instance.get_instance<ConstantsManager>();

    ConstantsManager::ConstantsManager()
    {
        _construct();
    }

    ConstantsManager::~ConstantsManager()
    {
        _destruct();
    }

    bool
        ConstantsManager::construct()
    {
        _construct();

        return _boolean_ouput_cache_1;
    }

    void
        ConstantsManager::_construct()
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
        ConstantsManager::destruct()
    {
        _destruct();

        return _boolean_ouput_cache_1;
    }

    void
        ConstantsManager::_destruct()
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
