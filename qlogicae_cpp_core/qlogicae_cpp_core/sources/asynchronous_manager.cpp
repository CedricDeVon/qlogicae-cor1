#include "pch.hpp"

#include "../includes/asynchronous_manager.hpp"

namespace QLogicaeCppCore
{    
    AsynchronousManager&
        AsynchronousManager::singleton =
            SingletonManager::get_singleton<AsynchronousManager>();

    AsynchronousManager::AsynchronousManager()        
    {        
        _construct();
    }

    AsynchronousManager::~AsynchronousManager()
    {        
        _destruct();
    }

    bool
        AsynchronousManager::construct()
    {        
        _construct();

        return
            ValueCache::boolean_1;
    }

    void
        AsynchronousManager::_construct()
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
        AsynchronousManager::destruct()
    {        
        _destruct();

        return
            ValueCache::boolean_1;
    }

    void
        AsynchronousManager::_destruct()
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
        AsynchronousManager::setup(
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
        AsynchronousManager::setup()
    {
        AsynchronousManagerConfigurations::cache =
            {};

        _setup();

        return
            ValueCache::boolean_1;
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
            ValueCache::boolean_1;
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
            _begin_one_thread(
                callback
            );

            return
                ValueCache::boolean_1;
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
        if (AsynchronousManagerConfigurations::cache_is_enabled)
        {
            ValueCache::boolean_1 =
                false;

            return;
        }

        boost::unique_lock<boost::mutex>
            unique_lock(AsynchronousManagerUtilities::mutex);

        if (AsynchronousManagerUtilities::main_thread_pool == nullptr)
        {
            AsynchronousManagerUtilities::main_thread_pool =
                std::make_shared<boost::asio::thread_pool>(
                    std::thread::hardware_concurrency()
                );
        }

        boost::asio::post(
            *AsynchronousManagerUtilities::main_thread_pool,
            callback
        );

        ValueCache::boolean_1 =
            true;
    }
}
