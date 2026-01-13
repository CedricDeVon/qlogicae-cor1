#include "pch.hpp"

#include "../includes/error_manager_configurations.hpp"

namespace QLogicaeCppCore
{    
    bool
        ErrorManagerConfigurations
			::initial_is_enabled =
				false;

    bool
        ErrorManagerConfigurations
			::initial_is_thread_safety_enabled =
				false;

    bool
        ErrorManagerConfigurations
			::initial_is_console_output_enabled =
				true;

    bool
        ErrorManagerConfigurations
			::initial_is_file_output_enabled =
				true;

    bool
        ErrorManagerConfigurations
			::initial_is_gui_output_enabled =
				true;

    bool
        ErrorManagerConfigurations
			::initial_is_runtime_throw_output_enabled =
				true;

    bool
        ErrorManagerConfigurations
			::initial_is_asynchronous_output_enabled =
				false;

    bool
        ErrorManagerConfigurations
			::initial_is_asynchronous_console_output_enabled =
				false;

    bool
        ErrorManagerConfigurations
			::initial_is_asynchronous_file_output_enabled =
				false;

    bool
        ErrorManagerConfigurations
			::initial_is_asynchronous_gui_output_enabled =
				false;

    bool
        ErrorManagerConfigurations
			::initial_is_asynchronous_runtime_throw_output_enabled =
				false;

    std::string
        ErrorManagerConfigurations
			::initial_title_message_separator =
				"-";

    std::vector<std::string>
        ErrorManagerConfigurations
			::initial_full_file_output_paths =
				{
					"qlogicae.all.log"  
				};



    bool
        ErrorManagerConfigurations
			::default_is_enabled =
	            ErrorManagerConfigurations
					::initial_is_enabled;

    bool
        ErrorManagerConfigurations
			::default_is_thread_safety_enabled =
	            ErrorManagerConfigurations
					::initial_is_thread_safety_enabled;

    bool
        ErrorManagerConfigurations
			::default_is_console_output_enabled =
	            ErrorManagerConfigurations
					::initial_is_console_output_enabled;

    bool
        ErrorManagerConfigurations
			::default_is_file_output_enabled =
	            ErrorManagerConfigurations
					::initial_is_file_output_enabled;

    bool
        ErrorManagerConfigurations
			::default_is_gui_output_enabled =
	            ErrorManagerConfigurations
					::initial_is_gui_output_enabled;

    bool
        ErrorManagerConfigurations
			::default_is_runtime_throw_output_enabled =
	            ErrorManagerConfigurations
					::initial_is_runtime_throw_output_enabled;

    bool
        ErrorManagerConfigurations
			::default_is_asynchronous_output_enabled =
	            ErrorManagerConfigurations
					::initial_is_asynchronous_output_enabled;

    bool
        ErrorManagerConfigurations
			::default_is_asynchronous_console_output_enabled =
	            ErrorManagerConfigurations
					::initial_is_asynchronous_console_output_enabled;

    bool
        ErrorManagerConfigurations
			::default_is_asynchronous_file_output_enabled =
	            ErrorManagerConfigurations
					::initial_is_asynchronous_file_output_enabled;

    bool
        ErrorManagerConfigurations
			::default_is_asynchronous_gui_output_enabled =
	            ErrorManagerConfigurations
					::initial_is_asynchronous_gui_output_enabled;

    bool
        ErrorManagerConfigurations
			::default_is_asynchronous_runtime_throw_output_enabled =
	            ErrorManagerConfigurations
					::initial_is_asynchronous_runtime_throw_output_enabled;

    std::string
        ErrorManagerConfigurations
			::default_title_message_separator =
	            ErrorManagerConfigurations
					::initial_title_message_separator;

    std::vector<std::string>
        ErrorManagerConfigurations
			::default_full_file_output_paths =
	            ErrorManagerConfigurations
					::initial_full_file_output_paths;



    bool
        ErrorManagerConfigurations
			::cache_is_enabled =
	            ErrorManagerConfigurations
					::initial_is_enabled;

    bool
        ErrorManagerConfigurations
			::cache_is_thread_safety_enabled =
	            ErrorManagerConfigurations
					::initial_is_thread_safety_enabled;

    bool
        ErrorManagerConfigurations
			::cache_is_console_output_enabled =
	            ErrorManagerConfigurations
					::initial_is_console_output_enabled;

