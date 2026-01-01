#include "pch.hpp"

#include "../includes/mutex_manager.hpp"

namespace QLogicaeCppCore
{        
    MutexManager&
        MutexManager::instance =
            InstanceManager::instance.get_instance<MutexManager>();



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

        return ValueCache::boolean_1;
    }

    void
        MutexManager::_construct()
    {
        try
        {
            ValueCache::boolean_1 = true;
        }
        catch (...)
        {
            ValueCache::boolean_1 = false;
        }
    }

    bool
        MutexManager::destruct()
    {
        _destruct();

        return ValueCache::boolean_1;
    }

    void
        MutexManager::_destruct()
    {
        try
        {
            ValueCache::boolean_1 = true;
        }
        catch (...)
        {
            ValueCache::boolean_1 = false;
        }
    }

    bool
        MutexManager::setup(
            const MutexManagerConfigurations&
                new_configurations
        )
    {
        MutexManagerCache::configurations =
            new_configurations;

        _setup();

        return ValueCache::boolean_1;
    }

    bool
        MutexManager::setup()
    {
        MutexManagerCache::configurations =
            {};

        _setup();

        return ValueCache::boolean_1;
    }

    void
        MutexManager::_setup()
    {
        try
        {
            MutexManagerCache::instance._setup();                
        }
        catch (...)
        {
            ValueCache::boolean_1 = false;
        }
    }

    bool
        MutexManager::reset()
    {
        _reset();

        return ValueCache::boolean_1;
    }

    void
        MutexManager::_reset()
    {
        try
        {
            MutexManagerCache::instance._clear_all_collections();
        }
        catch (...)
        {
            ValueCache::boolean_1 = false;
        }
    }

    bool
        MutexManager::lock_micro_mutex()
    {
        ValueCache::void_pointer_1 =
            this;

        ValueCache::string_view_1 =
            MutexManagerCache::name;

        _lock_micro_mutex();

        return ValueCache::boolean_1;
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
            MutexManagerCache::name;

        _lock_micro_mutex();

        return ValueCache::boolean_1;
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

        return ValueCache::boolean_1;
    }

    bool
        MutexManager::lock_micro_mutex(
            const MutexManagerConfigurations&
            configurations
        )
    {
        ValueCache::void_pointer_1 =
            const_cast<void*>(configurations.pointer);

        ValueCache::string_view_1 =
            configurations.name;

        _lock_micro_mutex();

        return ValueCache::boolean_1;
    }

    void
        MutexManager::_lock_micro_mutex()
    {
        try
        {
            folly::MicroSpinLock*
                micro_spin_lock =
                &MutexManagerCache::folly_micro_spin_lock_collection[
            {
                ValueCache::void_pointer_1,
                    ValueCache::string_view_1.data()
            }
                ];

            micro_spin_lock->lock();

            ValueCache::boolean_1 = true;
        }
        catch (...)
        {
            ValueCache::boolean_1 = false;
        }
    }

    bool
        MutexManager::unlock_micro_mutex()
    {
        _unlock_micro_mutex();

        return ValueCache::boolean_1;
    }

    bool
        MutexManager::unlock_micro_mutex(
            const void*
            pointer
        )
    {
        ValueCache::void_pointer_1 =
            const_cast<void*>(pointer);

        ValueCache::string_view_1 =
            MutexManagerCache::name;

        _unlock_micro_mutex();

        return ValueCache::boolean_1;
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
            const_cast<void*>(pointer);

        ValueCache::string_view_1 =
            name;

        _unlock_micro_mutex();

        return ValueCache::boolean_1;
    }

    bool
        MutexManager::unlock_micro_mutex(
            const MutexManagerConfigurations&
            configurations
        )
    {
        ValueCache::void_pointer_1 =
            const_cast<void*>(configurations.pointer);

        ValueCache::string_view_1 =
            configurations.name;

        _unlock_micro_mutex();

        return ValueCache::boolean_1;
    }

    void
        MutexManager::_unlock_micro_mutex()
    {
        try
        {
            folly::MicroSpinLock*
                micro_spin_lock =
                &MutexManagerCache::folly_micro_spin_lock_collection
                [
            {
                this,
                    MutexManagerCache::name
            }
                ];

            micro_spin_lock->unlock();

            ValueCache::boolean_1 = true;
        }
        catch (...)
        {
            ValueCache::boolean_1 = false;
        }
    }
}
