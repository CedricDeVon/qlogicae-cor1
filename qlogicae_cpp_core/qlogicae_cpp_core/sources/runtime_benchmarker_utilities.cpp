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
            RuntimeBenchmarkerConfigurations::cache_configurations =
                {};

            _handle_construct();
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

    RuntimeBenchmarkerUtilities::~RuntimeBenchmarkerUtilities()
    {
        try
        {
            RuntimeBenchmarkerConfigurations::cache_configurations =
                {};

            _handle_destruct();
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

    bool
        RuntimeBenchmarkerUtilities::construct(
            const RuntimeBenchmarkerConfigurations&
                    configurations
        )
    {
        RuntimeBenchmarkerConfigurations::cache_configurations =
            configurations;

        _handle_construct();

        return
            cache_boolean_1;
    }
    
    bool
        RuntimeBenchmarkerUtilities::destruct(
            const RuntimeBenchmarkerConfigurations&
                    configurations
        )
    {
        RuntimeBenchmarkerConfigurations::cache_configurations =
            configurations;

        _handle_destruct();

        return
            cache_boolean_1;
    }

    bool
        RuntimeBenchmarkerUtilities::setup(
            const RuntimeBenchmarkerConfigurations&
                configurations
        )
    {
        RuntimeBenchmarkerConfigurations::cache_configurations =
            configurations;

        _handle_setup();

        return
            cache_boolean_1;
    }

    bool
        RuntimeBenchmarkerUtilities::reset(
            const RuntimeBenchmarkerConfigurations&
                configurations
        )
    {
        RuntimeBenchmarkerConfigurations::cache_configurations =
            configurations;

        _handle_reset();

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
            cache_boolean_1 =
                false;

            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
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

    void
        RuntimeBenchmarkerUtilities::_handle_setup()
    {
        try
        {
            RuntimeBenchmarkerConfigurations::_handle_setup();

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
        RuntimeBenchmarkerUtilities::_handle_reset()
    {
        try
        {
            RuntimeBenchmarkerConfigurations::_handle_reset();

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

