#include "pch.hpp"

#include "../includes/file_system_manager.hpp"

namespace
	QLogicaeCppCore
{
    FileSystemManager&
        FileSystemManager
			::singleton =
				SingletonManager
					::singleton
						.get_singleton<FileSystemManager>();


	
	FileSystemManager
		::FileSystemManager() :
			AbstractClass<FileSystemManagerConfigurations>()
    {
        try
        {
            construct();
        }
        catch
        (
            const std::exception&
                exception
        )
        {
			handle_error_outputs(
				exception
			);
        }
    }

    FileSystemManager
		::~FileSystemManager()
    {
        try
        {
            destruct();
        }
        catch
        (
            const std::exception&
                exception
        )
        {
			handle_error_outputs(
				exception
			);
        }
    }

    bool
        FileSystemManager
			::construct()
    {
        try
        {			
			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_utility_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						utility_handling_mutex_1
					);
			}

			relative_private_qlogicae_folder_path =
				".qlogicae";

			relative_public_qlogicae_folder_path =
				"qlogicae";

			relative_application_name_folder_path =
				"qlogicae";

			relative_application_version_name_folder_path =
				"v1.0.0";

			relative_application_environment_name_folder_path =
				"development";

			relative_log_folder_path =
				"log";

			relative_log_date_folder_path =
				"date";

			relative_log_level_folder_path =
				"level";

			relative_all_log_file_path =
				"all.log";

			relative_info_log_file_path =
				"info.log";

			relative_debug_log_file_path =
				"debug.log";

			relative_warning_log_file_path =
				"warning.log";

			relative_success_log_file_path =
				"success.log";

			relative_critical_log_file_path =
				"critical.log";

			relative_error_log_file_path =
				"error.log";

			relative_cache_folder_path =
				"cache";

			relative_main_folder_path =
				"main";

			relative_assets_folder_path =
				"assets";

			relative_documentation_folder_path =
				"documentation";

			relative_environment_json_file_path =
				"environment.json";

			relative_license_txt_file_path =
				"LICENSE.txt";

			relative_application_folder_path =
				"application";

			relative_application_icon_file_path =
				"application.ico";

			relative_qlogicae_json_file_path =
				"qlogicae.json";

			relative_configurations_folder_path =
				"configurations";

			relative_development_folder_path =
				"development";

			relative_debug_folder_path =
				"debug";

			relative_test_folder_path =
				"test";

			relative_release_folder_path =
				"release";

			relative_windows_registry_software_qlogicae_folder_path =
				"Software\\QLogicae";

			full_executable_folder_path =
				get_executable_folder_path();

			full_executed_folder_path =
				get_executed_folder_path();

			full_roaming_app_data_folder_path =
				get_roaming_app_data_folder_path();

			full_local_app_data_folder_path =
				get_local_app_data_folder_path();

			full_program_data_folder_path =
				get_program_data_folder_path();

			return
				true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
			return
				handle_error_outputs(
					exception
				);
        }
    }

    bool
        FileSystemManager
			::destruct()
    {
        try
        {		
			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_utility_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						utility_handling_mutex_1
					);
			}			

			return
				true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
			return
				handle_error_outputs(
					exception
				);
        }
    }

	std::string
        FileSystemManager
			::get_executable_folder_path()
    {
        try
        {       
			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_feature_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}
     
			std::filesystem::path
				cache_directory_path;

			DWORD
				cache_dword_path_length;

			wchar_t
				cache_wchar_t_buffer[MAX_PATH];

			int
				cache_int_1;

			std::string
				cache_string_1;

			std::wstring
				cache_wstring_1;

			std::vector<std::string>
				cache_vector_string_1;

            cache_dword_path_length =
                GetModuleFileNameW(
                    nullptr,
                    cache_wchar_t_buffer,
                    MAX_PATH
                );

            if (cache_dword_path_length == 0 ||
                cache_dword_path_length == MAX_PATH
                )
            {
                return
					"";
            }

            cache_directory_path =
                std::filesystem::path(cache_wchar_t_buffer)
                    .parent_path();

            cache_wstring_1 =
                cache_directory_path.wstring();
            
            if (cache_wstring_1.empty())
            {
				return
					"";
            }

            cache_int_1 =
                WideCharToMultiByte(
                    CP_UTF8,
                    0,
                    cache_wstring_1.data(),
                    -1,
                    nullptr,
                    0,
                    nullptr,
                    nullptr
                );

            cache_string_1 = std::string(
                cache_int_1 - 1,
                0
            );

            WideCharToMultiByte(
                CP_UTF8,
                0,
                cache_wstring_1.data(),
                -1,
                cache_string_1.data(),
                cache_int_1,
                nullptr,
                nullptr
            );         

			return
				cache_string_1;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
			handle_error_outputs(
				exception
			);

			return
				"";
        }
    }

	std::string
        FileSystemManager::get_executed_folder_path()
    {
        try
        {
			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_feature_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}

			std::filesystem::path
				cache_directory_path;

			DWORD
				cache_dword_path_length;

			std::string
				cache_string_1;

			std::wstring
				cache_wstring_1;

			std::vector<std::string>
				cache_vector_string_1;

            cache_dword_path_length =
                GetCurrentDirectoryA(
                    0,
                    nullptr
                );

            cache_string_1 =
                std::string(
                    cache_dword_path_length,
                    '\0'
                );

            GetCurrentDirectoryA(
                cache_dword_path_length,
                cache_string_1.data()
            );
            
            cache_string_1
                .pop_back();

			return
				cache_string_1;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
			handle_error_outputs(
				exception
			);

			return
				"";
        }
    }

	std::string
        FileSystemManager::get_program_data_folder_path()
    {
        try
        {
			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_feature_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}

			std::filesystem::path
				cache_directory_path;

			int
				cache_int_1;

			std::string
				cache_string_1;

			std::wstring
				cache_wstring_1;

			std::vector<std::string>
				cache_vector_string_1;

			wchar_t*
				cache_wchar_t_pointer_1;

            if (SUCCEEDED(
                SHGetKnownFolderPath(
                    FOLDERID_ProgramData,
                    0,
                    NULL,
                    &cache_wchar_t_pointer_1)
            ))
            {
                cache_wstring_1.assign(
                    cache_wchar_t_pointer_1
                );
                CoTaskMemFree(
                    cache_wchar_t_pointer_1
                );
            }

            cache_int_1 =
                WideCharToMultiByte(
                    CP_UTF8,
                    0,
                    cache_wstring_1.data(),
                    -1,
                    nullptr,
                    0,
                    nullptr,
                    nullptr
                );

            cache_string_1 = std::string(
                cache_int_1,
                0
            );

            WideCharToMultiByte(
                CP_UTF8,
                0,
                cache_wstring_1.data(),
                -1,
                &cache_string_1[0],
                cache_int_1,
                nullptr,
                nullptr
            );
            
            cache_string_1
                .pop_back();

			return
				cache_string_1;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
			handle_error_outputs(
				exception
			);

			return
				"";
        }
    }

    std::string
        FileSystemManager::get_local_app_data_folder_path()
    {
        try
        {
			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_feature_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}

			std::filesystem::path
				cache_directory_path;

			int
				cache_int_1;

			std::string
				cache_string_1;

			std::wstring
				cache_wstring_1;

			std::vector<std::string>
				cache_vector_string_1;

			wchar_t*
				cache_wchar_t_pointer_1;

            if (SUCCEEDED(SHGetKnownFolderPath(
                FOLDERID_LocalAppData,
                0,
                NULL,
                &cache_wchar_t_pointer_1))
            )
            {
                cache_wstring_1.assign(
                    cache_wchar_t_pointer_1
                );
                CoTaskMemFree(
                    cache_wchar_t_pointer_1
                );
            }

            cache_int_1 =
                WideCharToMultiByte(
                    CP_UTF8,
                    0,
                    cache_wstring_1.data(),
                    -1,
                    nullptr,
                    0,
                    nullptr,
                    nullptr
                );

            cache_string_1 =
                std::string(
                    cache_int_1,
                    0
                );

            WideCharToMultiByte(
                CP_UTF8,
                0,
                cache_wstring_1.data(),
                -1,
                &cache_string_1[0],
                cache_int_1,
                nullptr,
                nullptr
            );

            cache_string_1
                .pop_back();

			return
				cache_string_1;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
			handle_error_outputs(
				exception
			);

            return
				"";
				
        }
    }
}
