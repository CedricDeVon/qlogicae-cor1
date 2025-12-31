#include "pch.hpp"

#include "../includes/mutex_manager_cache.hpp"

namespace QLogicaeCppCore
{    
    void*
        MutexManagerCache::pointer =
            MutexManagerConfigurations::default_pointer;

    std::string
        MutexManagerCache::name =
            MutexManagerConfigurations::default_name;

    MutexManagerConfigurations
        MutexManagerCache::configurations =
            {};

    MutexManagerCache&
        MutexManagerCache::instance =
            InstanceManager::instance
                .get_instance<MutexManagerCache>();



    MutexManagerCache::MutexManagerCache()
    {
        _construct();
    }

    MutexManagerCache::~MutexManagerCache()
    {
        _destruct();
    }

    bool
        MutexManagerCache::construct()
    {
        _construct();

        return ValueCache::boolean_1;
    }

    void
        MutexManagerCache::_construct()
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
        MutexManagerCache::destruct()
    {
        _destruct();

        return ValueCache::boolean_1;
    }

    void
        MutexManagerCache::_destruct()
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
        MutexManagerCache::setup(
            const MutexManagerConfigurations&
                new_configurations
        )
    {
        configurations =
            new_configurations;

        _setup();

        return ValueCache::boolean_1;
    }

    bool
        MutexManagerCache::setup()
    {
        configurations =
            {};

        _setup();

        return ValueCache::boolean_1;
    }

    void
        MutexManagerCache::_setup()
    {
        try
        {
            pointer =
                MutexManagerConfigurations::default_pointer =
                configurations.pointer;

            name =
                MutexManagerConfigurations::default_name =
                configurations.name;

            ValueCache::boolean_1 = true;
        }
        catch (...)
        {
            ValueCache::boolean_1 = false;
        }
    }

    bool
        MutexManagerCache::reset()
    {
        _reset();

        return ValueCache::boolean_1;
    }

    void
        MutexManagerCache::_reset()
    {
        try
        {
            pointer =
                MutexManagerConfigurations::default_pointer =
                MutexManagerConfigurations::default_pointer;

            name =
                MutexManagerConfigurations::default_name =
                MutexManagerConfigurations::default_name;

            ValueCache::boolean_1 = true;
        }
        catch (...)
        {
            ValueCache::boolean_1 = false;
        }
    }

}
