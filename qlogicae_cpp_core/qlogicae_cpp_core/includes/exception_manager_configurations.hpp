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

        

        std::string
            folder_output_path;

        std::string
            file_name;

        std::string
            file_extension;
        


        static bool
            default_is_enabled;

        static bool
            default_is_console_output_enabled;

        static bool
            default_is_file_output_enabled;

        static bool
            default_is_exception_throwing_enabled;

        static std::string
            default_folder_output_path;

        static std::string
            default_file_name;

        static std::string
            default_file_extension;



        static bool
            cache_is_enabled;

        static bool
            cache_is_console_output_enabled;

        static bool
            cache_is_file_output_enabled;

        static bool
            cache_is_exception_throwing_enabled;

        static std::string
            cache_folder_output_path;

        static std::string
            cache_file_name;

        static std::string
            cache_file_extension;

        static ExceptionManagerConfigurations
            cache;
    };    
}
