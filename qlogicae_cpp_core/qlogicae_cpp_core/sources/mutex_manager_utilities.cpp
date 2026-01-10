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
            _handle_construct();
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
            _handle_destruct();
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
        _handle_construct();

        return
            cache_boolean_1;
    }

    void
        MutexManagerUtilities::_handle_construct()
    {
        try
        {
            cache_boolean_1 =
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
        _handle_destruct();

        return
            cache_boolean_1;
    }

    void
        MutexManagerUtilities::_handle_destruct()
    {
        try
        {
            cache_boolean_1 =
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

        _handle_setup();

        return
            cache_boolean_1;
    }

    bool
        MutexManagerUtilities::setup()
    {
        MutexManagerConfigurations::cache =
        {};

        _handle_setup();

        return
            cache_boolean_1;
    }

    void
        MutexManagerUtilities::_handle_setup()
    {
        try
        {
            MutexManagerConfigurations::_handle_setup();

            cache_boolean_1 =
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
        _handle_reset();

        return
            cache_boolean_1;
    }

    void
        MutexManagerUtilities::_handle_reset()
    {
        try
        {
            MutexManagerConfigurations::_handle_reset();

            cache_boolean_1 =
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
        _handle_clear_all_collections();

        return
            cache_boolean_1;
    }

    void
        MutexManagerUtilities::_handle_clear_all_collections()
    {
        try
        {
            cache_mutex_collection
                .clear();

            cache_timed_mutex_collection
                .clear();

            cache_recursive_mutex_collection
                .clear();

            cache_recursive_timed_mutex_collection
                .clear();

            cache_shared_mutex_collection
                .clear();

            cache_boost_mutex_collection
                .clear();

            cache_boost_timed_mutex_collection
                .clear();

            cache_boost_recursive_mutex_collection
                .clear();

            cache_boost_recursive_timed_mutex_collection
                .clear();

            cache_boost_shared_mutex_collection
                .clear();

            cache_folly_micro_spin_lock_collection
                .clear();

            cache_boolean_1 =
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
