#pragma once

#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "file_system_entity.hpp"
#include "file_system_manager_configurations.hpp"

#include <Shlwapi.h>

namespace
	QLogicaeCppCore
{
    class
		FileSystemManager :
			public AbstractClass<FileSystemManagerConfigurations>
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

        static FileSystemManager&
            singleton;

        FileSystemManager();

		~FileSystemManager();

        bool
            construct();

		bool
			destruct();

		std::wstring
			get_executable_folder_wstring_path();

		std::wstring
			get_executed_folder_wstring_path();

		std::wstring
			get_program_data_folder_wstring_path();

		std::wstring
			get_local_app_data_folder_wstring_path();

		std::wstring
			get_roaming_app_data_folder_wstring_path();

        size_t
            get_file_byte_size(            
                const wchar_t*
                    origin_path
			);

        size_t
            get_folder_byte_size(            
				const wchar_t*
                    origin_path
			);

        std::wstring
            get_absolute_path(
				const wchar_t*
                    origin_path
			);

        std::wstring
            get_relative_path(
				const wchar_t*
                    origin_path,
				const wchar_t*
                    target_path
			);

        std::wstring
            get_file_extension(
				const wchar_t*
                    origin_path
			);

		std::wstring
            get_file_stem(
                const wchar_t*
                    origin_path
			);

        bool
            is_path_found(
                const wchar_t*
                    origin_path
			);

        bool
            is_entity(
                const wchar_t*
                    origin_path
			);

        bool
            is_file(
                const wchar_t*
                    origin_path
			);

        bool
            is_folder(
                const wchar_t*
                    origin_path
			);

        bool
            is_entity_user_permission_level_valid(
				const wchar_t*
                    origin_path,
                const std::filesystem::perms&
                    permission_level
			);

        bool
            set_entity_read_status(
                const wchar_t*
                    origin_path,
                const bool&
                    value
			);

        bool
            set_entity_write_status(
				const wchar_t*
                    origin_path,
                const bool&
                    value
			);

        bool
            set_entity_visibility(
				const wchar_t*
                    origin_path,
                const bool&
                    value
			);

        bool
            create_folder(
				const wchar_t*
                    origin_path
			);

        bool
            copy_file(
                const wchar_t*
                    origin_path,
                const wchar_t*
                    target_path
			);

        bool
            copy_folder(
                const wchar_t*
                    origin_path,
                const wchar_t*
                    target_path
			);

        bool
            move_entity(
                const wchar_t*
                    origin_path,
                const wchar_t*
                    target_path
			);

        bool
            move_file(
                const wchar_t*
                    origin_path,
                const wchar_t*
                    target_path
			);

        bool
            move_folder(
                const wchar_t*
                    origin_path,
                const wchar_t*
                    target_path
			);

        bool
            rename_entity(
                const wchar_t*
                    origin_path,
                const wchar_t*
                    name
			);

        bool
            rename_file(
                const wchar_t*
                    origin_path,
                const wchar_t*
                    name
			);

        bool
            rename_folder(
                const wchar_t*
                    origin_path,
                const wchar_t*
                    name
			);

        bool
            remove_file(
				const wchar_t*
                    origin_path
			);

        bool
            remove_folder(
				const wchar_t*
                    origin_path
			);

        bool
            remove_folder_sub_files(
				const wchar_t*
                    origin_path
			);

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

        size_t
            get_file_byte_size(            
                const std::string&
                    origin_path
			);

        size_t
            get_folder_byte_size(            
                const std::string&
                    origin_path
			);

        std::string
            get_absolute_path(
                const std::string&
                    origin_path
			);

        std::string
            get_relative_path(
                const std::string&
                    origin_path,
                const std::string&
                    target_path
			);

        std::string
            get_file_extension(
                const std::string&
                    origin_path
			);

        std::string
            get_file_stem(
                const std::string&
                    origin_path
			);

        bool
            is_path_found(
                const std::string&
                    origin_path
			);

        bool
            is_entity(
                const std::string&
                    origin_path
			);

        bool
            is_file(
                const std::string&
                    origin_path
			);

        bool
            is_folder(
                const std::string&
                    origin_path
			);

        bool
            is_entity_user_permission_level_valid(
                const std::string&
                    origin_path,
                const std::filesystem::perms&
                    permission_level
			);

        bool
            set_entity_read_status(
                const std::string&
                    origin_path,
                const bool&
                    value
			);

        bool
            set_entity_write_status(
                const std::string&
                    origin_path,
                const bool&
                    value
			);

        bool
            set_entity_visibility(
                const std::string&
                    origin_path,
                const bool&
                    value
			);

        bool
            create_folder(
                const std::string&
                    origin_path
			);

        bool
            copy_file(
                const std::string&
                    origin_path,
                const std::string&
                    target_path
			);

        bool
            copy_folder(
                const std::string&
                    origin_path,
                const std::string&
                    target_path
			);

        bool
            move_entity(
                const std::string&
                    origin_path,
                const std::string&
                    target_path
			);

        bool
            move_file(
                const std::string&
                    origin_path,
                const std::string&
                    target_path
			);

        bool
            move_folder(
                const std::string&
                    origin_path,
                const std::string&
                    target_path
			);

        bool
            rename_entity(
                const std::string&
                    origin_path,
                const std::string&
                    name
			);

        bool
            rename_file(
                const std::string&
                    origin_path,
                const std::string&
                    name
			);

        bool
            rename_folder(
                const std::string&
                    origin_path,
                const std::string&
                    name
			);

        bool
            remove_file(
                const std::string&
                    origin_path
			);

        bool
            remove_folder(
                const std::string&
                    origin_path
			);

        bool
            remove_folder_sub_files(
                const std::string&
                    origin_path
			);   
    };
}



/*
		std::vector<std::wstring>
			get_entity_paths(
				const std::wstring&
					origin_path
			);

		std::vector<std::wstring>
			get_file_paths(
				const std::wstring&
					origin_path
			);

		std::vector<std::wstring>
			get_folder_paths(
				const std::wstring&
					origin_path
			);


		std::vector<std::string>
			find_files_by_pattern(
				const std::wstring&
					origin_path,
				const std::wstring&
					pattern
			);

		std::vector<std::string>
			find_files_by_pattern(
				const std::string&
					origin_path,
				const std::string&
					pattern
			);

		std::vector<std::string>
			get_entity_paths(
				const std::string&
				origin_path
			);

		std::vector<std::string>
			get_file_paths(
				const std::string&
				origin_path
			);

		std::vector<std::string>
			get_folder_paths(
				const std::string&
				origin_path
			);

*/ 
