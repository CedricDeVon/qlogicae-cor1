#include "pch.hpp"

#include "../includes/file_system_manager_utilities.hpp"

namespace QLogicaeCppCore
{
    std::string
        FileSystemManagerUtilities::relative_private_qlogicae_folder_path =
            ".qlogicae";

    std::string
        FileSystemManagerUtilities::relative_public_qlogicae_folder_path =
            "qlogicae";

    std::string
        FileSystemManagerUtilities::relative_application_name_folder_path =
            "qlogicae";

    std::string
        FileSystemManagerUtilities::relative_application_version_name_folder_path =
            "v1.0.0";

    std::string
        FileSystemManagerUtilities::relative_application_environment_name_folder_path =
            "development";

    std::string
        FileSystemManagerUtilities::relative_log_folder_path =
            "log";

    std::string
        FileSystemManagerUtilities::relative_log_date_folder_path =
            "date";

    std::string
        FileSystemManagerUtilities::relative_log_level_folder_path =
            "level";

    std::string
        FileSystemManagerUtilities::relative_all_log_file_path =
            "all.log";

    std::string
        FileSystemManagerUtilities::relative_info_log_file_path =
            "info.log";

    std::string
        FileSystemManagerUtilities::relative_debug_log_file_path =
            "debug.log";

    std::string
        FileSystemManagerUtilities::relative_warning_log_file_path =
            "warning.log";

    std::string
        FileSystemManagerUtilities::relative_success_log_file_path =
            "success.log";

    std::string
        FileSystemManagerUtilities::relative_critical_log_file_path =
            "critical.log";

    std::string
        FileSystemManagerUtilities::relative_error_log_file_path =
            "error.log";

    std::string
        FileSystemManagerUtilities::relative_cache_folder_path =
            "cache";

    std::string
        FileSystemManagerUtilities::relative_main_folder_path =
            "main";

    std::string
        FileSystemManagerUtilities::relative_assets_folder_path =
            "assets";

    std::string
        FileSystemManagerUtilities::relative_documentation_folder_path =
            "documentation";

    std::string
        FileSystemManagerUtilities::relative_environment_json_file_path =
            "environment.json";

    std::string
        FileSystemManagerUtilities::relative_license_txt_file_path =
            "LICENSE.txt";

    std::string
        FileSystemManagerUtilities::relative_application_folder_path =
            "application";

    std::string
        FileSystemManagerUtilities::relative_application_icon_file_path =
            "application.ico";

    std::string
        FileSystemManagerUtilities::relative_qlogicae_json_file_path =
            "qlogicae.json";

    std::string
        FileSystemManagerUtilities::relative_configurations_folder_path =
            "configurations";

    std::string
        FileSystemManagerUtilities::relative_development_folder_path =
            "development";

    std::string
        FileSystemManagerUtilities::relative_debug_folder_path =
            "debug";

    std::string
        FileSystemManagerUtilities::relative_test_folder_path =
            "test";

    std::string
        FileSystemManagerUtilities::relative_release_folder_path =
            "release";

    std::string
        FileSystemManagerUtilities::relative_windows_registry_software_qlogicae_folder_path =
            "Software\\QLogicae";

    std::string
        FileSystemManagerUtilities::full_executable_folder_path =
            "";

    std::string
        FileSystemManagerUtilities::full_executed_folder_path =
            "";

    std::string
        FileSystemManagerUtilities::full_roaming_app_data_folder_path =
            "";

    std::string
        FileSystemManagerUtilities::full_local_app_data_folder_path =
            "";

    std::string
        FileSystemManagerUtilities::full_program_data_folder_path =
            "";

    std::filesystem::path
        FileSystemManagerUtilities::cache_directory_path;

    DWORD
        FileSystemManagerUtilities::cache_dword_path_length;

    wchar_t
        FileSystemManagerUtilities::cache_wchar_t_buffer[MAX_PATH];


    FileSystemManagerUtilities&
        FileSystemManagerUtilities::singleton =
            SingletonManager::get_singleton<FileSystemManagerUtilities>();

