#pragma once

#include "instance_manager.hpp"
#include "valid_mutex_lock.hpp"
#include "pair_hash_operator.hpp"
#include "mutex_manager_configurations.hpp"

namespace QLogicaeCppCore
{    
    class MutexManager
    {
    public:
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

        static MutexManager&
            instance;

        static folly::MicroSpinLock
            micro_spinlock;

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

        bool
            construct();

        void
            _construct();

        bool
            destruct();

        void
            _destruct();

        bool
            lock_micro_mutex();

        void
            _lock_micro_mutex();

        bool
            unlock_micro_mutex();

        void
            _unlock_micro_mutex();

        template<typename LockType, typename MutexType> bool
            lock_mutex(
                const void* pointer
            ) requires ValidLock<LockType, MutexType>;
        
        template<typename LockType, typename MutexType> bool
            lock_mutex(
                const void* pointer,
                const std::string_view& name
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
        void_pointer_cache_1 =
            const_cast<void*>(pointer);

        string_view_cache_1 =
            MutexManagerConfigurations::base_name_cache;

        _lock_mutex<LockType, MutexType>();

        return boolean_cache_1;
    }

    template<typename LockType, typename MutexType> bool
        MutexManager::lock_mutex(
            const void* pointer,
            const std::string_view& name
    ) requires ValidLock<LockType, MutexType>
    {
        void_pointer_cache_1 =
            const_cast<void*>(pointer);

        string_view_cache_1 =
            name;

        _lock_mutex<LockType, MutexType>();

        return boolean_cache_1;
    }

    template<typename LockType, typename MutexType> void
        MutexManager::_lock_mutex(
    ) requires ValidLock<LockType, MutexType>
    {
        try
        {
            if (!void_pointer_cache_1)
            {
                boolean_cache_1 = false;

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
                            void_pointer_cache_1,
                            string_view_cache_1.data()
                        }
                    ];
            }
            else if constexpr
                (std::is_same_v<MutexType, std::timed_mutex>)
            {
                mutex_pointer =
                    &timed_mutex_collection[
                        {
                            void_pointer_cache_1,
                            string_view_cache_1.data()
                        }
                    ];
            }
            else if constexpr
                (std::is_same_v<MutexType, std::recursive_mutex>)
            {
                mutex_pointer =
                    &recursive_mutex_collection[
                        {
                            void_pointer_cache_1,
                            string_view_cache_1.data()
                        }
                    ];
            }
            else if constexpr
                (std::is_same_v<MutexType, std::recursive_timed_mutex>)
            {
                mutex_pointer =
                    &recursive_timed_mutex_collection[
                        {
                            void_pointer_cache_1,
                            string_view_cache_1.data()
                        }
                    ];
            }
            else if constexpr
                (std::is_same_v<MutexType, std::shared_mutex>)
            {
                mutex_pointer =
                    &shared_mutex_collection[
                        {
                            void_pointer_cache_1,
                            string_view_cache_1.data()
                        }
                    ];
            }
            else if constexpr
                (std::is_same_v<MutexType, boost::mutex>)
            {
                mutex_pointer =
                    &boost_mutex_collection[
                        {
                            void_pointer_cache_1,
                            string_view_cache_1.data()
                        }
                    ];
            }
            else if constexpr
                (std::is_same_v<MutexType, boost::timed_mutex>)
            {
                mutex_pointer =
                    &boost_timed_mutex_collection[
                        {
                            void_pointer_cache_1,
                            string_view_cache_1.data()
                        }
                    ];
            }
            else if constexpr
                (std::is_same_v<MutexType, boost::recursive_mutex>)
            {
                mutex_pointer =
                    &boost_recursive_mutex_collection[
                        {
                            void_pointer_cache_1,
                            string_view_cache_1.data()
                        }
                    ];
            }
            else if constexpr
                (std::is_same_v<MutexType, boost::recursive_timed_mutex>)
            {
                mutex_pointer =
                    &boost_recursive_timed_mutex_collection[
                        {
                            void_pointer_cache_1,
                            string_view_cache_1.data()
                        }
                    ];
            }
            else if constexpr
                (std::is_same_v<MutexType, boost::shared_mutex>)
            {
                mutex_pointer =
                    &boost_shared_mutex_collection[
                        {
                            void_pointer_cache_1,
                            string_view_cache_1.data()
                        }
                    ];
            }
            else
            {
                boolean_cache_1 =
                    false;

                return;
            }

            LockType lock(
                *mutex_pointer
            );

            boolean_cache_1 =
                true;
        }
        catch (...)
        {
            boolean_cache_1 =
                false;
        }
    }
}
