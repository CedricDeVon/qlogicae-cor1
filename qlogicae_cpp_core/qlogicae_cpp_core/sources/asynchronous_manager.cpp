#include "pch.hpp"

#include "../includes/asynchronous_manager.hpp"

namespace QLogicaeCppCore
{    
    AsynchronousManager&
        AsynchronousManager::instance =
            InstanceManager::instance
                .get_instance<AsynchronousManager>();

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

        return ValueCache::boolean_1;
    }

    void
        AsynchronousManager::_construct()
    {
        try
        {            
            ValueCache::boolean_1 =
                true;
        }
        catch (...)
        {
            ValueCache::boolean_1 =
                false;
        }               
    }

    bool
        AsynchronousManager::destruct()
    {        
        _destruct();

        return ValueCache::boolean_1;
    }

    void
        AsynchronousManager::_destruct()
    {
        try
        {
            AsynchronousManagerCache::instance
                ._destruct();
        }
        catch (...)
        {
            ValueCache::boolean_1 =
                false;
        }
    }

    bool
        AsynchronousManager::setup(
            const AsynchronousManagerConfigurations&
                new_configurations
        )
    {
        AsynchronousManagerCache::configurations =
            new_configurations;

        _setup();

        return ValueCache::boolean_1;
    }

    bool
        AsynchronousManager::setup()
    {
        AsynchronousManagerCache::configurations =
            {};

        _setup();

        return ValueCache::boolean_1;
    }

    void
        AsynchronousManager::_setup()
    {
        try
        {
            AsynchronousManagerCache::instance
                .setup();
        }
        catch (...)
        {
            ValueCache::boolean_1 =
                false;
        }
    }

    bool
        AsynchronousManager::reset()
    {
        _reset();

        return ValueCache::boolean_1;
    }

    void
        AsynchronousManager::_reset()
    {
        try
        {
            AsynchronousManagerCache::instance
                .reset();
        }
        catch (...)
        {
            ValueCache::boolean_1 =
                false;
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
        }
        catch (...)
        {
            ValueCache::boolean_1 = false;
        }

        return ValueCache::boolean_1;
    }

    void AsynchronousManager::_begin_one_thread(
        const std::function<void()>& callback
    )
    {
        if (AsynchronousManagerCache::is_enabled)
        {
            ValueCache::boolean_1 =
                false;

            return;
        }

        boost::unique_lock<boost::mutex>
            unique_lock(AsynchronousManagerCache::mutex);

        if (AsynchronousManagerCache::main_thread_pool == nullptr)
        {
            AsynchronousManagerCache::main_thread_pool =
                std::make_shared<boost::asio::thread_pool>(
                    std::thread::hardware_concurrency()
                );
        }

        boost::asio::post(
            *AsynchronousManagerCache::main_thread_pool,
            callback
        );

        ValueCache::boolean_1 =
            true;
    }
}
