#include "pch.hpp"

#include "../includes/exception_manager_configurations.hpp"

namespace QLogicaeCppCore
{
    bool
        ExceptionManagerConfigurations::initial_is_enabled =
            true;

    bool
        ExceptionManagerConfigurations::initial_is_console_output_enabled =
            false;

    bool
        ExceptionManagerConfigurations::initial_is_file_output_enabled =
            false;

    bool
        ExceptionManagerConfigurations::initial_is_runtime_throw_enabled =
            false;



    bool
        ExceptionManagerConfigurations::default_is_enabled =
            ExceptionManagerConfigurations::initial_is_enabled;

    bool
        ExceptionManagerConfigurations::default_is_console_output_enabled =
            ExceptionManagerConfigurations::initial_is_console_output_enabled;

    bool
        ExceptionManagerConfigurations::default_is_file_output_enabled =
            ExceptionManagerConfigurations::initial_is_file_output_enabled;

    bool
        ExceptionManagerConfigurations::default_is_runtime_throw_enabled =
            ExceptionManagerConfigurations::initial_is_runtime_throw_enabled;
}
