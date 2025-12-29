#pragma once

namespace QLogicaeCppCore
{
    struct ExceptionManagerConfigurations
    {        
        bool
            is_enabled =
                default_is_enabled;

        bool
            is_console_output_enabled =
                default_is_console_output_enabled;

        bool
            is_file_output_enabled =
                default_is_file_output_enabled;

        bool
            is_exception_throwing_enabled =
                default_is_exception_throwing_enabled;

        static bool
            default_is_enabled;

        static bool
            default_is_console_output_enabled;

        static bool
            default_is_file_output_enabled;

        static bool
            default_is_exception_throwing_enabled;

        static bool
            cache_is_enabled;

        static bool
            cache_is_console_output_enabled;

        static bool
            cache_is_file_output_enabled;

        static bool
            cache_is_exception_throwing_enabled;

        static ExceptionManagerConfigurations
            cache;
    };    
}
