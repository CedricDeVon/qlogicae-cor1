#include "pch.hpp"

#include "../includes/windows_environment_variable_manager.hpp"

namespace
	QLogicaeCppCore
{
	WindowsEnvironmentVariableManager&
        WindowsEnvironmentVariableManager
			::singleton =
				SingletonManager
					::get_singleton<WindowsEnvironmentVariableManager>();



    WindowsEnvironmentVariableManager
		::WindowsEnvironmentVariableManager() :
			AbstractClass<WindowsEnvironmentVariableManagerConfigurations>()
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

	WindowsEnvironmentVariableManager
		::~WindowsEnvironmentVariableManager()
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
        WindowsEnvironmentVariableManager
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
        WindowsEnvironmentVariableManager
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
		WindowsEnvironmentVariableManager
			::get_value(
				const std::wstring&
					key
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

			if (key.empty())
			{
				return L"";
			}

			DWORD size = GetEnvironmentVariableW(key.c_str(), nullptr, 0);
			if (size == 0)
			{
				return L"";
			}

			std::wstring result(size - 1, L'\0');
			if (GetEnvironmentVariableW(key.c_str(), &result[0], size) == 0)
			{
				return L"";
			}

			return result;
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
		WindowsEnvironmentVariableManager
			::set_value(
				const std::wstring&
					key,
				const std::wstring&
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

			return
				(key.empty() || value.empty()) ?
					false :
					SetEnvironmentVariableW(
						key.c_str(),
						value.c_str()
					) != 0;
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
		WindowsEnvironmentVariableManager
			::remove_value(
				const std::wstring&
					key
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
				(key.empty()) ?
					false :
					SetEnvironmentVariableW(
						key.c_str(),
						nullptr
					) != 0;
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
		WindowsEnvironmentVariableManager
			::get_value(
				const std::string&
					key
			)
	{
		try
        {					
			return
				TextManager::singleton.convert_text<std::wstring, std::string>(
					get_value(
						TextManager::singleton.convert_text<std::string, std::wstring>(
							key
						)
					)
				);
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

	bool
		WindowsEnvironmentVariableManager
			::set_value(
				const std::string&
					key,
				const std::string&
					value
			)
	{
		try
        {		
			return
				set_value(
					TextManager::singleton.convert_text<std::string, std::wstring>(
						key
					),
					TextManager::singleton.convert_text<std::string, std::wstring>(
						value
					)
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
		WindowsEnvironmentVariableManager
			::remove_value(
				const std::string&
					key
			)
	{
		try
        {		
			return
				remove_value(
					TextManager::singleton.convert_text<std::string, std::wstring>(
						key
					)
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
}
