#include "pch.hpp"

#include "../includes/error_manager.hpp"

namespace QLogicaeCppCore
{        
    bool
        ErrorManager::
			cache_boolean_1 =
				false;

    boost::mutex
        ErrorManager::
				cache_mutex_1;

    std::string
        ErrorManager::
			cache_error_log =
				"";

    fast_io::native_io_observer
        ErrorManager::					
            cache_fast_io_error_console_output_type =
                fast_io::err();

    ErrorManager&
        ErrorManager::
			singleton =
				SingletonManager::
					get_singleton<ErrorManager>();



    ErrorManager
		::ErrorManager()
    {        
        boost::unique_lock<boost::mutex>
            mutex_lock;
        if (ErrorManagerConfigurations::
                cache_is_thread_safety_enabled)
        {
            mutex_lock =
                boost::unique_lock<boost::mutex>
                (
                    cache_mutex_1
                );

			ErrorManagerConfigurations::
				cache_configurations =
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

            _handle();
        }
    }

    ErrorManager
			::~ErrorManager()
    {
        boost::unique_lock<boost::mutex>
            mutex_lock;
        if (ErrorManagerConfigurations::cache_is_thread_safety_enabled)
        {
            mutex_lock =
                boost::unique_lock<boost::mutex>
                (
                    cache_mutex_1
                );

            ErrorManagerConfigurations::cache_configurations =
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

            _handle();
        }
    }

    bool
        ErrorManager
			::construct(
				const ErrorManagerConfigurations&
					configurations
			)
    {
        {
            boost::unique_lock<boost::mutex>
                mutex_lock;
            if (configurations.is_thread_safety_enabled)
            {
                mutex_lock =
                    boost::unique_lock<boost::mutex>
                    (
                        cache_mutex_1
                    );
            }

            ErrorManagerConfigurations::cache_configurations =
                configurations;
        }

        _handle_construct();

        return
            cache_boolean_1;
    }

    bool
        ErrorManager
			::destruct(
				const ErrorManagerConfigurations&
					configurations
			)
    {
        {
            boost::unique_lock<boost::mutex>
                mutex_lock;
            if (configurations.is_thread_safety_enabled)
            {
                mutex_lock =
                    boost::unique_lock<boost::mutex>
                    (
                        cache_mutex_1
                    );
            }

            ErrorManagerConfigurations::cache_configurations =
                configurations;
        }

        _handle_destruct();

        return
            cache_boolean_1;
    }

    bool
        ErrorManager
			::setup(
				const ErrorManagerConfigurations&
					configurations
			)
    {
        {
            boost::unique_lock<boost::mutex>
                mutex_lock;
            if (configurations.is_thread_safety_enabled)
            {
                mutex_lock =
                    boost::unique_lock<boost::mutex>
                    (
                        cache_mutex_1
                    );
            }

            ErrorManagerConfigurations::cache_configurations =
                configurations;
        }

        _handle_setup();

        return
            cache_boolean_1;
    }

    bool
        ErrorManager
			::reset(
				const ErrorManagerConfigurations&
					configurations
			)
    {
        {
            boost::unique_lock<boost::mutex>
                mutex_lock;
            if (configurations.is_thread_safety_enabled)
            {
                mutex_lock = boost::unique_lock<boost::mutex>
                    (cache_mutex_1);
            }

            ErrorManagerConfigurations::cache_configurations =
                configurations;
        }

        _handle_reset();

        return
            cache_boolean_1;
    }

    bool
        ErrorManager
			::handle(
				const std::string_view&
					title,
				const std::string_view&
					message,
				const ErrorManagerConfigurations&
					configurations
			)
    {
        {
            boost::unique_lock<boost::mutex>
                mutex_lock;
            if (configurations.is_thread_safety_enabled)
            {
                mutex_lock =
                    boost::unique_lock<boost::mutex>
                    (
                        cache_mutex_1
                    );
            }

            ErrorManagerConfigurations::cache_configurations =
                configurations;
            ErrorManagerConfigurations::_handle_setup_caches();

            cache_error_log =
                std::string(title.data()) +
                ErrorManagerConfigurations::cache_title_message_separator +
                message.data();
        }

        _handle();

        {
            boost::unique_lock<boost::mutex>
                mutex_lock;
            if (ErrorManagerConfigurations::cache_is_thread_safety_enabled)
            {
                mutex_lock =
                    boost::unique_lock<boost::mutex>
                    (
                        cache_mutex_1
                    );
            }

			ErrorManagerConfigurations::cache_configurations =
                {};
            ErrorManagerConfigurations::_handle_setup_caches();
        }

        return
            cache_boolean_1;
    }

