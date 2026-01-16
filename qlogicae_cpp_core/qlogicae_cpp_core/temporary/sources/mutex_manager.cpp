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

    MutexManager::~MutexManager()
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
        MutexManager::construct()
    {
        _handle_construct();

        return
            cache_boolean_1;
    }

    void
        MutexManager::_handle_construct()
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
        MutexManager::destruct()
    {
        _handle_destruct();

        return
            cache_boolean_1;
    }

    void
        MutexManager::_handle_destruct()
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
        MutexManager::setup(
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
        MutexManager::setup()
    {
        MutexManagerConfigurations::cache =
        {};

        _handle_setup();

        return
            cache_boolean_1;
    }

    void
        MutexManager::_handle_setup()
    {
        try
        {
            MutexManagerUtilities::singleton
                ._handle_setup();

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
        MutexManager::reset()
    {
        _handle_reset();

        return
            cache_boolean_1;
    }

    void
        MutexManager::_handle_reset()
    {
        try
        {
            MutexManagerUtilities::singleton
                ._handle_clear_all_collections();

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
        MutexManager::lock_micro_mutex()
    {
        cache_void_pointer_1 =
            this;

        cache_string_view_1 =
            MutexManagerConfigurations::default_name;

        _handle_lock_micro_mutex();

        return
            cache_boolean_1;
    }

    bool
        MutexManager::lock_micro_mutex(
            const void*
            pointer
        )
    {
        cache_void_pointer_1 =
            const_cast<void*>(
                pointer
                );

        cache_string_view_1 =
            MutexManagerConfigurations::default_name;

        _handle_lock_micro_mutex();

        return
            cache_boolean_1;
    }

    bool
        MutexManager::lock_micro_mutex(
            const void*
            pointer,
            const std::string_view&
            name
        )
    {
        cache_void_pointer_1 =
            const_cast<void*>(pointer);

        cache_string_view_1 =
            name;

        _handle_lock_micro_mutex();

        return
            cache_boolean_1;
    }

    bool
        MutexManager::lock_micro_mutex(
            const MutexManagerConfigurations&
            configurations
        )
    {
        cache_void_pointer_1 =
            const_cast<void*>(
                configurations.pointer
                );

        cache_string_view_1 =
            configurations.name;

        _handle_lock_micro_mutex();

        return
            cache_boolean_1;
    }

    void
        MutexManager::_handle_lock_micro_mutex()
    {
        try
        {
            folly::MicroSpinLock*
                micro_spin_lock =
                &MutexManagerUtilities::cache_folly_micro_spin_lock_collection
                [
            {
                cache_void_pointer_1,
                    cache_string_view_1.data()
            }
                ];

            micro_spin_lock->lock();

            cache_boolean_1 = true;
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
        cache_void_pointer_1 =
            this;

        cache_string_view_1 =
            MutexManagerConfigurations::default_name;

        _handle_unlock_micro_mutex();

        return
            cache_boolean_1;
    }

    bool
        MutexManager::unlock_micro_mutex(
            const void*
            pointer
        )
    {
        cache_void_pointer_1 =
            const_cast<void*>(
                pointer
                );

        cache_string_view_1 =
            MutexManagerConfigurations::default_name;

        _handle_unlock_micro_mutex();

        return
            cache_boolean_1;
    }

    bool
        MutexManager::unlock_micro_mutex(
            const void*
            pointer,
            const std::string_view&
            name
        )
    {
        cache_void_pointer_1 =
            const_cast<void*>(
                pointer
                );

        cache_string_view_1 =
            name;

        _handle_unlock_micro_mutex();

        return
            cache_boolean_1;
    }

    bool
        MutexManager::unlock_micro_mutex(
            const MutexManagerConfigurations&
            configurations
        )
    {
        cache_void_pointer_1 =
            const_cast<void*>(
                configurations.pointer
                );

        cache_string_view_1 =
            configurations.name;

        _handle_unlock_micro_mutex();

        return
            cache_boolean_1;
    }

    void
        MutexManager::_handle_unlock_micro_mutex()
    {
        try
        {
            folly::MicroSpinLock*
                micro_spin_lock =
                &MutexManagerUtilities::cache_folly_micro_spin_lock_collection
                [
            {
                cache_void_pointer_1,
                    cache_string_view_1.data()
            }
                ];

            micro_spin_lock->unlock();

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
