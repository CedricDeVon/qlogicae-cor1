#pragma once

namespace QLogicaeCppCore
{
    struct ExceptionManagerConfigurations
    {        
        inline static bool
            is_enabled_default =
                true;

        inline static bool
            is_console_output_enabled_default =
                false;

        inline static bool
            is_file_output_enabled_default =
                false;

        inline static bool
            is_exception_throwing_enabled_default =
                false;

        bool
            is_enabled =
                is_enabled_default;
        
        bool
            is_console_output_enabled =
                is_console_output_enabled_default;

        bool
            is_file_output_enabled =
                is_file_output_enabled_default;

        bool
            is_exception_throwing_enabled =
                is_exception_throwing_enabled_default;

        inline static bool
            is_enabled_cache =
                is_enabled_default;

        inline static bool
            is_console_output_enabled_cache =
                is_console_output_enabled_default;

        inline static bool
            is_file_output_enabled_cache =
                is_file_output_enabled_default;

        inline static bool
            is_exception_throwing_enabled_cache =
                is_exception_throwing_enabled_default;
    };

    inline static ExceptionManagerConfigurations
        exception_manager_configurations_default;
}
