#include "pch.hpp"

#include "../includes/mutex_manager.hpp"

namespace QLogicaeCppCore
{
    MutexManager&
        MutexManager::instance =
            InstanceManager::instance.get_instance<MutexManager>();

    folly::MicroSpinLock
        MutexManager::micro_spinlock;

    std::unordered_map<std::pair<void*, std::string>, std::mutex, PairHashOperator>
        MutexManager::mutex_collection;

    std::unordered_map<std::pair<void*, std::string>, std::timed_mutex, PairHashOperator>
        MutexManager::timed_mutex_collection;

    std::unordered_map<std::pair<void*, std::string>, std::recursive_mutex, PairHashOperator>
        MutexManager::recursive_mutex_collection;

    std::unordered_map<std::pair<void*, std::string>, std::recursive_timed_mutex, PairHashOperator>
        MutexManager::recursive_timed_mutex_collection;

    std::unordered_map<std::pair<void*, std::string>, std::shared_mutex, PairHashOperator>
        MutexManager::shared_mutex_collection;

    std::unordered_map<std::pair<void*, std::string>, boost::mutex, PairHashOperator>
        MutexManager::boost_mutex_collection;

    std::unordered_map<std::pair<void*, std::string>, boost::timed_mutex, PairHashOperator>
        MutexManager::boost_timed_mutex_collection;

    std::unordered_map<std::pair<void*, std::string>, boost::recursive_mutex, PairHashOperator>
        MutexManager::boost_recursive_mutex_collection;

    std::unordered_map<std::pair<void*, std::string>, boost::recursive_timed_mutex, PairHashOperator>
        MutexManager::boost_recursive_timed_mutex_collection;

    std::unordered_map<std::pair<void*, std::string>, boost::shared_mutex, PairHashOperator>
        MutexManager::boost_shared_mutex_collection;


    MutexManager::MutexManager()
    {
        
    }

    MutexManager::~MutexManager()
    {
        destruct();
    }

    bool
        MutexManager::construct()
    {
        _construct();

        return boolean_cache_1;
    }

    void
        MutexManager::_construct()
    {
        try
        {
            boolean_cache_1 = true;
        }
        catch (...)
        {
            boolean_cache_1 = false;
        }        
    }

    bool
        MutexManager::destruct()
    {
        _destruct();

        return boolean_cache_1;
    }

    void
        MutexManager::_destruct()
    {
        try
        {
            boolean_cache_1 = true;
        }
        catch (...)
        {
            boolean_cache_1 = false;
        }        
    }

    bool
        MutexManager::lock_micro_mutex()
    {
        _lock_micro_mutex();

        return boolean_cache_1;
    }

    void
        MutexManager::_lock_micro_mutex()
    {
        try
        {
            micro_spinlock.lock();

            boolean_cache_1 = true;
        }
        catch (...)
        {
            boolean_cache_1 = false;
        }
    }

    bool
        MutexManager::unlock_micro_mutex()
    {        
        _unlock_micro_mutex();

        return boolean_cache_1;
    }

    void
        MutexManager::_unlock_micro_mutex()
    {
        try
        {
            micro_spinlock.unlock();

            boolean_cache_1 = true;
        }
        catch (...)
        {
            boolean_cache_1 = false;
        }
    }
}
