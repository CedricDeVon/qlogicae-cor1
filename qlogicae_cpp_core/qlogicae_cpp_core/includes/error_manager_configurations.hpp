#pragma once

namespace QLogicaeCppCore
{    
    struct ErrorManagerConfigurations
    {
        bool
            is_enabled =
                default_is_enabled;

        bool
            is_thread_safety_enabled =
                default_is_thread_safety_enabled;

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

        std::string
            title_message_separator =
                default_title_message_separator;

        std::vector<std::string>
            full_file_output_paths =
                default_full_file_output_paths;
    

        
        static bool
            initial_is_enabled;

        static bool
            initial_is_thread_safety_enabled;

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

        static std::string
            initial_title_message_separator;

        static std::vector<std::string>
            initial_full_file_output_paths;



        static bool
            default_is_enabled;

        static bool
            default_is_thread_safety_enabled;

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

        static std::string
            default_title_message_separator;

        static std::vector<std::string>
            default_full_file_output_paths;



        static bool
            cache_is_enabled;

        static bool
            cache_is_thread_safety_enabled;

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

        static std::string
            cache_title_message_separator;

        static std::vector<std::string>
            cache_full_file_output_paths;



        static bool
            cache_boolean_1;
            
        static boost::mutex
            cache_mutex_1;

        static ErrorManagerConfigurations
            cache_configurations;



        static bool
            construct(
                const ErrorManagerConfigurations&
                    configurations = {}
            );

        static bool
            destruct(
                const ErrorManagerConfigurations&
                    configurations = {}
            );

        static bool
            setup(
                const ErrorManagerConfigurations&
                    configurations = {}
            );

        static bool
            reset(
                const ErrorManagerConfigurations&
                    configurations = {}
            );

        static bool
            setup_caches(
                const ErrorManagerConfigurations&
                    configurations = {}
            );

        static bool
            setup_defaults(
                const ErrorManagerConfigurations&
                    configurations = {}
            );

        static bool
            reset_caches(
                const ErrorManagerConfigurations&
                    configurations = {}
            );

        static bool
            reset_defaults(
                const ErrorManagerConfigurations&
                    configurations = {}
            );

        static void
            _handle_construct();

        static void
            _handle_destruct();

        static void
            _handle_setup();

        static void
            _handle_reset();

        static void
            _handle_setup_caches();

        static void
            _handle_setup_defaults();

        static void
            _handle_reset_caches();

        static void
            _handle_reset_defaults();
    };    
}
