#include "pch.hpp"

#include "../includes/asynchronous_manager_utilities.hpp"

namespace QLogicaeCppCore
{    
    std::shared_ptr<boost::asio::thread_pool>
        AsynchronousManagerUtilities::main_thread_pool =
            nullptr;

    std::shared_ptr<boost::asio::thread_pool>
        AsynchronousManagerUtilities::temporary_thread_pool =
            nullptr;

    AsynchronousManagerConfigurations
        AsynchronousManagerUtilities::configurations =
            {};

    boost::mutex
        AsynchronousManagerUtilities::mutex;

    AsynchronousManagerUtilities&
        AsynchronousManagerUtilities::singleton =
            SingletonManager::get_singleton<AsynchronousManagerUtilities>();

    AsynchronousManagerUtilities::AsynchronousManagerUtilities()
    {
        _construct();
    }

    AsynchronousManagerUtilities::~AsynchronousManagerUtilities()
    {
        _destruct();
    }

    bool
        AsynchronousManagerUtilities::construct()
    {
        _construct();

        return
            ValueCache::boolean_1;
    }

    void
        AsynchronousManagerUtilities::_construct()
    {
        try
        {
            main_thread_pool =
                std::make_shared<boost::asio::thread_pool>(
                    std::thread::hardware_concurrency()
                );

            temporary_thread_pool =
                nullptr;

            ValueCache::boolean_1 =
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
            ValueCache::boolean_1;
    }

    void
        AsynchronousManagerUtilities::_destruct()
    {
        try
        {
            ValueCache::boolean_1 =
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
            ValueCache::boolean_1;
    }

    bool
        AsynchronousManagerUtilities::setup()
    {
        AsynchronousManagerConfigurations::cache =
            {};

        _setup();

        return
            ValueCache::boolean_1;
    }

    void
        AsynchronousManagerUtilities::_setup()
    {
        try
        {
            AsynchronousManagerConfigurations::cache_is_enabled =
                AsynchronousManagerConfigurations::default_is_enabled =
                AsynchronousManagerConfigurations::cache.is_enabled;

            ValueCache::boolean_1 =
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
            ValueCache::boolean_1;
    }

    void
        AsynchronousManagerUtilities::_reset()
    {
        try
        {
            AsynchronousManagerConfigurations::cache_is_enabled =
                AsynchronousManagerConfigurations::default_is_enabled =
                AsynchronousManagerConfigurations::initial_is_enabled;

            ValueCache::boolean_1 =
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
            ValueCache::boolean_1;
    }

    void AsynchronousManagerUtilities::_complete_all_threads()
    {
        try
        {
            if (!AsynchronousManagerConfigurations::cache_is_enabled)
            {
                ValueCache::boolean_1 = 
                    false;

                return;
            }

            {
                boost::unique_lock<boost::mutex>
                    unique_lock(mutex);

                temporary_thread_pool =
                    main_thread_pool;

                main_thread_pool.reset();
            }

            if (temporary_thread_pool)
            {
                temporary_thread_pool->join();
            }

            ValueCache::boolean_1 =
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
