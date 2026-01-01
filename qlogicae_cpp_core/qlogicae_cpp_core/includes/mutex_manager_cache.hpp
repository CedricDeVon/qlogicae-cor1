#pragma once

#include "value_cache.hpp"
#include "instance_manager.hpp"
#include "valid_mutex_lock.hpp"
#include "pair_hash_operator.hpp"
#include "mutex_manager_configurations.hpp"

namespace QLogicaeCppCore
{
    class MutexManagerCache
    {
    public:        
        static void*
            pointer;

        static std::string
            name;

        static MutexManagerConfigurations
            configurations;

        static std::unordered_map<std::pair<void*, std::string>,
            std::mutex, PairHashOperator>
                mutex_collection;

        static std::unordered_map<std::pair<void*, std::string>,
            std::timed_mutex, PairHashOperator>
                timed_mutex_collection;

        static std::unordered_map<std::pair<void*, std::string>,
            std::recursive_mutex, PairHashOperator>
                recursive_mutex_collection;

        static std::unordered_map<std::pair<void*, std::string>,
            std::recursive_timed_mutex, PairHashOperator>
                recursive_timed_mutex_collection;

        static std::unordered_map<std::pair<void*, std::string>,
            std::shared_mutex, PairHashOperator>
                shared_mutex_collection;

        static std::unordered_map<std::pair<void*, std::string>,
            boost::mutex, PairHashOperator>
                boost_mutex_collection;

        static std::unordered_map<std::pair<void*, std::string>,
            boost::timed_mutex, PairHashOperator>
                boost_timed_mutex_collection;

        static std::unordered_map<std::pair<void*, std::string>,
            boost::recursive_mutex, PairHashOperator>
                boost_recursive_mutex_collection;

        static std::unordered_map<std::pair<void*, std::string>,
            boost::recursive_timed_mutex, PairHashOperator>
                boost_recursive_timed_mutex_collection;

        static std::unordered_map<std::pair<void*, std::string>,
            boost::shared_mutex, PairHashOperator>
                boost_shared_mutex_collection;

        static std::unordered_map<std::pair<void*, std::string>,
            folly::MicroSpinLock, PairHashOperator>
                folly_micro_spin_lock_collection;

        static MutexManagerCache&
            instance;

        MutexManagerCache();

        ~MutexManagerCache();

        MutexManagerCache(
            const MutexManagerCache&
                instance
        ) = delete;

        MutexManagerCache(
            MutexManagerCache&&
                instance
        ) noexcept = delete;

        MutexManagerCache&
            operator = (
                MutexManagerCache&&
                    instance
            ) = delete;

        MutexManagerCache&
            operator = (
                const MutexManagerCache&
                    instance
            ) = delete;

        bool
            construct();

        void
            _construct();

        bool
            destruct();

        void
            _destruct();

        bool
            setup(
                const MutexManagerConfigurations&
                    new_configurations
            );

        bool
            setup();

        void
            _setup();

        bool
            reset();

        void
            _reset();

        bool
            clear_all_collections();

        void
            _clear_all_collections();
    };    
}
