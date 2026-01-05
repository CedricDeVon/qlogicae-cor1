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
            is_gui_output_enabled =
                default_is_gui_output_enabled;

        bool
            is_runtime_throw_output_enabled =
                default_is_runtime_throw_output_enabled;

        bool
            is_asynchronous_output_enabled =
                default_is_asynchronous_output_enabled;

        bool
            is_asynchronous_console_output_enabled =
                default_is_asynchronous_console_output_enabled;

        bool
            is_asynchronous_file_output_enabled =
                default_is_asynchronous_file_output_enabled;

        bool
            is_asynchronous_gui_output_enabled =
                default_is_asynchronous_gui_output_enabled;

        bool
            is_asynchronous_runtime_throw_output_enabled =
                default_is_asynchronous_runtime_throw_output_enabled;

        std::vector<std::string>
            file_output_paths =
                default_file_output_paths;



        static bool
            initial_is_enabled;

        static bool
            initial_is_console_output_enabled;

        static bool
            initial_is_file_output_enabled;

        static bool
            initial_is_gui_output_enabled;

        static bool
            initial_is_runtime_throw_output_enabled;

        static bool
            initial_is_asynchronous_output_enabled;

        static bool
            initial_is_asynchronous_console_output_enabled;

        static bool
            initial_is_asynchronous_file_output_enabled;

        static bool
            initial_is_asynchronous_gui_output_enabled;

        static bool
            initial_is_asynchronous_runtime_throw_output_enabled;

        static std::vector<std::string>
            initial_file_output_paths;



        static bool
            default_is_enabled;

        static bool
            default_is_console_output_enabled;

        static bool
            default_is_file_output_enabled;

        static bool
            default_is_gui_output_enabled;

        static bool
            default_is_runtime_throw_output_enabled;

        static bool
            default_is_asynchronous_output_enabled;

        static bool
            default_is_asynchronous_console_output_enabled;

        static bool
            default_is_asynchronous_file_output_enabled;

        static bool
            default_is_asynchronous_gui_output_enabled;

        static bool
            default_is_asynchronous_runtime_throw_output_enabled;

        static std::vector<std::string>
            default_file_output_paths;



        static bool
            cache_is_enabled;

        static bool
            cache_is_console_output_enabled;

        static bool
            cache_is_file_output_enabled;

        static bool
            cache_is_gui_output_enabled;

        static bool
            cache_is_runtime_throw_output_enabled;

        static bool
            cache_is_asynchronous_output_enabled;

        static bool
            cache_is_asynchronous_console_output_enabled;

        static bool
            cache_is_asynchronous_file_output_enabled;

        static bool
            cache_is_asynchronous_gui_output_enabled;

        static bool
            cache_is_asynchronous_runtime_throw_output_enabled;

        static std::vector<std::string>
            cache_file_output_paths;



        static ErrorManagerConfigurations
            cache_instance;
    };
}
