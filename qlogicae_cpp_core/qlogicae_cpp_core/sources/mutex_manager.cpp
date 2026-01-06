#include "pch.hpp"

#include "../includes/mutex_manager.hpp"

namespace QLogicaeCppCore
{        
    MutexManager&
        MutexManager::singleton =
            SingletonManager::get_singleton<MutexManager>();



    MutexManager::MutexManager()
    {
        _construct();
    }

    MutexManager::~MutexManager()
    {
        _destruct();
    }

    bool
        MutexManager::construct()
    {
        _construct();

        return
            ValueCache::boolean_1;
    }

    void
        MutexManager::_construct()
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
        MutexManager::destruct()
    {
        _destruct();

        return
            ValueCache::boolean_1;
    }

    void
        MutexManager::_destruct()
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
        MutexManager::setup(
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
        MutexManager::setup()
    {
        MutexManagerConfigurations::cache =
            {};

        _setup();

        return
            ValueCache::boolean_1;
    }

    void
        MutexManager::_setup()
    {
        try
        {
            MutexManagerUtilities::singleton
                ._setup();                
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
        MutexManager::reset()
    {
        _reset();

        return
            ValueCache::boolean_1;
    }

    void
        MutexManager::_reset()
    {
        try
        {
            MutexManagerUtilities::singleton
                ._clear_all_collections();
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
        MutexManager::lock_micro_mutex()
    {
        ValueCache::void_pointer_1 =
            this;

        ValueCache::string_view_1 =
            MutexManagerConfigurations::default_name;

        _lock_micro_mutex();

        return
            ValueCache::boolean_1;
    }

    bool
        MutexManager::lock_micro_mutex(
            const void*
                pointer
        )
    {
        ValueCache::void_pointer_1 =
            const_cast<void*>(pointer);

        ValueCache::string_view_1 =
            MutexManagerConfigurations::default_name;

        _lock_micro_mutex();

        return
            ValueCache::boolean_1;
    }

    bool
        MutexManager::lock_micro_mutex(
            const void*
                pointer,
            const std::string_view&
                name
        )
    {
        ValueCache::void_pointer_1 =
            const_cast<void*>(pointer);

        ValueCache::string_view_1 =
            name;

        _lock_micro_mutex();

        return
            ValueCache::boolean_1;
    }

    bool
        MutexManager::lock_micro_mutex(
            const MutexManagerConfigurations&
                configurations
        )
    {
        ValueCache::void_pointer_1 =
            const_cast<void*>(
                configurations.pointer
            );

        ValueCache::string_view_1 =
            configurations.name;

        _lock_micro_mutex();

        return
            ValueCache::boolean_1;
    }

    void
        MutexManager::_lock_micro_mutex()
    {
        try
        {
            folly::MicroSpinLock*
                micro_spin_lock =
                &MutexManagerUtilities::folly_micro_spin_lock_collection
                [
                    {
                        ValueCache::void_pointer_1,
                        ValueCache::string_view_1.data()
                    }
                ];

            micro_spin_lock->lock();

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
        MutexManager::unlock_micro_mutex()
    {
        ValueCache::void_pointer_1 =
            this;

        ValueCache::string_view_1 =
            MutexManagerConfigurations::default_name;

        _unlock_micro_mutex();

        return
            ValueCache::boolean_1;
    }

    bool
        MutexManager::unlock_micro_mutex(
            const void*
                pointer
        )
    {
        ValueCache::void_pointer_1 =
            const_cast<void*>(
                pointer
            );

        ValueCache::string_view_1 =
            MutexManagerConfigurations::default_name;

        _unlock_micro_mutex();

        return
            ValueCache::boolean_1;
    }

    bool
        MutexManager::unlock_micro_mutex(
            const void*
                pointer,
            const std::string_view&
                name
        )
    {
        ValueCache::void_pointer_1 =
            const_cast<void*>(
                pointer
            );

        ValueCache::string_view_1 =
            name;

        _unlock_micro_mutex();

        return
            ValueCache::boolean_1;
    }

    bool
        MutexManager::unlock_micro_mutex(
            const MutexManagerConfigurations&
                configurations
        )
    {
        ValueCache::void_pointer_1 =
            const_cast<void*>(
                configurations.pointer
            );

        ValueCache::string_view_1 =
            configurations.name;

        _unlock_micro_mutex();

        return
            ValueCache::boolean_1;
    }

    void
        MutexManager::_unlock_micro_mutex()
    {
        try
        {
            folly::MicroSpinLock*
                micro_spin_lock =
                &MutexManagerUtilities::folly_micro_spin_lock_collection
                [
                    {
                        ValueCache::void_pointer_1,
                        ValueCache::string_view_1.data()
                    }
                ];

            micro_spin_lock->unlock();

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
}
