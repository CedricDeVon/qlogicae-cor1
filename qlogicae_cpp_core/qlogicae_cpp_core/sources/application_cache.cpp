#include "pch.hpp"

#include "../includes/constants_cache.hpp"

namespace QLogicaeCppCore
{
    ConstantsCache&
        ConstantsCache::instance =
            InstanceManager::instance.get_instance<ConstantsCache>();

    ConstantsCache::ConstantsCache()
    {

    }

    ConstantsCache::~ConstantsCache()
    {
        
    }

    bool
        ConstantsCache::construct()
    {
        _construct();

        return ValueCache::boolean_1;
    }

    void
        ConstantsCache::_construct()
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
        ConstantsCache::destruct()
    {
        _destruct();

        return ValueCache::boolean_1;
    }

    void
        ConstantsCache::_destruct()
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
}
