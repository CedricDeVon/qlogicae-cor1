#include "pch.hpp"

#include "../includes/time_manager_utilities.hpp"

namespace QLogicaeCppCore
{
    bool
        TimeManagerUtilities::cache_boolean_1 =
            false;

    TimeManagerUtilities&
        TimeManagerUtilities::singleton =
            SingletonManager::get_singleton<TimeManagerUtilities>();



    
    TimeManagerUtilities::TimeManagerUtilities()
    {
        try
        {
            _handle_construct();
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    TimeManagerUtilities::~TimeManagerUtilities()
    {
        try
        {
            _handle_destruct();
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }   
    }

    bool
        TimeManagerUtilities::construct()
    {
        _handle_construct();

        return
            cache_boolean_1;
    }

    void
        TimeManagerUtilities::_handle_construct()
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
            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    bool
        TimeManagerUtilities::destruct()
    {
        _handle_destruct();

        return
            cache_boolean_1;
    }

    void
        TimeManagerUtilities::_handle_destruct()
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
            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    bool
        TimeManagerUtilities::setup(
            const TimeManagerConfigurations&
                new_configurations
        )
    {
        TimeManagerConfigurations::cache =
            new_configurations;

        _handle_setup();

        return
            cache_boolean_1;
    }

    bool
        TimeManagerUtilities::setup()
    {
        TimeManagerConfigurations::cache =
            {};

        _handle_setup();

        return
            cache_boolean_1;
    }

    void
        TimeManagerUtilities::_handle_setup()
    {
        try
        {
            TimeManagerConfigurations::_handle_setup();

            cache_boolean_1 =
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    bool
        TimeManagerUtilities::reset()
    {
        _handle_reset();

        return
            cache_boolean_1;
    }

    void
        TimeManagerUtilities::_handle_reset()
    {
        try
        {
            TimeManagerConfigurations::_handle_reset();

            cache_boolean_1 =
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }
}
