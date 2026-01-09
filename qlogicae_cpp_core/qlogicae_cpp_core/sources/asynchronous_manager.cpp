#include "pch.hpp"

#include "../includes/asynchronous_manager.hpp"

namespace QLogicaeCppCore
{        
    bool
        AsynchronousManager::cache_boolean_1 =
        false;

    AsynchronousManager&
        AsynchronousManager::singleton =
        SingletonManager::get_singleton<AsynchronousManager>();

    AsynchronousManager::AsynchronousManager()
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

    AsynchronousManager::~AsynchronousManager()
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
        AsynchronousManager::construct()
    {
        _construct();

        return
            AsynchronousManager::cache_boolean_1;
    }

    void
        AsynchronousManager::_construct()
    {
        try
        {
            AsynchronousManager::cache_boolean_1 =
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
        AsynchronousManager::destruct()
    {
        _destruct();

        return
            AsynchronousManager::cache_boolean_1;
    }

    void
        AsynchronousManager::_destruct()
    {
        try
        {
            AsynchronousManager::cache_boolean_1 =
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
        AsynchronousManager::setup(
            const AsynchronousManagerConfigurations&
            new_configurations
        )
    {
        AsynchronousManagerConfigurations::cache =
            new_configurations;

        _setup();

        return
            AsynchronousManager::cache_boolean_1;
    }

    bool
        AsynchronousManager::setup()
    {
        AsynchronousManagerConfigurations::cache =
        {};

        _setup();

        return
            AsynchronousManager::cache_boolean_1;
    }

    void
        AsynchronousManager::_setup()
    {
        try
        {
            AsynchronousManagerUtilities::singleton
                ._setup();
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
        AsynchronousManager::reset()
    {
        _reset();

        return
            AsynchronousManager::cache_boolean_1;
    }

    void
        AsynchronousManager::_reset()
    {
        try
        {
            AsynchronousManagerUtilities::singleton
                ._reset();
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

    bool AsynchronousManager::begin_one_thread(
        const std::function<void()>& callback
    )
    {
        try
        {
            if (!AsynchronousManagerConfigurations::cache_is_enabled)
            {
                return false;
            }

            _begin_one_thread(
                callback
            );

            return
                AsynchronousManager::cache_boolean_1;
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

    void AsynchronousManager::_begin_one_thread(
        const std::function<void()>& callback
    )
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
                    ErrorManager::cache_error_log =
                        exception.what();

                    ErrorManager::singleton
                        ._handle();
                }
            }
        );

        AsynchronousManager::cache_boolean_1 =
            true;
    }
}
