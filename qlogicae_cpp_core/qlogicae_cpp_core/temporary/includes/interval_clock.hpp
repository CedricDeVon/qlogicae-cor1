#pragma once

#include "error_manager.hpp"
#include "interval_clock_utilities.hpp"
#include "interval_clock_configurations.hpp"

namespace QLogicaeCppCore
{
    class IntervalClock
    {
    public:
        std::thread
            cache_thread;

        mutable std::mutex
            cache_mutex;

        std::atomic<bool>
            cache_is_paused
                { false };

        std::atomic<bool>
            cache_is_running
                { false };

        std::atomic<bool>
            cache_is_cancelled
                { false };

        std::atomic<size_t>
            cache_execution_count
                { 0 };

        std::condition_variable
            cache_condition_variable;

        bool
            cache_boolean_1;

        size_t
            cache_size_t_1;

        IntervalClockConfigurations
            configurations;
        
        IntervalClock(
            const IntervalClockConfigurations&
                new_configurations
        );

        IntervalClock();

        ~IntervalClock();

        IntervalClock(
            const IntervalClock&
                instance
        ) = delete;

        IntervalClock(
            IntervalClock&&
                instance
        ) noexcept = delete;

        IntervalClock& operator = (
            IntervalClock&&
                instance
        ) = delete;

        IntervalClock& operator = (
            const IntervalClock&
                instance
        ) = delete;

        bool
            construct(
                const IntervalClockConfigurations&
                    new_configurations
            );

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

        bool
            start();

        bool
            stop();

        bool
            pause();

        bool
            resume();

        bool
            cancel();

        bool
            restart();

        bool
            is_paused();

        bool
            is_running();

        bool
            is_cancelled();

        size_t
            get_execution_count();

        bool
            run_interval();

        void
            _handle_construct();

        void
            _handle_destruct();

        void
            _handle_setup();

        void
            _handle_reset();

        void
            _handle_start();

        void
            _handle_stop();

        void
            _handle_pause();

        void
            _handle_resume();

        void
            _handle_cancel();

        void
            _handle_restart();

        void
            _handle_is_paused();

        void
            _handle_is_running();

        void
            _handle_is_cancelled();

        void
            _handle_get_execution_count();

        void
            _handle_run_interval();
    };
}
