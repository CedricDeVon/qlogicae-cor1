#include "pch.hpp"

#include "../includes/utilities.hpp"

namespace QLogicaeCppCore
{
    bool
        Utilities::_boolean_ouput_cache_1 =
            false;

    Utilities&
        Utilities::instance =
            InstanceManager::instance.get_instance<Utilities>();

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
        Utilities::_construct()
    {
        _boolean_ouput_cache_1 = true;
    }

    bool
        Utilities::destruct()
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
        Utilities::_destruct()
    {
        _boolean_ouput_cache_1 = true;
    }
}
