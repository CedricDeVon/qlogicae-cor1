#include "pch.hpp"

#include "../includes/utilities_cache.hpp"

namespace QLogicaeCppCore
{
    UtilitiesCache&
        UtilitiesCache::instance =
            InstanceManager::instance
                .get_instance<UtilitiesCache>();

    UtilitiesCache::UtilitiesCache()
    {
        _construct();
    }

    UtilitiesCache::~UtilitiesCache()
    {
        _destruct();
    }

    bool
        UtilitiesCache::construct()
    {
        _construct();

        return ValueCache::boolean_1;
    }

    void
        UtilitiesCache::_construct()
    {
        try
        {
            full_executable_folder_path;

            full_executed_folder_path;

            full_roaming_app_data_folder_path;

            full_local_app_data_folder_path;

            full_program_data_folder_path;

            ValueCache::boolean_1 =
                true;
        }
        catch (...)
        {
            ValueCache::boolean_1 =
                false;
        }
    }

    bool
        UtilitiesCache::destruct()
    {
        _destruct();

        return ValueCache::boolean_1;
    }

    void
        UtilitiesCache::_destruct()
    {
        try
        {
            ValueCache::boolean_1 =
                true;
        }
        catch (...)
        {
            ValueCache::boolean_1 =
                false;
        }
    }

    bool
        UtilitiesCache::setup()
    {        
        _setup();

        return ValueCache::boolean_1;
    }

    void
        UtilitiesCache::_setup()
    {
        try
        {
            ValueCache::boolean_1 =
                true;
        }
        catch (...)
        {
            ValueCache::boolean_1 =
                false;
        }
    }

    bool
        UtilitiesCache::reset()
    {
        _reset();

        return ValueCache::boolean_1;
    }

    void
        UtilitiesCache::_reset()
    {
        try
        {
            ValueCache::boolean_1 =
                true;
        }
        catch (...)
        {
            ValueCache::boolean_1 =
                false;
        }
    }

    std::string
        UtilitiesCache::get_executable_folder_path()
    {
        _get_executable_folder_path();

        return ValueCache::string_1;
    }

    void
        UtilitiesCache::_get_executable_folder_path()
    {
        try
        {
            /*
            wchar_t buffer[MAX_PATH];
            DWORD length = GetModuleFileNameW(
                nullptr,
                buffer,
                MAX_PATH
            );
            if (length == 0 ||
                length == MAX_PATH
                )
            {
                return {};
            }

            std::filesystem::path dir =
                std::filesystem::path(buffer)
                .parent_path();
            const std::wstring& wstr =
                dir.wstring();
            if (wstr.empty())
            {
                return {};
            }

            int size_needed =
                WideCharToMultiByte(
                    CP_UTF8,
                    0,
                    wstr.data(),
                    -1,
                    nullptr,
                    0,
                    nullptr,
                    nullptr
                );
            std::string result(
                size_needed - 1,
                0
            );
            WideCharToMultiByte(
                CP_UTF8,
                0,
                wstr.data(),
                -1,
                result.data(),
                size_needed,
                nullptr,
                nullptr
            );
            */

        }
        catch (...)
        {
            ValueCache::string_1 = "";
        }
    }

    std::string
        UtilitiesCache::get_executed_folder_path()
    {
        _get_executed_folder_path();

        return ValueCache::string_1;
    }

    void
        UtilitiesCache::_get_executed_folder_path()
    {
        try
        {
            ValueCache::string_1 =
                std::filesystem::current_path()
                    .string();
        }
        catch (...)
        {
            ValueCache::string_1 = "";
        }
    }

    std::string
        UtilitiesCache::get_program_data_folder_path()
    {
        _get_program_data_folder_path();

        return ValueCache::string_1;
    }

    void
        UtilitiesCache::_get_program_data_folder_path()
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
                ValueCache::wstring_1.assign(ValueCache::wchar_t_pointer_1);
                CoTaskMemFree(ValueCache::wchar_t_pointer_1);
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
        catch (...)
        {
            ValueCache::string_1 = "";
        }
    }

    std::string
        UtilitiesCache::get_local_app_data_folder_path()
    {
        _get_local_app_data_folder_path();

        return ValueCache::string_1;
    }

    void
        UtilitiesCache::_get_local_app_data_folder_path()
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
                ValueCache::wstring_1.assign(ValueCache::wchar_t_pointer_1);
                CoTaskMemFree(ValueCache::wchar_t_pointer_1);
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
        catch (...)
        {
            ValueCache::string_1 = "";
        }
    }

    std::string
        UtilitiesCache::get_roaming_app_data_folder_path()
    {
        _get_roaming_app_data_folder_path();

        return ValueCache::string_1;
    }

    void
        UtilitiesCache::_get_roaming_app_data_folder_path()
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
                ValueCache::wstring_1.assign(ValueCache::wchar_t_pointer_1);
                CoTaskMemFree(ValueCache::wchar_t_pointer_1);
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
        catch (...)
        {
            ValueCache::string_1 = "";
        }
    }
}
