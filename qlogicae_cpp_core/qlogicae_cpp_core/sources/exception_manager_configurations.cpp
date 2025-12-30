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

    std::string
        ExceptionManagerConfigurations::default_folder_output_path =
            "";

    std::string
        ExceptionManagerConfigurations::default_file_name =
            "exceptions";

    std::string
        ExceptionManagerConfigurations::default_file_extension =
            ".log";

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

    std::string
        ExceptionManagerConfigurations::cache_folder_output_path =
            ExceptionManagerConfigurations::default_folder_output_path;

    std::string
        ExceptionManagerConfigurations::cache_file_name =
            ExceptionManagerConfigurations::default_file_name;

    std::string
        ExceptionManagerConfigurations::cache_file_extension =
            ExceptionManagerConfigurations::default_file_extension;

    ExceptionManagerConfigurations
        ExceptionManagerConfigurations::cache;
}
