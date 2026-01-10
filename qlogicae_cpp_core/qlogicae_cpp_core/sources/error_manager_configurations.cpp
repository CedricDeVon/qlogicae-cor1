#include "pch.hpp"

#include "../includes/error_manager_configurations.hpp"

namespace QLogicaeCppCore
{    
    bool
        ErrorManagerConfigurations::initial_is_enabled =
            false;

    bool
        ErrorManagerConfigurations::initial_is_console_output_enabled =
            true;

    bool
        ErrorManagerConfigurations::initial_is_file_output_enabled =
            true;

    bool
        ErrorManagerConfigurations::initial_is_gui_output_enabled =
            true;

    bool
        ErrorManagerConfigurations::initial_is_runtime_throw_output_enabled =
            true;

    bool
        ErrorManagerConfigurations::initial_is_asynchronous_output_enabled =
            false;

    bool
        ErrorManagerConfigurations::initial_is_asynchronous_console_output_enabled =
            false;

    bool
        ErrorManagerConfigurations::initial_is_asynchronous_file_output_enabled =
            false;

    bool
        ErrorManagerConfigurations::initial_is_asynchronous_gui_output_enabled =
            false;

    bool
        ErrorManagerConfigurations::initial_is_asynchronous_runtime_throw_output_enabled =
            false;

    std::vector<std::string>
        ErrorManagerConfigurations::initial_full_file_output_paths =
        {
            "qlogicae.all.log"  
        };



    bool
        ErrorManagerConfigurations::default_is_enabled =
            ErrorManagerConfigurations::initial_is_enabled;

    bool
        ErrorManagerConfigurations::default_is_console_output_enabled =
            ErrorManagerConfigurations::initial_is_console_output_enabled;

    bool
        ErrorManagerConfigurations::default_is_file_output_enabled =
            ErrorManagerConfigurations::initial_is_file_output_enabled;

    bool
        ErrorManagerConfigurations::default_is_gui_output_enabled =
            ErrorManagerConfigurations::initial_is_gui_output_enabled;

    bool
        ErrorManagerConfigurations::default_is_runtime_throw_output_enabled =
            ErrorManagerConfigurations::initial_is_runtime_throw_output_enabled;

    bool
        ErrorManagerConfigurations::default_is_asynchronous_output_enabled =
            ErrorManagerConfigurations::initial_is_asynchronous_output_enabled;

    bool
        ErrorManagerConfigurations::default_is_asynchronous_console_output_enabled =
            ErrorManagerConfigurations::initial_is_asynchronous_console_output_enabled;

    bool
        ErrorManagerConfigurations::default_is_asynchronous_file_output_enabled =
            ErrorManagerConfigurations::initial_is_asynchronous_file_output_enabled;

    bool
        ErrorManagerConfigurations::default_is_asynchronous_gui_output_enabled =
            ErrorManagerConfigurations::initial_is_asynchronous_gui_output_enabled;

    bool
        ErrorManagerConfigurations::default_is_asynchronous_runtime_throw_output_enabled =
            ErrorManagerConfigurations::initial_is_asynchronous_runtime_throw_output_enabled;

    std::vector<std::string>
        ErrorManagerConfigurations::default_full_file_output_paths =
            ErrorManagerConfigurations::initial_full_file_output_paths;



    bool
        ErrorManagerConfigurations::cache_is_enabled =
            ErrorManagerConfigurations::initial_is_enabled;

    bool
        ErrorManagerConfigurations::cache_is_console_output_enabled =
            ErrorManagerConfigurations::initial_is_console_output_enabled;

    bool
        ErrorManagerConfigurations::cache_is_file_output_enabled =
            ErrorManagerConfigurations::initial_is_file_output_enabled;

    bool
        ErrorManagerConfigurations::cache_is_gui_output_enabled =
            ErrorManagerConfigurations::initial_is_gui_output_enabled;

    bool
        ErrorManagerConfigurations::cache_is_runtime_throw_output_enabled =
            ErrorManagerConfigurations::initial_is_runtime_throw_output_enabled;

    bool
        ErrorManagerConfigurations::cache_is_asynchronous_output_enabled =
            ErrorManagerConfigurations::initial_is_asynchronous_output_enabled;

    bool
        ErrorManagerConfigurations::cache_is_asynchronous_console_output_enabled =
            ErrorManagerConfigurations::initial_is_asynchronous_console_output_enabled;

    bool
        ErrorManagerConfigurations::cache_is_asynchronous_file_output_enabled =
            ErrorManagerConfigurations::initial_is_asynchronous_file_output_enabled;

