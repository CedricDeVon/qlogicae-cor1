#pragma once

#include "value_cache.hpp"
#include "instance_manager.hpp"

namespace QLogicaeCppCore
{
    class UtilitiesCache
    {
    public:
        std::string relative_private_qlogicae_folder_path =
            ".qlogicae";

        std::string relative_public_qlogicae_folder_path =
            "qlogicae";

        std::string relative_application_name_folder_path =
            "qlogicae";

        std::string relative_application_version_name_folder_path =
            "v1.0.0";

        std::string relative_application_environment_name_folder_path =
            "development";



        std::string relative_log_folder_path =
            "log";

        std::string relative_log_date_folder_path =
            "date";

        std::string relative_log_level_folder_path =
            "level";

        std::string relative_all_log_file_path =
            "all.log";

        std::string relative_info_log_file_path =
            "info.log";

        std::string relative_debug_log_file_path =
            "debug.log";

        std::string relative_warning_log_file_path =
            "warning.log";

        std::string relative_success_log_file_path =
            "success.log";

        std::string relative_critical_log_file_path =
            "critical.log";

        std::string relative_error_log_file_path =
            "error.log";





        std::string relative_cache_folder_path =
            "cache";

        std::string relative_main_folder_path =
            "main";
        


        std::string relative_assets_folder_path =
            "assets";

        std::string relative_documentation_folder_path =
            "documentation";

        std::string relative_environment_json_file_path =
            "environment.json";

        std::string relative_license_txt_file_path =
            "LICENSE.txt";

        std::string relative_application_folder_path =
            "application";

        std::string relative_application_icon_file_path =
            "application.ico";

        std::string relative_qlogicae_json_file_path =
            "qlogicae.json";

        std::string relative_configurations_folder_path =
            "configurations";

        std::string relative_development_folder_path =
            "development";

        std::string relative_debug_folder_path =
            "debug";

        std::string relative_test_folder_path =
            "test";

        std::string relative_release_folder_path =
            "release";

        std::string relative_windows_registry_software_qlogicae_folder_path =
            "Software\\QLogicae";

        std::string full_executable_folder_path;

        std::string full_executed_folder_path;

        std::string full_roaming_app_data_folder_path;

        std::string full_local_app_data_folder_path;

        std::string full_program_data_folder_path;

        static UtilitiesCache&
            instance;

        UtilitiesCache();

        ~UtilitiesCache();

        UtilitiesCache(
            const UtilitiesCache& instance
        ) = delete;

        UtilitiesCache(
            UtilitiesCache&& instance
        ) noexcept = delete;

        UtilitiesCache& operator = (
            UtilitiesCache&& instance
        ) = delete;

        UtilitiesCache& operator = (
            const UtilitiesCache& instance
        ) = delete;

        bool
            construct();

        void
            _construct();

        bool
            destruct();

        void
            _destruct();

        bool
            setup();

        void
            _setup();

        bool
            reset();

        void
            _reset();

        std::string
            get_executable_folder_path();

        void
            _get_executable_folder_path();

        std::string
            get_executed_folder_path();

        void
            _get_executed_folder_path();

        std::string
            get_program_data_folder_path();

        void
            _get_program_data_folder_path();

        std::string
            get_local_app_data_folder_path();

        void
            _get_local_app_data_folder_path();

        std::string
            get_roaming_app_data_folder_path();

        void
            _get_roaming_app_data_folder_path();

    };
}
