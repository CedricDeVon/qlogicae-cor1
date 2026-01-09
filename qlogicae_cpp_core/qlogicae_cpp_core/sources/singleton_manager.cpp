#include "pch.hpp"

#include "../includes/singleton_manager.hpp"

namespace QLogicaeCppCore
{           
    bool
        SingletonManager::cache_boolean_1 =
            false;

    std::string
        SingletonManager::cache_error_log =
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
            SingletonManager::cache_error_log =
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
            SingletonManager::cache_error_log =
                exception.what();

            _handle_error();
        }
    }

    bool
        SingletonManager::construct()
    {
        _construct();

        return
            SingletonManager::cache_boolean_1;
    }

    bool
        SingletonManager::destruct()
    {
        _destruct();

        return
            SingletonManager::cache_boolean_1;
    }

    bool
        SingletonManager::setup(
            const SingletonManagerConfigurations&
                new_configurations
        )
    {
        SingletonManagerConfigurations::cache =
            new_configurations;

        _setup();

        return
            SingletonManager::cache_boolean_1;
    }

    bool
        SingletonManager::setup()
    {
        SingletonManagerConfigurations::cache =
            {};

        _setup();

        return
            SingletonManager::cache_boolean_1;
    }

    bool
        SingletonManager::reset()
    {
        _reset();

        return
            SingletonManager::cache_boolean_1;
    }

    bool
        SingletonManager::handle_error(
            const std::exception&
                exception
        )
    {
        SingletonManager::cache_error_log =
            exception.what();

        _handle_error();

        return
            SingletonManager::cache_boolean_1;
    }

    void
        SingletonManager::_construct()
    {
        try
        {
            SingletonManager::cache_boolean_1 =
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            SingletonManager::cache_error_log =
                exception.what();

            _handle_error();
        }
    }

    void
        SingletonManager::_destruct()
    {
        try
        {
            SingletonManager::cache_boolean_1 =
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            SingletonManager::cache_error_log =
                exception.what();

            _handle_error();
        }
    }

    void
        SingletonManager::_setup()
    {
        try
        {
            SingletonManager::cache_boolean_1 =
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            SingletonManager::cache_error_log =
                exception.what();

            _handle_error();
        }
    }

    void
        SingletonManager::_reset()
    {
        try
        {
            SingletonManager::cache_boolean_1 =
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            SingletonManager::cache_error_log =
                exception.what();

            _handle_error();
        }
    }
    
    void
        SingletonManager::_handle_error()
    {
        try
        {
            SingletonManager::cache_boolean_1 =
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
            SingletonManager::cache_boolean_1 =
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
                            SingletonManager::cache_fast_io_error_console_output_type,
                            SingletonManager::cache_error_log
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
                                SingletonManager::cache_error_log
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
                            SingletonManager::cache_error_log
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
                SingletonManager::cache_fast_io_error_console_output_type,
                SingletonManager::cache_error_log
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
                    SingletonManager::cache_error_log
                );
            }
        }

        if (ErrorManagerConfigurations::cache_is_runtime_throw_output_enabled)
        {
            throw std::runtime_error(
                SingletonManager::cache_error_log
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
