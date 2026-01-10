#include "pch.hpp"

#include "../includes/runtime_benchmarker_utilities.hpp"

namespace QLogicaeCppCore
{    
    bool
        RuntimeBenchmarkerUtilities::cache_boolean_1 =
            false;

    RuntimeBenchmarkerUtilities&
        RuntimeBenchmarkerUtilities::singleton =
            SingletonManager::get_singleton<RuntimeBenchmarkerUtilities>();



    RuntimeBenchmarkerUtilities::RuntimeBenchmarkerUtilities()
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

    RuntimeBenchmarkerUtilities::~RuntimeBenchmarkerUtilities()
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
        RuntimeBenchmarkerUtilities::construct()
    {
        _handle_construct();

        return
            cache_boolean_1;
    }

    void
        RuntimeBenchmarkerUtilities::_handle_construct()
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
        RuntimeBenchmarkerUtilities::destruct()
    {
        _handle_destruct();

        return
            cache_boolean_1;
    }

    void
        RuntimeBenchmarkerUtilities::_handle_destruct()
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
        RuntimeBenchmarkerUtilities::setup()
    {
        _handle_setup();

        return
            cache_boolean_1;
    }

    void
        RuntimeBenchmarkerUtilities::_handle_setup()
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
        RuntimeBenchmarkerUtilities::reset()
    {
        _handle_reset();

        return
            cache_boolean_1;
    }

    void
        RuntimeBenchmarkerUtilities::_handle_reset()
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
}

