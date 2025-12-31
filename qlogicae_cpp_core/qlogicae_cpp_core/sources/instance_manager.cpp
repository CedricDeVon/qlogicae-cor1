#include "pch.hpp"

#include "../includes/instance_manager.hpp"

namespace QLogicaeCppCore
{
    bool
        InstanceManager::is_successful =
            false;

    InstanceManager&
        InstanceManager::instance =
            InstanceManager::get_instance_manager();



    InstanceManager::InstanceManager()
    {
        _construct();
    }

    InstanceManager::~InstanceManager()
    {
        _destruct();
    }

    bool
        InstanceManager::construct()
    {
        _construct();

        return is_successful;
    }

    void
        InstanceManager::_construct()
    {
        try
        {
            is_successful =
                true;
        }
        catch (...)
        {
            is_successful =
                false;
        }
    }

    bool
        InstanceManager::destruct()
    {
        _destruct();

        return is_successful;
    }

    void
        InstanceManager::_destruct()
    {
        try
        {
            is_successful =
                true;
        }
        catch (...)
        {
            is_successful =
                false;
        }
    }

    bool
        InstanceManager::setup()
    {
        _setup();

        return is_successful;
    }

    void
        InstanceManager::_setup()
    {
        try
        {
            is_successful =
                true;
        }
        catch (...)
        {
            is_successful =
                false;
        }
    }

    bool
        InstanceManager::reset()
    {
        _reset();

        return is_successful;
    }

    void
        InstanceManager::_reset()
    {
        try
        {
            is_successful =
                true;
        }
        catch (...)
        {
            is_successful =
                false;
        }
    }

    InstanceManager&
        InstanceManager::get_instance_manager()
    {
        static InstanceManager instance;

        is_successful =
            true;

        return instance;
    }
}
