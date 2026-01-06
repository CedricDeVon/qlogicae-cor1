#include "pch.hpp"

#include "../includes/runtime_benchmarker.hpp"

namespace QLogicaeCppCore
{
	RuntimeBenchmarker&
        RuntimeBenchmarker::singleton =
            SingletonManager::get_singleton<RuntimeBenchmarker>();

    RuntimeBenchmarker::RuntimeBenchmarker()
    {
        _construct();
    }

    RuntimeBenchmarker::~RuntimeBenchmarker()
    {
        _destruct();
    }

    bool
        RuntimeBenchmarker::construct()
    {
        _construct();

        return
            ValueCache::boolean_1;
    }

    void
        RuntimeBenchmarker::_construct()
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
        RuntimeBenchmarker::destruct()
    {
        _destruct();

        return
            ValueCache::boolean_1;
    }

    void
        RuntimeBenchmarker::_destruct()
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
        RuntimeBenchmarker::setup()
    {        
        _setup();

        return
            ValueCache::boolean_1;
    }

    void
        RuntimeBenchmarker::_setup()
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
        RuntimeBenchmarker::reset()
    {
        _reset();

        return
            ValueCache::boolean_1;
    }

    void
        RuntimeBenchmarker::_reset()
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
