#include "pch.hpp"

#include "../includes/singleton_manager.hpp"

namespace QLogicaeCppCore
{        
    SingletonManager&
        SingletonManager::singleton =
            SingletonManager::get_this_singleton();

    SingletonManager::SingletonManager()
    {
        std::cout << "SingletonManager" << "\n";

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
            SingletonManager__cache_error_log =
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
            SingletonManager__cache_error_log =
                exception.what();

            _handle_error();
        }
    }

    bool
        SingletonManager::construct()
    {
        _construct();

        return
            SingletonManager__cache_is_successful;
    }

    bool
        SingletonManager::destruct()
    {
        _destruct();

        return
            SingletonManager__cache_is_successful;
    }

    bool
        SingletonManager::setup(
            const SingletonManagerConfigurations&
                new_configurations
        )
    {
        SingletonManagerConfigurations__cache =
            new_configurations;

        _setup();

        return
            SingletonManager__cache_is_successful;
    }

    bool
        SingletonManager::setup()
    {
        SingletonManagerConfigurations__cache =
            {};

        _setup();

        return
            SingletonManager__cache_is_successful;
    }

    bool
        SingletonManager::reset()
    {
        _reset();

        return
            SingletonManager__cache_is_successful;
    }

    bool
        SingletonManager::handle_error(
            const std::exception&
                exception
        )
    {
        SingletonManager__cache_error_log =
            exception.what();

        _handle_error();

        return
            SingletonManager__cache_is_successful;
    }

    void
        SingletonManager::_construct()
    {
        try
        {
            SingletonManager__cache_is_successful =
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            SingletonManager__cache_error_log =
                exception.what();

            _handle_error();
        }
    }

    void
        SingletonManager::_destruct()
    {
        try
        {
            SingletonManager__cache_is_successful =
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            SingletonManager__cache_error_log =
                exception.what();

            _handle_error();
        }
    }

    void
        SingletonManager::_setup()
    {
        try
        {
            SingletonManager__cache_is_successful =
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            SingletonManager__cache_error_log =
                exception.what();

            _handle_error();
        }
    }

    void
        SingletonManager::_reset()
    {
        try
        {
            SingletonManager__cache_is_successful =
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            SingletonManager__cache_error_log =
                exception.what();

            _handle_error();
        }
    }
    
    void
        SingletonManager::_handle_error()
    {
        try
        {
            SingletonManager__cache_is_successful =
                false;
            
            if (!ErrorManagerConfigurations__cache_is_enabled)
            {
                return;
            }

            if (ErrorManagerConfigurations__cache_is_asynchronous_output_enabled)
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
            SingletonManager__cache_is_successful =
                false;
        }
    }

    void
        SingletonManager::_handle_error_asynchronously()
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
                            SingletonManager__cache_fast_io_error_console_output_type,
                            SingletonManager__cache_error_log
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
                                SingletonManager__cache_error_log
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
                            SingletonManager__cache_error_log
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
        if (ErrorManagerConfigurations__cache_is_console_output_enabled)
        {
            fast_io::io::println(
                SingletonManager__cache_fast_io_error_console_output_type,
                SingletonManager__cache_error_log
            );
        }

        if (ErrorManagerConfigurations__cache_is_file_output_enabled)
        {
            for (const std::string& cache_full_file_output_path :
                ErrorManagerConfigurations__cache_full_file_output_paths
                )
            {
                fast_io::native_file
                    fast_io_native_file(
                        cache_full_file_output_path,
                        fast_io::open_mode::app
                    );

                fast_io::io::println(
                    fast_io_native_file,
                    SingletonManager__cache_error_log
                );
            }
        }

        if (ErrorManagerConfigurations__cache_is_runtime_throw_output_enabled)
        {
            throw std::runtime_error(
                SingletonManager__cache_error_log
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
