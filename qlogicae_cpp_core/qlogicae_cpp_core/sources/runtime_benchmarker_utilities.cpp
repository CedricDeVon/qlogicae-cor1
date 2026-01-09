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
            _construct();
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
            _destruct();
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
        _construct();

        return
            RuntimeBenchmarkerUtilities::cache_boolean_1;
    }

    void
        RuntimeBenchmarkerUtilities::_construct()
    {
        try
        {
            RuntimeBenchmarkerUtilities::cache_boolean_1 =
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
        _destruct();

        return
            RuntimeBenchmarkerUtilities::cache_boolean_1;
    }

    void
        RuntimeBenchmarkerUtilities::_destruct()
    {
        try
        {
            RuntimeBenchmarkerUtilities::cache_boolean_1 =
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
        _setup();

        return
            RuntimeBenchmarkerUtilities::cache_boolean_1;
    }

    void
        RuntimeBenchmarkerUtilities::_setup()
    {
        try
        {
            RuntimeBenchmarkerUtilities::cache_boolean_1 =
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
        _reset();

        return
            RuntimeBenchmarkerUtilities::cache_boolean_1;
    }

    void
        RuntimeBenchmarkerUtilities::_reset()
    {
        try
        {
            RuntimeBenchmarkerUtilities::cache_boolean_1 =
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

