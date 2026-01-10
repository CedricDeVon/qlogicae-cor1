#pragma once

#include "error_manager.hpp"
#include "singleton_manager.hpp"
#include "interval_clock_configurations.hpp"

namespace QLogicaeCppCore
{
    class IntervalClockUtilities
    {
    public:
        static bool
            cache_boolean_1;

        static IntervalClockUtilities&
            singleton;

        IntervalClockUtilities();

        ~IntervalClockUtilities();

        IntervalClockUtilities(
            const IntervalClockUtilities&
            instance
        ) = delete;

        IntervalClockUtilities(
            IntervalClockUtilities&&
            instance
        ) noexcept = delete;

        IntervalClockUtilities& operator = (
            IntervalClockUtilities&&
            instance
            ) = delete;

        IntervalClockUtilities& operator = (
            const IntervalClockUtilities&
            instance
            ) = delete;

        bool
            construct();

        bool
            destruct();

        bool
            setup(
                const IntervalClockConfigurations&
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
