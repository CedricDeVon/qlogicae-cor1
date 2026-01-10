#pragma once

#include "error_manager.hpp"
#include "singleton_manager.hpp"
#include "timeout_clock_configurations.hpp"

namespace QLogicaeCppCore
{
    class TimeoutClockUtilities
    {
    public:
        static bool
            cache_boolean_1;

        static TimeoutClockUtilities&
            singleton;

        TimeoutClockUtilities();

        ~TimeoutClockUtilities();

        TimeoutClockUtilities(
            const TimeoutClockUtilities&
            instance
        ) = delete;

        TimeoutClockUtilities(
            TimeoutClockUtilities&&
            instance
        ) noexcept = delete;

        TimeoutClockUtilities& operator = (
            TimeoutClockUtilities&&
            instance
            ) = delete;

        TimeoutClockUtilities& operator = (
            const TimeoutClockUtilities&
            instance
            ) = delete;

        bool
            construct();

        bool
            destruct();

        bool
            setup(
                const TimeoutClockConfigurations&
                    new_configurations
            );

        bool
            setup();

        bool
            reset();

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
