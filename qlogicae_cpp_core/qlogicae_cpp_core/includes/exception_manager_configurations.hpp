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
            is_runtime_throw_enabled =
                default_is_runtime_throw_enabled;



        static bool
            initial_is_enabled;

        static bool
            initial_is_console_output_enabled;

        static bool
            initial_is_file_output_enabled;

        static bool
            initial_is_runtime_throw_enabled;



        static bool
            default_is_enabled;

        static bool
            default_is_console_output_enabled;

        static bool
            default_is_file_output_enabled;

        static bool
            default_is_runtime_throw_enabled;
    };
}
