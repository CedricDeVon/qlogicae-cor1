#pragma once

#include "value_cache.hpp"
#include "valid_mutex_lock.hpp"
#include "singleton_manager.hpp"
#include "pair_hash_operator.hpp"
#include "mutex_manager_configurations.hpp"

namespace QLogicaeCppCore
{
    class MutexManagerUtilities
    {
    public:                
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

        static MutexManagerUtilities&
            singleton;

        MutexManagerUtilities();

        ~MutexManagerUtilities();

        MutexManagerUtilities(
            const MutexManagerUtilities&
                instance
        ) = delete;

        MutexManagerUtilities(
            MutexManagerUtilities&&
                instance
        ) noexcept = delete;

        MutexManagerUtilities&
            operator = (
                MutexManagerUtilities&&
                    instance
        ) = delete;

        MutexManagerUtilities&
            operator = (
                const MutexManagerUtilities&
                    instance
        ) = delete;

        bool
            construct();

        bool
            destruct();

        bool
            setup(
                const MutexManagerConfigurations&
                    new_configurations
            );

        bool
            setup();

        bool
            reset();

        bool
            clear_all_collections();

        void
            _construct();
        
        void
            _destruct();

        void
            _setup();

        void
            _reset();

        void
            _clear_all_collections();
    };    
}
