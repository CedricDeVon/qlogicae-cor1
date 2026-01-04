#pragma once

namespace QLogicaeCppCore
{
    struct ErrorManagerConfigurations
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

        std::vector<std::string>
            file_outpu_paths =
                default_file_outpu_paths;



        static bool
            initial_is_enabled;

        static bool
            initial_is_console_output_enabled;

        static bool
            initial_is_file_output_enabled;

        static bool
            initial_is_runtime_throw_enabled;

        std::vector<std::string>
            initial_file_outpu_paths;



        static bool
            default_is_enabled;

        static bool
            default_is_console_output_enabled;

        static bool
            default_is_file_output_enabled;

        static bool
            default_is_runtime_throw_enabled;

        std::vector<std::string>
            default_file_outpu_paths;
    };
}
