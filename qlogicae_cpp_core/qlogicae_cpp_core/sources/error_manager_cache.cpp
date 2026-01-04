#include "pch.hpp"

#include "../includes/error_manager_cache.hpp"

namespace QLogicaeCppCore
{
    Utilities&
        Utilities::instance =
        InstanceManager::instance
        .get_instance<Utilities>();

    Utilities::Utilities()
    {
        _construct();
    }

    Utilities::~Utilities()
    {
        _destruct();
    }

    bool
        Utilities::construct()
    {
        _construct();

        return ValueCache::boolean_1;
    }

    void
        Utilities::_construct()
    {
        try
        {
            UtilitiesCache::instance._construct();
        }
        catch (...)
        {
            ValueCache::boolean_1 =
                false;
        }
    }

    bool
        Utilities::destruct()
    {
        _destruct();

        return ValueCache::boolean_1;
    }

    void
        Utilities::_destruct()
    {
        try
        {
            UtilitiesCache::instance._destruct();
        }
        catch (...)
        {
            ValueCache::boolean_1 =
                false;
        }
    }

    bool
        Utilities::setup()
    {
        _setup();

        return ValueCache::boolean_1;
    }

    void
        Utilities::_setup()
    {
        try
        {
            UtilitiesCache::instance._setup();
        }
        catch (...)
        {
            ValueCache::boolean_1 =
                false;
        }
    }

    bool
        Utilities::reset()
    {
        _reset();

        return ValueCache::boolean_1;
    }

    void
        Utilities::_reset()
    {
        try
        {
            UtilitiesCache::instance._reset();
        }
        catch (...)
        {
            ValueCache::boolean_1 =
                false;
        }
    }
}
