#pragma once

#include "error_manager.hpp"
#include "singleton_manager.hpp"
#include "runtime_benchmarker_configurations.hpp"

namespace QLogicaeCppCore
{    
    class RuntimeBenchmarkerUtilities
    {
    public:        
        static bool
            cache_boolean_1;

        static RuntimeBenchmarkerUtilities&
            singleton;

        RuntimeBenchmarkerUtilities();

        ~RuntimeBenchmarkerUtilities();

        RuntimeBenchmarkerUtilities(
            const RuntimeBenchmarkerUtilities&
                instance
        ) = delete;

        RuntimeBenchmarkerUtilities(
            RuntimeBenchmarkerUtilities&&
                instance
        ) noexcept = delete;

        RuntimeBenchmarkerUtilities& operator = (
            RuntimeBenchmarkerUtilities&&
                instance
        ) = delete;

        RuntimeBenchmarkerUtilities& operator = (
            const RuntimeBenchmarkerUtilities&
                instance
        ) = delete;

        bool
            construct(
                const RuntimeBenchmarkerConfigurations&
                    configurations = {}
        );

        bool
            destruct(
                const RuntimeBenchmarkerConfigurations&
                    configurations = {}
        );

        bool
            setup(
                const RuntimeBenchmarkerConfigurations&
                    configurations = {}
        );

        bool
            reset(
                const RuntimeBenchmarkerConfigurations&
                    configurations = {}
        );

        void
            _handle_construct();

        void
            _handle_destruct();

        void
            _handle_setup();

        void
            _handle_reset();
    };    
}
