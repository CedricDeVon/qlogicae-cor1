#pragma once

#include "instance_manager.hpp"
#include "valid_mutex_lock.hpp"
#include "pair_hash_operator.hpp"
#include "mutex_manager_cache.hpp"
#include "mutex_manager_configurations.hpp"

namespace QLogicaeCppCore
{    
    class MutexManager
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

        static MutexManager&
            instance;

        MutexManager();

        ~MutexManager();

        MutexManager(
            const MutexManager& instance
        ) = delete;

        MutexManager(
            MutexManager&& instance
        ) noexcept = delete;

        MutexManager& operator = (
            MutexManager&& instance
        ) = delete;

        MutexManager& operator = (
            const MutexManager& instance
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
                    configurations
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
            lock_micro_mutex();

        bool
            lock_micro_mutex(
                const void*
                    pointer
            );

        bool
            lock_micro_mutex(
                const void*
                    pointer,
                const std::string_view&
                    name
            );

        bool
            lock_micro_mutex(
                const MutexManagerConfigurations&
                    configurations
            );

        void
            _lock_micro_mutex();

        bool
            unlock_micro_mutex();

        bool
            unlock_micro_mutex(
                const void* pointer
            );

        bool
            unlock_micro_mutex(
                const void*
                    pointer,
                const std::string_view&
                    name
            );

        bool
            unlock_micro_mutex(
                const MutexManagerConfigurations&
                    configurations
            );

        void
            _unlock_micro_mutex();

        bool
            clear_all_collections();

        void
            _clear_all_collections();

        template<typename LockType, typename MutexType> bool
            lock_mutex(
                const void*
                    pointer
            ) requires ValidLock<LockType, MutexType>;
        
        template<typename LockType, typename MutexType> bool
            lock_mutex(
                const void*
                    pointer,
                const std::string_view&
                    name
            ) requires ValidLock<LockType, MutexType>;

        template<typename LockType, typename MutexType> bool
            lock_mutex(
                const MutexManagerConfigurations&
                    configurations
            ) requires ValidLock<LockType, MutexType>;

        template<typename LockType, typename MutexType> void
            _lock_mutex()
                requires ValidLock<LockType, MutexType>;
    };

    template<typename LockType, typename MutexType> bool
        MutexManager::lock_mutex(
            const void* pointer
        ) requires ValidLock<LockType, MutexType>
    {
        ValueCache::void_pointer_1 =
            const_cast<void*>(pointer);

        ValueCache::string_view_1 =
            MutexManagerCache::name;

        _lock_mutex<LockType, MutexType>();

        return ValueCache::boolean_1;
    }

    template<typename LockType, typename MutexType> bool
        MutexManager::lock_mutex(
            const void* pointer,
            const std::string_view& name
        ) requires ValidLock<LockType, MutexType>
    {
        ValueCache::void_pointer_1 =
            const_cast<void*>(pointer);

        ValueCache::string_view_1 =
            name;

        _lock_mutex<LockType, MutexType>();

        return ValueCache::boolean_1;
    }

    template<typename LockType, typename MutexType> bool
        MutexManager::lock_mutex(
            const MutexManagerConfigurations&
                configurations
        ) requires ValidLock<LockType, MutexType>
    {
        ValueCache::void_pointer_1 =
            const_cast<void*>(configurations.pointer);

        ValueCache::string_view_1 =
            configurations.name;

        _lock_mutex<LockType, MutexType>();

        return ValueCache::boolean_1;
    }

    template<typename LockType, typename MutexType> void
        MutexManager::_lock_mutex(
        ) requires ValidLock<LockType, MutexType>
    {
        try
        {
            if (!ValueCache::void_pointer_1)
            {
                ValueCache::boolean_1 = false;

                return;
            }

            MutexType*
                mutex_pointer =
                    nullptr;

            if constexpr
                (std::is_same_v<MutexType, std::mutex>)
            {
                mutex_pointer =
                    &mutex_collection[
                {
                    ValueCache::void_pointer_1,
                        ValueCache::string_view_1.data()
                }
                    ];
            }
            else if constexpr
                (std::is_same_v<MutexType, std::timed_mutex>)
            {
                mutex_pointer =
                    &timed_mutex_collection[
                {
                    ValueCache::void_pointer_1,
                        ValueCache::string_view_1.data()
                }
                    ];
            }
            else if constexpr
                (std::is_same_v<MutexType, std::recursive_mutex>)
            {
                mutex_pointer =
                    &recursive_mutex_collection[
                {
                    ValueCache::void_pointer_1,
                        ValueCache::string_view_1.data()
                }
                    ];
            }
            else if constexpr
                (std::is_same_v<MutexType, std::recursive_timed_mutex>)
            {
                mutex_pointer =
                    &recursive_timed_mutex_collection[
                {
                    ValueCache::void_pointer_1,
                        ValueCache::string_view_1.data()
                }
                    ];
            }
            else if constexpr
                (std::is_same_v<MutexType, std::shared_mutex>)
            {
                mutex_pointer =
                    &shared_mutex_collection[
                {
                    ValueCache::void_pointer_1,
                        ValueCache::string_view_1.data()
                }
                    ];
            }
            else if constexpr
                (std::is_same_v<MutexType, boost::mutex>)
            {
                mutex_pointer =
                    &boost_mutex_collection[
                {
                    ValueCache::void_pointer_1,
                        ValueCache::string_view_1.data()
                }
                    ];
            }
            else if constexpr
                (std::is_same_v<MutexType, boost::timed_mutex>)
            {
                mutex_pointer =
                    &boost_timed_mutex_collection[
                {
                    ValueCache::void_pointer_1,
                        ValueCache::string_view_1.data()
                }
                    ];
            }
            else if constexpr
                (std::is_same_v<MutexType, boost::recursive_mutex>)
            {
                mutex_pointer =
                    &boost_recursive_mutex_collection[
                {
                    ValueCache::void_pointer_1,
                        ValueCache::string_view_1.data()
                }
                    ];
            }
            else if constexpr
                (std::is_same_v<MutexType, boost::recursive_timed_mutex>)
            {
                mutex_pointer =
                    &boost_recursive_timed_mutex_collection[
                {
                    ValueCache::void_pointer_1,
                        ValueCache::string_view_1.data()
                }
                    ];
            }
            else if constexpr
                (std::is_same_v<MutexType, boost::shared_mutex>)
            {
                mutex_pointer =
                    &boost_shared_mutex_collection[
                {
                    ValueCache::void_pointer_1,
                        ValueCache::string_view_1.data()
                }
                    ];
            }
            else
            {
                ValueCache::boolean_1 =
                    false;

                return;
            }

            LockType lock(
                *mutex_pointer
            );

            ValueCache::boolean_1 =
                true;
        }
        catch (...)
        {
            ValueCache::boolean_1 =
                false;
        }
    }
}
