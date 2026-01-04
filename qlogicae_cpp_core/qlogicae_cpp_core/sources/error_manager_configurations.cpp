#include "pch.hpp"

#include "../includes/error_manager_configurations.hpp"

namespace QLogicaeCppCore
{
    bool
        ErrorManagerConfigurations::initial_is_enabled =
            true;

    bool
        ErrorManagerConfigurations::initial_is_console_output_enabled =
            false;

    bool
        ErrorManagerConfigurations::initial_is_file_output_enabled =
            false;

    bool
        ErrorManagerConfigurations::initial_is_runtime_throw_enabled =
            false;

    std::vector<std::string>
        ErrorManagerConfigurations::initial_file_outpu_paths =
        {
            "error.log"  
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
        ErrorManagerConfigurations::default_is_runtime_throw_enabled =
            ErrorManagerConfigurations::initial_is_runtime_throw_enabled;

    std::vector<std::string>
        ErrorManagerConfigurations::default_file_outpu_paths =
            ErrorManagerConfigurations::initial_file_outpu_paths;
}
