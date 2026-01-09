#include "pch.hpp"

#include "../includes/mutex_manager.hpp"

namespace QLogicaeCppCore
{           
    bool
        MutexManager::cache_boolean_1 =
            false;

    void*
        MutexManager::cache_void_pointer_1 =
            nullptr;

    std::string_view
        MutexManager::cache_string_view_1 =
            "";

    std::string_view
        MutexManager::cache_string_view_2 =
            "";

    MutexManager&
        MutexManager::singleton =
            SingletonManager::get_singleton<MutexManager>();

    MutexManager::MutexManager()
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

    MutexManager::~MutexManager()
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
        MutexManager::construct()
    {
        _construct();

        return
            MutexManager::cache_boolean_1;
    }

    void
        MutexManager::_construct()
    {
        try
        {
            MutexManager::cache_boolean_1 =
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
            MutexManager::cache_boolean_1;
    }

    void
        MutexManager::_destruct()
    {
        try
        {
            MutexManager::cache_boolean_1 =
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
            MutexManager::cache_boolean_1;
    }

    bool
        MutexManager::setup()
    {
        MutexManagerConfigurations::cache =
        {};

        _setup();

        return
            MutexManager::cache_boolean_1;
    }

    void
        MutexManager::_setup()
    {
        try
        {
            MutexManagerUtilities::singleton
                ._setup();

            MutexManager::cache_boolean_1 =
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
        MutexManager::reset()
    {
        _reset();

        return
            MutexManager::cache_boolean_1;
    }

    void
        MutexManager::_reset()
    {
        try
        {
            MutexManagerUtilities::singleton
                ._clear_all_collections();

            MutexManager::cache_boolean_1 =
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
        MutexManager::lock_micro_mutex()
    {
        MutexManager::cache_void_pointer_1 =
            this;

        MutexManager::cache_string_view_1 =
            MutexManagerConfigurations::default_name;

        _lock_micro_mutex();

        return
            MutexManager::cache_boolean_1;
    }

    bool
        MutexManager::lock_micro_mutex(
            const void*
            pointer
        )
    {
        MutexManager::cache_void_pointer_1 =
            const_cast<void*>(
                pointer
                );

        MutexManager::cache_string_view_1 =
            MutexManagerConfigurations::default_name;

        _lock_micro_mutex();

        return
            MutexManager::cache_boolean_1;
    }

    bool
        MutexManager::lock_micro_mutex(
            const void*
            pointer,
            const std::string_view&
            name
        )
    {
        MutexManager::cache_void_pointer_1 =
            const_cast<void*>(pointer);

        MutexManager::cache_string_view_1 =
            name;

        _lock_micro_mutex();

        return
            MutexManager::cache_boolean_1;
    }

    bool
        MutexManager::lock_micro_mutex(
            const MutexManagerConfigurations&
            configurations
        )
    {
        MutexManager::cache_void_pointer_1 =
            const_cast<void*>(
                configurations.pointer
                );

        MutexManager::cache_string_view_1 =
            configurations.name;

        _lock_micro_mutex();

        return
            MutexManager::cache_boolean_1;
    }

    void
        MutexManager::_lock_micro_mutex()
    {
        try
        {
            folly::MicroSpinLock*
                micro_spin_lock =
                &MutexManagerUtilities::cache_folly_micro_spin_lock_collection
                [
            {
                MutexManager::cache_void_pointer_1,
                    MutexManager::cache_string_view_1.data()
            }
                ];

            micro_spin_lock->lock();

            MutexManager::cache_boolean_1 = true;
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
        MutexManager::cache_void_pointer_1 =
            this;

        MutexManager::cache_string_view_1 =
            MutexManagerConfigurations::default_name;

        _unlock_micro_mutex();

        return
            MutexManager::cache_boolean_1;
    }

    bool
        MutexManager::unlock_micro_mutex(
            const void*
            pointer
        )
    {
        MutexManager::cache_void_pointer_1 =
            const_cast<void*>(
                pointer
                );

        MutexManager::cache_string_view_1 =
            MutexManagerConfigurations::default_name;

        _unlock_micro_mutex();

        return
            MutexManager::cache_boolean_1;
    }

    bool
        MutexManager::unlock_micro_mutex(
            const void*
            pointer,
            const std::string_view&
            name
        )
    {
        MutexManager::cache_void_pointer_1 =
            const_cast<void*>(
                pointer
                );

        MutexManager::cache_string_view_1 =
            name;

        _unlock_micro_mutex();

        return
            MutexManager::cache_boolean_1;
    }

    bool
        MutexManager::unlock_micro_mutex(
            const MutexManagerConfigurations&
            configurations
        )
    {
        MutexManager::cache_void_pointer_1 =
            const_cast<void*>(
                configurations.pointer
                );

        MutexManager::cache_string_view_1 =
            configurations.name;

        _unlock_micro_mutex();

        return
            MutexManager::cache_boolean_1;
    }

    void
        MutexManager::_unlock_micro_mutex()
    {
        try
        {
            folly::MicroSpinLock*
                micro_spin_lock =
                &MutexManagerUtilities::cache_folly_micro_spin_lock_collection
                [
            {
                MutexManager::cache_void_pointer_1,
                    MutexManager::cache_string_view_1.data()
            }
                ];

            micro_spin_lock->unlock();

            MutexManager::cache_boolean_1 =
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
