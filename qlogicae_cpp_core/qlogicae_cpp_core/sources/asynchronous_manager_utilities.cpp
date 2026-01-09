#include "pch.hpp"

#include "../includes/asynchronous_manager_utilities.hpp"

namespace QLogicaeCppCore
{            
    bool
        AsynchronousManagerUtilities::cache_boolean_1 =
            false;

    std::shared_ptr<boost::asio::thread_pool>
        AsynchronousManagerUtilities::cache_main_thread_pool =
            nullptr;

    std::shared_ptr<boost::asio::thread_pool>
        AsynchronousManagerUtilities::cache_temporary_thread_pool =
            nullptr;

    boost::mutex
        AsynchronousManagerUtilities::cache_mutex;

    AsynchronousManagerUtilities&
        AsynchronousManagerUtilities::singleton =
            SingletonManager::get_singleton<AsynchronousManagerUtilities>();



    AsynchronousManagerUtilities::AsynchronousManagerUtilities()
    {
        try
        {
            _construct();
        }
        catch
            (
                const std::exception&
                exception
                )
        {
            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    AsynchronousManagerUtilities::~AsynchronousManagerUtilities()
    {
        try
        {
            _destruct();
        }
        catch
            (
                const std::exception&
                exception
                )
        {
            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    bool
        AsynchronousManagerUtilities::construct()
    {
        _construct();

        return
            cache_boolean_1;
    }

    void
        AsynchronousManagerUtilities::_construct()
    {
        try
        {
            cache_main_thread_pool =
                std::make_shared<boost::asio::thread_pool>(
                    std::thread::hardware_concurrency()
                );

            cache_temporary_thread_pool =
                nullptr;

            cache_boolean_1 =
                true;
        }
        catch
            (
                const std::exception&
                exception
                )
        {
            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    bool
        AsynchronousManagerUtilities::destruct()
    {
        _destruct();

        return
            cache_boolean_1;
    }

    void
        AsynchronousManagerUtilities::_destruct()
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
            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    bool
        AsynchronousManagerUtilities::setup(
            const AsynchronousManagerConfigurations&
            new_configurations
        )
    {
        AsynchronousManagerConfigurations::cache =
            new_configurations;

        _setup();

        return
            cache_boolean_1;
    }

    bool
        AsynchronousManagerUtilities::setup()
    {
        AsynchronousManagerConfigurations::cache =
        {};

        _setup();

        return
            cache_boolean_1;
    }

    void
        AsynchronousManagerUtilities::_setup()
    {
        try
        {
            AsynchronousManagerConfigurations::cache_is_enabled =
                AsynchronousManagerConfigurations::default_is_enabled =
                AsynchronousManagerConfigurations::cache.is_enabled;

            cache_boolean_1 =
                true;
        }
        catch
            (
                const std::exception&
                exception
                )
        {
            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    bool
        AsynchronousManagerUtilities::reset()
    {
        _reset();

        return
            cache_boolean_1;
    }

    void
        AsynchronousManagerUtilities::_reset()
    {
        try
        {
            AsynchronousManagerConfigurations::cache_is_enabled =
                AsynchronousManagerConfigurations::default_is_enabled =
                AsynchronousManagerConfigurations::initial_is_enabled;

            cache_boolean_1 =
                true;
        }
        catch
            (
                const std::exception&
                exception
                )
        {
            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    bool AsynchronousManagerUtilities::complete_all_threads()
    {
        _complete_all_threads();

        return
            cache_boolean_1;
    }

    void AsynchronousManagerUtilities::_complete_all_threads()
    {
        try
        {
            if (!AsynchronousManagerConfigurations::cache_is_enabled)
            {
                cache_boolean_1 =
                    false;

                return;
            }

            {
                boost::unique_lock<boost::mutex>
                    unique_lock(
                        cache_mutex
                    );

                cache_temporary_thread_pool =
                    cache_main_thread_pool;

                cache_main_thread_pool.reset();
            }

            if (cache_temporary_thread_pool)
            {
                cache_temporary_thread_pool->join();
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
            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }
}
