#include "pch.hpp"

#include "../includes/singleton_manager.hpp"

namespace QLogicaeCppCore
{           
    bool
        SingletonManager
			::cache_boolean_1 =
				false;
	
    boost::mutex
		SingletonManager
			::cache_mutex_1;

    std::string
        SingletonManager
			::cache_error_log =
				"";

    fast_io::native_io_observer
        SingletonManager
			::cache_fast_io_error_console_output_type =
				fast_io::err();

    SingletonManager&
        SingletonManager
			::singleton =
				SingletonManager
					::get_this_singleton();



    SingletonManager
		::SingletonManager()
    {      
		{
			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (SingletonManagerConfigurations::
					cache_is_thread_safety_enabled)
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						cache_mutex_1
					);

			}		
			
			SingletonManagerConfigurations
				::cache_configurations =
					{};
		}

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
            cache_boolean_1 =
                false;

            cache_error_log =
                exception.what();

            _handle_error();
        }
    }

    SingletonManager
		::~SingletonManager()
    {
		{
			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (SingletonManagerConfigurations::
					cache_is_thread_safety_enabled)
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						cache_mutex_1
					);

			}		
			
			SingletonManagerConfigurations
				::cache_configurations =
					{};
		}

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
            cache_boolean_1 =
                false;

            cache_error_log =
                exception.what();

            _handle_error();
        }
    }

    bool
        SingletonManager
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

			SingletonManagerConfigurations
				::cache_configurations =
					configurations;
		}
		
        _handle_construct();

        return
            cache_boolean_1;
    }

    bool
        SingletonManager
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

			SingletonManagerConfigurations
				::cache_configurations =
					configurations;
		}

        _handle_destruct();

        return
            cache_boolean_1;
    }

    bool
        SingletonManager
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

			SingletonManagerConfigurations
				::cache_configurations =
					configurations;
		}

        _handle_setup();

        return
            cache_boolean_1;
    }

    bool
        SingletonManager
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

			SingletonManagerConfigurations
				::cache_configurations =
					configurations;
		}

        _handle_reset();

        return
            cache_boolean_1;
    }

    bool
        SingletonManager
			::handle_error(
				const std::exception&
					exception,
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

			SingletonManagerConfigurations
				::cache_configurations =
					configurations;
			SingletonManagerConfigurations
				::_handle_setup_caches();

			cache_error_log =
				exception.what();
		}        

        _handle_error();

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

			SingletonManagerConfigurations
				::cache_configurations =
					{};
			SingletonManagerConfigurations
				::_handle_setup_caches();
		}
        
        return
            cache_boolean_1;
    }
    
    SingletonManager&
        SingletonManager
			::get_this_singleton(
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

			SingletonManagerConfigurations
				::cache_configurations =
					configurations;
			SingletonManagerConfigurations
				::_handle_setup_caches();
		}

        static SingletonManager
            singleton;

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

			SingletonManagerConfigurations
				::cache_configurations =
					{};
			SingletonManagerConfigurations
				::_handle_setup_caches();
		}        

        return
            singleton;
    }

    void
        SingletonManager
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

            cache_error_log =
                exception.what();

            _handle_error();
        }
    }

    void
        SingletonManager
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

            cache_error_log =
                exception.what();

            _handle_error();
        }
    }

    void
        SingletonManager
			::_handle_setup()
    {
        try
        {
            SingletonManagerConfigurations
				::_handle_setup();

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

            cache_error_log =
                exception.what();

            _handle_error();
        }
    }

    void
        SingletonManager
			::_handle_reset()
    {
        try
        {
            SingletonManagerConfigurations
				::_handle_reset();

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

            cache_error_log =
                exception.what();

            _handle_error();
        }
    }
    
    void
        SingletonManager
			::_handle_error()
    {
        try
        {
            cache_boolean_1 =
                false;
            
            if (!ErrorManagerConfigurations
					::cache_is_enabled)
            {
                return;
            }

            if (ErrorManagerConfigurations
					::cache_is_asynchronous_output_enabled)
            {
                _handle_error_asynchronously();
            }
            else
            {
                _handle_error_synchronously();
            }
        }
        catch (...)
        {
            cache_boolean_1 =
                false;
        }
    }

    void
        SingletonManager
			::_handle_error_asynchronously()
    {
        std::vector<std::future<void>>
            futures;

        if (ErrorManagerConfigurations
				::cache_is_asynchronous_console_output_enabled &&
            ErrorManagerConfigurations
				::cache_is_console_output_enabled
            )
        {
            futures.push_back(
                std::async(
                    std::launch::async,
                    [&]()
                    {
                        fast_io::io::println(
                            SingletonManager
			::cache_fast_io_error_console_output_type,
                            cache_error_log
                        );
                    }
                )
            );
        }

        if (ErrorManagerConfigurations
				::cache_is_asynchronous_file_output_enabled &&
            ErrorManagerConfigurations
				::cache_is_file_output_enabled
            )
        {
            for (const std::string& cache_full_file_output_path :
                ErrorManagerConfigurations::cache_full_file_output_paths
                )
            {
                futures.push_back(
                    std::async(
                        std::launch::async,
                        [&]()
                        {
                            fast_io::native_file
                                fast_io_native_file(
                                    cache_full_file_output_path,
                                    fast_io::open_mode::app
                                );

                            fast_io::io::println(
                                fast_io_native_file,
                                cache_error_log
                            );
                        }
                    )
                );
            }
        }

        if (ErrorManagerConfigurations
				::cache_is_asynchronous_runtime_throw_output_enabled &&
            ErrorManagerConfigurations
				::cache_is_runtime_throw_output_enabled
            )
        {
            futures.push_back(
                std::async(
                    std::launch::async,
                    [&]()
                    {
                        throw
							std::runtime_error(
								cache_error_log
							);
                    }
                )
            );
        }

        for (std::future<void>& future : futures)
        {
            future.get();
        }
    }

    void
        SingletonManager
			::_handle_error_synchronously()
    {
        if (ErrorManagerConfigurations
				::cache_is_console_output_enabled)
        {
            fast_io::io::println(
                SingletonManager
					::cache_fast_io_error_console_output_type,
                cache_error_log
            );
        }

        if (ErrorManagerConfigurations
				::cache_is_file_output_enabled)
        {
            for (const std::string&
					cache_full_file_output_path :
					ErrorManagerConfigurations
						::cache_full_file_output_paths
                )
            {
                fast_io::native_file
                    fast_io_native_file(
                        cache_full_file_output_path,
                        fast_io::open_mode::app
                    );

                fast_io::io::println(
                    fast_io_native_file,
                    cache_error_log
                );
            }
        }

        if (ErrorManagerConfigurations
				::cache_is_runtime_throw_output_enabled)
        {
            throw
				std::runtime_error(
					cache_error_log
				);
        }
    }
}