    bool
        ErrorManagerConfigurations::cache_is_asynchronous_gui_output_enabled =
            ErrorManagerConfigurations::initial_is_asynchronous_gui_output_enabled;

    bool
        ErrorManagerConfigurations::cache_is_asynchronous_runtime_throw_output_enabled =
            ErrorManagerConfigurations::initial_is_asynchronous_runtime_throw_output_enabled;

    std::vector<std::string>
        ErrorManagerConfigurations::cache_full_file_output_paths =
            ErrorManagerConfigurations::initial_full_file_output_paths;



    bool
        ErrorManagerConfigurations::cache_boolean_1 =
            false;

    ErrorManagerConfigurations
        ErrorManagerConfigurations::cache;



    bool
        ErrorManagerConfigurations::construct()
    {
        _handle_construct();

        return
            cache_boolean_1;
    }

    bool
        ErrorManagerConfigurations::destruct()
    {
        _handle_destruct();

        return
            cache_boolean_1;
    }

    bool
        ErrorManagerConfigurations::setup(
            const ErrorManagerConfigurations&
            new_configurations
        )
    {
        cache =
            new_configurations;

        _handle_setup();

        return
            cache_boolean_1;
    }

    bool
        ErrorManagerConfigurations::setup()
    {
        cache =
            {};

        _handle_setup();

        return
            cache_boolean_1;
    }

    bool
        ErrorManagerConfigurations::reset()
    {
        _handle_reset();

        return
            cache_boolean_1;
    }

    void
        ErrorManagerConfigurations::_handle_construct()
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
        ErrorManagerConfigurations::_handle_destruct()
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
        ErrorManagerConfigurations::_handle_setup()
    {
        try
        {
            default_is_enabled =
                cache_is_enabled =
                cache.is_enabled;

            default_is_console_output_enabled =
                cache_is_console_output_enabled =
                cache.is_console_output_enabled;

            default_is_file_output_enabled =
                cache_is_file_output_enabled =
                cache.is_file_output_enabled;

            default_is_gui_output_enabled =
                cache_is_gui_output_enabled =
                cache.is_gui_output_enabled;

            default_is_runtime_throw_output_enabled =
                cache_is_runtime_throw_output_enabled =
                cache.is_runtime_throw_output_enabled;

            default_is_asynchronous_output_enabled =
                cache_is_asynchronous_output_enabled =
                cache.is_asynchronous_output_enabled;

            default_is_asynchronous_console_output_enabled =
                cache_is_asynchronous_console_output_enabled =
                cache.is_asynchronous_console_output_enabled;

            default_is_asynchronous_file_output_enabled =
                cache_is_asynchronous_file_output_enabled =
                cache.is_asynchronous_file_output_enabled;

            default_is_asynchronous_gui_output_enabled =
                cache_is_asynchronous_gui_output_enabled =
                cache.is_asynchronous_gui_output_enabled;

            default_is_asynchronous_runtime_throw_output_enabled =
                cache_is_asynchronous_runtime_throw_output_enabled =
                cache.is_asynchronous_runtime_throw_output_enabled;

            default_full_file_output_paths =
                cache_full_file_output_paths =
                cache.full_file_output_paths;

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
        ErrorManagerConfigurations::_handle_reset()
    {
        try
        {
            default_is_enabled =
                cache_is_enabled =
                initial_is_enabled;

            default_is_console_output_enabled =
                cache_is_console_output_enabled =
                initial_is_console_output_enabled;

            default_is_file_output_enabled =
                cache_is_file_output_enabled =
                initial_is_file_output_enabled;

            default_is_gui_output_enabled =
                cache_is_gui_output_enabled =
                initial_is_gui_output_enabled;

            default_is_runtime_throw_output_enabled =
                cache_is_runtime_throw_output_enabled =
                initial_is_runtime_throw_output_enabled;

            default_is_asynchronous_output_enabled =
                cache_is_asynchronous_output_enabled =
                initial_is_asynchronous_output_enabled;

            default_is_asynchronous_console_output_enabled =
                cache_is_asynchronous_console_output_enabled =
                initial_is_asynchronous_console_output_enabled;

            default_is_asynchronous_file_output_enabled =
                cache_is_asynchronous_file_output_enabled =
                initial_is_asynchronous_file_output_enabled;

            default_is_asynchronous_gui_output_enabled =
                cache_is_asynchronous_gui_output_enabled =
                initial_is_asynchronous_gui_output_enabled;

            default_is_asynchronous_runtime_throw_output_enabled =
                cache_is_asynchronous_runtime_throw_output_enabled =
                initial_is_asynchronous_runtime_throw_output_enabled;

            default_full_file_output_paths =
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
}
