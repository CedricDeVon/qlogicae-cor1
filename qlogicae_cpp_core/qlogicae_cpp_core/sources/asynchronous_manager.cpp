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
        
    }

    AsynchronousManager::~AsynchronousManager()
    {        
        _destruct();
    }

    bool
        AsynchronousManager::construct()
    {        
        _construct();

        return boolean_cache_1;
    }

    void
        AsynchronousManager::_construct()
    {
        try
        {
            main_thread_pool =
                std::make_shared<boost::asio::thread_pool>(
                    std::thread::hardware_concurrency()
                );

            boolean_cache_1 =
                true;
        }
        catch (...)
        {
            boolean_cache_1 =
                false;
        }               
    }

    bool
        AsynchronousManager::destruct()
    {        
        _destruct();

        return boolean_cache_1;
    }

    void
        AsynchronousManager::_destruct()
    {
        try
        {
            _complete_all_threads();
        }
        catch (...)
        {
            boolean_cache_1 = false;
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
            boolean_cache_1 = false;
        }

        return boolean_cache_1;
    }

    void AsynchronousManager::_begin_one_thread(
        const std::function<void()>& callback
    )
    {
        if (AsynchronousManagerConfigurations::is_enabled_cache)
        {
            boolean_cache_1 =
                false;

            return;
        }

        void_pointer_cache_1 =
            this;

        MutexManager::instance
            ._lock_mutex<std::unique_lock<std::mutex>, std::mutex>();

        if (main_thread_pool == nullptr)
        {
            main_thread_pool =
                std::make_shared<boost::asio::thread_pool>(
                    std::thread::hardware_concurrency()
                );
        }

        boost::asio::post(
            *main_thread_pool,
            callback
        );

        boolean_cache_1 =
            true;
    }

    bool AsynchronousManager::complete_all_threads()
    {        
        _complete_all_threads();

        return boolean_cache_1;
    }

    void AsynchronousManager::_complete_all_threads()
    {
        try
        {
            {
                void_pointer_cache_1 =
                    this;

                MutexManager::instance
                    ._lock_mutex<std::unique_lock<std::mutex>, std::mutex>();

                temporary_thread_pool =
                    main_thread_pool;

                main_thread_pool.reset();
            }

            if (temporary_thread_pool)
            {
                temporary_thread_pool->join();
            }

            boolean_cache_1 =
                true;
        }
        catch (...)
        {
            boolean_cache_1 =
                false;
        }        
    }
}
