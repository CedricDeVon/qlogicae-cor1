#include "pch.hpp"

#include "../includes/mutex_manager_cache.hpp"

namespace QLogicaeCppCore
{    
    void*
        MutexManagerCache::pointer =
            MutexManagerConfigurations::default_pointer;

    std::string
        MutexManagerCache::name =
            MutexManagerConfigurations::default_name;

    MutexManagerConfigurations
        MutexManagerCache::configurations =
            {};

    std::unordered_map<std::pair<void*, std::string>, std::mutex, PairHashOperator>
        MutexManagerCache::mutex_collection;

    std::unordered_map<std::pair<void*, std::string>, std::timed_mutex, PairHashOperator>
        MutexManagerCache::timed_mutex_collection;

    std::unordered_map<std::pair<void*, std::string>, std::recursive_mutex, PairHashOperator>
        MutexManagerCache::recursive_mutex_collection;

    std::unordered_map<std::pair<void*, std::string>, std::recursive_timed_mutex, PairHashOperator>
        MutexManagerCache::recursive_timed_mutex_collection;

    std::unordered_map<std::pair<void*, std::string>, std::shared_mutex, PairHashOperator>
        MutexManagerCache::shared_mutex_collection;

    std::unordered_map<std::pair<void*, std::string>, boost::mutex, PairHashOperator>
        MutexManagerCache::boost_mutex_collection;

    std::unordered_map<std::pair<void*, std::string>, boost::timed_mutex, PairHashOperator>
        MutexManagerCache::boost_timed_mutex_collection;

    std::unordered_map<std::pair<void*, std::string>, boost::recursive_mutex, PairHashOperator>
        MutexManagerCache::boost_recursive_mutex_collection;

    std::unordered_map<std::pair<void*, std::string>, boost::recursive_timed_mutex, PairHashOperator>
        MutexManagerCache::boost_recursive_timed_mutex_collection;

    std::unordered_map<std::pair<void*, std::string>, boost::shared_mutex, PairHashOperator>
        MutexManagerCache::boost_shared_mutex_collection;

    std::unordered_map<std::pair<void*, std::string>, folly::MicroSpinLock, PairHashOperator>
        MutexManagerCache::folly_micro_spin_lock_collection;

    MutexManagerCache&
        MutexManagerCache::instance =
            InstanceManager::instance
                .get_instance<MutexManagerCache>();



    MutexManagerCache::MutexManagerCache()
    {
        _construct();
    }

    MutexManagerCache::~MutexManagerCache()
    {
        _destruct();
    }

    bool
        MutexManagerCache::construct()
    {
        _construct();

        return ValueCache::boolean_1;
    }

    void
        MutexManagerCache::_construct()
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
        MutexManagerCache::destruct()
    {
        _destruct();

        return ValueCache::boolean_1;
    }

    void
        MutexManagerCache::_destruct()
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
        MutexManagerCache::setup(
            const MutexManagerConfigurations&
                new_configurations
        )
    {
        configurations =
            new_configurations;

        _setup();

        return ValueCache::boolean_1;
    }

    bool
        MutexManagerCache::setup()
    {
        configurations =
            {};

        _setup();

        return ValueCache::boolean_1;
    }

    void
        MutexManagerCache::_setup()
    {
        try
        {
            pointer =
                MutexManagerConfigurations::default_pointer =
                configurations.pointer;

            name =
                MutexManagerConfigurations::default_name =
                configurations.name;

            ValueCache::boolean_1 = true;
        }
        catch (...)
        {
            ValueCache::boolean_1 = false;
        }
    }

    bool
        MutexManagerCache::reset()
    {
        _reset();

        return ValueCache::boolean_1;
    }

    void
        MutexManagerCache::_reset()
    {
        try
        {
            pointer =
                MutexManagerConfigurations::default_pointer =
                MutexManagerConfigurations::default_pointer;

            name =
                MutexManagerConfigurations::default_name =
                MutexManagerConfigurations::default_name;

            ValueCache::boolean_1 = true;
        }
        catch (...)
        {
            ValueCache::boolean_1 = false;
        }
    }

    bool
        MutexManagerCache::clear_all_collections()
    {
        _clear_all_collections();

        return ValueCache::boolean_1;
    }

    void
        MutexManagerCache::_clear_all_collections()
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
