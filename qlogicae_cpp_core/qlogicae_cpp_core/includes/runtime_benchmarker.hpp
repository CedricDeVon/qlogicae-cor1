#pragma once

#include "error_manager.hpp"
#include "singleton_manager.hpp"
#include "runtime_benchmarker_utilities.hpp"
#include "runtime_benchmarker_test_case.hpp"
#include "runtime_benchmarker_test_suite.hpp"
#include "runtime_benchmarker_epoch_iteration_pair.hpp"

namespace QLogicaeCppCore
{    
    class RuntimeBenchmarker
    {
    public:        
        static bool
            cache_boolean_1;
        
        static RuntimeBenchmarker&
            singleton;

        RuntimeBenchmarker();

        ~RuntimeBenchmarker();

        RuntimeBenchmarker(
            const RuntimeBenchmarker&
                instance
        ) = delete;

        RuntimeBenchmarker(
            RuntimeBenchmarker&&
                instance
        ) noexcept = delete;

        RuntimeBenchmarker& operator = (
            RuntimeBenchmarker&&
                instance
        ) = delete;

        RuntimeBenchmarker& operator = (
            const RuntimeBenchmarker&
                instance
        ) = delete;

        bool
            construct();

        bool
            destruct();

        bool
            setup();

        bool
            reset();

        bool
            execute(
                const RuntimeBenchmarkerTestSuite&
                    test_suite
            );

        void
            _handle_execute();

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
