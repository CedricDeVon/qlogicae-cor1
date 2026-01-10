#include "pch.hpp"

#include "../includes/singleton_manager_configurations.hpp"

namespace QLogicaeCppCore
{   
    bool
        SingletonManagerConfigurations::cache_boolean_1 =
            false;

    SingletonManagerConfigurations
        SingletonManagerConfigurations::cache;



    bool
        SingletonManagerConfigurations::construct()
    {
        _handle_construct();

        return
            cache_boolean_1;
    }

    bool
        SingletonManagerConfigurations::destruct()
    {
        _handle_destruct();

        return
            cache_boolean_1;
    }

    bool
        SingletonManagerConfigurations::setup(
            const SingletonManagerConfigurations&
                new_configurations
        )
    {
        cache =
            new_configurations;

        _handle_setup();

        return
            cache_boolean_1;
    }

    bool
        SingletonManagerConfigurations::setup()
    {
        cache =
            {};

        _handle_setup();

        return
            cache_boolean_1;
    }

    bool
        SingletonManagerConfigurations::reset()
    {
        _handle_reset();

        return
            cache_boolean_1;
    }

    void
        SingletonManagerConfigurations::_handle_construct()
    {
        try
        {
            cache_boolean_1 =
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            cache_boolean_1 =
                false;

            throw std::runtime_error(
                exception.what()
            );
        }        
    }

    void
        SingletonManagerConfigurations::_handle_destruct()
    {
        try
        {
            cache_boolean_1 =
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            cache_boolean_1 =
                false;

            throw std::runtime_error(
                exception.what()
            );
        }
    }

    void
        SingletonManagerConfigurations::_handle_setup()
    {
        try
        {            
            cache_boolean_1 =
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            cache_boolean_1 =
                false;

            throw std::runtime_error(
                exception.what()
            );
        }
    }

    void
        SingletonManagerConfigurations::_handle_reset()
    {
        try
        {            
            cache_boolean_1 =
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            cache_boolean_1 =
                false;

            throw std::runtime_error(
                exception.what()
            );
        }
    }
}
