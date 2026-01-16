#include "pch.hpp"

#include "../includes/interval_clock.hpp"

namespace QLogicaeCppCore
{    
    IntervalClock::IntervalClock(
        const IntervalClockConfigurations&
            new_configurations
    )
    {    
        try
        {
            IntervalClockConfigurations::cache =
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

    IntervalClock::IntervalClock()
    {            
        try
        {
            IntervalClockConfigurations::cache =
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

    IntervalClock::~IntervalClock()
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
        IntervalClock::construct(
            const IntervalClockConfigurations&
                new_configurations
        )
    {
        IntervalClockConfigurations::cache =
            new_configurations;

        _handle_construct();

        return
            cache_boolean_1;
    }

    bool
        IntervalClock::construct()
    {
        IntervalClockConfigurations::cache =
            {};

        _handle_construct();

        return
            cache_boolean_1;
    }

    bool
        IntervalClock::destruct()
    {
        _handle_destruct();

        return
            cache_boolean_1;
    }
    
    bool
        IntervalClock::setup(
            const IntervalClockConfigurations&
                new_configurations
        )
    {
        IntervalClockConfigurations::cache =
            new_configurations;

        _handle_setup();

        return
            cache_boolean_1;
    }

    bool
        IntervalClock::setup()
    {
        IntervalClockConfigurations::cache =
            {};

        _handle_setup();

        return
            cache_boolean_1;
    }

    bool
        IntervalClock::reset()
    {
        _handle_reset();

        return
            cache_boolean_1;
    }

    bool
        IntervalClock::start()
    {
        _handle_start();

        return
            cache_boolean_1;
    }

    bool
        IntervalClock::stop()
    {
        _handle_stop();

        return
            cache_boolean_1;
    }

    bool
        IntervalClock::pause()
    {
        _handle_pause();

        return
            cache_boolean_1;
    }

    bool
        IntervalClock::resume()
    {
        _handle_resume();

        return
            cache_boolean_1;
    }

    bool
        IntervalClock::cancel()
    {
        _handle_cancel();

        return
            cache_boolean_1;
    }

    bool
        IntervalClock::restart()
    {
        _handle_restart();

        return
            cache_boolean_1;
    }

    bool
        IntervalClock::is_paused()
    {
        _handle_is_paused();

        return
            cache_boolean_1;
    }

    bool
        IntervalClock::is_running()
    {
        _handle_is_running();

        return
            cache_boolean_1;
    }

    bool
        IntervalClock::is_cancelled()
    {
        _handle_is_cancelled();

        return
            cache_boolean_1;
    }

    size_t
        IntervalClock::get_execution_count()
    {
        _handle_get_execution_count();

        return
            cache_size_t_1;
    }

    bool
        IntervalClock::run_interval()
    {
        _handle_run_interval();

        return
            cache_boolean_1;
    }

    void
        IntervalClock::_handle_construct()
    {
        try
        {            
            configurations =
                IntervalClockConfigurations::cache;

            cache_is_cancelled.store(false);
            cache_is_paused.store(false);
            cache_is_running.store(false);
            cache_execution_count.store(0);

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
        IntervalClock::_handle_destruct()
    {
        try
        {
            _handle_cancel();

            if (cache_thread.joinable())
            {
                cache_thread.join();
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
        IntervalClock::_handle_setup()
    {
        try
        {
            configurations =
                IntervalClockConfigurations::cache;

            cache_is_cancelled.store(false);
            cache_is_paused.store(false);
            cache_is_running.store(false);
            cache_execution_count.store(0);

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
        IntervalClock::_handle_reset()
    {
        try
        {
            _handle_cancel();

            if (cache_thread.joinable())
            {
                cache_thread.join();
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
        IntervalClock::_handle_start()
    {
        try
        {
            if (cache_thread.joinable())
            {
                if (!cache_is_running.load())
                {
                    cache_thread.join();
                }
                else
                {
                    cache_boolean_1 =
                        false;

                    return;
                }
            }

            cache_is_cancelled.store(false);
            cache_is_paused.store(false);
            cache_is_running.store(true);
            cache_execution_count.store(0);

            cache_thread = std::thread(
                &IntervalClock::_handle_run_interval,
                this
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

    void
        IntervalClock::_handle_stop()
    {
        try
        {
            cache_is_running.store(false);
            cache_is_paused.store(false);
            cache_condition_variable.notify_all();

            if (cache_thread.joinable() &&
                !cache_is_running.load()
            )
            {
                cache_thread.join();
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
        IntervalClock::_handle_pause()
    {
        try
        {
            cache_is_paused.store(
                true
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

    void
        IntervalClock::_handle_resume()
    {
        try
        {
            if (cache_is_paused.load())
            {
                cache_is_paused.store(false);
                cache_condition_variable.notify_all();
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
        IntervalClock::_handle_cancel()
    {
        try
        {
            cache_is_cancelled.store(true);
            cache_is_paused.store(false);
            cache_is_running.store(false);
            cache_condition_variable.notify_all();

            if (cache_thread.joinable())
            {
                cache_thread.join();
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
        IntervalClock::_handle_restart()
    {
        try
        {
            _handle_cancel();

            cache_execution_count.store(0);
            cache_is_cancelled.store(false);
            cache_is_paused.store(false);
            cache_is_running.store(false);

            _handle_start();
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
        IntervalClock::_handle_is_paused()
    {
        try
        {
            cache_boolean_1 =
                cache_is_paused.load();
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
        IntervalClock::_handle_is_running()
    {
        try
        {
            cache_boolean_1 =
                cache_is_running.load();
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
        IntervalClock::_handle_is_cancelled()
    {
        try
        {
            cache_boolean_1 =
                cache_is_cancelled.load();
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
        IntervalClock::_handle_get_execution_count()
    {
        try
        {
            cache_size_t_1 =
                cache_execution_count.load();
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            cache_size_t_1 =
                0;

            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        IntervalClock::_handle_run_interval()
    {
        try
        {
            cache_is_running.store(true);
            cache_is_cancelled.store(false);

            if (configurations.is_executed_immediately &&
                !cache_is_cancelled.load())
            {
                size_t current = ++cache_execution_count;

                bool should_continue = false;
                try
                {
                    should_continue = configurations.callback(current);
                }
                catch (...)
                {
                    should_continue = false;
                }

                if (!should_continue)
                {
                    cache_is_running.store(false);
                    cache_condition_variable.notify_all();

                    cache_boolean_1 =
                        true;

                    return;
                }

                if (configurations.maximum_interval_count &&
                    cache_execution_count.load() >= configurations.maximum_interval_count)
                {
                    cache_is_running.store(false);
                    cache_condition_variable.notify_all();

                    cache_boolean_1 =
                        true;

                    return;
                }
            }

            while (!cache_is_cancelled.load() && cache_is_running.load())
            {
                std::unique_lock<std::mutex> lock(cache_mutex);

                if (cache_is_paused.load())
                {
                    cache_condition_variable.wait(lock, [this]() {
                        return !cache_is_paused.load() || cache_is_cancelled.load();
                        });
                }

                if (cache_is_cancelled.load() || !cache_is_running.load())
                {
                    break;
                }

                auto start = std::chrono::steady_clock::now();
                lock.unlock();

                size_t current = ++cache_execution_count;

                bool should_continue = false;
                try
                {
                    should_continue = configurations.callback(current);
                }
                catch (...)
                {
                    should_continue = false;
                }

                if (!should_continue)
                {
                    cache_is_running.store(false);
                    cache_condition_variable.notify_all();

                    cache_boolean_1 =
                        true;

                    return;
                }

                if (configurations.maximum_interval_count &&
                    cache_execution_count.load() >= configurations.maximum_interval_count)
                {
                    cache_is_running.store(false);
                    cache_condition_variable.notify_all();

                    cache_boolean_1 =
                        true;

                    return;
                }

                auto end = std::chrono::steady_clock::now();
                auto elapsed =
                    std::chrono::duration_cast<std::chrono::milliseconds>(
                        end - start
                    );
                auto delay =
                    configurations.delay_in_milliseconds > elapsed ?
                    configurations.delay_in_milliseconds - elapsed :
                    std::chrono::milliseconds(0);

                for (std::chrono::milliseconds waited(0);
                    waited < delay && !cache_is_cancelled.load() && cache_is_running.load();
                    )
                {
                    auto to_wait = std::min<std::chrono::milliseconds>(
                        std::chrono::milliseconds(50),
                        delay - waited
                    );

                    std::this_thread::sleep_for(to_wait);
                    waited += to_wait;
                }
            }

            cache_is_running.store(false);
            cache_condition_variable.notify_all();

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
