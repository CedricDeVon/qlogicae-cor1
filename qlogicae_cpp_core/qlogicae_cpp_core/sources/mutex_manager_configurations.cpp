#include "pch.hpp"

#include "../includes/mutex_manager_configurations.hpp"

namespace QLogicaeCppCore
{   
    void*
        MutexManagerConfigurations::initial_pointer =
            nullptr;

    std::string
        MutexManagerConfigurations::initial_name =
            "static";

    bool
        MutexManagerConfigurations::initial_is_enabled =
            false;



    std::string
        MutexManagerConfigurations::default_name =
            MutexManagerConfigurations::initial_name;

    void*
        MutexManagerConfigurations::default_pointer =
            MutexManagerConfigurations::initial_pointer;
    bool
        MutexManagerConfigurations::default_is_enabled =
            MutexManagerConfigurations::initial_is_enabled;



    std::string
        MutexManagerConfigurations::cache_name =
            MutexManagerConfigurations::initial_name;

    void*
        MutexManagerConfigurations::cache_pointer =
            MutexManagerConfigurations::initial_pointer;
    bool
        MutexManagerConfigurations::cache_is_enabled =
            MutexManagerConfigurations::initial_is_enabled;



    bool
        MutexManagerConfigurations::cache_boolean_1 =
            false;

    MutexManagerConfigurations
        MutexManagerConfigurations::cache_configurations;



    bool
        MutexManagerConfigurations::construct(
            const MutexManagerConfigurations&
                configurations
        )
    {
        cache_configurations =
            configurations;

        _handle_construct();

        return
            cache_boolean_1;
    }

    bool
        MutexManagerConfigurations::destruct(
            const MutexManagerConfigurations&
                configurations
        )
    {
        cache_configurations =
            configurations;

        _handle_destruct();

        return
            cache_boolean_1;
    }

    bool
        MutexManagerConfigurations::setup(
            const MutexManagerConfigurations&
                configurations
        )
    {
        cache_configurations =
            configurations;

        _handle_setup();

        return
            cache_boolean_1;
    }

    bool
        MutexManagerConfigurations::reset(
            const MutexManagerConfigurations&
                configurations
        )
    {
        cache_configurations =
            configurations;

        _handle_reset();

        return
            cache_boolean_1;
    }
    
    bool
        MutexManagerConfigurations::setup_caches(
            const MutexManagerConfigurations&
                configurations
        )
    {
        cache_configurations =
            configurations;

        _handle_setup_caches();

        return
            cache_boolean_1;
    }
    
    bool
        MutexManagerConfigurations::setup_defaults(
            const MutexManagerConfigurations&
                configurations
        )
    {
        cache_configurations =
            configurations;

        _handle_setup_defaults();

        return
            cache_boolean_1;
    }
    
    bool
        MutexManagerConfigurations::reset_caches(
            const MutexManagerConfigurations&
                configurations
        )
    {
        cache_configurations =
            configurations;

        _handle_reset_caches();

        return
            cache_boolean_1;
    }
    
    bool
        MutexManagerConfigurations::reset_defaults(
            const MutexManagerConfigurations&
                configurations
        )
    {
        cache_configurations =
            configurations;

        _handle_reset_defaults();

        return
            cache_boolean_1;
    }

    void
        MutexManagerConfigurations::_handle_construct()
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

            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        MutexManagerConfigurations::_handle_destruct()
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

            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        MutexManagerConfigurations::_handle_setup()
    {
        try
        {
            _handle_setup_caches();
            _handle_setup_defaults();

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

            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        MutexManagerConfigurations::_handle_reset()
    {
        try
        {
            _handle_reset_caches();
            _handle_reset_defaults();

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

            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }
    
    void
        MutexManagerConfigurations::_handle_setup_caches()
    {
        try
        {            
            cache_pointer =
                cache_configurations.pointer;

            cache_name =
                cache_configurations.name;

            cache_is_enabled =
                cache_configurations.is_enabled;

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

            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        MutexManagerConfigurations::_handle_setup_defaults()
    {
        try
        {         
            default_pointer =
                cache_configurations.pointer;

            default_name =
                cache_configurations.name;

            default_is_enabled =
                cache_configurations.is_enabled;

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

            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }
    
    void
        MutexManagerConfigurations::_handle_reset_caches()
    {
        try
        {            
            cache_pointer =
                initial_pointer;

            cache_name =
                initial_name;

            cache_is_enabled =
                initial_is_enabled;

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

            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        MutexManagerConfigurations::_handle_reset_defaults()
    {
        try
        {            
            default_pointer =
                initial_pointer;

            default_name =
                initial_name;

            default_is_enabled =
                initial_is_enabled;

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

            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }
}