    bool
        ErrorManagerConfigurations
			::cache_is_file_output_enabled =
	            ErrorManagerConfigurations
					::initial_is_file_output_enabled;

    bool
        ErrorManagerConfigurations
			::cache_is_gui_output_enabled =
	            ErrorManagerConfigurations
					::initial_is_gui_output_enabled;

    bool
        ErrorManagerConfigurations
			::cache_is_runtime_throw_output_enabled =
	            ErrorManagerConfigurations
					::initial_is_runtime_throw_output_enabled;

    bool
        ErrorManagerConfigurations
			::cache_is_asynchronous_output_enabled =
	            ErrorManagerConfigurations
					::initial_is_asynchronous_output_enabled;

    bool
        ErrorManagerConfigurations
			::cache_is_asynchronous_console_output_enabled =
	            ErrorManagerConfigurations
					::initial_is_asynchronous_console_output_enabled;

    bool
        ErrorManagerConfigurations
			::cache_is_asynchronous_file_output_enabled =
	            ErrorManagerConfigurations
					::initial_is_asynchronous_file_output_enabled;

    bool
        ErrorManagerConfigurations
			::cache_is_asynchronous_gui_output_enabled =
	            ErrorManagerConfigurations
					::initial_is_asynchronous_gui_output_enabled;

    bool
        ErrorManagerConfigurations
			::cache_is_asynchronous_runtime_throw_output_enabled =
	            ErrorManagerConfigurations
					::initial_is_asynchronous_runtime_throw_output_enabled;

    std::string
        ErrorManagerConfigurations
			::cache_title_message_separator =
	            ErrorManagerConfigurations
					::initial_title_message_separator;

    std::vector<std::string>
        ErrorManagerConfigurations
			::cache_full_file_output_paths =
	            ErrorManagerConfigurations
					::initial_full_file_output_paths;



    bool
        ErrorManagerConfigurations
			::cache_boolean_1 =
				false;

    boost::mutex
        ErrorManagerConfigurations
			::cache_mutex_1;

    ErrorManagerConfigurations
        ErrorManagerConfigurations
			::cache_configurations;



    bool
        ErrorManagerConfigurations
			::construct(
				const ErrorManagerConfigurations&
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
        ErrorManagerConfigurations
			::destruct(
				const ErrorManagerConfigurations&
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
        ErrorManagerConfigurations
			::setup(
				const ErrorManagerConfigurations&
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
        ErrorManagerConfigurations
			::reset(
				const ErrorManagerConfigurations&
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
        ErrorManagerConfigurations
			::setup_caches(
				const ErrorManagerConfigurations&
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
        ErrorManagerConfigurations
			::setup_defaults(
				const ErrorManagerConfigurations&
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
        ErrorManagerConfigurations
			::reset_caches(
				const ErrorManagerConfigurations&
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
        ErrorManagerConfigurations
			::reset_defaults(
				const ErrorManagerConfigurations&
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
        ErrorManagerConfigurations
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

            throw std::runtime_error(
                exception.what()
            );
        }
    }

    void
        ErrorManagerConfigurations
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

            throw std::runtime_error(
                exception.what()
            );
        }
    }

    void
        ErrorManagerConfigurations
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

            throw std::runtime_error(
                exception.what()
            );
        }
    }

    void
        ErrorManagerConfigurations
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

            throw std::runtime_error(
                exception.what()
            );
        }
    }
    
    void
        ErrorManagerConfigurations
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

            cache_is_console_output_enabled =
                cache_configurations
					.is_console_output_enabled;

            cache_is_file_output_enabled =
                cache_configurations
					.is_file_output_enabled;

            cache_is_gui_output_enabled =
                cache_configurations
					.is_gui_output_enabled;

            cache_is_runtime_throw_output_enabled =
                cache_configurations
					.is_runtime_throw_output_enabled;

            cache_is_asynchronous_output_enabled =
                cache_configurations
					.is_asynchronous_output_enabled;

            cache_is_asynchronous_console_output_enabled =
                cache_configurations
					.is_asynchronous_console_output_enabled;

            cache_is_asynchronous_file_output_enabled =
                cache_configurations
					.is_asynchronous_file_output_enabled;

            cache_is_asynchronous_gui_output_enabled =
                cache_configurations
					.is_asynchronous_gui_output_enabled;

