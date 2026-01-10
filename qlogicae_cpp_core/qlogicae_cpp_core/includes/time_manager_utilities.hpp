#pragma once

#include "error_manager.hpp"
#include "singleton_manager.hpp"
#include "time_manager_configurations.hpp"

namespace QLogicaeCppCore
{
    class TimeManagerUtilities
    {
    public:
        static bool
            cache_boolean_1;

        static TimeManagerUtilities&
            singleton;

        TimeManagerUtilities();

        ~TimeManagerUtilities();

        TimeManagerUtilities(
            const TimeManagerUtilities&
            instance
        ) = delete;

        TimeManagerUtilities(
            TimeManagerUtilities&&
            instance
        ) noexcept = delete;

        TimeManagerUtilities& operator = (
            TimeManagerUtilities&&
            instance
            ) = delete;

        TimeManagerUtilities& operator = (
            const TimeManagerUtilities&
            instance
            ) = delete;

        bool
            construct();

        bool
            destruct();

        bool
            setup(
                const TimeManagerConfigurations&
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
