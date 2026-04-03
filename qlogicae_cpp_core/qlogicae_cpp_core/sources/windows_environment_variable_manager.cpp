#include "pch.hpp"

#include "../includes/windows_environment_variable_manager.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{	
    WindowsEnvironmentVariableManager
		::WindowsEnvironmentVariableManager() :
			AbstractClass<WindowsEnvironmentVariableManagerConfigurations>()
	{
			
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
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling() ||				
				(
					configurations
						.is_edge_case_enabled_for_feature_handling() &&
					(
						key.empty()
					)
				)
			)
			{
				return
					L"";
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
            QLOGICAE_COR_V1__BASE__HPP_CPP__TRY_CATCH_EXCEPTION_PARAMETER
        )
        {
			QLOGICAE_COR_V1__IMPLICIT__HPP_CPP__CATCH_CODE_TEMPLATE();
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
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling() ||				
				(
					configurations
						.is_edge_case_enabled_for_feature_handling() &&
					(
						key.empty() ||
						value.empty()
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

			return
				SetEnvironmentVariableW(
					key.c_str(),
					value.c_str()
				) != 0;
        }
        catch
        (
            QLOGICAE_COR_V1__BASE__HPP_CPP__TRY_CATCH_EXCEPTION_PARAMETER
        )
        {
			QLOGICAE_COR_V1__IMPLICIT__HPP_CPP__CATCH_CODE_TEMPLATE();
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
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling() ||				
				(
					configurations
						.is_edge_case_enabled_for_feature_handling() &&
					(
						key.empty()
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

			return
				SetEnvironmentVariableW(
					key.c_str(),
					nullptr
				) != 0;
        }
        catch
        (
            QLOGICAE_COR_V1__BASE__HPP_CPP__TRY_CATCH_EXCEPTION_PARAMETER
        )
        {
			QLOGICAE_COR_V1__IMPLICIT__HPP_CPP__CATCH_CODE_TEMPLATE();
        }
	}

	std::string
		WindowsEnvironmentVariableManager
			::get_value(
				const std::string&
					key
			)
	{
		return
			SingletonManager::get_singleton<TextManager>().convert_text<std::wstring, std::string>(
				get_value(
					SingletonManager::get_singleton<TextManager>().convert_text<std::string, std::wstring>(
						key
					)
				)
			);
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
		return
			set_value(
				SingletonManager::get_singleton<TextManager>().convert_text<std::string, std::wstring>(
					key
				),
				SingletonManager::get_singleton<TextManager>().convert_text<std::string, std::wstring>(
					value
				)
			);
	}

	bool
		WindowsEnvironmentVariableManager
			::remove_value(
				const std::string&
					key
			)
	{
		return
			remove_value(
				SingletonManager::get_singleton<TextManager>().convert_text<std::string, std::wstring>(
					key
				)
			);
	}
}
