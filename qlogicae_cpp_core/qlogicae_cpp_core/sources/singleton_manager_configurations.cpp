#include "pch.hpp"

#include "../includes/singleton_manager_configurations.hpp"

namespace QLogicaeCppCore
{   
    bool
        SingletonManagerConfigurations
			::initial_is_enabled =
				false;

    bool
        SingletonManagerConfigurations
			::initial_is_thread_safety_enabled =
				false;
	
	

	bool
        SingletonManagerConfigurations
			::default_is_enabled =
	            SingletonManagerConfigurations
					::initial_is_enabled;

    bool
        SingletonManagerConfigurations
			::default_is_thread_safety_enabled =
	            SingletonManagerConfigurations
					::initial_is_thread_safety_enabled;
	


	bool
        SingletonManagerConfigurations
			::cache_is_enabled =
	            SingletonManagerConfigurations
					::initial_is_enabled;

    bool
        SingletonManagerConfigurations
			::cache_is_thread_safety_enabled =
	            SingletonManagerConfigurations
					::initial_is_thread_safety_enabled;



	bool
        SingletonManagerConfigurations
			::cache_boolean_1 =
				false;
	
	boost::mutex
		SingletonManagerConfigurations
			::cache_mutex_1;

    SingletonManagerConfigurations
        SingletonManagerConfigurations
			::cache_configurations;


    
    bool
        SingletonManagerConfigurations
			::construct(
				const SingletonManagerConfigurations&
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
        SingletonManagerConfigurations
			::destruct(
				const SingletonManagerConfigurations&
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
        SingletonManagerConfigurations
			::setup(
				const SingletonManagerConfigurations&
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
        SingletonManagerConfigurations
			::reset(
				const SingletonManagerConfigurations&
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
        SingletonManagerConfigurations
			::setup_caches(
				const SingletonManagerConfigurations&
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
        SingletonManagerConfigurations
			::setup_defaults(
				const SingletonManagerConfigurations&
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
        SingletonManagerConfigurations
			::reset_caches(
				const SingletonManagerConfigurations&
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
        SingletonManagerConfigurations
			::reset_defaults(
				const SingletonManagerConfigurations&
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
        SingletonManagerConfigurations
			::_handle_construct()
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

            throw
				std::runtime_error(
					exception.what()
				);
        }
    }

    void
        SingletonManagerConfigurations
			::_handle_destruct()
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

            throw
				std::runtime_error(
					exception.what()
				);
        }
    }

    void
        SingletonManagerConfigurations
			::_handle_setup()
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

            throw
				std::runtime_error(
					exception.what()
				);
        }
    }

    void
        SingletonManagerConfigurations
			::_handle_reset()
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

            throw
				std::runtime_error(
					exception.what()
				);
        }
    }
    
    void
        SingletonManagerConfigurations
			::_handle_setup_caches()
    {
        try
        {            
			cache_is_enabled =
                cache_configurations
					.is_enabled;

            cache_is_thread_safety_enabled =
                cache_configurations
					.is_thread_safety_enabled;

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

            throw
				std::runtime_error(
					exception.what()
				);
        }
    }

    void
        SingletonManagerConfigurations
			::_handle_setup_defaults()
    {
        try
        {            
			default_is_enabled =
                cache_configurations
					.is_enabled;

            default_is_thread_safety_enabled =
                cache_configurations
					.is_thread_safety_enabled;

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

            throw
				std::runtime_error(
					exception.what()
				);
        }
    }
    
    void
        SingletonManagerConfigurations
			::_handle_reset_caches()
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

            throw
				std::runtime_error(
					exception.what()
				);
        }
    }

    void
        SingletonManagerConfigurations
			::_handle_reset_defaults()
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

            throw
				std::runtime_error(
					exception.what()
				);
        }
    }
}
