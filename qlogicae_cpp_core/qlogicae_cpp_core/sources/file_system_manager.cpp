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
			if (configurations.is_thread_safety_enabled_for_method_execution())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						method_handling_layer_mutex_1
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

	std::string
        FileSystemManager::get_executable_folder_path()
    {
        try
        {            
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

/*
	FileSystemManager::FileSystemManager()
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
			ErrorManager::cache_error_log =
				exception.what();

			ErrorManager::singleton
				._handle();
		}
	}

	FileSystemManager::~FileSystemManager()
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
			ErrorManager::cache_error_log =
				exception.what();

			ErrorManager::singleton
				._handle();
		}
	}

	bool
		FileSystemManager::construct()
	{
		construct();

		return
			FileSystemManager::cache_boolean_1;
	}

	bool
		FileSystemManager::destruct()
	{
		destruct();

		return
			FileSystemManager::cache_boolean_1;
	}

	bool
		FileSystemManager::setup(
			const FileSystemManagerConfigurations&
					new_configurations
		)
	{
		FileSystemManagerConfigurations::cache =
			new_configurations;

		setup();

		return
			FileSystemManager::cache_boolean_1;
	}

	bool
		FileSystemManager::setup()
	{
		FileSystemManagerConfigurations::cache =
			{};

		setup();

		return
			FileSystemManager::cache_boolean_1;
	}

	bool
		FileSystemManager::reset()
	{
		reset();

		return
			FileSystemManager::cache_boolean_1;
	}

	size_t
		FileSystemManager::get_file_byte_size(
			const std::string_view&
				origin_path
	)
	{


		get_file_byte_size();

		return
			FileSystemManager::cache_size_t_1;
	}

	size_t
		FileSystemManager::get_folder_byte_size(
			const std::string_view&
				origin_path,
			const bool&
				is_recursive
	)
	{
		get_folder_byte_size();

		return
			FileSystemManager::cache_size_t_1;
	}

	std::string
		FileSystemManager::get_absolute_path(
			const std::string_view&
				origin_path
	)
	{
		get_absolute_path();

		return
			FileSystemManager::cache_string_1;
	}

	std::string
		FileSystemManager::get_relative_path(
			const std::string_view&
				origin_path,
			const std::string_view&
				target_path
	)
	{
		get_relative_path();

		return
			FileSystemManager::cache_string_1;
	}

	std::string
		FileSystemManager::get_file_extension(
			const std::string_view&
				origin_path
	)
	{
		get_file_extension();

		return
			FileSystemManager::cache_string_1;
	}

	std::string
		FileSystemManager::get_file_stem(
			const std::string_view&
				origin_path
	)
	{
		get_file_stem();

		return
			FileSystemManager::cache_string_1;
	}

	std::vector<std::string>
		FileSystemManager::get_entity_paths(
			const std::string_view&
				origin_path,
			const bool&
				is_recursive
	)
	{
		get_entity_paths();

		return
			FileSystemManager::cache_vector_string_1;
	}

	std::vector<std::string>
		FileSystemManager::get_file_paths(
			const std::string_view&
				origin_path,
			const bool&
				is_recursive
	)
	{
		get_file_paths();

		return
			FileSystemManager::cache_vector_string_1;
	}

	std::vector<std::string>
		FileSystemManager::get_folder_paths(
			const std::string_view&
				origin_path,
			const bool&
				is_recursive
	)
	{
		get_folder_paths();

		return
			FileSystemManager::cache_vector_string_1;
	}

	bool
		FileSystemManager::is_path_found(
			const std::string_view&
				origin_path
	)
	{
		is_path_found();

		return
			FileSystemManager::cache_boolean_1;
	}

	bool
		FileSystemManager::is_entity(
			const std::string_view&
				origin_path
	)
	{
		is_entity();

		return
			FileSystemManager::cache_boolean_1;
	}

	bool
		FileSystemManager::is_file(
			const std::string_view&
				origin_path
	)
	{
		is_file();

		return
			FileSystemManager::cache_boolean_1;
	}

	bool
		FileSystemManager::is_folder(
			const std::string_view&
				origin_path
	)
	{
		is_folder();

		return
			FileSystemManager::cache_boolean_1;
	}

	bool
		FileSystemManager::is_entity_user_permission_level_valid(
			const std::string_view&
				origin_path,
			const std::filesystem::perms&
				permission_level
	)
	{
		is_entity_user_permission_level_valid();

		return
			FileSystemManager::cache_boolean_1;
	}

	std::vector<std::string>
		FileSystemManager::find_files_by_pattern(
			const std::string_view&
				origin_path,
			const std::string_view&
				pattern,
			const bool&
				is_recursive
	)
	{
		find_files_by_pattern();

		return
			FileSystemManager::cache_vector_string_1;
	}

	bool
		FileSystemManager::set_entity_read_status(
			const std::string_view&
				origin_path,
			const bool&
				value
	)
	{
		set_entity_read_status();

		return
			FileSystemManager::cache_boolean_1;
	}

	bool
		FileSystemManager::set_entity_write_status(
			const std::string_view&
				origin_path,
			const bool&
				value
	)
	{
		set_entity_write_status();



		return
			FileSystemManager::cache_boolean_1;
	}

	bool
		FileSystemManager::set_entity_visibility(
			const std::string_view&
				origin_path,
			const bool&
				value
	)
	{
		set_entity_visibility();

		return
			FileSystemManager::cache_boolean_1;
	}

	bool
		FileSystemManager::create_folder(
			const std::string_view&
				origin_path
	)
	{
		create_folder();

		return
			FileSystemManager::cache_boolean_1;
	}

	bool
		FileSystemManager::copy_file(
			const std::string_view&
				origin_path,
			const std::string_view&
				target_path
	)
	{
		copy_file();

		return
			FileSystemManager::cache_boolean_1;
	}

	bool
		FileSystemManager::copy_folder(
			const std::string_view&
				origin_path,
			const std::string_view&
				target_path,
			const bool& is_recursive
	)
	{
		copy_folder();

		return
			FileSystemManager::cache_boolean_1;
	}

	bool
		FileSystemManager::move_entity(
			const std::string_view&
				origin_path,
			const std::string_view&
				target_path
	)
	{
		move_entity();

		return
			FileSystemManager::cache_boolean_1;
	}

	bool
		FileSystemManager::move_file(
			const std::string_view&
				origin_path,
			const std::string_view&
				target_path
	)
	{
		move_file();

		return
			FileSystemManager::cache_boolean_1;
	}

	bool
		FileSystemManager::move_folder(
			const std::string_view&
				origin_path,
			const std::string_view&
				target_path
	)
	{
		move_folder();

		return
			FileSystemManager::cache_boolean_1;
	}

	bool
		FileSystemManager::rename_entity(
			const std::string_view&
				origin_path,
			const std::string_view&
				name
	)
	{
		rename_entity();

		return
			FileSystemManager::cache_boolean_1;
	}

	bool
		FileSystemManager::rename_file(
			const std::string_view&
				origin_path,
			const std::string_view&
				name
	)
	{
		rename_file();

		return
			FileSystemManager::cache_boolean_1;
	}

	bool
		FileSystemManager::rename_folder(
			const std::string_view&
				origin_path,
			const std::string_view&
				name
	)
	{
		rename_folder();

		return
			FileSystemManager::cache_boolean_1;
	}

	bool
		FileSystemManager::remove_file(
			const std::string_view&
				origin_path
	)
	{
		remove_file();

		return
			FileSystemManager::cache_boolean_1;
	}

	bool
		FileSystemManager::remove_folder(
			const std::string_view&
				origin_path
	)
	{
		remove_folder();

		return
			FileSystemManager::cache_boolean_1;
	}

	bool
		FileSystemManager::remove_folder_sub_files(
			const std::string_view&
				origin_path,
			const bool&
				is_recursive
	)
	{
		remove_folder_sub_files();

		return
			FileSystemManager::cache_boolean_1;
	}


	void
		FileSystemManager::construct()
	{
		try
		{
			FileSystemManager::cache_boolean_1 =
				true;
		}
		catch
		(
			const std::exception&
				exception
		)
		{
			ErrorManager::cache_error_log =
				exception.what();

			ErrorManager::singleton
				._handle();
		}
	}

	void
		FileSystemManager::destruct()
	{
		try
		{
			FileSystemManager::cache_boolean_1 =
				true;
		}
		catch
		(
			const std::exception&
				exception
		)
		{
			ErrorManager::cache_error_log =
				exception.what();

			ErrorManager::singleton
				._handle();
		}
	}

	void
		FileSystemManager::setup()
	{
		try
		{
			FileSystemManager::singleton
				.setup();
		}
		catch
		(
			const std::exception&
				exception
		)
		{
			ErrorManager::cache_error_log =
				exception.what();

			ErrorManager::singleton
				._handle();
		}
	}

	void
		FileSystemManager::reset()
	{
		try
		{
			FileSystemManager::singleton
				.reset();
		}
		catch
		(
			const std::exception&
				exception
		)
		{
			ErrorManager::cache_error_log =
				exception.what();

			ErrorManager::singleton
				._handle();
		}
	}

	void
		FileSystemManager::get_file_byte_size()
	{
		try
		{

		}
		catch
		(
			const std::exception&
				exception
		)
		{
			ErrorManager::cache_error_log =
				exception.what();

			ErrorManager::singleton
				._handle();
		}
	}

	void
		FileSystemManager::get_folder_byte_size()
	{
		try
		{

		}
		catch
		(
			const std::exception&
				exception
		)
		{
			ErrorManager::cache_error_log =
				exception.what();

			ErrorManager::singleton
				._handle();
		}
	}

	void
		FileSystemManager::get_absolute_path()
	{
		try
		{

		}
		catch
		(
			const std::exception&
				exception
		)
		{
			ErrorManager::cache_error_log =
				exception.what();

			ErrorManager::singleton
				._handle();
		}
	}

	void
		FileSystemManager::get_relative_path()
	{
		try
		{

		}
		catch
		(
			const std::exception&
				exception
		)
		{
			ErrorManager::cache_error_log =
				exception.what();

			ErrorManager::singleton
				._handle();
		}
	}

	void
		FileSystemManager::get_file_extension()
	{
		try
		{

		}
		catch
		(
			const std::exception&
				exception
		)
		{
			ErrorManager::cache_error_log =
				exception.what();

			ErrorManager::singleton
				._handle();
		}
	}

	void
		FileSystemManager::get_file_stem()
	{
		try
		{

		}
		catch
		(
			const std::exception&
				exception
		)
		{
			ErrorManager::cache_error_log =
				exception.what();

			ErrorManager::singleton
				._handle();
		}
	}

	void
		FileSystemManager::get_entity_paths()
	{
		try
		{

		}
		catch
		(
			const std::exception&
				exception
		)
		{
			ErrorManager::cache_error_log =
				exception.what();

			ErrorManager::singleton
				._handle();
		}
	}

	void
		FileSystemManager::get_file_paths()
	{
		try
		{

		}
		catch
		(
			const std::exception&
				exception
		)
		{
			ErrorManager::cache_error_log =
				exception.what();

			ErrorManager::singleton
				._handle();
		}
	}

	void
		FileSystemManager::get_folder_paths()
	{
		try
		{

		}
		catch
		(
			const std::exception&
				exception
		)
		{
			ErrorManager::cache_error_log =
				exception.what();

			ErrorManager::singleton
				._handle();
		}
	}

	void
		FileSystemManager::is_path_found()
	{
		try
		{

		}
		catch
		(
			const std::exception&
				exception
		)
		{
			ErrorManager::cache_error_log =
				exception.what();

			ErrorManager::singleton
				._handle();
		}
	}

	void
		FileSystemManager::is_entity()
	{
		try
		{

		}
		catch
		(
			const std::exception&
				exception
		)
		{
			ErrorManager::cache_error_log =
				exception.what();

			ErrorManager::singleton
				._handle();
		}
	}

	void
		FileSystemManager::is_file()
	{
		try
		{

		}
		catch
		(
			const std::exception&
				exception
		)
		{
			ErrorManager::cache_error_log =
				exception.what();

			ErrorManager::singleton
				._handle();
		}
	}

	void
		FileSystemManager::is_folder()
	{
		try
		{

		}
		catch
		(
			const std::exception&
				exception
		)
		{
			ErrorManager::cache_error_log =
				exception.what();

			ErrorManager::singleton
				._handle();
		}
	}

	void
		FileSystemManager::is_entity_user_permission_level_valid()
	{
		try
		{

		}
		catch
		(
			const std::exception&
				exception
		)
		{
			ErrorManager::cache_error_log =
				exception.what();

			ErrorManager::singleton
				._handle();
		}
	}

	void
		FileSystemManager::find_files_by_pattern()
	{
		try
		{

		}
		catch
		(
			const std::exception&
				exception
		)
		{
			ErrorManager::cache_error_log =
				exception.what();

			ErrorManager::singleton
				._handle();
		}
	}

	void
		FileSystemManager::set_entity_read_status()
	{
		try
		{

		}
		catch
		(
			const std::exception&
				exception
		)
		{
			ErrorManager::cache_error_log =
				exception.what();

			ErrorManager::singleton
				._handle();
		}
	}

	void
		FileSystemManager::set_entity_write_status()
	{
		try
		{

		}
		catch
		(
			const std::exception&
				exception
		)
		{
			ErrorManager::cache_error_log =
				exception.what();

			ErrorManager::singleton
				._handle();
		}
	}

	void
		FileSystemManager::set_entity_visibility()
	{
		try
		{

		}
		catch
		(
			const std::exception&
				exception
		)
		{
			ErrorManager::cache_error_log =
				exception.what();

			ErrorManager::singleton
				._handle();
		}
	}

	void
		FileSystemManager::create_folder()
	{
		try
		{

		}
		catch
		(
			const std::exception&
				exception
		)
		{
			ErrorManager::cache_error_log =
				exception.what();

			ErrorManager::singleton
				._handle();
		}
	}

	void
		FileSystemManager::copy_file()
	{
		try
		{

		}
		catch
		(
			const std::exception&
				exception
		)
		{
			ErrorManager::cache_error_log =
				exception.what();

			ErrorManager::singleton
				._handle();
		}
	}

	void
		FileSystemManager::copy_folder()
	{
		try
		{

		}
		catch
		(
			const std::exception&
				exception
		)
		{
			ErrorManager::cache_error_log =
				exception.what();

			ErrorManager::singleton
				._handle();
		}
	}

	void
		FileSystemManager::move_entity()
	{
		try
		{

		}
		catch
		(
			const std::exception&
				exception
		)
		{
			ErrorManager::cache_error_log =
				exception.what();

			ErrorManager::singleton
				._handle();
		}
	}

	void
		FileSystemManager::move_file()
	{
		try
		{

		}
		catch
		(
			const std::exception&
				exception
		)
		{
			ErrorManager::cache_error_log =
				exception.what();

			ErrorManager::singleton
				._handle();
		}
	}

	void
		FileSystemManager::move_folder()
	{
		try
		{

		}
		catch
		(
			const std::exception&
				exception
		)
		{
			ErrorManager::cache_error_log =
				exception.what();

			ErrorManager::singleton
				._handle();
		}
	}

	void
		FileSystemManager::rename_entity()
	{
		try
		{

		}
		catch
		(
			const std::exception&
				exception
		)
		{
			ErrorManager::cache_error_log =
				exception.what();

			ErrorManager::singleton
				._handle();
		}
	}

	void
		FileSystemManager::rename_file()
	{
		try
		{

		}
		catch
		(
			const std::exception&
				exception
		)
		{
			ErrorManager::cache_error_log =
				exception.what();

			ErrorManager::singleton
				._handle();
		}
	}

	void
		FileSystemManager::rename_folder()
	{
		try
		{

		}
		catch
		(
			const std::exception&
				exception
		)
		{
			ErrorManager::cache_error_log =
				exception.what();

			ErrorManager::singleton
				._handle();
		}
	}

	void
		FileSystemManager::remove_file()
	{
		try
		{

		}
		catch
		(
			const std::exception&
				exception
		)
		{
			ErrorManager::cache_error_log =
				exception.what();

			ErrorManager::singleton
				._handle();
		}
	}

	void
		FileSystemManager::remove_folder()
	{
		try
		{

		}
		catch
		(
			const std::exception&
				exception
		)
		{
			ErrorManager::cache_error_log =
				exception.what();

			ErrorManager::singleton
				._handle();
		}
	}

	void
		FileSystemManager::remove_folder_sub_files()
	{
		try
		{

		}
		catch
		(
			const std::exception&
				exception
		)
		{
			ErrorManager::cache_error_log =
				exception.what();

			ErrorManager::singleton
				._handle();
		}
	}

*/ 
