#include "pch.hpp"

#include "../includes/error_manager.hpp"

namespace QLogicaeCppCore
{    
    ErrorManager::ErrorManager()
    {
        std::cout << "ErrorManager" << "\n";
        
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
            ErrorManager__cache_error_log =
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
            ErrorManager__cache_error_log =
                exception.what();

            _handle();
        }
    }

    bool
        ErrorManager::construct()
    {
        _construct();

        return ErrorManager__cache_is_successful;
    }

    void
        ErrorManager::_construct()
    {
        try
        {            
            ErrorManager__cache_is_successful =
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            ErrorManager__cache_error_log =
                exception.what();

            _handle();
        }
    }

    bool
        ErrorManager::destruct()
    {
        _destruct();

        return ErrorManager__cache_is_successful;
    }

    void
        ErrorManager::_destruct()
    {
        try
        {
            ErrorManager__cache_is_successful =
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            ErrorManager__cache_error_log =
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
        ErrorManagerConfigurations__cache =
            new_configurations;

        _setup();

        return ErrorManager__cache_is_successful;
    }

    bool
        ErrorManager::setup()
    {
        ErrorManagerConfigurations__cache =
            {};

        _setup();

        return ErrorManager__cache_is_successful;
    }

    void
        ErrorManager::_setup()
    {
        try
        {
            ErrorManagerConfigurations__default_is_enabled =
                ErrorManagerConfigurations__cache_is_enabled =
                ErrorManagerConfigurations__cache.is_enabled;

            ErrorManagerConfigurations__default_is_console_output_enabled =
                ErrorManagerConfigurations__cache_is_console_output_enabled =
                ErrorManagerConfigurations__cache.is_console_output_enabled;

            ErrorManagerConfigurations__default_is_file_output_enabled =
                ErrorManagerConfigurations__cache_is_file_output_enabled =
                ErrorManagerConfigurations__cache.is_file_output_enabled;

            ErrorManagerConfigurations__default_is_gui_output_enabled =
                ErrorManagerConfigurations__cache_is_gui_output_enabled =
                ErrorManagerConfigurations__cache.is_gui_output_enabled;

            ErrorManagerConfigurations__default_is_runtime_throw_output_enabled =
                ErrorManagerConfigurations__cache_is_runtime_throw_output_enabled =
                ErrorManagerConfigurations__cache.is_runtime_throw_output_enabled;

            ErrorManagerConfigurations__default_is_asynchronous_output_enabled =
                ErrorManagerConfigurations__cache_is_asynchronous_output_enabled =
                ErrorManagerConfigurations__cache.is_asynchronous_output_enabled;

            ErrorManagerConfigurations__default_is_asynchronous_console_output_enabled =
                ErrorManagerConfigurations__cache_is_asynchronous_console_output_enabled =
                ErrorManagerConfigurations__cache.is_asynchronous_console_output_enabled;

            ErrorManagerConfigurations__default_is_asynchronous_file_output_enabled =
                ErrorManagerConfigurations__cache_is_asynchronous_file_output_enabled =
                ErrorManagerConfigurations__cache.is_asynchronous_file_output_enabled;

            ErrorManagerConfigurations__default_is_asynchronous_gui_output_enabled =
                ErrorManagerConfigurations__cache_is_asynchronous_gui_output_enabled =
                ErrorManagerConfigurations__cache.is_asynchronous_gui_output_enabled;

            ErrorManagerConfigurations__default_is_asynchronous_runtime_throw_output_enabled =
                ErrorManagerConfigurations__cache_is_asynchronous_runtime_throw_output_enabled =
                ErrorManagerConfigurations__cache.is_asynchronous_runtime_throw_output_enabled;

            ErrorManagerConfigurations__default_full_file_output_paths =
                ErrorManagerConfigurations__cache_full_file_output_paths =
                ErrorManagerConfigurations__cache.full_file_output_paths;

            ErrorManager__cache_is_successful =
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            ErrorManager__cache_error_log =
                exception.what();

            _handle();
        }
    }

    bool
        ErrorManager::reset()
    {
        _reset();

        return ErrorManager__cache_is_successful;
    }

    void
        ErrorManager::_reset()
    {
        try
        {
            ErrorManagerConfigurations__default_is_enabled =
                ErrorManagerConfigurations__cache_is_enabled =
                ErrorManagerConfigurations__initial_is_enabled;

            ErrorManagerConfigurations__default_is_console_output_enabled =
                ErrorManagerConfigurations__cache_is_console_output_enabled =
                ErrorManagerConfigurations__initial_is_console_output_enabled;

            ErrorManagerConfigurations__default_is_file_output_enabled =
                ErrorManagerConfigurations__cache_is_file_output_enabled =
                ErrorManagerConfigurations__initial_is_file_output_enabled;

            ErrorManagerConfigurations__default_is_gui_output_enabled =
                ErrorManagerConfigurations__cache_is_gui_output_enabled =
                ErrorManagerConfigurations__initial_is_gui_output_enabled;

            ErrorManagerConfigurations__default_is_runtime_throw_output_enabled =
                ErrorManagerConfigurations__cache_is_runtime_throw_output_enabled =
                ErrorManagerConfigurations__initial_is_runtime_throw_output_enabled;

            ErrorManagerConfigurations__default_is_asynchronous_output_enabled =
                ErrorManagerConfigurations__cache_is_asynchronous_output_enabled =
                ErrorManagerConfigurations__initial_is_asynchronous_output_enabled;

            ErrorManagerConfigurations__default_is_asynchronous_console_output_enabled =
                ErrorManagerConfigurations__cache_is_asynchronous_console_output_enabled =
                ErrorManagerConfigurations__initial_is_asynchronous_console_output_enabled;

            ErrorManagerConfigurations__default_is_asynchronous_file_output_enabled =
                ErrorManagerConfigurations__cache_is_asynchronous_file_output_enabled =
                ErrorManagerConfigurations__initial_is_asynchronous_file_output_enabled;

            ErrorManagerConfigurations__default_is_asynchronous_gui_output_enabled =
                ErrorManagerConfigurations__cache_is_asynchronous_gui_output_enabled =
                ErrorManagerConfigurations__initial_is_asynchronous_gui_output_enabled;

            ErrorManagerConfigurations__default_is_asynchronous_runtime_throw_output_enabled =
                ErrorManagerConfigurations__cache_is_asynchronous_runtime_throw_output_enabled =
                ErrorManagerConfigurations__initial_is_asynchronous_runtime_throw_output_enabled;

            ErrorManagerConfigurations__default_full_file_output_paths =
                ErrorManagerConfigurations__cache_full_file_output_paths =
                ErrorManagerConfigurations__initial_full_file_output_paths;

            ErrorManager__cache_is_successful =
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            ErrorManager__cache_error_log =
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
        ErrorManager__cache_error_log =
            std::string(title.data()) +
            " - " +
            message.data();

        _handle();

        return ErrorManager__cache_is_successful;
    }

    bool
        ErrorManager::handle(
            const std::string_view&
                message
        )
    {
        ErrorManager__cache_error_log =
            message;
            
        _handle();

        return ErrorManager__cache_is_successful;
    }

    bool
        ErrorManager::handle(
            const std::exception& exception
        )
    {                
        ErrorManager__cache_error_log =
            std::string(typeid(exception).name()) +
            " - " +
            exception.what();

        _handle();

        return ErrorManager__cache_is_successful;
    }

    void
        ErrorManager::_handle()
    {
        ErrorManager__cache_is_successful =
            false;

        if (!ErrorManagerConfigurations__cache_is_enabled)
        {
            return;
        }

        if (ErrorManagerConfigurations__cache_is_asynchronous_output_enabled)
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

        if (ErrorManagerConfigurations__cache_is_asynchronous_console_output_enabled &&
            ErrorManagerConfigurations__cache_is_console_output_enabled
            )
        {
            futures.push_back(
                std::async(
                    std::launch::async,
                    [&]()
                    {
                        fast_io::io::println(
                            ErrorManager__cache_fast_io_error_console_output_type,
                            ErrorManager__cache_error_log
                        );
                    }
                )
            );
        }

        if (ErrorManagerConfigurations__cache_is_asynchronous_file_output_enabled &&
            ErrorManagerConfigurations__cache_is_file_output_enabled
            )
        {
            for (const std::string& cache_full_file_output_path :
                ErrorManagerConfigurations__cache_full_file_output_paths
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
                                ErrorManager__cache_error_log
                            );
                        }
                    )
                );
            }
        }

        if (ErrorManagerConfigurations__cache_is_asynchronous_runtime_throw_output_enabled &&
            ErrorManagerConfigurations__cache_is_runtime_throw_output_enabled
            )
        {
            futures.push_back(
                std::async(
                    std::launch::async,
                    [&]()
                    {
                        throw std::runtime_error(
                            ErrorManager__cache_error_log
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
        if (ErrorManagerConfigurations__cache_is_console_output_enabled)
        {
            fast_io::io::println(
                ErrorManager__cache_fast_io_error_console_output_type,
                ErrorManager__cache_error_log
            );
        }

        if (ErrorManagerConfigurations__cache_is_file_output_enabled)
        {
            for (const std::string& cache_full_file_output_path :
                ErrorManagerConfigurations__cache_full_file_output_paths
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
                    ErrorManager__cache_error_log
                );
            }
        }

        if (ErrorManagerConfigurations__cache_is_runtime_throw_output_enabled)
        {
            throw std::runtime_error(
                ErrorManager__cache_error_log
            );
        }
    }
}
