#pragma once

#include "value_cache.hpp"
#include "error_manager.hpp"
#include "singleton_manager.hpp"

namespace QLogicaeCppCore
{
    class RuntimeBenchmarkerUtilities
    {
    public:
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
            construct();

        bool
            destruct();

        bool
            setup();

        bool
            reset();

        void
            _construct();

        void
            _destruct();

        void
            _setup();

        void
            _reset();
    };
}
