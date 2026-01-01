#include "pch.hpp"

#include "../includes/utilities_cache.hpp"

namespace QLogicaeCppCore
{
    UtilitiesCache&
        UtilitiesCache::instance =
            InstanceManager::instance
                .get_instance<UtilitiesCache>();

    UtilitiesCache::UtilitiesCache()
    {
        _construct();
    }

    UtilitiesCache::~UtilitiesCache()
    {
        _destruct();
    }

    bool
        UtilitiesCache::construct()
    {
        _construct();

        return ValueCache::boolean_1;
    }

    void
        UtilitiesCache::_construct()
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
        UtilitiesCache::destruct()
    {
        _destruct();

        return ValueCache::boolean_1;
    }

    void
        UtilitiesCache::_destruct()
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
        UtilitiesCache::setup()
    {        
        _setup();

        return ValueCache::boolean_1;
    }

    void
        UtilitiesCache::_setup()
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
        UtilitiesCache::reset()
    {
        _reset();

        return ValueCache::boolean_1;
    }

    void
        UtilitiesCache::_reset()
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
