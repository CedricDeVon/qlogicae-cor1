#include "pch.hpp"

#include "../includes/timeout_clock.hpp"

namespace QLogicaeCppCore
{   
    TimeoutClock::TimeoutClock(
        const TimeoutClockConfigurations&
            new_configurations
    )
    {
        try
        {
            TimeoutClockConfigurations::cache =
                new_configurations;

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

    TimeoutClock::TimeoutClock()
    {
        try
        {
            TimeoutClockConfigurations::cache =
                {};

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

    TimeoutClock::~TimeoutClock()
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

    bool TimeoutClock::construct(
        const TimeoutClockConfigurations&
            new_configurations
    )
    {
        TimeoutClockConfigurations::cache =
            new_configurations;

        _handle_construct();

        return
            cache_boolean_1;
    }

    bool TimeoutClock::construct()
    {
        TimeoutClockConfigurations::cache =
            {};

        _handle_construct();

        return
            cache_boolean_1;
    }

    bool TimeoutClock::destruct()
    {
        _handle_destruct();

        return
            cache_boolean_1;
    }

    bool TimeoutClock::setup(
        const TimeoutClockConfigurations&
            new_configurations
    )
    {
        TimeoutClockConfigurations::cache =
            new_configurations;

        _handle_construct();

        return
            cache_boolean_1;
    }

    bool TimeoutClock::setup()
    {
        TimeoutClockConfigurations::cache =
            {};

        _handle_construct();

        return
            cache_boolean_1;
    }

    bool TimeoutClock::reset()
    {        
        _handle_reset();

        return
            cache_boolean_1;
    }

    bool TimeoutClock::cancel()
    {
        _handle_cancel();

        return
            cache_boolean_1;
    }

    bool TimeoutClock::restart()
    {
        _handle_restart();

        return
            cache_boolean_1;
    }

    bool TimeoutClock::is_cancelled()
    {
        _handle_is_cancelled();

        return
            cache_boolean_1;
    }

    bool TimeoutClock::start_thread()
    {
        _handle_start_thread();

        return
            cache_boolean_1;
    }

    void TimeoutClock::_handle_construct()
    {
        try
        {
            configurations =
                TimeoutClockConfigurations::cache;

            cache_is_executed_immediately_async.store(
                configurations.is_executed_immediately
            );
            cache_is_flag_stopped_async.store(false);
            cache_is_cancelled_async.store(false);

            _handle_start_thread();

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

    void TimeoutClock::_handle_destruct()
    {
        try
        {
            configurations =
                {};

            _handle_cancel();

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

    void TimeoutClock::_handle_setup()
    {
        try
        {
            configurations =
                TimeoutClockConfigurations::cache;

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

    void TimeoutClock::_handle_reset()
    {
        try
        {
            configurations =
                {};

            _handle_cancel();

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

    void TimeoutClock::_handle_cancel()
    {
        try
        {
            std::lock_guard<std::mutex>
                lock(
                    cache_thread_mutex
                );

            cache_is_flag_stopped_async.store(true);

            if (cache_thread.joinable())
            {
                cache_thread.request_stop();
                cache_thread.join();
            }

            cache_is_cancelled_async.store(true);

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

    void TimeoutClock::_handle_restart()
    {
        try
        {
            _handle_cancel();

            cache_is_flag_stopped_async.store(false);
            cache_is_cancelled_async.store(false);
            cache_is_executed_immediately_async.store(
                configurations.is_executed_immediately
            );

            _handle_start_thread();

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

    void TimeoutClock::_handle_is_cancelled()
    {
        try
        {
            cache_boolean_1 =
                cache_is_cancelled_async.load();
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

    void TimeoutClock::_handle_start_thread()
    {
        try
        {
            std::unique_lock<std::mutex>
                lock(
                    cache_thread_mutex
                );

            if (cache_thread.joinable())
            {
                cache_thread.request_stop();
                cache_thread.join();
            }

            auto local_callback =
                configurations.callback;
            
            auto local_delay =
                configurations.delay_in_milliseconds;
            
            bool execute_immediately =
                configurations.is_executed_immediately || local_delay.count() == 0;

            cache_thread = std::jthread([local_callback, local_delay, execute_immediately](std::stop_token stop_token)
                {
                    if (!execute_immediately)
                    {
                        std::this_thread::sleep_for(local_delay);
                    }

                    if (stop_token.stop_requested())
                    {
                        return;
                    }

                    try
                    {
                        local_callback();
                    }
                    catch (...)
                    {

                    }
                }
            );

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
