#include "pch.hpp"

#include "../includes/error_manager.hpp"

namespace QLogicaeCppCore
{        
    bool
        ErrorManager::cache_boolean_1 =
            false;

    std::string
        ErrorManager::cache_error_log =
            "";

    fast_io::native_io_observer
        ErrorManager::cache_fast_io_error_console_output_type =
            fast_io::err();

    ErrorManager&
        ErrorManager::singleton =
            SingletonManager::get_singleton<ErrorManager>();



    ErrorManager::ErrorManager()
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
            cache_error_log =
                exception.what();

            _handle();
        }
    }

    ErrorManager::~ErrorManager()
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
            cache_error_log =
                exception.what();

            _handle();
        }
    }

    bool
        ErrorManager::construct()
    {
        _construct();

        return cache_boolean_1;
    }

    void
        ErrorManager::_construct()
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
            cache_error_log =
                exception.what();

            _handle();
        }
    }

    bool
        ErrorManager::destruct()
    {
        _destruct();

        return cache_boolean_1;
    }

    void
        ErrorManager::_destruct()
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
            cache_error_log =
                exception.what();

            _handle();
        }
    }

    bool
        ErrorManager::setup(
            const ErrorManagerConfigurations&
                new_configurations
        )
    {
        ErrorManagerConfigurations::cache =
            new_configurations;

        _setup();

        return cache_boolean_1;
    }

    bool
        ErrorManager::setup()
    {
        ErrorManagerConfigurations::cache =
            {};

        _setup();

        return cache_boolean_1;
    }

    void
        ErrorManager::_setup()
    {
        try
        {
            ErrorManagerConfigurations::default_is_enabled =
                ErrorManagerConfigurations::cache_is_enabled =
                ErrorManagerConfigurations::cache.is_enabled;

            ErrorManagerConfigurations::default_is_console_output_enabled =
                ErrorManagerConfigurations::cache_is_console_output_enabled =
                ErrorManagerConfigurations::cache.is_console_output_enabled;

            ErrorManagerConfigurations::default_is_file_output_enabled =
                ErrorManagerConfigurations::cache_is_file_output_enabled =
                ErrorManagerConfigurations::cache.is_file_output_enabled;

            ErrorManagerConfigurations::default_is_gui_output_enabled =
                ErrorManagerConfigurations::cache_is_gui_output_enabled =
                ErrorManagerConfigurations::cache.is_gui_output_enabled;

            ErrorManagerConfigurations::default_is_runtime_throw_output_enabled =
                ErrorManagerConfigurations::cache_is_runtime_throw_output_enabled =
                ErrorManagerConfigurations::cache.is_runtime_throw_output_enabled;

            ErrorManagerConfigurations::default_is_asynchronous_output_enabled =
                ErrorManagerConfigurations::cache_is_asynchronous_output_enabled =
                ErrorManagerConfigurations::cache.is_asynchronous_output_enabled;

            ErrorManagerConfigurations::default_is_asynchronous_console_output_enabled =
                ErrorManagerConfigurations::cache_is_asynchronous_console_output_enabled =
                ErrorManagerConfigurations::cache.is_asynchronous_console_output_enabled;

            ErrorManagerConfigurations::default_is_asynchronous_file_output_enabled =
                ErrorManagerConfigurations::cache_is_asynchronous_file_output_enabled =
                ErrorManagerConfigurations::cache.is_asynchronous_file_output_enabled;

            ErrorManagerConfigurations::default_is_asynchronous_gui_output_enabled =
                ErrorManagerConfigurations::cache_is_asynchronous_gui_output_enabled =
                ErrorManagerConfigurations::cache.is_asynchronous_gui_output_enabled;

            ErrorManagerConfigurations::default_is_asynchronous_runtime_throw_output_enabled =
                ErrorManagerConfigurations::cache_is_asynchronous_runtime_throw_output_enabled =
                ErrorManagerConfigurations::cache.is_asynchronous_runtime_throw_output_enabled;

            ErrorManagerConfigurations::default_full_file_output_paths =
                ErrorManagerConfigurations::cache_full_file_output_paths =
                ErrorManagerConfigurations::cache.full_file_output_paths;

            cache_boolean_1 =
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            cache_error_log =
                exception.what();

            _handle();
        }
    }

    bool
        ErrorManager::reset()
    {
        _reset();

        return cache_boolean_1;
    }

    void
        ErrorManager::_reset()
    {
        try
        {
            ErrorManagerConfigurations::default_is_enabled =
                ErrorManagerConfigurations::cache_is_enabled =
                ErrorManagerConfigurations::initial_is_enabled;

            ErrorManagerConfigurations::default_is_console_output_enabled =
                ErrorManagerConfigurations::cache_is_console_output_enabled =
                ErrorManagerConfigurations::initial_is_console_output_enabled;

            ErrorManagerConfigurations::default_is_file_output_enabled =
                ErrorManagerConfigurations::cache_is_file_output_enabled =
                ErrorManagerConfigurations::initial_is_file_output_enabled;

            ErrorManagerConfigurations::default_is_gui_output_enabled =
                ErrorManagerConfigurations::cache_is_gui_output_enabled =
                ErrorManagerConfigurations::initial_is_gui_output_enabled;

            ErrorManagerConfigurations::default_is_runtime_throw_output_enabled =
                ErrorManagerConfigurations::cache_is_runtime_throw_output_enabled =
                ErrorManagerConfigurations::initial_is_runtime_throw_output_enabled;

            ErrorManagerConfigurations::default_is_asynchronous_output_enabled =
                ErrorManagerConfigurations::cache_is_asynchronous_output_enabled =
                ErrorManagerConfigurations::initial_is_asynchronous_output_enabled;

            ErrorManagerConfigurations::default_is_asynchronous_console_output_enabled =
                ErrorManagerConfigurations::cache_is_asynchronous_console_output_enabled =
                ErrorManagerConfigurations::initial_is_asynchronous_console_output_enabled;

            ErrorManagerConfigurations::default_is_asynchronous_file_output_enabled =
                ErrorManagerConfigurations::cache_is_asynchronous_file_output_enabled =
                ErrorManagerConfigurations::initial_is_asynchronous_file_output_enabled;

            ErrorManagerConfigurations::default_is_asynchronous_gui_output_enabled =
                ErrorManagerConfigurations::cache_is_asynchronous_gui_output_enabled =
                ErrorManagerConfigurations::initial_is_asynchronous_gui_output_enabled;

            ErrorManagerConfigurations::default_is_asynchronous_runtime_throw_output_enabled =
                ErrorManagerConfigurations::cache_is_asynchronous_runtime_throw_output_enabled =
                ErrorManagerConfigurations::initial_is_asynchronous_runtime_throw_output_enabled;

            ErrorManagerConfigurations::default_full_file_output_paths =
                ErrorManagerConfigurations::cache_full_file_output_paths =
                ErrorManagerConfigurations::initial_full_file_output_paths;

            cache_boolean_1 =
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            cache_error_log =
                exception.what();

            _handle();
        }
    }

    bool
        ErrorManager::handle(
            const std::string_view&
                title,
            const std::string_view&
                message
        )
    {        
        cache_error_log =
            std::string(title.data()) +
            " - " +
            message.data();

        _handle();

        return cache_boolean_1;
    }

    bool
        ErrorManager::handle(
            const std::string_view&
                message
        )
    {
        cache_error_log =
            message;
            
        _handle();

        return cache_boolean_1;
    }

    bool
        ErrorManager::handle(
            const std::exception& exception
        )
    {                
        cache_error_log =
            std::string(typeid(exception).name()) +
            " - " +
            exception.what();

        _handle();

        return cache_boolean_1;
    }

    void
        ErrorManager::_handle()
    {
        cache_boolean_1 =
            false;

        if (!ErrorManagerConfigurations::cache_is_enabled)
        {
            return;
        }

        if (ErrorManagerConfigurations::cache_is_asynchronous_output_enabled)
        {
            _handle_asynchronously();
        }
        else
        {
            _handle_synchronously();
        }
    }

    void
        ErrorManager::_handle_asynchronously()
    {
        std::vector<std::future<void>>
            futures;

        if (ErrorManagerConfigurations::cache_is_asynchronous_console_output_enabled &&
            ErrorManagerConfigurations::cache_is_console_output_enabled
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

        if (ErrorManagerConfigurations::cache_is_asynchronous_file_output_enabled &&
            ErrorManagerConfigurations::cache_is_file_output_enabled
            )
        {
            for (const std::string& cache_full_file_output_path :
                ErrorManagerConfigurations::cache_full_file_output_paths
                )
            {
                if (!std::filesystem::exists(cache_full_file_output_path))
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

        if (ErrorManagerConfigurations::cache_is_asynchronous_runtime_throw_output_enabled &&
            ErrorManagerConfigurations::cache_is_runtime_throw_output_enabled
            )
        {
            futures.push_back(
                std::async(
                    std::launch::async,
                    [&]()
                    {
                        throw std::runtime_error(
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
        ErrorManager::_handle_synchronously()
    {
        if (ErrorManagerConfigurations::cache_is_console_output_enabled)
        {
            fast_io::io::println(
                cache_fast_io_error_console_output_type,
                cache_error_log
            );
        }

        if (ErrorManagerConfigurations::cache_is_file_output_enabled)
        {
            for (const std::string& cache_full_file_output_path :
                ErrorManagerConfigurations::cache_full_file_output_paths
                )
            {
                if (!std::filesystem::exists(cache_full_file_output_path))
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

        if (ErrorManagerConfigurations::cache_is_runtime_throw_output_enabled)
        {
            throw std::runtime_error(
                cache_error_log
            );
        }
    }
}
