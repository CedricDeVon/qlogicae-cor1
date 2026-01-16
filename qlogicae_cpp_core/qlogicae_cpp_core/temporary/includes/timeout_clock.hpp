#pragma once

#include "error_manager.hpp"
#include "timeout_clock_utilities.hpp"
#include "timeout_clock_configurations.hpp"

namespace QLogicaeCppCore
{    
    class TimeoutClock
    {
    public:
        std::jthread
            cache_thread;

        std::mutex
            cache_thread_mutex;

        std::atomic<bool>
            cache_is_flag_stopped_async
                { false };

        std::atomic<bool>
            cache_is_cancelled_async
                { false };

        std::atomic<bool>
            cache_is_executed_immediately_async
                { false };

        bool
            cache_boolean_1;
                
        TimeoutClockConfigurations
            configurations;

        TimeoutClock(
            const TimeoutClockConfigurations&
                new_configurations
        );
        
        TimeoutClock();

        ~TimeoutClock();
        
        TimeoutClock(
            const TimeoutClock&
                instance
        ) = delete;
        
        TimeoutClock(
            TimeoutClock&&
                instance
        ) noexcept = delete;
        
        TimeoutClock& operator = (
            TimeoutClock&&
                instance
        ) = delete;
        
        TimeoutClock& operator = (
            const TimeoutClock&
                instance
        ) = delete;

        bool
            construct(
                const TimeoutClockConfigurations&
                    new_configurations
            );

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

        bool
            cancel();

        bool
            restart();

        bool
            is_cancelled();

        bool
            start_thread();

        void
            _handle_construct();

        void
            _handle_destruct();

        void
            _handle_setup();

        void
            _handle_reset();

        void
            _handle_cancel();

        void
            _handle_restart();

        void
            _handle_is_cancelled();

        void
            _handle_start_thread();
    };
}
