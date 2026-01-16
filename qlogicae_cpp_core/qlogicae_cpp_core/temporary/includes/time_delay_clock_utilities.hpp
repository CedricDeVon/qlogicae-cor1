#pragma once

#include "error_manager.hpp"
#include "singleton_manager.hpp"
#include "time_delay_clock_configurations.hpp"

namespace QLogicaeCppCore
{
    class TimeDelayClockUtilities
    {
    public:
        static bool
            cache_boolean_1;

        static TimeDelayClockUtilities&
            singleton;

        TimeDelayClockUtilities();

        ~TimeDelayClockUtilities();

        TimeDelayClockUtilities(
            const TimeDelayClockUtilities&
            instance
        ) = delete;

        TimeDelayClockUtilities(
            TimeDelayClockUtilities&&
            instance
        ) noexcept = delete;

        TimeDelayClockUtilities& operator = (
            TimeDelayClockUtilities&&
            instance
            ) = delete;

        TimeDelayClockUtilities& operator = (
            const TimeDelayClockUtilities&
            instance
            ) = delete;

        bool
            construct();

        bool
            destruct();

        bool
            setup(
                const TimeDelayClockConfigurations&
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
