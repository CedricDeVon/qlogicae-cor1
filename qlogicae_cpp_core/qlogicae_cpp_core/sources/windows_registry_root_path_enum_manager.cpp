#include "pch.hpp"

#include "../includes/windows_registry_root_path_enum_manager.hpp"

namespace
	QLogicae::Cor::V1
{        	
	WindowsRegistryRootPathEnumManager
		::WindowsRegistryRootPathEnumManager() :
			AbstractClass<WindowsRegistryRootPathEnumManagerConfigurations>()
    {
        
    }

	std::string
		WindowsRegistryRootPathEnumManager
			::convert_enum_to_string(
				const WindowsRegistryRootPath&
					value
			)
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
					"NONE";
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

			switch (value)
			{
				case (WindowsRegistryRootPath::HKCU):
				{
					return
						"HKCU";
				}
				case (WindowsRegistryRootPath::HKLM):
				{
					return
						"HKLM";
				}
				case (WindowsRegistryRootPath::NONE):
				{
					return
						"NONE";
				}				
				default:
				{
					return
						"NONE";
				}
			}
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
				"NONE";
        }
	}

	std::string
		WindowsRegistryRootPathEnumManager
			::convert_enum_to_string()
	{
		return
			convert_enum_to_string(
				configurations
					.type
			);
	}

	WindowsRegistryRootPath
		WindowsRegistryRootPathEnumManager
			::convert_string_to_enum(
				const std::string&
					value
			)
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
					WindowsRegistryRootPath
						::NONE;
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

			if
			(
				value == "HKCU"
			)
			{
				return
					WindowsRegistryRootPath
						::HKCU;
			}
			else if
			(
				value == "HKLM"
			)
			{
				return
					WindowsRegistryRootPath
						::HKLM;
			}	
			else if
			(
				value == "NONE"
			)
			{
				return
					WindowsRegistryRootPath
						::NONE;
			}
			else
			{
				return
					WindowsRegistryRootPath
						::NONE;
			}
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
				WindowsRegistryRootPath
					::NONE;
        }
	}

	WindowsRegistryRootPath
		WindowsRegistryRootPathEnumManager
			::convert_string_to_enum()
	{
		return
			convert_string_to_enum(
				convert_enum_to_string(
					configurations
						.type
				)
			);
	}
}
