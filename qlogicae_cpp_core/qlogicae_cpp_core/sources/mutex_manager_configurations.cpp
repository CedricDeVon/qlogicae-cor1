#include "pch.hpp"

#include "../includes/mutex_manager_configurations.hpp"

namespace QLogicaeCppCore
{
    MutexManagerConfigurations&
        MutexManagerConfigurations::instance =
            InstanceManager::instance.get_instance<MutexManagerConfigurations>();

    void*
        MutexManagerConfigurations::pointer =
            MutexManagerConfigurationParameters::default_pointer;

    std::string
        MutexManagerConfigurations::name =
            MutexManagerConfigurationParameters::default_name;

    MutexManagerConfigurationParameters
        MutexManagerConfigurations::parameters =
            {};

    MutexManagerConfigurations::MutexManagerConfigurations()
    {

    }

    MutexManagerConfigurations::~MutexManagerConfigurations()
    {
        
    }

    bool
        MutexManagerConfigurations::construct(
            const MutexManagerConfigurationParameters&
                new_parameters
        )
    {
        parameters =
            new_parameters;

        _construct();

        return ValueCache::boolean_1;
    }

    bool
        MutexManagerConfigurations::construct()
    {
        parameters =
            {};

        _construct();

        return ValueCache::boolean_1;
    }

    void
        MutexManagerConfigurations::_construct()
    {
        try
        {
            MutexManagerConfigurationParameters::default_pointer =
                pointer =
                    parameters.pointer;

            MutexManagerConfigurationParameters::default_name =
                name =
                    parameters.name;

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
