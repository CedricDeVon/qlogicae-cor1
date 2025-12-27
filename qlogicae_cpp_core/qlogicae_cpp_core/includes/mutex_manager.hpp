#pragma once

#include "instance_manager.hpp"
#include "valid_mutex_lock.hpp"
#include "pair_hash_operator.hpp"

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

        static bool
            _boolean_ouput_cache_1; // is_successful
        
        static void*
            _void_pointer_ouput_cache_1; // object reference

        static std::string_view
            _string_view_ouput_cache_1; // key name

        static std::unordered_map<std::pair<void*, std::string>,
            std::mutex, PairHashOperator>
                _mutex_collection;

        static std::unordered_map<std::pair<void*, std::string>,
            std::timed_mutex, PairHashOperator>
                _timed_mutex_collection;

        static std::unordered_map<std::pair<void*, std::string>,
            std::recursive_mutex, PairHashOperator>
                _recursive_mutex_collection;

        static std::unordered_map<std::pair<void*, std::string>,
            std::recursive_timed_mutex, PairHashOperator>
                _recursive_timed_mutex_collection;

        static std::unordered_map<std::pair<void*, std::string>,
            std::shared_mutex, PairHashOperator>
                _shared_mutex_collection;

        bool
            construct();

        void
            _construct();

        bool
            destruct();

        void
            _destruct();
    
        template<typename LockType, typename MutexType>
        bool
            lock_mutex(
                const void* pointer
            ) requires ValidLock<LockType, MutexType>;
        
        template<typename LockType, typename MutexType>
        bool
            lock_mutex(
                const void* pointer,
                const std::string_view& name
            ) requires ValidLock<LockType, MutexType>;

        template<typename LockType, typename MutexType>
        void
            _lock_mutex()
                requires ValidLock<LockType, MutexType>;
    };

    template<typename LockType, typename MutexType>
    bool MutexManager::lock_mutex(
        const void* pointer
    ) requires ValidLock<LockType, MutexType>
    {
        try
        {
            _void_pointer_ouput_cache_1 = pointer;
            _string_view_ouput_cache_1 = "static";

            _lock_mutex<LockType, MutexType>();
        }
        catch (...)
        {
            _boolean_ouput_cache_1 = false;
        }

        return _boolean_ouput_cache_1;        
    }

    template<typename LockType, typename MutexType>
    bool MutexManager::lock_mutex(
        const void* pointer,
        const std::string_view& name
    ) requires ValidLock<LockType, MutexType>
    {
        try
        {
            _void_pointer_ouput_cache_1 = pointer;
            _string_view_ouput_cache_1 = name;

            _lock_mutex<LockType, MutexType>();
        }
        catch (...)
        {
            _boolean_ouput_cache_1 = false;
        }

        return _boolean_ouput_cache_1;
    }

    template<typename LockType, typename MutexType>
    void MutexManager::_lock_mutex(
    ) requires ValidLock<LockType, MutexType>
    {
        MutexType* mutex_pointer =
            nullptr;
        
        if constexpr
            (std::is_same_v<MutexType, std::mutex>)
        {
            mutex_pointer =
                &_mutex_collection[
                     {
                        _void_pointer_ouput_cache_1,
                        _string_view_ouput_cache_1.data()
                     }
                ];
        }
        else if constexpr
            (std::is_same_v<MutexType, std::timed_mutex>)
        {
            mutex_pointer =
                &_timed_mutex_collection[
                    {
                        _void_pointer_ouput_cache_1,
                        _string_view_ouput_cache_1.data()
                     }
                ];
        }
        else if constexpr
            (std::is_same_v<MutexType, std::recursive_mutex>)
        {
            mutex_pointer =
                &_recursive_mutex_collection[
                    {
                        _void_pointer_ouput_cache_1,
                        _string_view_ouput_cache_1.data()
                     }
                ];
        }
        else if constexpr
            (std::is_same_v<MutexType, std::recursive_timed_mutex>)
        {
            mutex_pointer =
                &_recursive_timed_mutex_collection[
                    {
                        _void_pointer_ouput_cache_1,
                        _string_view_ouput_cache_1.data()
                     }
                ];
        }
        else if constexpr
            (std::is_same_v<MutexType, std::shared_mutex>)
        {
            mutex_pointer =
                &_shared_mutex_collection[
                    {
                        _void_pointer_ouput_cache_1,
                        _string_view_ouput_cache_1.data()
                     }
                ];
        }
        else if constexpr
            (std::is_same_v<MutexType, std::recursive_timed_mutex>)
        {
            mutex_pointer =
                &_shared_mutex_collection[
                    {
                        _void_pointer_ouput_cache_1,
                        _string_view_ouput_cache_1.data()
                     }
                ];
        }        
        else
        {
            _boolean_ouput_cache_1 = false;

            return;
        }

        LockType lock(*mutex_pointer);
        _boolean_ouput_cache_1 = true;
    }
}