            cache_is_asynchronous_runtime_throw_output_enabled =
                cache_configurations
					.is_asynchronous_runtime_throw_output_enabled;

            cache_title_message_separator =
                cache_configurations
					.title_message_separator;

            cache_full_file_output_paths =
                cache_configurations
					.full_file_output_paths;

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

            throw std::runtime_error(
                exception.what()
            );
        }
    }

    void
        ErrorManagerConfigurations
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

            default_is_console_output_enabled =
                cache_configurations
					.is_console_output_enabled;

            default_is_file_output_enabled =
                cache_configurations
					.is_file_output_enabled;

            default_is_gui_output_enabled =
                cache_configurations
					.is_gui_output_enabled;

            default_is_runtime_throw_output_enabled =
                cache_configurations
					.is_runtime_throw_output_enabled;

            default_is_asynchronous_output_enabled =
                cache_configurations
					.is_asynchronous_output_enabled;

            default_is_asynchronous_console_output_enabled =
                cache_configurations
					.is_asynchronous_console_output_enabled;

            default_is_asynchronous_file_output_enabled =
                cache_configurations
					.is_asynchronous_file_output_enabled;

            default_is_asynchronous_gui_output_enabled =
                cache_configurations
					.is_asynchronous_gui_output_enabled;

            default_is_asynchronous_runtime_throw_output_enabled =
                cache_configurations
					.is_asynchronous_runtime_throw_output_enabled;

            default_title_message_separator =
                cache_configurations
					.title_message_separator;

            default_full_file_output_paths =
                cache_configurations
					.full_file_output_paths;

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

            throw std::runtime_error(
                exception.what()
            );
        }
    }
    
    void
        ErrorManagerConfigurations
			::_handle_reset_caches()
    {	
		try
		{
            cache_is_enabled =
                initial_is_enabled;

            cache_is_thread_safety_enabled =
                initial_is_thread_safety_enabled;

            cache_is_console_output_enabled =
                initial_is_console_output_enabled;

            cache_is_file_output_enabled =
                initial_is_file_output_enabled;

            cache_is_gui_output_enabled =
                initial_is_gui_output_enabled;

            cache_is_runtime_throw_output_enabled =
                initial_is_runtime_throw_output_enabled;

            cache_is_asynchronous_output_enabled =
                initial_is_asynchronous_output_enabled;

            cache_is_asynchronous_console_output_enabled =
                initial_is_asynchronous_console_output_enabled;

            cache_is_asynchronous_file_output_enabled =
                initial_is_asynchronous_file_output_enabled;

            cache_is_asynchronous_gui_output_enabled =
                initial_is_asynchronous_gui_output_enabled;

            cache_is_asynchronous_runtime_throw_output_enabled =
                initial_is_asynchronous_runtime_throw_output_enabled;

            cache_title_message_separator =
                initial_title_message_separator;

            cache_full_file_output_paths =
                initial_full_file_output_paths;

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

            throw std::runtime_error(
                exception.what()
            );
        }
    }

    void
        ErrorManagerConfigurations
			::_handle_reset_defaults()
    {	
		try
		{
            default_is_enabled =
                initial_is_enabled;

            default_is_thread_safety_enabled =
                initial_is_thread_safety_enabled;

            default_is_console_output_enabled =
                initial_is_console_output_enabled;

            default_is_file_output_enabled =
                initial_is_file_output_enabled;

            default_is_gui_output_enabled =
                initial_is_gui_output_enabled;

            default_is_runtime_throw_output_enabled =
                initial_is_runtime_throw_output_enabled;

            default_is_asynchronous_output_enabled =
                initial_is_asynchronous_output_enabled;

            default_is_asynchronous_console_output_enabled =
                initial_is_asynchronous_console_output_enabled;

            default_is_asynchronous_file_output_enabled =
                initial_is_asynchronous_file_output_enabled;

            default_is_asynchronous_gui_output_enabled =
                initial_is_asynchronous_gui_output_enabled;

            default_is_asynchronous_runtime_throw_output_enabled =
                initial_is_asynchronous_runtime_throw_output_enabled;

            default_title_message_separator =
                initial_title_message_separator;

            default_full_file_output_paths =
                initial_full_file_output_paths;

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

            throw std::runtime_error(
                exception.what()
            );
        }
    }
}
