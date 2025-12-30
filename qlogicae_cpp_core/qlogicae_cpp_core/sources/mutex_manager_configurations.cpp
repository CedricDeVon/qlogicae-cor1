#include "pch.hpp"

#include "../includes/mutex_manager_configurations.hpp"

namespace QLogicaeCppCore
{
    MutexManagerConfigurations&
        MutexManagerConfigurations::instance =
            InstanceManager::instance.get_instance<MutexManagerConfigurations>();

    std::string
        MutexManagerConfigurations::base_name =
        MutexManagerConfigurationsParameters::default_base_name;

    MutexManagerConfigurations::MutexManagerConfigurations()
    {

    }

    MutexManagerConfigurations::~MutexManagerConfigurations()
    {
        destruct();
    }

    bool
        MutexManagerConfigurations::construct(
            const MutexManagerConfigurationsParameters&
                new_parameters
        )
    {
        MutexManagerConfigurationsParameters::instance =
            new_parameters;

        _construct();

        return ValueCache::boolean_1;
    }

    bool
        MutexManagerConfigurations::construct()
    {
        MutexManagerConfigurationsParameters::instance =
            {};

        _construct();

        return ValueCache::boolean_1;
    }

    void
        MutexManagerConfigurations::_construct()
    {
        try
        {
            base_name =
                MutexManagerConfigurationsParameters::default_base_name =
                MutexManagerConfigurationsParameters::instance.base_name;

            ValueCache::boolean_1 = true;
        }
        catch (...)
        {
            ValueCache::boolean_1 = false;
        }
    }

    bool
        MutexManagerConfigurations::destruct()
    {
        _destruct();

        return ValueCache::boolean_1;
    }

    void
        MutexManagerConfigurations::_destruct()
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
