#include "pch.hpp"

#include "../includes/file_system_manager.hpp"

namespace
	QLogicaeCppCore
{
	std::string
		FileSystemManager
			::relative_private_qlogicae_folder_path =
				".qlogicae";

	std::string
		FileSystemManager
			::relative_public_qlogicae_folder_path =
				"qlogicae";

	std::string
		FileSystemManager
			::relative_application_name_folder_path =
				"qlogicae";

	std::string
		FileSystemManager
			::relative_application_version_name_folder_path =
				"v1.0.0";

	std::string
		FileSystemManager
			::relative_application_environment_name_folder_path =
				"development";

	std::string
		FileSystemManager
			::relative_log_folder_path =
				"log";

	std::string
		FileSystemManager
			::relative_log_date_folder_path =
				"date";

	std::string
		FileSystemManager
			::relative_log_level_folder_path =
				"level";

	std::string
		FileSystemManager
			::relative_all_log_file_path =
				"all.log";

	std::string
		FileSystemManager
			::relative_info_log_file_path =
				"info.log";

	std::string
		FileSystemManager
			::relative_debug_log_file_path =
				"debug.log";

	std::string
		FileSystemManager
			::relative_warning_log_file_path =
				"warning.log";

	std::string
		FileSystemManager
			::relative_success_log_file_path =
				"success.log";

	std::string
		FileSystemManager
			::relative_critical_log_file_path =
				"critical.log";

	std::string
		FileSystemManager
			::relative_error_log_file_path =
				"error.log";

	std::string
		FileSystemManager
			::relative_cache_folder_path =
				"cache";

	std::string
		FileSystemManager
			::relative_main_folder_path =
				"main";

	std::string
		FileSystemManager
			::relative_assets_folder_path =
				"assets";

	std::string
		FileSystemManager
			::relative_documentation_folder_path =
				"documentation";

	std::string
		FileSystemManager
			::relative_environment_json_file_path =
				"environment.json";

	std::string
		FileSystemManager
			::relative_license_txt_file_path =
				"LICENSE.txt";

	std::string
		FileSystemManager
			::relative_application_folder_path =
				"application";

	std::string
		FileSystemManager
			::relative_application_icon_file_path =
				"application.ico";

	std::string
		FileSystemManager
			::relative_qlogicae_json_file_path =
				"qlogicae.json";

	std::string
		FileSystemManager
			::relative_configurations_folder_path =
				"configurations";

	std::string
		FileSystemManager
			::relative_development_folder_path =
				"development";

	std::string
		FileSystemManager
			::relative_debug_folder_path =
				"debug";

	std::string
		FileSystemManager
			::relative_test_folder_path =
				"test";

	std::string
		FileSystemManager
			::relative_release_folder_path =
				"release";

	std::string
		FileSystemManager
			::relative_windows_registry_software_qlogicae_folder_path =
				"Software\\QLogicae";

	std::string
		FileSystemManager
			::full_executable_folder_path =
				"";

	std::string
		FileSystemManager
			::full_executed_folder_path =
				"";

	std::string
		FileSystemManager
			::full_roaming_app_data_folder_path =
				"";

	std::string
		FileSystemManager
			::full_local_app_data_folder_path =
				"";

	std::string
		FileSystemManager
			::full_program_data_folder_path =
				"";

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

	std::wstring
        FileSystemManager
			::get_executable_folder_wstring_path()
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
     
			wchar_t buffer[MAX_PATH];
			DWORD length =
				GetModuleFileNameW(
					nullptr,
					buffer,
					MAX_PATH
				);

			if (length == 0 || length == MAX_PATH)
			{
				return L"";
			}

			wchar_t* last_separator =
				wcsrchr(buffer, L'\\');

			if (last_separator != nullptr)
			{
				*last_separator = L'\0';
			}

			return std::wstring(buffer);
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
				L"";
        }
    }

	std::wstring
        FileSystemManager
			::get_executed_folder_wstring_path()
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

			DWORD required_size =
				GetCurrentDirectoryW(0, nullptr);

			if (required_size == 0)
			{
				return L"";
			}

			std::wstring path;
			path.resize(required_size - 1);

			if (!GetCurrentDirectoryW(
					required_size,
					path.data()))
			{
				return L"";
			}

			return path;
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
				L"";
        }
    }

	std::wstring
        FileSystemManager
			::get_program_data_folder_wstring_path()
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

			wchar_t buffer[MAX_PATH];

			HRESULT result =
				SHGetFolderPathW(
					nullptr,
					CSIDL_COMMON_APPDATA,
					nullptr,
					SHGFP_TYPE_CURRENT,
					buffer
				);

			if (FAILED(result))
			{
				return L"";
			}

			return std::wstring(buffer);
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
				L"";
        }
    }

    std::wstring
        FileSystemManager
			::get_local_app_data_folder_wstring_path()
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

			wchar_t buffer[MAX_PATH];

			HRESULT result =
				SHGetFolderPathW(
					nullptr,
					CSIDL_LOCAL_APPDATA,
					nullptr,
					SHGFP_TYPE_CURRENT,
					buffer
				);

			if (FAILED(result))
			{
				return L"";
			}

			return std::wstring(buffer);
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
				L"";
				
        }
    }

	std::wstring
        FileSystemManager
			::get_roaming_app_data_folder_wstring_path()
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

			wchar_t buffer[MAX_PATH];

			HRESULT result =
				SHGetFolderPathW(
					nullptr,
					CSIDL_APPDATA,
					nullptr,
					SHGFP_TYPE_CURRENT,
					buffer
				);

			if (FAILED(result))
			{
				return L"";
			}

			return std::wstring(buffer);
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
				L"";
				
        }
    }
	

    size_t
		FileSystemManager
			::get_file_byte_size(
				const wchar_t*
					origin_path
			)
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

			WIN32_FILE_ATTRIBUTE_DATA data;
			if (!GetFileAttributesExW(
				origin_path, GetFileExInfoStandard, &data)
			)
			{
				return
					0;
			}
			if (data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			{
				return
					0;
			}

			ULARGE_INTEGER size;
			size.HighPart = data.nFileSizeHigh;
			size.LowPart = data.nFileSizeLow;

			return
				size.QuadPart;
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
				0;
        }
	}

	size_t
		FileSystemManager
			::get_folder_byte_size(
				const wchar_t*
					origin_path
			)
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

			wchar_t search_path[MAX_PATH];
			wsprintfW(search_path, L"%s\\*", origin_path);

			WIN32_FIND_DATAW find_data;
			HANDLE handle =
				FindFirstFileW(search_path, &find_data);

			if (handle == INVALID_HANDLE_VALUE)
			{
				return 0;
			}

			size_t total_size = 0;

			do
			{
				if (wcscmp(find_data.cFileName, L".") == 0 ||
					wcscmp(find_data.cFileName, L"..") == 0)
				{
					continue;
				}

				wchar_t entity_path[MAX_PATH];
				wsprintfW(
					entity_path,
					L"%s\\%s",
					origin_path,
					find_data.cFileName
				);

				if (find_data.dwFileAttributes &
					FILE_ATTRIBUTE_DIRECTORY)
				{
					if ((find_data.dwFileAttributes &
						FILE_ATTRIBUTE_REPARSE_POINT) == 0)
					{
						total_size +=
							get_folder_byte_size(entity_path);
					}
				}
				else
				{
					LARGE_INTEGER size;
					size.HighPart = find_data.nFileSizeHigh;
					size.LowPart = find_data.nFileSizeLow;

					total_size +=
						static_cast<size_t>(size.QuadPart);
				}
			} while (FindNextFileW(handle, &find_data));

			FindClose(handle);

			return total_size;
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
				0;
        }
	}

	std::wstring
		FileSystemManager
			::get_absolute_path(
				const wchar_t*
					origin_path
			)
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

			std::wstring buffer;
			buffer.assign(MAX_PATH, L'\0');
			DWORD len = GetFullPathNameW(
				origin_path,
				MAX_PATH, buffer.data(),
				nullptr
			);
        
			if (len == 0 || len > MAX_PATH)
			{	
				return
					0;
			}
        
			buffer.resize(len);

			return
				buffer;
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
				L"";
        }
	}

	std::wstring
		FileSystemManager
			::get_relative_path(
				const wchar_t*
					origin_path,
				const wchar_t*
					target_path
			)
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

			wchar_t buffer[MAX_PATH];

			const DWORD origin_attributes =
				GetFileAttributesW(
					origin_path
				);

			const DWORD target_attributes =
				GetFileAttributesW(
					target_path
				);

			if (origin_attributes == INVALID_FILE_ATTRIBUTES ||
				target_attributes == INVALID_FILE_ATTRIBUTES)
			{
				return L"";
			}

			const DWORD origin_type =
				(origin_attributes & FILE_ATTRIBUTE_DIRECTORY) != 0
					? FILE_ATTRIBUTE_DIRECTORY
					: FILE_ATTRIBUTE_NORMAL;

			const DWORD target_type =
				(target_attributes & FILE_ATTRIBUTE_DIRECTORY) != 0
					? FILE_ATTRIBUTE_DIRECTORY
					: FILE_ATTRIBUTE_NORMAL;

			const BOOL result =
				PathRelativePathToW(
					buffer,
					origin_path,
					origin_type,
					target_path,
					target_type
				);

			return (result == FALSE) ? L"" : buffer;
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
				L"";
        }
	}

	std::wstring
		FileSystemManager
			::get_file_extension(
				const wchar_t*
					origin_path
			)
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

			return
				std::wstring(PathFindExtensionW(origin_path));
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
				L"";
        }
	}

	std::wstring
		FileSystemManager
			::get_file_stem(
				const wchar_t*
					origin_path
			)
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

			wchar_t* filename = PathFindFileNameW(origin_path);
			PathRemoveExtensionW(filename);

			return
				std::wstring(filename);
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
				L"";
        }
	}

	bool
		FileSystemManager
			::is_path_found(
				const wchar_t*
					origin_path
			)
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

			return
				(GetFileAttributesW(
					origin_path
				) != INVALID_FILE_ATTRIBUTES);
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
			::is_entity(
				const wchar_t*
					origin_path
			)
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

			return
				(GetFileAttributesW(
					origin_path
				) != INVALID_FILE_ATTRIBUTES);
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
			::is_file(
				const wchar_t*
					origin_path
			)
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

			DWORD file_attribute =
				GetFileAttributesW(
					origin_path
				);

			return
				(file_attribute != INVALID_FILE_ATTRIBUTES &&
				!(file_attribute & FILE_ATTRIBUTE_DIRECTORY));
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
			::is_folder(
				const wchar_t*
					origin_path
			)
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

			DWORD file_attribute =
				GetFileAttributesW(
					origin_path
				);

			return
				(file_attribute != INVALID_FILE_ATTRIBUTES &&
				(file_attribute & FILE_ATTRIBUTE_DIRECTORY));
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
			::is_entity_user_permission_level_valid(
				const wchar_t*
					origin_path,
				const std::filesystem::perms&
					permission_level
			)
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

			DWORD
				desired_access =
					0;

			if ((permission_level & std::filesystem::perms::owner_read)
				!= std::filesystem::perms::none)
			{
				desired_access |= GENERIC_READ;
			}

			if ((permission_level & std::filesystem::perms::owner_write)
				!= std::filesystem::perms::none)
			{
				desired_access |= GENERIC_WRITE;
			}

			if ((permission_level & std::filesystem::perms::owner_exec)
				!= std::filesystem::perms::none)
			{
				desired_access |= GENERIC_EXECUTE;
			}

			HANDLE
				token =
					nullptr;

			if (!OpenProcessToken(
				GetCurrentProcess(),
				TOKEN_QUERY,
				&token)
			)
			{
				return
					false;
			}

			DWORD access_status = 0;
			BOOL access_allowed = FALSE;
			PRIVILEGE_SET privileges{};
			DWORD privilege_size = sizeof(PRIVILEGE_SET);

			PSECURITY_DESCRIPTOR security_descriptor = nullptr;

			if (GetNamedSecurityInfoW(
				origin_path,
				SE_FILE_OBJECT,
				DACL_SECURITY_INFORMATION,
				nullptr,
				nullptr,
				nullptr,
				nullptr,
				&security_descriptor) != ERROR_SUCCESS)
			{
				CloseHandle(token);

				return
					false;
			}

			if (!AccessCheck(
				security_descriptor,
				token,
				desired_access,
				nullptr,
				&privileges,
				&privilege_size,
				&access_status,
				&access_allowed))
			{
				LocalFree(security_descriptor);
				CloseHandle(token);

				return
					false;
			}

			LocalFree(security_descriptor);
			CloseHandle(token);

			return
				access_allowed == TRUE;
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
			::set_entity_read_status(
				const wchar_t*
					origin_path,
				const bool&
					value
			)
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

			DWORD attributes = ::GetFileAttributesW(origin_path);
			if (attributes == INVALID_FILE_ATTRIBUTES)
			{
				return false;
			}

			if (value)
			{
				attributes &= ~FILE_ATTRIBUTE_READONLY;
			}
			else
			{
				attributes |= FILE_ATTRIBUTE_READONLY; 
			}

			return SetFileAttributesW(origin_path, attributes) != FALSE;
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
			::set_entity_write_status(
				const wchar_t*
					origin_path,
				const bool&
					value
			)
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

			DWORD attributes = GetFileAttributesW(origin_path);
			if (attributes == INVALID_FILE_ATTRIBUTES)
			{
				return
					false;
			}

			if (value)
			{
				attributes &= ~FILE_ATTRIBUTE_READONLY;
			}
			else
			{
				attributes |= FILE_ATTRIBUTE_READONLY;
			}

			return
				SetFileAttributesW(origin_path, attributes) != FALSE;
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
			::set_entity_visibility(
				const wchar_t*
					origin_path,
				const bool&
					value
			)
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

			DWORD attributes = GetFileAttributesW(origin_path);
			if (attributes == INVALID_FILE_ATTRIBUTES)
			{
				return
					false;
			}

			if (value)
			{
				attributes &= ~FILE_ATTRIBUTE_HIDDEN;
			}
			else
			{
				attributes |= FILE_ATTRIBUTE_HIDDEN;
			}

			return
				SetFileAttributesW(origin_path, attributes) != FALSE;
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
			::create_folder(
				const wchar_t*
					origin_path
			)
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

			return
				(CreateDirectoryW(origin_path, nullptr) ||
					GetLastError() == ERROR_ALREADY_EXISTS);
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
			::copy_file(
				const wchar_t*
					origin_path,
				const wchar_t*
					target_path
			)
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

			return
				CopyFileW(origin_path, target_path, FALSE);
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
			::copy_folder(
				const wchar_t*
					origin_path,
				const wchar_t*
					target_path
			)
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

			return
				CopyFileW(origin_path, target_path, FALSE);
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
			::move_entity(
				const wchar_t*
					origin_path,
				const wchar_t*
					target_path
			)
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
						feature_handling_mutex_2
					);
			}			

			return
				MoveFileExW(
					origin_path,
					target_path,
					MOVEFILE_COPY_ALLOWED |
					MOVEFILE_REPLACE_EXISTING |
					MOVEFILE_WRITE_THROUGH
				) != FALSE;
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
			::move_file(
				const wchar_t*
					origin_path,
				const wchar_t*
					target_path
			)
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

			DWORD
				attributes =
					GetFileAttributesW(
						origin_path
					);

			if (attributes == INVALID_FILE_ATTRIBUTES ||
				(attributes & FILE_ATTRIBUTE_DIRECTORY) != 0)
			{
				return
					false;
			}

			return
				move_entity(
					origin_path,
					target_path
				);
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
			::move_folder(
				const wchar_t*
					origin_path,
				const wchar_t*
					target_path
			)
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

			DWORD
				attributes =
					::GetFileAttributesW(
						origin_path
					);

			if (attributes == INVALID_FILE_ATTRIBUTES ||
				(attributes & FILE_ATTRIBUTE_DIRECTORY) == 0)
			{
				return
					false;
			}

			return
				move_entity(
					origin_path,
					target_path
				);
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
			::rename_entity(
				const wchar_t*
					origin_path,
				const wchar_t*
					name
			)
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
						feature_handling_mutex_2
					);
			}			

			wchar_t buffer[MAX_PATH];

			const DWORD length =
				GetFullPathNameW(
					origin_path,
					MAX_PATH,
					buffer,
					nullptr
				);

			if (length == 0 || length >= MAX_PATH)
			{
				return false;
			}

			wchar_t* filename =
				::wcsrchr(buffer, L'\\');

			if (filename == nullptr)
			{
				return false;
			}

			++filename;
			*filename = L'\0';

			return
				move_entity(
					origin_path,
					(std::wstring(buffer) + std::wstring(name)).data()
				);
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
			::rename_file(
				const wchar_t*
					origin_path,
				const wchar_t*
					name
			)
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

			const DWORD
				attributes =
					GetFileAttributesW(
						origin_path
					);

			if (attributes == INVALID_FILE_ATTRIBUTES ||
				(attributes & FILE_ATTRIBUTE_DIRECTORY) != 0)
			{
				return
					false;
			}

			return
				rename_entity(
					origin_path,
					name
				);
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
			::rename_folder(
				const wchar_t*
					origin_path,
				const wchar_t*
					name
			)
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

			const DWORD
				attributes =
					GetFileAttributesW(
						origin_path
					);

			if (attributes == INVALID_FILE_ATTRIBUTES ||
				(attributes & FILE_ATTRIBUTE_DIRECTORY) == 0)
			{
				return
					false;
			}

			return
				rename_entity(
					origin_path,
					name
				);
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
			::remove_file(
				const wchar_t*
					origin_path
			)
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

			return
				DeleteFileW(origin_path);
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
			::remove_folder(
				const wchar_t*
					origin_path
			)
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

			return
				RemoveDirectoryW(origin_path);
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
			::remove_folder_sub_files(
				const wchar_t*
					origin_path
			)
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

			wchar_t search_path[MAX_PATH];
			wsprintfW(search_path, L"%s\\*", origin_path);

			WIN32_FIND_DATAW find_data;
			HANDLE handle =
				FindFirstFileW(search_path, &find_data);

			if (handle == INVALID_HANDLE_VALUE)
			{
				return false;
			}

			bool success = true;

			do
			{
				if (wcscmp(find_data.cFileName, L".") == 0 ||
					wcscmp(find_data.cFileName, L"..") == 0)
				{
					continue;
				}

				if ((find_data.dwFileAttributes &
					FILE_ATTRIBUTE_DIRECTORY) == 0)
				{
					wchar_t file_path[MAX_PATH];
					wsprintfW(
						file_path,
						L"%s\\%s",
						origin_path,
						find_data.cFileName
					);

					if (!DeleteFileW(file_path))
					{
						success = false;
					}
				}
			} while (FindNextFileW(handle, &find_data));

			FindClose(handle);

			return success;
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
        FileSystemManager
			::get_executed_folder_path()
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
        FileSystemManager
			::get_program_data_folder_path()
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
        FileSystemManager
			::get_local_app_data_folder_path()
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
	

    std::string
        FileSystemManager
			::get_roaming_app_data_folder_path()
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

			wchar_t buffer[MAX_PATH];
			
			HRESULT result =
				SHGetFolderPathW(
					nullptr,
					CSIDL_APPDATA,
					nullptr,
					SHGFP_TYPE_CURRENT,
					buffer
				);

			if (FAILED(result))
			{
				return std::string();
			}
			
			int required_size =
				WideCharToMultiByte(
					CP_UTF8,
					0,
					buffer,
					-1,
					nullptr,
					0,
					nullptr,
					nullptr
				);

			if (required_size <= 0)
			{
				return std::string();
			}

			std::string utf8_path;
			utf8_path.resize(required_size - 1); 

			WideCharToMultiByte(
				CP_UTF8,
				0,
				buffer,
				-1,
				utf8_path.data(),
				required_size,
				nullptr,
				nullptr
			);

			return utf8_path;
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
	



	size_t
        FileSystemManager
			::get_file_byte_size(            
				const std::string&
					origin_path
			)
	{
		
	}

    size_t
        FileSystemManager
			::get_folder_byte_size(            
				const std::string&
					origin_path
			)
	{
		
	}

    std::string
        FileSystemManager
			::get_absolute_path(
				const std::string&
					origin_path
			)
	{
		
	}

    std::string
        FileSystemManager
			::get_relative_path(
				const std::string&
					origin_path,
				const std::string&
					target_path
			)
	{
		
	}

    std::string
        FileSystemManager
			::get_file_extension(
				const std::string&
					origin_path
			)
	{
		
	}

    std::string
        FileSystemManager
			::get_file_stem(
				const std::string&
					origin_path
			)
	{
		
	}

    bool
        FileSystemManager
			::is_path_found(
				const std::string&
					origin_path
			)
	{
		
	}

    bool
        FileSystemManager
			::is_entity(
				const std::string&
					origin_path
			)
	{
		
	}

    bool
        FileSystemManager
			::is_file(
				const std::string&
					origin_path
			)
	{
		
	}

    bool
        FileSystemManager
			::is_folder(
				const std::string&
					origin_path
			)
	{
		
	}

    bool
        FileSystemManager
			::is_entity_user_permission_level_valid(
				const std::string&
					origin_path,
				const std::filesystem::perms&
					permission_level
			)
	{
		
	}

    bool
        FileSystemManager
			::set_entity_read_status(
				const std::string&
					origin_path,
				const bool&
					value
			)
	{
		
	}

    bool
        FileSystemManager
			::set_entity_write_status(
				const std::string&
					origin_path,
				const bool&
					value
			)
	{
		
	}

    bool
        FileSystemManager
			::set_entity_visibility(
				const std::string&
					origin_path,
				const bool&
					value
			)
	{
		
	}

    bool
        FileSystemManager
			::create_folder(
				const std::string&
					origin_path
			)
	{
		
	}

    bool
        FileSystemManager
			::copy_file(
				const std::string&
					origin_path,
				const std::string&
					target_path
			)
	{
		
	}

    bool
        FileSystemManager
			::copy_folder(
				const std::string&
					origin_path,
				const std::string&
					target_path
			)
	{
		
	}

    bool
        FileSystemManager
			::move_entity(
				const std::string&
					origin_path,
				const std::string&
					target_path
			)
	{
		
	}

    bool
        FileSystemManager
			::move_file(
				const std::string&
					origin_path,
				const std::string&
					target_path
			)
	{
		
	}

    bool
        FileSystemManager
			::move_folder(
				const std::string&
					origin_path,
				const std::string&
					target_path
			)
	{
		
	}

    bool
        FileSystemManager
			::rename_entity(
				const std::string&
					origin_path,
				const std::string&
					name
			)
	{
		
	}

    bool
        FileSystemManager
			::rename_file(
				const std::string&
					origin_path,
				const std::string&
					name
			)
	{
		
	}

    bool
        FileSystemManager
			::rename_folder(
				const std::string&
					origin_path,
				const std::string&
					name
			)
	{
		
	}

    bool
        FileSystemManager
			::remove_file(
				const std::string&
					origin_path
			)
	{
		
	}

    bool
        FileSystemManager
			::remove_folder(
				const std::string&
					origin_path
			)
	{
		
	}

    bool
        FileSystemManager
			::remove_folder_sub_files(
				const std::string&
					origin_path
			)
	{
		
	}
}
