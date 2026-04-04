#include "pch.hpp"

#include "../includes/windows_registry_root_path_enum_manager.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
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
			QLOGICAE_COR_V1__EXPLICIT__HPP_CPP__PRE_EXECUTION_GUARD_TEMPLATE
			(
				"NONE",
				QLOGICAE_COR_V1__BASE__HPP_CPP__MUTEX_LAYER_1,
				QLOGICAE_COR_V1__BASE__HPP_CPP__EMPTY_EDGE_CASES
			);			

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
            QLOGICAE_COR_V1__BASE__HPP_CPP__TRY_CATCH_EXCEPTION_PARAMETER
        )
        {	
			QLOGICAE_COR_V1__EXPLICIT__HPP_CPP__CATCH_CODE_TEMPLATE
			(
				"NONE"
			);
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
			QLOGICAE_COR_V1__EXPLICIT__HPP_CPP__PRE_EXECUTION_GUARD_TEMPLATE
			(
				WindowsRegistryRootPath::NONE,
				QLOGICAE_COR_V1__BASE__HPP_CPP__MUTEX_LAYER_1,
				QLOGICAE_COR_V1__BASE__HPP_CPP__EMPTY_EDGE_CASES
			);

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
            QLOGICAE_COR_V1__BASE__HPP_CPP__TRY_CATCH_EXCEPTION_PARAMETER
        )
        {		
			QLOGICAE_COR_V1__EXPLICIT__HPP_CPP__CATCH_CODE_TEMPLATE
			(
				WindowsRegistryRootPath::NONE
			);			
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

