#include "pch.hpp"

#include "../includes/singleton_manager.hpp"

namespace QLogicaeCppCore
{    
    bool
        SingletonManager::cache_is_successful =
            false;  

    std::string
        SingletonManager::cache_exception_log =
            "";

    fast_io::native_io_observer
        SingletonManager::cache_fast_io_error_console_output_type =
            fast_io::err();

    SingletonManager&
        SingletonManager::singleton =
            SingletonManager::get_this_singleton();



    SingletonManager::SingletonManager()
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
            cache_exception_log =
                exception.what();

            _handle_error();
        }
    }

    SingletonManager::~SingletonManager()
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
            cache_exception_log =
                exception.what();

            _handle_error();
        }
    }

    bool
        SingletonManager::construct()
    {
        _construct();

        return
            cache_is_successful;
    }

    bool
        SingletonManager::destruct()
    {
        _destruct();

        return
            cache_is_successful;
    }

    bool
        SingletonManager::setup(
            const SingletonManagerConfigurations&
                new_configurations
        )
    {
        SingletonManagerConfigurations::cache_instance =
            new_configurations;

        _setup();

        return
            cache_is_successful;
    }

    bool
        SingletonManager::setup()
    {
        SingletonManagerConfigurations::cache_instance =
        {};

        _setup();

        return
            cache_is_successful;
    }

    bool
        SingletonManager::reset()
    {
        _reset();

        return cache_is_successful;
    }

    bool
        SingletonManager::handle_error(
            const std::exception&
                exception
        )
    {
        cache_exception_log =
            exception.what();

        _handle_error();

        return
            cache_is_successful;
    }

    void
        SingletonManager::_construct()
    {
        try
        {
            cache_is_successful =
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            cache_exception_log =
                exception.what();

            _handle_error();
        }
    }

    void
        SingletonManager::_destruct()
    {
        try
        {
            cache_is_successful =
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            cache_exception_log =
                exception.what();

            _handle_error();
        }
    }

    void
        SingletonManager::_setup()
    {
        try
        {
            cache_is_successful =
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            cache_exception_log =
                exception.what();

            _handle_error();
        }
    }

    void
        SingletonManager::_reset()
    {
        try
        {
            cache_is_successful =
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            cache_exception_log =
                exception.what();

            _handle_error();
        }
    }
    
    void
        SingletonManager::_handle_error()
    {
        try
        {
            cache_is_successful =
                false;
            
            if (!ErrorManagerConfigurations::cache_is_enabled)
            {
                return;
            }

            if (ErrorManagerConfigurations::cache_is_asynchronous_output_enabled)
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
            cache_is_successful =
                false;
        }
    }

    void
        SingletonManager::_handle_error_asynchronously()
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
                            cache_exception_log
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
                                cache_exception_log
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
                            cache_exception_log
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
        SingletonManager::_handle_error_synchronously()
    {
        if (ErrorManagerConfigurations::cache_is_console_output_enabled)
        {
            fast_io::io::println(
                cache_fast_io_error_console_output_type,
                cache_exception_log
            );
        }

        if (ErrorManagerConfigurations::cache_is_file_output_enabled)
        {
            for (const std::string& cache_full_file_output_path :
                ErrorManagerConfigurations::cache_full_file_output_paths
                )
            {
                fast_io::native_file
                    fast_io_native_file(
                        cache_full_file_output_path,
                        fast_io::open_mode::app
                    );

                fast_io::io::println(
                    fast_io_native_file,
                    cache_exception_log
                );
            }
        }

        if (ErrorManagerConfigurations::cache_is_runtime_throw_output_enabled)
        {
            throw std::runtime_error(
                cache_exception_log
            );
        }
    }

    SingletonManager&
        SingletonManager::get_this_singleton()
    {
        static SingletonManager
            singleton;

        return
            singleton;
    }
}
