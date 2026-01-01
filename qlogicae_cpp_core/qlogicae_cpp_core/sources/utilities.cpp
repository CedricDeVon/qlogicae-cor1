#include "pch.hpp"

#include "../includes/utilities.hpp"

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
