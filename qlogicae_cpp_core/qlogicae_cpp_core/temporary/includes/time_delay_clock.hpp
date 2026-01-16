#pragma once

#include "error_manager.hpp"
#include "singleton_manager.hpp"
#include "time_delay_clock_utilities.hpp"
#include "time_delay_clock_configurations.hpp"

namespace QLogicaeCppCore
{
    class TimeDelayClock
    {
    public:
        static double
            cache_double_1;
        
        static bool
            cache_boolean_1;

        static double
            cache_cycles_per_microsecond;

        static TimeDelayClock&
            singleton;

        TimeDelayClock();

        ~TimeDelayClock();

        TimeDelayClock(
            const TimeDelayClock&
                instance
        ) = delete;

        TimeDelayClock(
            TimeDelayClock&&
                instance
        ) noexcept = delete;

        TimeDelayClock& operator = (
            TimeDelayClock&&
                instance
        ) = delete;

        TimeDelayClock& operator = (
            const TimeDelayClock&
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

        bool
            in_years(            
                const double&
                    value
            );

        bool
            in_months(            
                const double&
                    value
            );

        bool
            in_days(            
                const double&
                    value
            );
        
        bool
            in_hours(            
                const double&
                    value
            );

        bool
            in_minutes(            
                const double&
                    value
            );

        bool
            in_seconds(            
                const double&
                    value
            );

        bool
            in_milliseconds(            
                const double&
                    value
            );

        bool
            in_microseconds(            
                const double&
                    value
            );

        bool
            in_nanoseconds(            
                const double&
                    value
            );

        bool
            calibrate();

        bool
            real_time_stamp_counter(            
                const double&
                    microseconds
            );

        bool
            query_performance_counter(            
                const double&
                    microseconds
            );
        
        void
            _handle_construct();

        void
            _handle_destruct();

        void
            _handle_setup();

        void
            _handle_reset();

        void
            _handle_in_years();

        void
            _handle_in_months();

        void
            _handle_in_days();

        void
            _handle_in_hours();

        void
            _handle_in_minutes();

        void
            _handle_in_seconds();

        void
            _handle_in_milliseconds();

        void
            _handle_in_microseconds();

        void
            _handle_in_nanoseconds();

        void
            _handle_calibrate();

        void
            _handle_real_time_stamp_counter();

        void
            _handle_query_performance_counter();
    };
}

/*

    void TimeDelayClock::calibrate(
        Result<bool>& result
    )
    {
        
    }

    void TimeDelayClock::query_performance_counter(
        Result<bool>& result,
        const double& microseconds
    )
    {
        
    }

    void TimeDelayClock::real_time_stamp_counter(
        Result<bool>& result,
        const double& microseconds
    )
    {
        
    }

    void TimeDelayClock::in_nanoseconds(
        Result<bool>& result,
        const double& value
    )
    {
        
    }

    void TimeDelayClock::in_microseconds(
        Result<bool>& result,
        const double& value
    )
    {
        
    }

    void TimeDelayClock::in_milliseconds(
        Result<bool>& result,
        const double& value
    )
    {
        
    }

    void TimeDelayClock::in_seconds(
        Result<bool>& result,
        const double& value
    )
    {
        
    }

    void TimeDelayClock::in_minutes(
        Result<bool>& result,
        const double& value
    )
    {
        
    }

    void TimeDelayClock::in_hours(
        Result<bool>& result,
        const double& value
    )
    {
        
    }

    void TimeDelayClock::in_days(
        Result<bool>& result,
        const double& value
    )
    {
        
    }

    void TimeDelayClock::in_months(
        Result<bool>& result,
        const double& value
    )
    {
        
    }

    void TimeDelayClock::in_years(
        Result<bool>& result,
        const double& value
    )
    {
        
    }

*/