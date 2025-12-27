#include "pch.hpp"

#include "../includes/asynchronous_manager.hpp"

namespace QLogicaeCppCore
{
    AsynchronousManager&
        AsynchronousManager::instance =
        InstanceManager::instance.get_instance<AsynchronousManager>();

    bool
        AsynchronousManager::_boolean_ouput_cache_1 =
            false;

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
        try
        {
            _construct();
        }
        catch (...)
        {
            _boolean_ouput_cache_1 = false;
        }

        return _boolean_ouput_cache_1;
    }

    void
        AsynchronousManager::_construct()
    {
        _thread_pool =
            std::make_shared<boost::asio::thread_pool>(
                std::thread::hardware_concurrency()
            );

        _boolean_ouput_cache_1 =
            true;
    }

    bool
        AsynchronousManager::destruct()
    {
        try
        {
            _destruct();
        }
        catch (...)
        {
            _boolean_ouput_cache_1 = false;
        }

        return _boolean_ouput_cache_1;
    }

    void
        AsynchronousManager::_destruct()
    {
        _complete_all_threads();
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
            _boolean_ouput_cache_1 = false;
        }

        return _boolean_ouput_cache_1;
    }

    void AsynchronousManager::_begin_one_thread(
        const std::function<void()>& callback
    )
    {
        MutexManager::instance._void_pointer_ouput_cache_1 = this;
        MutexManager::instance._lock_mutex<std::unique_lock<std::mutex>, std::mutex>();

        if (_thread_pool == nullptr)
        {
            _thread_pool =
                std::make_shared<boost::asio::thread_pool>(
                    std::thread::hardware_concurrency());
        }

        boost::asio::post(*_thread_pool, callback);

        _boolean_ouput_cache_1 =
            true;
    }

    bool AsynchronousManager::complete_all_threads()
    {
        try
        {
            _complete_all_threads();
        }
        catch (...)
        {
            _boolean_ouput_cache_1 = false;
        }

        return _boolean_ouput_cache_1;
    }

    void AsynchronousManager::_complete_all_threads()
    {
        {
            MutexManager::instance._void_pointer_ouput_cache_1 = this;
            MutexManager::instance._lock_mutex<std::unique_lock<std::mutex>, std::mutex>();

            _temporary_thread_pool = _thread_pool;
            _thread_pool.reset();
        }

        if (_temporary_thread_pool)
        {
            _temporary_thread_pool->join();
        }

        _boolean_ouput_cache_1 =
            true;
    }
}
