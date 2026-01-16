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
            AsynchronousManagerConfigurations::cache_configurations =
                {};

            _handle_construct();

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

    AsynchronousManagerUtilities::~AsynchronousManagerUtilities()
    {
        try
        {
            AsynchronousManagerConfigurations::cache_configurations =
                {};

            _handle_destruct();

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

    bool
        AsynchronousManagerUtilities::construct(
            const AsynchronousManagerConfigurations&
                configurations
        )
    {
        AsynchronousManagerConfigurations::cache_configurations =
            configurations;

        _handle_construct();

        return
            cache_boolean_1;
    }

    bool
        AsynchronousManagerUtilities::destruct(
            const AsynchronousManagerConfigurations&
                configurations
        )
    {
        AsynchronousManagerConfigurations::cache_configurations =
            configurations;

        _handle_destruct();

        return
            cache_boolean_1;
    }
    
    bool
        AsynchronousManagerUtilities::setup(
            const AsynchronousManagerConfigurations&
                configurations
        )
    {
        AsynchronousManagerConfigurations::cache_configurations =
            configurations;

        _handle_setup();

        return
            cache_boolean_1;
    }

    bool
        AsynchronousManagerUtilities::reset(
            const AsynchronousManagerConfigurations&
                configurations
        )
    {
        AsynchronousManagerConfigurations::cache_configurations =
            configurations;

        _handle_reset();

        return
            cache_boolean_1;
    }

    bool AsynchronousManagerUtilities::complete_all_threads(
            const AsynchronousManagerConfigurations&
                configurations
        )
    {
        AsynchronousManagerConfigurations::cache_configurations =
            configurations;
        AsynchronousManagerConfigurations::_handle_setup_caches();

        _handle_complete_all_threads();

        AsynchronousManagerConfigurations::cache_configurations =
            {};
        AsynchronousManagerConfigurations::_handle_setup_caches();

        return
            cache_boolean_1;
    }

    void
        AsynchronousManagerUtilities::_handle_construct()
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
            cache_boolean_1 =
                false;

            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        AsynchronousManagerUtilities::_handle_destruct()
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
        AsynchronousManagerUtilities::_handle_setup()
    {
        try
        {
            AsynchronousManagerConfigurations::_handle_setup();

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
        AsynchronousManagerUtilities::_handle_reset()
    {
        try
        {
            AsynchronousManagerConfigurations::_handle_reset();

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

    void AsynchronousManagerUtilities::_handle_complete_all_threads()
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
            cache_boolean_1 =
                false;

            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }
}
