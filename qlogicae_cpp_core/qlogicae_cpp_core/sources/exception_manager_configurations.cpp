#include "pch.hpp"

#include "../includes/exception_manager_configurations.hpp"

namespace QLogicaeCppCore
{
    bool
        ExceptionManagerConfigurations::default_is_enabled =
            true;

    bool
        ExceptionManagerConfigurations::default_is_console_output_enabled =
            false;

    bool
        ExceptionManagerConfigurations::default_is_file_output_enabled =
            false;

    bool
        ExceptionManagerConfigurations::default_is_exception_throwing_enabled =
            false;

    bool
        ExceptionManagerConfigurations::cache_is_enabled =
            ExceptionManagerConfigurations::default_is_enabled;

    bool
        ExceptionManagerConfigurations::cache_is_console_output_enabled =
            ExceptionManagerConfigurations::default_is_console_output_enabled;

    bool
        ExceptionManagerConfigurations::cache_is_file_output_enabled =
            ExceptionManagerConfigurations::default_is_file_output_enabled;

    bool
        ExceptionManagerConfigurations::cache_is_exception_throwing_enabled =
            ExceptionManagerConfigurations::default_is_exception_throwing_enabled;

    ExceptionManagerConfigurations
        ExceptionManagerConfigurations::cache;
}
