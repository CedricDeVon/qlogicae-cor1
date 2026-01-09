#include "pch.hpp"

#include "../includes/mutex_manager_utilities.hpp"

namespace QLogicaeCppCore
{            
    bool
        MutexManagerUtilities::cache_boolean_1;

    std::unordered_map<std::pair<void*, std::string>, std::mutex, PairHashOperator>
        MutexManagerUtilities::cache_mutex_collection;

    std::unordered_map<std::pair<void*, std::string>, std::timed_mutex, PairHashOperator>
        MutexManagerUtilities::cache_timed_mutex_collection;

    std::unordered_map<std::pair<void*, std::string>, std::recursive_mutex, PairHashOperator>
        MutexManagerUtilities::cache_recursive_mutex_collection;

    std::unordered_map<std::pair<void*, std::string>, std::recursive_timed_mutex, PairHashOperator>
        MutexManagerUtilities::cache_recursive_timed_mutex_collection;

    std::unordered_map<std::pair<void*, std::string>, std::shared_mutex, PairHashOperator>
        MutexManagerUtilities::cache_shared_mutex_collection;

    std::unordered_map<std::pair<void*, std::string>, boost::mutex, PairHashOperator>
        MutexManagerUtilities::cache_boost_mutex_collection;

    std::unordered_map<std::pair<void*, std::string>, boost::timed_mutex, PairHashOperator>
        MutexManagerUtilities::cache_boost_timed_mutex_collection;

    std::unordered_map<std::pair<void*, std::string>, boost::recursive_mutex, PairHashOperator>
        MutexManagerUtilities::cache_boost_recursive_mutex_collection;

    std::unordered_map<std::pair<void*, std::string>, boost::recursive_timed_mutex, PairHashOperator>
        MutexManagerUtilities::cache_boost_recursive_timed_mutex_collection;

    std::unordered_map<std::pair<void*, std::string>, boost::shared_mutex, PairHashOperator>
        MutexManagerUtilities::cache_boost_shared_mutex_collection;

    std::unordered_map<std::pair<void*, std::string>, folly::MicroSpinLock, PairHashOperator>
        MutexManagerUtilities::cache_folly_micro_spin_lock_collection;

    MutexManagerUtilities&
        MutexManagerUtilities::singleton =
        SingletonManager::get_singleton<MutexManagerUtilities>();

    MutexManagerUtilities::MutexManagerUtilities()
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

    MutexManagerUtilities::~MutexManagerUtilities()
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
        MutexManagerUtilities::construct()
    {
        _construct();

        return
            MutexManagerUtilities::cache_boolean_1;
    }

    void
        MutexManagerUtilities::_construct()
    {
        try
        {
            MutexManagerUtilities::cache_boolean_1 =
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
            MutexManagerUtilities::cache_boolean_1;
    }

    void
        MutexManagerUtilities::_destruct()
    {
        try
        {
            MutexManagerUtilities::cache_boolean_1 =
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
            MutexManagerUtilities::cache_boolean_1;
    }

    bool
        MutexManagerUtilities::setup()
    {
        MutexManagerConfigurations::cache =
        {};

        _setup();

        return
            MutexManagerUtilities::cache_boolean_1;
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

            MutexManagerUtilities::cache_boolean_1 =
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
            MutexManagerUtilities::cache_boolean_1;
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

            MutexManagerUtilities::cache_boolean_1 =
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
        MutexManagerUtilities::clear_all_collections()
    {
        _clear_all_collections();

        return
            MutexManagerUtilities::cache_boolean_1;
    }

    void
        MutexManagerUtilities::_clear_all_collections()
    {
        try
        {
            MutexManagerUtilities::cache_mutex_collection
                .clear();

            MutexManagerUtilities::cache_timed_mutex_collection
                .clear();

            MutexManagerUtilities::cache_recursive_mutex_collection
                .clear();

            MutexManagerUtilities::cache_recursive_timed_mutex_collection
                .clear();

            MutexManagerUtilities::cache_shared_mutex_collection
                .clear();

            MutexManagerUtilities::cache_boost_mutex_collection
                .clear();

            MutexManagerUtilities::cache_boost_timed_mutex_collection
                .clear();

            MutexManagerUtilities::cache_boost_recursive_mutex_collection
                .clear();

            MutexManagerUtilities::cache_boost_recursive_timed_mutex_collection
                .clear();

            MutexManagerUtilities::cache_boost_shared_mutex_collection
                .clear();

            MutexManagerUtilities::cache_folly_micro_spin_lock_collection
                .clear();

            MutexManagerUtilities::cache_boolean_1 =
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
}
