#include "pch.hpp"

#include "../includes/windows_system_access_manager.hpp"

namespace
	QLogicaeCppCore
{
	WindowsSystemAccessManager&
        WindowsSystemAccessManager
			::singleton =
				SingletonManager
					::get_singleton<WindowsSystemAccessManager>();



    WindowsSystemAccessManager
		::WindowsSystemAccessManager() :
			AbstractClass<WindowsSystemAccessManagerConfigurations>()
	{
		
	}

	bool
		WindowsSystemAccessManager
			::run_process(
				const std::string&
					command
			)
	{
		try
        {		
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling() ||				
				(
					configurations
						.is_edge_case_enabled_for_feature_handling() &&
					(
						command.empty()
					)
				)
			)
			{
				return
					false;
			}

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

			STARTUPINFOA startup_info{};
			PROCESS_INFORMATION process_info{};
			startup_info.cb = sizeof(STARTUPINFOA);
			startup_info.dwFlags = STARTF_USESHOWWINDOW;
			startup_info.wShowWindow = SW_HIDE;

			std::string full_cmd =
				absl::StrCat("cmd.exe /c \"", command, "\"");

			BOOL created = CreateProcessA(
				NULL,
				const_cast<LPSTR>(full_cmd.c_str()),
				NULL,
				NULL,
				FALSE,
				CREATE_NO_WINDOW,
				NULL,
				NULL,
				&startup_info,
				&process_info
			);

			if (created == FALSE)
			{
				return
					false;
			}

			CloseHandle(process_info.hThread);
			CloseHandle(process_info.hProcess);

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
		WindowsSystemAccessManager
			::has_admin_access()
	{
		try
        {		
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling()
			)
			{
				return
					false;
			}

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

			BOOL is_admin = FALSE;
			PSID administrators_group = nullptr;
			SID_IDENTIFIER_AUTHORITY nt_authority = SECURITY_NT_AUTHORITY;

			if (AllocateAndInitializeSid(
				&nt_authority,
				2,
				SECURITY_BUILTIN_DOMAIN_RID,
				DOMAIN_ALIAS_RID_ADMINS,
				0, 0, 0, 0, 0, 0,
				&administrators_group))
			{
				CheckTokenMembership(
					nullptr,
					administrators_group,
					&is_admin
				);
				FreeSid(administrators_group);
			}

			return
				is_admin == TRUE;
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
		WindowsSystemAccessManager
			::restart_with_admin_access()
	{
		try
        {		
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling()
			)
			{
				return
					false;
			}

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

			wchar_t file_path[MAX_PATH];
			if (::GetEnvironmentVariableW(
				L"VSAPPIDDIR",
				nullptr,
				0
			) > 0 ||
				GetModuleFileNameW(
					nullptr,
					file_path,
					MAX_PATH
				) == 0)
			{
				ExitProcess(1);
				return
					false;
			}

			SHELLEXECUTEINFOW sei = { sizeof(sei) };
			sei.lpVerb = L"runas";
			sei.lpFile = file_path;
			sei.hwnd = nullptr;
			sei.nShow = SW_SHOWNORMAL;

			ShellExecuteExW(&sei);
			ExitProcess(0);

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
}

