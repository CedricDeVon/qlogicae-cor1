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


    ErrorManagerConfigurations
        ErrorManagerConfigurations::cache;
}
