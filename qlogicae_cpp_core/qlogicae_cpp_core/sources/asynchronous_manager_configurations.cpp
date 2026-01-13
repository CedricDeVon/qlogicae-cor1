#include "pch.hpp"

#include "../includes/asynchronous_manager_configurations.hpp"

namespace QLogicaeCppCore
{
    bool
        AsynchronousManagerConfigurations
			::initial_is_enabled =
				true;

    bool
        AsynchronousManagerConfigurations
			::default_is_enabled =
				AsynchronousManagerConfigurations
					::initial_is_enabled;

    bool
        AsynchronousManagerConfigurations
			::cache_is_enabled =
				AsynchronousManagerConfigurations
					::initial_is_enabled;
    
	bool
        AsynchronousManagerConfigurations
			::initial_is_thread_safety_enabled =
				true;

    bool
        AsynchronousManagerConfigurations
			::default_is_thread_safety_enabled =
				AsynchronousManagerConfigurations
					::initial_is_thread_safety_enabled;

    bool
        AsynchronousManagerConfigurations
			::cache_is_thread_safety_enabled =
				AsynchronousManagerConfigurations
					::initial_is_thread_safety_enabled;
    


    bool
        AsynchronousManagerConfigurations
			::cache_boolean_1 =
				false;

	boost::mutex
		AsynchronousManagerConfigurations
			::cache_mutex_1;

    AsynchronousManagerConfigurations
        AsynchronousManagerConfigurations
			::cache_configurations;


    
    bool
        AsynchronousManagerConfigurations
			::construct(
				const AsynchronousManagerConfigurations&
					configurations
			)
    {
        {
            boost::unique_lock<boost::mutex>
                mutex_lock;
            if (configurations
					.is_thread_safety_enabled)
            {
                mutex_lock =
                    boost::unique_lock<boost::mutex>
                    (
                        cache_mutex_1
                    );
            }

            cache_configurations =
                configurations;
        }

        _handle_construct();

        return
            cache_boolean_1;
    }

    bool
        AsynchronousManagerConfigurations
			::destruct(
				const AsynchronousManagerConfigurations&
					configurations
			)
    {
        {
            boost::unique_lock<boost::mutex>
                mutex_lock;
            if (configurations
					.is_thread_safety_enabled)
            {
                mutex_lock =
                    boost::unique_lock<boost::mutex>
                    (
                        cache_mutex_1
                    );
            }

            cache_configurations =
                configurations;
        }

        _handle_destruct();

        return
            cache_boolean_1;
    }

    bool
        AsynchronousManagerConfigurations
			::setup(
				const AsynchronousManagerConfigurations&
					configurations
			)
    {
        {
            boost::unique_lock<boost::mutex>
                mutex_lock;
            if (configurations
					.is_thread_safety_enabled)
            {
                mutex_lock =
                    boost::unique_lock<boost::mutex>
                    (
                        cache_mutex_1
                    );
            }

            cache_configurations =
                configurations;
        }

        _handle_setup();

        return
            cache_boolean_1;
    }

    bool
        AsynchronousManagerConfigurations
			::reset(
				const AsynchronousManagerConfigurations&
					configurations
			)
    {
        {
            boost::unique_lock<boost::mutex>
                mutex_lock;
            if (configurations
					.is_thread_safety_enabled)
            {
                mutex_lock =
                    boost::unique_lock<boost::mutex>
                    (
                        cache_mutex_1
                    );
            }

            cache_configurations =
                configurations;
        }

        _handle_reset();

        return
            cache_boolean_1;
    }
    
    bool
        AsynchronousManagerConfigurations
			::setup_caches(
				const AsynchronousManagerConfigurations&
					configurations
			)
    {
        {
            boost::unique_lock<boost::mutex>
                mutex_lock;
            if (configurations
					.is_thread_safety_enabled)
            {
                mutex_lock =
                    boost::unique_lock<boost::mutex>
                    (
                        cache_mutex_1
                    );
            }

            cache_configurations =
                configurations;
        }

        _handle_setup_caches();

        return
            cache_boolean_1;
    }
    
    bool
        AsynchronousManagerConfigurations
			::setup_defaults(
				const AsynchronousManagerConfigurations&
					configurations
			)
    {
        {
            boost::unique_lock<boost::mutex>
                mutex_lock;
            if (configurations
					.is_thread_safety_enabled)
            {
                mutex_lock =
                    boost::unique_lock<boost::mutex>
                    (
                        cache_mutex_1
                    );
            }

            cache_configurations =
                configurations;
        }

        _handle_setup_defaults();

        return
            cache_boolean_1;
    }
    
    bool
        AsynchronousManagerConfigurations
			::reset_caches(
				const AsynchronousManagerConfigurations&
					configurations
			)
    {
        {
            boost::unique_lock<boost::mutex>
                mutex_lock;
            if (configurations
					.is_thread_safety_enabled)
            {
                mutex_lock =
                    boost::unique_lock<boost::mutex>
                    (
                        cache_mutex_1
                    );
            }

            cache_configurations =
                configurations;
        }

        _handle_reset_caches();

        return
            cache_boolean_1;
    }
    
    bool
        AsynchronousManagerConfigurations
			::reset_defaults(
				const AsynchronousManagerConfigurations&
					configurations
			)
    {
        {
            boost::unique_lock<boost::mutex>
                mutex_lock;
            if (configurations
					.is_thread_safety_enabled)
            {
                mutex_lock =
                    boost::unique_lock<boost::mutex>
                    (
                        cache_mutex_1
                    );
            }

            cache_configurations =
                configurations;
        }

        _handle_reset_defaults();

        return
            cache_boolean_1;
    }

    void
        AsynchronousManagerConfigurations::_handle_construct()
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
            cache_boolean_1 =
                false;

            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        AsynchronousManagerConfigurations::_handle_destruct()
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
            cache_boolean_1 =
                false;

            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        AsynchronousManagerConfigurations::_handle_setup()
    {
        try
        {
            _handle_setup_caches();
            _handle_setup_defaults();

            cache_boolean_1 =
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            cache_boolean_1 =
                false;

            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        AsynchronousManagerConfigurations::_handle_reset()
    {
        try
        {
            _handle_reset_caches();
            _handle_reset_defaults();

            cache_boolean_1 =
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            cache_boolean_1 =
                false;

            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }
    
    void
        AsynchronousManagerConfigurations::_handle_setup_caches()
    {
        try
        {         
            cache_is_enabled =
                cache_configurations.is_enabled;

			cache_is_thread_safety_enabled =
				cache_configurations.is_thread_safety_enabled;

            cache_boolean_1 =
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            cache_boolean_1 =
                false;

            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        AsynchronousManagerConfigurations::_handle_setup_defaults()
    {
        try
        {         
            default_is_enabled =
                cache_configurations.is_enabled;

			default_is_thread_safety_enabled =
				cache_configurations.is_thread_safety_enabled;

            cache_boolean_1 =
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            cache_boolean_1 =
                false;

            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }
    
    void
        AsynchronousManagerConfigurations::_handle_reset_caches()
    {
        try
        {            
            cache_is_enabled =
                initial_is_enabled;

			cache_is_thread_safety_enabled =
				initial_is_thread_safety_enabled;

            cache_boolean_1 =
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            cache_boolean_1 =
                false;

            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        AsynchronousManagerConfigurations::_handle_reset_defaults()
    {
        try
        {            
            default_is_enabled =
                initial_is_enabled;

			default_is_thread_safety_enabled =
				initial_is_thread_safety_enabled;

            cache_boolean_1 =
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            cache_boolean_1 =
                false;

            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }
}
