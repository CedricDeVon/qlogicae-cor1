#include "pch.hpp"

#include "../includes/runtime_benchmarker_utilities.hpp"

namespace QLogicaeCppCore
{
    RuntimeBenchmarkerUtilities&
        RuntimeBenchmarkerUtilities::singleton =
            SingletonManager::get_singleton<RuntimeBenchmarkerUtilities>();

    RuntimeBenchmarkerUtilities::RuntimeBenchmarkerUtilities()
    {
        _construct();
    }

    RuntimeBenchmarkerUtilities::~RuntimeBenchmarkerUtilities()
    {
        _destruct();
    }

    bool
        RuntimeBenchmarkerUtilities::construct()
    {
        _construct();

        return
            ValueCache::boolean_1;
    }

    void
        RuntimeBenchmarkerUtilities::_construct()
    {
        try
        {
            ValueCache::boolean_1 =
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
            ValueCache::boolean_1;
    }

    void
        RuntimeBenchmarkerUtilities::_destruct()
    {
        try
        {
            ValueCache::boolean_1 =
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
            ValueCache::boolean_1;
    }

    void
        RuntimeBenchmarkerUtilities::_setup()
    {
        try
        {
            ValueCache::boolean_1 =
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
            ValueCache::boolean_1;
    }

    void
        RuntimeBenchmarkerUtilities::_reset()
    {
        try
        {
            ValueCache::boolean_1 =
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

