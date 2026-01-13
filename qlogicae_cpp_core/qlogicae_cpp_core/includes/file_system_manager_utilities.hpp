#pragma once

#include "error_manager.hpp"
#include "singleton_manager.hpp"
#include "file_system_manager_configurations.hpp"

namespace QLogicaeCppCore
{
    class FileSystemManagerUtilities
    {
    public:        
        static std::string
            relative_private_qlogicae_folder_path;

        static std::string
            relative_public_qlogicae_folder_path;

        static std::string
            relative_application_name_folder_path;

        static std::string
            relative_application_version_name_folder_path;

        static std::string
            relative_application_environment_name_folder_path;

        static std::string
            relative_log_folder_path;

        static std::string
            relative_log_date_folder_path;

        static std::string
            relative_log_level_folder_path;

        static std::string
            relative_all_log_file_path;

        static std::string
            relative_info_log_file_path;

        static std::string
            relative_debug_log_file_path;

        static std::string
            relative_warning_log_file_path;

        static std::string
            relative_success_log_file_path;

        static std::string
            relative_critical_log_file_path;

        static std::string
            relative_error_log_file_path;

        static std::string
            relative_cache_folder_path;

        static std::string
            relative_main_folder_path;

        static std::string
            relative_assets_folder_path;

        static std::string
            relative_documentation_folder_path;

        static std::string
            relative_environment_json_file_path;

        static std::string
            relative_license_txt_file_path;

        static std::string
            relative_application_folder_path;

        static std::string
            relative_application_icon_file_path;

        static std::string
            relative_qlogicae_json_file_path;

        static std::string
            relative_configurations_folder_path;

        static std::string
            relative_development_folder_path;

        static std::string
            relative_debug_folder_path;

        static std::string
            relative_test_folder_path;

        static std::string
            relative_release_folder_path;

        static std::string
            relative_windows_registry_software_qlogicae_folder_path;

        static std::string
            full_executable_folder_path;

        static std::string
            full_executed_folder_path;

        static std::string
            full_roaming_app_data_folder_path;

        static std::string
            full_local_app_data_folder_path;

        static std::string
            full_program_data_folder_path;

        static std::filesystem::path
            cache_directory_path;

        static DWORD
            cache_dword_path_length;

        static wchar_t
            cache_wchar_t_buffer[MAX_PATH];

        static bool
            cache_boolean_1;

        static int
            cache_int_1;

        static size_t
            cache_size_t_1;

        static std::string
            cache_string_1;

        static std::wstring
            cache_wstring_1;

        static std::vector<std::string>
            cache_vector_string_1;

        static wchar_t*
            cache_wchar_t_pointer_1;

        static FileSystemManagerUtilities&
            singleton;

        FileSystemManagerUtilities();

        ~FileSystemManagerUtilities();

        FileSystemManagerUtilities(
            const FileSystemManagerUtilities&
            instance
        ) = delete;

        FileSystemManagerUtilities(
            FileSystemManagerUtilities&&
            instance
        ) noexcept = delete;

        FileSystemManagerUtilities& operator = (
            FileSystemManagerUtilities&&
            instance
            ) = delete;

        FileSystemManagerUtilities& operator = (
            const FileSystemManagerUtilities&
                instance
        ) = delete;

        bool
            construct();

        bool
            destruct();

        bool
            setup(
                const FileSystemManagerConfigurations&
                    new_configursations
            );

        bool
            setup();

        bool
            reset();

        std::string
            get_executable_folder_path();

        std::string
            get_executed_folder_path();

        std::string
            get_program_data_folder_path();

        std::string
            get_local_app_data_folder_path();

        std::string
            get_roaming_app_data_folder_path();

        void
            _handle_construct();

        void
            _handle_destruct();

        void
            _handle_setup();

        void
            _handle_reset();

        void
            _handle_get_executable_folder_path();

        void
            _handle_get_executed_folder_path();

        void
            _handle_get_program_data_folder_path();

        void
            _handle_get_local_app_data_folder_path();

        void
            _handle_get_roaming_app_data_folder_path();

    };
}
