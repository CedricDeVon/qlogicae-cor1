#include "pch.hpp"

#include "../includes/mutex_manager_utilities.hpp"

namespace QLogicaeCppCore
{        
    std::unordered_map<std::pair<void*, std::string>, std::mutex, PairHashOperator>
        MutexManagerUtilities::mutex_collection;

    std::unordered_map<std::pair<void*, std::string>, std::timed_mutex, PairHashOperator>
        MutexManagerUtilities::timed_mutex_collection;

    std::unordered_map<std::pair<void*, std::string>, std::recursive_mutex, PairHashOperator>
        MutexManagerUtilities::recursive_mutex_collection;

    std::unordered_map<std::pair<void*, std::string>, std::recursive_timed_mutex, PairHashOperator>
        MutexManagerUtilities::recursive_timed_mutex_collection;

    std::unordered_map<std::pair<void*, std::string>, std::shared_mutex, PairHashOperator>
        MutexManagerUtilities::shared_mutex_collection;

    std::unordered_map<std::pair<void*, std::string>, boost::mutex, PairHashOperator>
        MutexManagerUtilities::boost_mutex_collection;

    std::unordered_map<std::pair<void*, std::string>, boost::timed_mutex, PairHashOperator>
        MutexManagerUtilities::boost_timed_mutex_collection;

    std::unordered_map<std::pair<void*, std::string>, boost::recursive_mutex, PairHashOperator>
        MutexManagerUtilities::boost_recursive_mutex_collection;

    std::unordered_map<std::pair<void*, std::string>, boost::recursive_timed_mutex, PairHashOperator>
        MutexManagerUtilities::boost_recursive_timed_mutex_collection;

    std::unordered_map<std::pair<void*, std::string>, boost::shared_mutex, PairHashOperator>
        MutexManagerUtilities::boost_shared_mutex_collection;

    std::unordered_map<std::pair<void*, std::string>, folly::MicroSpinLock, PairHashOperator>
        MutexManagerUtilities::folly_micro_spin_lock_collection;

    MutexManagerUtilities&
        MutexManagerUtilities::singleton =
            SingletonManager::get_singleton<MutexManagerUtilities>();



    MutexManagerUtilities::MutexManagerUtilities()
    {
        _construct();
    }

    MutexManagerUtilities::~MutexManagerUtilities()
    {
        _destruct();
    }

    bool
        MutexManagerUtilities::construct()
    {
        _construct();

        return
            ValueCache::boolean_1;
    }

    void
        MutexManagerUtilities::_construct()
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
        MutexManagerUtilities::destruct()
    {
        _destruct();

        return
            ValueCache::boolean_1;
    }

    void
        MutexManagerUtilities::_destruct()
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
        MutexManagerUtilities::setup(
            const MutexManagerConfigurations&
                new_configurations
        )
    {
        MutexManagerConfigurations::cache =
            new_configurations;

        _setup();

        return
            ValueCache::boolean_1;
    }

    bool
        MutexManagerUtilities::setup()
    {
        MutexManagerConfigurations::cache =
            {};

        _setup();

        return
            ValueCache::boolean_1;
    }

    void
        MutexManagerUtilities::_setup()
    {
        try
        {
            MutexManagerConfigurations::cache_pointer =
                MutexManagerConfigurations::default_pointer =
                MutexManagerConfigurations::cache.pointer;

            MutexManagerConfigurations::cache_name =
                MutexManagerConfigurations::default_name =
                MutexManagerConfigurations::cache.name;

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
        MutexManagerUtilities::reset()
    {
        _reset();

        return
            ValueCache::boolean_1;
    }

    void
        MutexManagerUtilities::_reset()
    {
        try
        {
            MutexManagerConfigurations::cache_pointer =
                MutexManagerConfigurations::default_pointer =
                MutexManagerConfigurations::initial_pointer;

            MutexManagerConfigurations::cache_name =
                MutexManagerConfigurations::default_name =
                MutexManagerConfigurations::initial_name;

            ValueCache::boolean_1 = true;
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
        MutexManagerUtilities::clear_all_collections()
    {
        _clear_all_collections();

        return
            ValueCache::boolean_1;
    }

    void
        MutexManagerUtilities::_clear_all_collections()
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
}