    bool
        ErrorManager
			::handle(
				const std::string_view&
					message,
				const ErrorManagerConfigurations&
					configurations
			)
    {
        {
            boost::unique_lock<boost::mutex>
                mutex_lock;
            if (configurations.is_thread_safety_enabled)
            {
                mutex_lock =
                    boost::unique_lock<boost::mutex>
                    (
                        cache_mutex_1
                    );
            }

            ErrorManagerConfigurations::cache_configurations =
                configurations;
            ErrorManagerConfigurations::_handle_setup_caches();
            cache_error_log =
                message;
        }

        _handle();

        {
            boost::unique_lock<boost::mutex>
                mutex_lock;
            if (ErrorManagerConfigurations::cache_is_thread_safety_enabled)
            {
                mutex_lock =
                    boost::unique_lock<boost::mutex>
                    (
                        cache_mutex_1
                    );
            }

            ErrorManagerConfigurations::cache_configurations =
                {};
            ErrorManagerConfigurations::_handle_setup_caches();
        }

        return
            cache_boolean_1;
    }

    bool
        ErrorManager
			::handle(
				const std::exception&
					exception,
				const ErrorManagerConfigurations&
					configurations
			)
    {
        {
            boost::unique_lock<boost::mutex>
                mutex_lock;
            if (configurations.is_thread_safety_enabled)
            {
                mutex_lock =
                    boost::unique_lock<boost::mutex>
                    (
                        cache_mutex_1
                    );
            }

            ErrorManagerConfigurations::cache_configurations =
                configurations;
            ErrorManagerConfigurations::_handle_setup_caches();
            cache_error_log =
                std::string(typeid(exception).name()) +
                ErrorManagerConfigurations::cache_title_message_separator +
                exception.what();
        }

        _handle();

        {
            boost::unique_lock<boost::mutex>
                mutex_lock;
            if (ErrorManagerConfigurations::cache_is_thread_safety_enabled)
            {
                mutex_lock =
                    boost::unique_lock<boost::mutex>
                    (
                        cache_mutex_1
                    );
            }

            ErrorManagerConfigurations::cache_configurations =
                {};
            ErrorManagerConfigurations::_handle_setup_caches();        
        }
        
        return
            cache_boolean_1;
    }
    
    void
        ErrorManager
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

            _handle();
        }
    }

    void
        ErrorManager
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

            _handle();
        }
    }

    void
        ErrorManager
			::_handle_setup()
    {
        try
        {
            ErrorManagerConfigurations
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

            _handle();
        }
    }
    
    void
        ErrorManager
			::_handle_reset()
    {
        try
        {
            ErrorManagerConfigurations
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

            _handle();
        }
    }

    void
        ErrorManager
			::_handle()
    {
        cache_boolean_1 =
            false;

        if (!ErrorManagerConfigurations
				::cache_is_enabled
			)
        {
            return;
        }

        if (ErrorManagerConfigurations
				::cache_is_asynchronous_output_enabled
			)
        {
            _handle_asynchronously();
        }
        else
        {
            _handle_synchronously();
        }
    }

    void
        ErrorManager
			::_handle_asynchronously()
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
                            cache_fast_io_error_console_output_type,
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
            for (const std::string&
					cache_full_file_output_path :
					ErrorManagerConfigurations
						::cache_full_file_output_paths
                )
            {
                if (!std::filesystem
						::exists(cache_full_file_output_path)
					)
                {
                    continue;
                }

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

        for (std::future<void>&
			future :
			futures
		)
        {
            future.get();
        }
    }

    void
        ErrorManager
			::_handle_synchronously()
    {
        if (ErrorManagerConfigurations
				::cache_is_console_output_enabled)
        {
            fast_io::io::println(
                cache_fast_io_error_console_output_type,
                cache_error_log
            );
        }

        if (ErrorManagerConfigurations
				::cache_is_file_output_enabled)
        {
            for (const std::string& cache_full_file_output_path :
                ErrorManagerConfigurations
					::cache_full_file_output_paths
                )
            {
                if (!std::filesystem
						::exists(cache_full_file_output_path)
					)
                {
                    continue;
                }

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
