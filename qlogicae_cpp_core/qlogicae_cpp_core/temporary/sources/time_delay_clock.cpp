#include "pch.hpp"

#include "../includes/time_delay_clock.hpp"

namespace QLogicaeCppCore
{
    double
        TimeDelayClock::cache_double_1 =
            0.0;

    double
        TimeDelayClock::cache_cycles_per_microsecond =
            0.0;

    TimeDelayClock&
        TimeDelayClock::singleton =
            SingletonManager::get_singleton<TimeDelayClock>();



    TimeDelayClock::TimeDelayClock()
    {
        try
        {            
            _handle_construct();
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            cache_boolean_1 =
                false;

            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    TimeDelayClock::~TimeDelayClock()
    {
        try
        {
            _handle_destruct();
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            cache_boolean_1 =
                false;

            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    bool
        TimeDelayClock::construct()
    {
        _handle_construct();

        return
            cache_boolean_1;
    }

    bool
        TimeDelayClock::destruct()
    {
        _handle_destruct();

        return
            cache_boolean_1;
    }

    bool
        TimeDelayClock::setup(
            const TimeDelayClockConfigurations&
                new_configurations
        )
    {
        TimeDelayClockConfigurations::cache =
            new_configurations;

        _handle_setup();

        return
            cache_boolean_1;
    }

    bool
        TimeDelayClock::setup()
    {
        TimeDelayClockConfigurations::cache =
            {};

        _handle_setup();

        return
            cache_boolean_1;
    }

    bool
        TimeDelayClock::reset()
    {
        _handle_reset();

        return
            cache_boolean_1;
    }

    bool
        TimeDelayClock::in_years(
            const double&
                value
        )
    {
        cache_double_1 =
            value;

        _handle_in_years();

        return
            cache_boolean_1;
    }

    bool
        TimeDelayClock::in_months(
            const double&
                value
        )
    {
        cache_double_1 =
            value;

        _handle_in_months();

        return
            cache_boolean_1;
    }

    bool
        TimeDelayClock::in_days(
            const double&
                value
        )
    {
        cache_double_1 =
            value;

        _handle_in_days();

        return
            cache_boolean_1;
    }

    bool
        TimeDelayClock::in_hours(
            const double&
                value
        )
    {
        cache_double_1 =
            value;

        _handle_in_hours();

        return
            cache_boolean_1;
    }

    bool
        TimeDelayClock::in_minutes(
            const double&
                value
        )
    {
        cache_double_1 =
            value;

        _handle_in_minutes();

        return
            cache_boolean_1;
    }

    bool
        TimeDelayClock::in_seconds(
            const double&
                value
        )
    {
        cache_double_1 =
            value;

        _handle_in_seconds();

        return
            cache_boolean_1;
    }

    bool
        TimeDelayClock::in_milliseconds(
            const double&
                value
        )
    {
        cache_double_1 =
            value;

        _handle_in_milliseconds();

        return
            cache_boolean_1;
    }

    bool
        TimeDelayClock::in_microseconds(
            const double&
                value
        )
    {
        cache_double_1 =
            value;

        _handle_in_microseconds();

        return
            cache_boolean_1;
    }

    bool
        TimeDelayClock::in_nanoseconds(
            const double&
                value
        )
    {
        cache_double_1 =
            value;

        _handle_in_nanoseconds();

        return
            cache_boolean_1;
    }

    bool
        TimeDelayClock::calibrate()
    {
        _handle_calibrate();

        return
            cache_boolean_1;
    }

    bool
        TimeDelayClock::real_time_stamp_counter(
            const double&
                microseconds
        )
    {
        cache_double_1 =
            microseconds;

        _handle_real_time_stamp_counter();

        return
            cache_boolean_1;
    }

    bool
        TimeDelayClock::query_performance_counter(
            const double&
                microseconds
        )
    {
        cache_double_1 =
            microseconds;

        _handle_query_performance_counter();

        return
            cache_boolean_1;
    }

    void
        TimeDelayClock::_handle_construct()
    {
        try
        {            
            cache_boolean_1 =
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            cache_boolean_1 =
                false;

            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        TimeDelayClock::_handle_destruct()
    {
        try
        {
            cache_boolean_1 =
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            cache_boolean_1 =
                false;

            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        TimeDelayClock::_handle_setup()
    {
        try
        {
            TimeDelayClockConfigurations::_handle_setup();

            cache_boolean_1 =
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            cache_boolean_1 =
                false;

            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        TimeDelayClock::_handle_reset()
    {
        try
        {
            TimeDelayClockConfigurations::_handle_reset();

            cache_boolean_1 =
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            cache_boolean_1 =
                false;

            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        TimeDelayClock::_handle_in_years()
    {
        try
        {
            cache_double_1 =
                cache_double_1 * 365.25;

            _handle_in_days();
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            cache_boolean_1 =
                false;

            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        TimeDelayClock::_handle_in_months()
    {
        try
        {
            cache_double_1 =
                cache_double_1 * 30.44;

            _handle_in_days();
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            cache_boolean_1 =
                false;

            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        TimeDelayClock::_handle_in_days()
    {
        try
        {
            cache_double_1 =
                cache_double_1 * 24.0;

            _handle_in_hours();
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            cache_boolean_1 =
                false;

            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        TimeDelayClock::_handle_in_hours()
    {
        try
        {
            cache_double_1 =
                cache_double_1 * 60.0;

            _handle_in_minutes();
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            cache_boolean_1 =
                false;

            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        TimeDelayClock::_handle_in_minutes()
    {
        try
        {
            cache_double_1 =
                cache_double_1 * 60.0;

            _handle_in_seconds();
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            cache_boolean_1 =
                false;

            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        TimeDelayClock::_handle_in_seconds()
    {
        try
        {
            cache_double_1 =
                cache_double_1 * 1'000'000.0;

            _handle_in_microseconds();
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            cache_boolean_1 =
                false;

            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        TimeDelayClock::_handle_in_milliseconds()
    {
        try
        {
            cache_double_1 =
                cache_double_1 * 1'000.0;

            _handle_in_microseconds();
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            cache_boolean_1 =
                false;

            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        TimeDelayClock::_handle_in_microseconds()
    {
        try
        {
            if (cache_double_1 <= 0.0 || cache_double_1 > 1e12)
            {
                cache_boolean_1 =
                    false;

                return;
            }

            LARGE_INTEGER frequency;
            LARGE_INTEGER start;
            LARGE_INTEGER current;

            QueryPerformanceFrequency(&frequency);
            QueryPerformanceCounter(&start);

            double elapsed = 0.0;
            while (elapsed < cache_double_1)
            {
                QueryPerformanceCounter(&current);
                elapsed = static_cast<double>(
                    current.QuadPart - start.QuadPart
                    ) * 1'000'000.0 / static_cast<double>(frequency.QuadPart);
            }

            cache_boolean_1 =
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            cache_boolean_1 =
                false;

            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        TimeDelayClock::_handle_in_nanoseconds()
    {
        try
        {
            cache_double_1 =
                cache_double_1 / 1'000.0;

            _handle_in_microseconds();
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            cache_boolean_1 =
                false;

            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        TimeDelayClock::_handle_calibrate()
    {
        try
        {
            static std::atomic<bool> calibrated = false;
            static std::atomic<double> cached_frequency = 0.0;

            if (calibrated.load())
            {
                cache_cycles_per_microsecond =
                    cached_frequency;

                cache_boolean_1 =
                    true;

                return;
            }

            LARGE_INTEGER frequency;
            LARGE_INTEGER start;
            LARGE_INTEGER end;

            QueryPerformanceFrequency(&frequency);
            QueryPerformanceCounter(&start);

            unsigned long long tsc_start = __rdtsc();
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
            unsigned long long tsc_end = __rdtsc();

            QueryPerformanceCounter(&end);

            const double elapsed_seconds =
                static_cast<double>(end.QuadPart - start.QuadPart) /
                static_cast<double>(frequency.QuadPart);

            const double cpu_frequency_hz =
                (tsc_end - tsc_start) / elapsed_seconds;

            cache_cycles_per_microsecond = cpu_frequency_hz / 1'000'000.0;
            cached_frequency = cache_cycles_per_microsecond;
            calibrated.store(true);

            cache_boolean_1 =
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            cache_boolean_1 =
                false;

            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        TimeDelayClock::_handle_real_time_stamp_counter()
    {
        try
        {
            if (cache_double_1 <= 0.0 || cache_double_1 > 1e12)
            {
                cache_boolean_1 =
                    false;

                return;
            }

            if (cache_cycles_per_microsecond == 0.0)
            {
                _handle_calibrate();
            }

            unsigned __int64 start = __rdtsc();
            unsigned __int64 target =
                static_cast<unsigned __int64>(
                    cache_double_1 * cache_cycles_per_microsecond);

            while ((__rdtsc() - start) < target)
            {
                _mm_pause();
            }

            cache_boolean_1 =
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            cache_boolean_1 =
                false;

            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        TimeDelayClock::_handle_query_performance_counter()
    {
        try
        {
            if (cache_double_1 <= 0.0 || cache_double_1 > 1e12)
            {
                cache_boolean_1 =
                    false;

                return;
            }

            LARGE_INTEGER frequency;
            LARGE_INTEGER start;
            LARGE_INTEGER current;

            QueryPerformanceFrequency(&frequency);
            QueryPerformanceCounter(&start);

            double elapsed = 0.0;

            do
            {
                QueryPerformanceCounter(&current);
                elapsed = (current.QuadPart - start.QuadPart) *
                    1'000'000.0 / frequency.QuadPart;
            } while (elapsed < cache_double_1);

            cache_boolean_1 =
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            cache_boolean_1 =
                false;

            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }
}
