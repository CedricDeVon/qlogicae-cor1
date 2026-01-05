#pragma once

#include "error_manager_configurations.hpp"

namespace QLogicaeCppCore
{
    class ErrorManagerCache
    {
    public:
        static ErrorManagerCache&
            instance;

        ErrorManagerCache();

        ~ErrorManagerCache();

        ErrorManagerCache(
            const ErrorManagerCache& instance
        ) = delete;

        ErrorManagerCache(
            ErrorManagerCache&& instance
        ) noexcept = delete;

        ErrorManagerCache& operator = (
            ErrorManagerCache&& instance
        ) = delete;

        ErrorManagerCache& operator = (
            const ErrorManagerCache& instance
        ) = delete;

        bool
            construct();

        void
            _construct();

        bool
            destruct();

        void
            _destruct();

        bool
            setup(
                const ErrorManagerConfigurations&
                    new_configurations
            );

        bool
            setup();

        void
            _setup();

        bool
            reset();

        void
            _reset();
    };
}
