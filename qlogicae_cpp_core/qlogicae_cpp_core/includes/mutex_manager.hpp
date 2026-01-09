#pragma once

#include "singleton_manager.hpp"
#include "mutex_manager_utilities.hpp"
#include "mutex_manager_configurations.hpp"

namespace QLogicaeCppCore
{        
    class MutexManager
    {
    public:     
        static bool
            cache_boolean_1;

        static void*
            cache_void_pointer_1;

        static std::string_view
            cache_string_view_1;

        static std::string_view
            cache_string_view_2;

        static MutexManager&
            singleton;

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
        cache_void_pointer_1 =
            const_cast<void*>(
                pointer
            );

        cache_string_view_1 =
            MutexManagerConfigurations::cache_name;

        _lock_mutex<LockType, MutexType>();

        return cache_boolean_1;
    }

    template<typename LockType, typename MutexType> bool
        MutexManager::lock_mutex(
            const void* pointer,
            const std::string_view& name
        ) requires ValidLock<LockType, MutexType>
    {
        cache_void_pointer_1 =
            const_cast<void*>(
                pointer
                );

        cache_string_view_1 =
            name;

        _lock_mutex<LockType, MutexType>();

        return cache_boolean_1;
    }

    template<typename LockType, typename MutexType> bool
        MutexManager::lock_mutex(
            const MutexManagerConfigurations&
            configurations
        ) requires ValidLock<LockType, MutexType>
    {
        cache_void_pointer_1 =
            const_cast<void*>(
                configurations.pointer
                );

        cache_string_view_1 =
            configurations.name;

        _lock_mutex<LockType, MutexType>();

        return cache_boolean_1;
    }

    template<typename LockType, typename MutexType> void
        MutexManager::_lock_mutex(
        ) requires ValidLock<LockType, MutexType>
    {
        try
        {
            if (!cache_void_pointer_1)
            {
                cache_boolean_1 = false;

                return;
            }

            MutexType*
                mutex_pointer =
                nullptr;

            if constexpr
                (std::is_same_v<MutexType, std::mutex>)
            {
                mutex_pointer =
                    &MutexManagerUtilities::cache_mutex_collection[
                {
                    cache_void_pointer_1,
                        cache_string_view_1.data()
                }
                    ];
            }
            else if constexpr
                (std::is_same_v<MutexType, std::timed_mutex>)
            {
                mutex_pointer =
                    &MutexManagerUtilities::cache_timed_mutex_collection[
                {
                    cache_void_pointer_1,
                        cache_string_view_1.data()
                }
                    ];
            }
            else if constexpr
                (std::is_same_v<MutexType, std::recursive_mutex>)
            {
                mutex_pointer =
                    &MutexManagerUtilities::cache_recursive_mutex_collection[
                {
                    cache_void_pointer_1,
                        cache_string_view_1.data()
                }
                    ];
            }
            else if constexpr
                (std::is_same_v<MutexType, std::recursive_timed_mutex>)
            {
                mutex_pointer =
                    &MutexManagerUtilities::cache_recursive_timed_mutex_collection[
                {
                    cache_void_pointer_1,
                        cache_string_view_1.data()
                }
                    ];
            }
            else if constexpr
                (std::is_same_v<MutexType, std::shared_mutex>)
            {
                mutex_pointer =
                    &MutexManagerUtilities::cache_shared_mutex_collection[
                {
                    cache_void_pointer_1,
                        cache_string_view_1.data()
                }
                    ];
            }
            else if constexpr
                (std::is_same_v<MutexType, boost::mutex>)
            {
                mutex_pointer =
                    &MutexManagerUtilities::cache_boost_mutex_collection[
                {
                    cache_void_pointer_1,
                        cache_string_view_1.data()
                }
                    ];
            }
            else if constexpr
                (std::is_same_v<MutexType, boost::timed_mutex>)
            {
                mutex_pointer =
                    &MutexManagerUtilities::cache_boost_timed_mutex_collection[
                {
                    cache_void_pointer_1,
                        cache_string_view_1.data()
                }
                    ];
            }
            else if constexpr
                (std::is_same_v<MutexType, boost::recursive_mutex>)
            {
                mutex_pointer =
                    &MutexManagerUtilities::cache_boost_recursive_mutex_collection[
                {
                    cache_void_pointer_1,
                        cache_string_view_1.data()
                }
                    ];
            }
            else if constexpr
                (std::is_same_v<MutexType, boost::recursive_timed_mutex>)
            {
                mutex_pointer =
                    &MutexManagerUtilities::cache_boost_recursive_timed_mutex_collection[
                {
                    cache_void_pointer_1,
                        cache_string_view_1.data()
                }
                    ];
            }
            else if constexpr
                (std::is_same_v<MutexType, boost::shared_mutex>)
            {
                mutex_pointer =
                    &MutexManagerUtilities::cache_boost_shared_mutex_collection[
                {
                    cache_void_pointer_1,
                        cache_string_view_1.data()
                }
                    ];
            }
            else
            {
                cache_boolean_1 =
                    false;

                return;
            }

            LockType lock(
                *mutex_pointer
            );

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