    FileSystemManagerUtilities::FileSystemManagerUtilities()
    {
        _construct();
    }

    FileSystemManagerUtilities::~FileSystemManagerUtilities()
    {
        _destruct();
    }

    bool
        FileSystemManagerUtilities::construct()
    {
        _construct();

        return
            ValueCache::boolean_1;
    }

    void
        FileSystemManagerUtilities::_construct()
    {
        try
        {
            _get_executable_folder_path();
            full_executable_folder_path =
                ValueCache::string_1;

            _get_executed_folder_path();
            full_executed_folder_path =
                ValueCache::string_1;

            _get_roaming_app_data_folder_path();
            full_roaming_app_data_folder_path =
                ValueCache::string_1;

            _get_local_app_data_folder_path();
            full_local_app_data_folder_path =
                ValueCache::string_1;

            _get_program_data_folder_path();
            full_program_data_folder_path =
                ValueCache::string_1;

            std::cout << full_executable_folder_path << "\n";
            std::cout << full_executed_folder_path << "\n";
            std::cout << full_roaming_app_data_folder_path << "\n";
            std::cout << full_local_app_data_folder_path << "\n";
            std::cout << full_program_data_folder_path << "\n";

            ValueCache::boolean_1 =
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

    bool
        FileSystemManagerUtilities::destruct()
    {
        _destruct();

        return
            ValueCache::boolean_1;
    }

    void
        FileSystemManagerUtilities::_destruct()
    {
        try
        {
            ValueCache::boolean_1 =
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

    bool
        FileSystemManagerUtilities::setup(
            const FileSystemManagerConfigurations&
                new_configurations
        )
    {
        FileSystemManagerConfigurations::cache =
            new_configurations;

        _setup();

        return
            ValueCache::boolean_1;
    }

    bool
        FileSystemManagerUtilities::setup()
    {        
        FileSystemManagerConfigurations::cache =
            {};

        _setup();

        return
            ValueCache::boolean_1;
    }

    void
        FileSystemManagerUtilities::_setup()
    {
        try
        {
            ValueCache::boolean_1 =
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

    bool
        FileSystemManagerUtilities::reset()
    {
        _reset();

        return
            ValueCache::boolean_1;
    }

    void
        FileSystemManagerUtilities::_reset()
    {
        try
        {
            ValueCache::boolean_1 =
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

    std::string
        FileSystemManagerUtilities::get_executable_folder_path()
    {
        _get_executable_folder_path();

        return
            ValueCache::string_1;
    }

    void
        FileSystemManagerUtilities::_get_executable_folder_path()
    {
        try
        {            
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
                ValueCache::string_1 =
                    "";

                return;
            }

            cache_directory_path =
                std::filesystem::path(cache_wchar_t_buffer)
                    .parent_path();

            ValueCache::wstring_1 =
                cache_directory_path.wstring();
            
            if (ValueCache::wstring_1.empty())
            {
                ValueCache::string_1 =
                    "";

                return;
            }

            ValueCache::int_1 =
                WideCharToMultiByte(
                    CP_UTF8,
                    0,
                    ValueCache::wstring_1.data(),
                    -1,
                    nullptr,
                    0,
                    nullptr,
                    nullptr
                );

            ValueCache::string_1 = std::string(
                ValueCache::int_1 - 1,
                0
            );

            WideCharToMultiByte(
                CP_UTF8,
                0,
                ValueCache::wstring_1.data(),
                -1,
                ValueCache::string_1.data(),
                ValueCache::int_1,
                nullptr,
                nullptr
            );            
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

    std::string
        FileSystemManagerUtilities::get_executed_folder_path()
    {
        _get_executed_folder_path();

        return
            ValueCache::string_1;
    }

    void
        FileSystemManagerUtilities::_get_executed_folder_path()
    {
        try
        {
            cache_dword_path_length =
                GetCurrentDirectoryA(
                    0,
                    nullptr
                );

            ValueCache::string_1 =
                std::string(
                    cache_dword_path_length,
                    '\0'
                );

            GetCurrentDirectoryA(
                cache_dword_path_length,
                ValueCache::string_1.data()
            );
            
            ValueCache::string_1
                .pop_back();
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

    std::string
        FileSystemManagerUtilities::get_program_data_folder_path()
    {
        _get_program_data_folder_path();

        return
            ValueCache::string_1;
    }

    void
        FileSystemManagerUtilities::_get_program_data_folder_path()
    {
        try
        {
            if (SUCCEEDED(
                SHGetKnownFolderPath(
                    FOLDERID_ProgramData,
                    0,
                    NULL,
                    &ValueCache::wchar_t_pointer_1)
            ))
            {
                ValueCache::wstring_1.assign(
                    ValueCache::wchar_t_pointer_1
                );
                CoTaskMemFree(
                    ValueCache::wchar_t_pointer_1
                );
            }

            ValueCache::int_1 =
                WideCharToMultiByte(
                    CP_UTF8,
                    0,
                    ValueCache::wstring_1.data(),
                    -1,
                    nullptr,
                    0,
                    nullptr,
                    nullptr
                );

            ValueCache::string_1 = std::string(
                ValueCache::int_1,
                0
            );

            WideCharToMultiByte(
                CP_UTF8,
                0,
                ValueCache::wstring_1.data(),
                -1,
                &ValueCache::string_1[0],
                ValueCache::int_1,
                nullptr,
                nullptr
            );
            
            ValueCache::string_1
                .pop_back();
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

    std::string
        FileSystemManagerUtilities::get_local_app_data_folder_path()
    {
        _get_local_app_data_folder_path();

        return
            ValueCache::string_1;
    }

    void
        FileSystemManagerUtilities::_get_local_app_data_folder_path()
    {
        try
        {
            if (SUCCEEDED(SHGetKnownFolderPath(
                FOLDERID_LocalAppData,
                0,
                NULL,
                &ValueCache::wchar_t_pointer_1))
            )
            {
                ValueCache::wstring_1.assign(
                    ValueCache::wchar_t_pointer_1
                );
                CoTaskMemFree(
                    ValueCache::wchar_t_pointer_1
                );
            }

            ValueCache::int_1 =
                WideCharToMultiByte(
                    CP_UTF8,
                    0,
                    ValueCache::wstring_1.data(),
                    -1,
                    nullptr,
                    0,
                    nullptr,
                    nullptr
                );

            ValueCache::string_1 =
                std::string(
                    ValueCache::int_1,
                    0
                );

            WideCharToMultiByte(
                CP_UTF8,
                0,
                ValueCache::wstring_1.data(),
                -1,
                &ValueCache::string_1[0],
                ValueCache::int_1,
                nullptr,
                nullptr
            );

            ValueCache::string_1
                .pop_back();
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

    std::string
        FileSystemManagerUtilities::get_roaming_app_data_folder_path()
    {
        _get_roaming_app_data_folder_path();

        return
            ValueCache::string_1;
    }

    void
        FileSystemManagerUtilities::_get_roaming_app_data_folder_path()
    {
        try
        {
            if (SUCCEEDED(SHGetKnownFolderPath(
                FOLDERID_RoamingAppData,
                0,
                NULL,
                &ValueCache::wchar_t_pointer_1
            )
            ))
            {
                ValueCache::wstring_1.assign(
                    ValueCache::wchar_t_pointer_1
                );
                
                CoTaskMemFree(
                    ValueCache::wchar_t_pointer_1
                );
            }

            ValueCache::int_1 =
                WideCharToMultiByte(
                    CP_UTF8,
                    0,
                    ValueCache::wstring_1.data(),
                    -1,
                    nullptr,
                    0,
                    nullptr,
                    nullptr
                );

            ValueCache::string_1 = std::string(
                ValueCache::int_1,
                0
            );

            WideCharToMultiByte(
                CP_UTF8,
                0,
                ValueCache::wstring_1.data(),
                -1,
                &ValueCache::string_1[0],
                ValueCache::int_1,
                nullptr,
                nullptr
            );

            ValueCache::string_1
                .pop_back();
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
}
