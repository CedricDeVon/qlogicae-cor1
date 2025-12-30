#include "pch.hpp"

#include "../includes/mutex_manager.hpp"

namespace QLogicaeCppCore
{
    MutexManager&
        MutexManager::instance =
            InstanceManager::instance.get_instance<MutexManager>();
    
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

    std::unordered_map<std::pair<void*, std::string>, folly::MicroSpinLock, PairHashOperator>
        MutexManager::folly_micro_spin_lock_collection;

    MutexManager::MutexManager()
    {
        
    }

    MutexManager::~MutexManager()
    {
        destruct();
    }

    bool
        MutexManager::construct(
            const MutexManagerConfigurationsParameters&
                new_configurations_parameters
        )
    {
        MutexManagerConfigurationsParameters::instance =
            new_configurations_parameters;

        _construct();

        return ValueCache::boolean_1;
    }

    bool
        MutexManager::construct()
    {
        MutexManagerConfigurationsParameters::instance =
            {};

        _construct();

        return ValueCache::boolean_1;
    }

    void
        MutexManager::_construct()
    {
        try
        {
            MutexManagerConfigurations::instance
                .construct(
                    MutexManagerConfigurationsParameters::instance
                );

            ValueCache::boolean_1 = true;
        }
        catch (...)
        {
            ValueCache::boolean_1 = false;
        }
    }

    bool
        MutexManager::destruct()
    {
        _destruct();

        return ValueCache::boolean_1;
    }

    void
        MutexManager::_destruct()
    {
        try
        {
            ValueCache::boolean_1 = true;
        }
        catch (...)
        {
            ValueCache::boolean_1 = false;
        }
    }

    bool
        MutexManager::lock_micro_mutex()
    {
        ValueCache::void_pointer_1 =
            this;

        ValueCache::string_view_1 =
            MutexManagerConfigurations::base_name;

        _lock_micro_mutex();

        return ValueCache::boolean_1;
    }

    bool
        MutexManager::lock_micro_mutex(
            const void* pointer
        )
    {
        ValueCache::void_pointer_1 =
            const_cast<void*>(pointer);

        ValueCache::string_view_1 =
            MutexManagerConfigurations::base_name;

        _lock_micro_mutex();

        return ValueCache::boolean_1;
    }

    bool
        MutexManager::lock_micro_mutex(
            const void* pointer,
            const std::string_view& name
        )
    {
        ValueCache::void_pointer_1 =
            const_cast<void*>(pointer);

        ValueCache::string_view_1 =
            name;

        _lock_micro_mutex();

        return ValueCache::boolean_1;
    }

    void
        MutexManager::_lock_micro_mutex()
    {
        try
        {
            folly::MicroSpinLock*
                micro_spin_lock =
                &folly_micro_spin_lock_collection[
            {
                ValueCache::void_pointer_1,
                    ValueCache::string_view_1.data()
            }
                ];

            micro_spin_lock->lock();

            ValueCache::boolean_1 = true;
        }
        catch (...)
        {
            ValueCache::boolean_1 = false;
        }
    }

    bool
        MutexManager::unlock_micro_mutex()
    {
        _unlock_micro_mutex();

        return ValueCache::boolean_1;
    }

    bool
        MutexManager::unlock_micro_mutex(
            const void* pointer
        )
    {
        ValueCache::void_pointer_1 =
            const_cast<void*>(pointer);

        ValueCache::string_view_1 =
            MutexManagerConfigurations::base_name;

        _unlock_micro_mutex();

        return ValueCache::boolean_1;
    }

    bool
        MutexManager::unlock_micro_mutex(
            const void* pointer,
            const std::string_view& name
        )
    {
        ValueCache::void_pointer_1 =
            const_cast<void*>(pointer);

        ValueCache::string_view_1 =
            name;

        _unlock_micro_mutex();

        return ValueCache::boolean_1;
    }

    void
        MutexManager::_unlock_micro_mutex()
    {
        try
        {
            folly::MicroSpinLock*
                micro_spin_lock =
                &folly_micro_spin_lock_collection
                [
            {
                this,
                    MutexManagerConfigurations::base_name
            }
                ];

            micro_spin_lock->unlock();

            ValueCache::boolean_1 = true;
        }
        catch (...)
        {
            ValueCache::boolean_1 = false;
        }
    }

    bool
        MutexManager::clear_all_collections()
    {
        _clear_all_collections();

        return ValueCache::boolean_1;
    }

    void
        MutexManager::_clear_all_collections()
    {
        try
        {
            mutex_collection.clear();
            timed_mutex_collection.clear();
            recursive_mutex_collection.clear();
            recursive_timed_mutex_collection.clear();
            shared_mutex_collection.clear();
            boost_mutex_collection.clear();
            boost_timed_mutex_collection.clear();
            boost_recursive_mutex_collection.clear();
            boost_recursive_timed_mutex_collection.clear();
            boost_shared_mutex_collection.clear();
            folly_micro_spin_lock_collection.clear();

            ValueCache::boolean_1 = true;
        }
        catch (...)
        {
            ValueCache::boolean_1 = false;
        }
    }
}
