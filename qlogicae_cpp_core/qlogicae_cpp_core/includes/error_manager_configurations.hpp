#pragma once

namespace QLogicaeCppCore
{
    
    inline static bool
        ErrorManagerConfigurations__initial_is_enabled =
            false;

    inline static bool
        ErrorManagerConfigurations__initial_is_console_output_enabled =
            true;

    inline static bool
        ErrorManagerConfigurations__initial_is_file_output_enabled =
            true;

    inline static bool
        ErrorManagerConfigurations__initial_is_gui_output_enabled =
            true;

    inline static bool
        ErrorManagerConfigurations__initial_is_runtime_throw_output_enabled =
            true;

    inline static bool
        ErrorManagerConfigurations__initial_is_asynchronous_output_enabled =
            false;

    inline static bool
        ErrorManagerConfigurations__initial_is_asynchronous_console_output_enabled =
            false;

    inline static bool
        ErrorManagerConfigurations__initial_is_asynchronous_file_output_enabled =
            false;

    inline static bool
        ErrorManagerConfigurations__initial_is_asynchronous_gui_output_enabled =
            false;

    inline static bool
        ErrorManagerConfigurations__initial_is_asynchronous_runtime_throw_output_enabled =
            false;

    inline static std::vector<std::string>
        ErrorManagerConfigurations__initial_full_file_output_paths =
        {
            "qlogicae.all.log"  
        };



    inline static bool
        ErrorManagerConfigurations__default_is_enabled =
            ErrorManagerConfigurations__initial_is_enabled;

    inline static bool
        ErrorManagerConfigurations__default_is_console_output_enabled =
            ErrorManagerConfigurations__initial_is_console_output_enabled;

    inline static bool
        ErrorManagerConfigurations__default_is_file_output_enabled =
            ErrorManagerConfigurations__initial_is_file_output_enabled;

    inline static bool
        ErrorManagerConfigurations__default_is_gui_output_enabled =
            ErrorManagerConfigurations__initial_is_gui_output_enabled;

    inline static bool
        ErrorManagerConfigurations__default_is_runtime_throw_output_enabled =
            ErrorManagerConfigurations__initial_is_runtime_throw_output_enabled;

    inline static bool
        ErrorManagerConfigurations__default_is_asynchronous_output_enabled =
            ErrorManagerConfigurations__initial_is_asynchronous_output_enabled;

    inline static bool
        ErrorManagerConfigurations__default_is_asynchronous_console_output_enabled =
            ErrorManagerConfigurations__initial_is_asynchronous_console_output_enabled;

    inline static bool
        ErrorManagerConfigurations__default_is_asynchronous_file_output_enabled =
            ErrorManagerConfigurations__initial_is_asynchronous_file_output_enabled;

    inline static bool
        ErrorManagerConfigurations__default_is_asynchronous_gui_output_enabled =
            ErrorManagerConfigurations__initial_is_asynchronous_gui_output_enabled;

    inline static bool
        ErrorManagerConfigurations__default_is_asynchronous_runtime_throw_output_enabled =
            ErrorManagerConfigurations__initial_is_asynchronous_runtime_throw_output_enabled;

    inline static std::vector<std::string>
        ErrorManagerConfigurations__default_full_file_output_paths =
            ErrorManagerConfigurations__initial_full_file_output_paths;



    inline static bool
        ErrorManagerConfigurations__cache_is_enabled =
            ErrorManagerConfigurations__initial_is_enabled;

    inline static bool
        ErrorManagerConfigurations__cache_is_console_output_enabled =
            ErrorManagerConfigurations__initial_is_console_output_enabled;

    inline static bool
        ErrorManagerConfigurations__cache_is_file_output_enabled =
            ErrorManagerConfigurations__initial_is_file_output_enabled;

    inline static bool
        ErrorManagerConfigurations__cache_is_gui_output_enabled =
            ErrorManagerConfigurations__initial_is_gui_output_enabled;

    inline static bool
        ErrorManagerConfigurations__cache_is_runtime_throw_output_enabled =
            ErrorManagerConfigurations__initial_is_runtime_throw_output_enabled;

    inline static bool
        ErrorManagerConfigurations__cache_is_asynchronous_output_enabled =
            ErrorManagerConfigurations__initial_is_asynchronous_output_enabled;

    inline static bool
        ErrorManagerConfigurations__cache_is_asynchronous_console_output_enabled =
            ErrorManagerConfigurations__initial_is_asynchronous_console_output_enabled;

    inline static bool
        ErrorManagerConfigurations__cache_is_asynchronous_file_output_enabled =
            ErrorManagerConfigurations__initial_is_asynchronous_file_output_enabled;

    inline static bool
        ErrorManagerConfigurations__cache_is_asynchronous_gui_output_enabled =
            ErrorManagerConfigurations__initial_is_asynchronous_gui_output_enabled;

    inline static bool
        ErrorManagerConfigurations__cache_is_asynchronous_runtime_throw_output_enabled =
            ErrorManagerConfigurations__initial_is_asynchronous_runtime_throw_output_enabled;

    inline static std::vector<std::string>
        ErrorManagerConfigurations__cache_full_file_output_paths =
            ErrorManagerConfigurations__initial_full_file_output_paths;



    struct ErrorManagerConfigurations
    {
        bool
            is_enabled =
                ErrorManagerConfigurations__default_is_enabled;
        bool
            is_console_output_enabled =
                ErrorManagerConfigurations__default_is_console_output_enabled;

        bool
            is_file_output_enabled =
                ErrorManagerConfigurations__default_is_file_output_enabled;

        bool
            is_gui_output_enabled =
                ErrorManagerConfigurations__default_is_gui_output_enabled;

        bool
            is_runtime_throw_output_enabled =
                ErrorManagerConfigurations__default_is_runtime_throw_output_enabled;

        bool
            is_asynchronous_output_enabled =
                ErrorManagerConfigurations__default_is_asynchronous_output_enabled;

        bool
            is_asynchronous_console_output_enabled =
                ErrorManagerConfigurations__default_is_asynchronous_console_output_enabled;

        bool
            is_asynchronous_file_output_enabled =
                ErrorManagerConfigurations__default_is_asynchronous_file_output_enabled;

        bool
            is_asynchronous_gui_output_enabled =
                ErrorManagerConfigurations__default_is_asynchronous_gui_output_enabled;

        bool
            is_asynchronous_runtime_throw_output_enabled =
                ErrorManagerConfigurations__default_is_asynchronous_runtime_throw_output_enabled;

        std::vector<std::string>
            full_file_output_paths =
                ErrorManagerConfigurations__default_full_file_output_paths;
    };



    inline static ErrorManagerConfigurations
        ErrorManagerConfigurations__cache;
}
