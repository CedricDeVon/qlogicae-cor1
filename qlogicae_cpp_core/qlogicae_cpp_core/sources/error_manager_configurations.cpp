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
            false;

    bool
        ErrorManagerConfigurations::initial_is_runtime_throw_output_enabled =
            false;

    bool
        ErrorManagerConfigurations::initial_is_asynchronous_output_enabled =
            true;

    bool
        ErrorManagerConfigurations::initial_is_asynchronous_console_output_enabled =
            true;

    bool
        ErrorManagerConfigurations::initial_is_asynchronous_file_output_enabled =
            true;

    bool
        ErrorManagerConfigurations::initial_is_asynchronous_gui_output_enabled =
            true;

    bool
        ErrorManagerConfigurations::initial_is_asynchronous_runtime_throw_output_enabled =
            true;

    std::vector<std::string>
        ErrorManagerConfigurations::initial_file_output_paths =
        {
            "error.log"  
        };



    bool
        ErrorManagerConfigurations::cache_is_enabled =
            ErrorManagerConfigurations::default_is_enabled =
            ErrorManagerConfigurations::initial_is_enabled;

    bool
        ErrorManagerConfigurations::cache_is_console_output_enabled =
            ErrorManagerConfigurations::default_is_console_output_enabled =
            ErrorManagerConfigurations::initial_is_console_output_enabled;

    bool
        ErrorManagerConfigurations::cache_is_file_output_enabled =
            ErrorManagerConfigurations::default_is_file_output_enabled =
            ErrorManagerConfigurations::initial_is_file_output_enabled;

    bool
        ErrorManagerConfigurations::cache_is_runtime_throw_output_enabled =
            ErrorManagerConfigurations::default_is_runtime_throw_output_enabled =
            ErrorManagerConfigurations::initial_is_runtime_throw_output_enabled;

    bool
        ErrorManagerConfigurations::cache_is_asynchronous_output_enabled =
            ErrorManagerConfigurations::default_is_asynchronous_output_enabled =
            ErrorManagerConfigurations::initial_is_asynchronous_output_enabled;

    bool
        ErrorManagerConfigurations::cache_is_asynchronous_console_output_enabled =
            ErrorManagerConfigurations::default_is_asynchronous_console_output_enabled =
            ErrorManagerConfigurations::initial_is_asynchronous_console_output_enabled;

    bool
        ErrorManagerConfigurations::cache_is_asynchronous_file_output_enabled =
            ErrorManagerConfigurations::default_is_asynchronous_file_output_enabled =
            ErrorManagerConfigurations::initial_is_asynchronous_file_output_enabled;

    bool
        ErrorManagerConfigurations::cache_is_asynchronous_runtime_throw_output_enabled =
            ErrorManagerConfigurations::default_is_asynchronous_runtime_throw_output_enabled =
            ErrorManagerConfigurations::initial_is_asynchronous_runtime_throw_output_enabled;

    std::vector<std::string>
        ErrorManagerConfigurations::cache_file_output_paths =
            ErrorManagerConfigurations::default_file_output_paths =
            ErrorManagerConfigurations::initial_file_output_paths;

    ErrorManagerConfigurations
        ErrorManagerConfigurations::cache_instance;
}
