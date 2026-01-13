#include "pch.hpp"

#include "../includes/asynchronous_manager.hpp"

namespace QLogicaeCppCore
{        
    AsynchronousManager&
        AsynchronousManager::singleton =
            SingletonManager::get_singleton<AsynchronousManager>();



    AsynchronousManager::AsynchronousManager()
    {
        try
        {
            AsynchronousManagerConfigurations::cache_configurations =
                {};

            _handle_construct();
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            AsynchronousManagerUtilities::cache_boolean_1 =
                false;

            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    AsynchronousManager::~AsynchronousManager()
    {
        try
        {
            AsynchronousManagerConfigurations::cache_configurations =
                {};

            _handle_destruct();
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            AsynchronousManagerUtilities::cache_boolean_1 =
                false;

            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    bool
        AsynchronousManager::construct(
            const AsynchronousManagerConfigurations&
                configurations
        )
    {
        AsynchronousManagerConfigurations::cache_configurations =
            configurations;

        _handle_construct();

        return
            AsynchronousManagerUtilities::cache_boolean_1;
    }
    
    bool
        AsynchronousManager::destruct(
            const AsynchronousManagerConfigurations&
                configurations
        )
    {
        AsynchronousManagerConfigurations::cache_configurations =
            configurations;

        _handle_destruct();

        return
            AsynchronousManagerUtilities::cache_boolean_1;
    }

    bool
        AsynchronousManager::setup(
            const AsynchronousManagerConfigurations&
                configurations
        )
    {
        AsynchronousManagerConfigurations::cache_configurations =
            configurations;

        _handle_setup();

        return
            AsynchronousManagerUtilities::cache_boolean_1;
    }

    bool
        AsynchronousManager::reset(
            const AsynchronousManagerConfigurations&
                configurations
        )
    {
        AsynchronousManagerConfigurations::cache_configurations =
            configurations;

        _handle_reset();

        return
            AsynchronousManagerUtilities::cache_boolean_1;
    }

    bool AsynchronousManager::begin_one_thread(
        const std::function<void()>&
            callback,
        const AsynchronousManagerConfigurations&
            configurations
    )
    {
        AsynchronousManagerConfigurations::cache_configurations =
            configurations;
        AsynchronousManagerConfigurations::_handle_setup_caches();

        if (!AsynchronousManagerConfigurations::cache_is_enabled)
        {
            AsynchronousManagerConfigurations::cache_configurations =
                {};
            AsynchronousManagerConfigurations::_handle_setup_caches();

            return false;
        }

        _handle_begin_one_thread(
            callback
        );

        AsynchronousManagerConfigurations::cache_configurations =
            {};
        AsynchronousManagerConfigurations::_handle_setup_caches();

        return
            AsynchronousManagerUtilities::cache_boolean_1;
    }

    void
        AsynchronousManager::_handle_construct()
    {
        try
        {
            AsynchronousManagerUtilities::cache_boolean_1 =
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            AsynchronousManagerUtilities::cache_boolean_1 =
                false;

            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        AsynchronousManager::_handle_destruct()
    {
        try
        {
            AsynchronousManagerUtilities::cache_boolean_1 =
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            AsynchronousManagerUtilities::cache_boolean_1 =
                false;

            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        AsynchronousManager::_handle_setup()
    {
        try
        {
            AsynchronousManagerUtilities::singleton
                ._handle_setup();
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            AsynchronousManagerUtilities::cache_boolean_1 =
                false;

            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        AsynchronousManager::_handle_reset()
    {
        try
        {
            AsynchronousManagerUtilities::singleton
                ._handle_reset();
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            AsynchronousManagerUtilities::cache_boolean_1 =
                false;

            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void AsynchronousManager::_handle_begin_one_thread(
        const std::function<void()>& callback
    )
    {
        try
        {
            boost::unique_lock<boost::mutex>
                unique_lock(AsynchronousManagerUtilities::cache_mutex);

            if (AsynchronousManagerUtilities::cache_main_thread_pool == nullptr)
            {
                AsynchronousManagerUtilities::cache_main_thread_pool =
                    std::make_shared<boost::asio::thread_pool>(
                        std::thread::hardware_concurrency()
                    );
            }

            boost::asio::post(
                *AsynchronousManagerUtilities::cache_main_thread_pool,
                [callback]()
                {
                    try
                    {
                        callback();
                    }
                    catch
                    (
                        const std::exception&
                            exception
                    )
                    {
                        AsynchronousManagerUtilities::cache_boolean_1 =
                            false;

                        ErrorManager::cache_error_log =
                            exception.what();

                        ErrorManager::singleton
                            ._handle();
                    }
                }
            );

            AsynchronousManagerUtilities::cache_boolean_1 =
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            AsynchronousManagerUtilities::cache_boolean_1 =
                false;

            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }        
    }
}
