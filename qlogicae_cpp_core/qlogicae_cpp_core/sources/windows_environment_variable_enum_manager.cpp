#include "pch.hpp"

#include "../includes/windows_environment_variable_enum_manager.hpp"

namespace
	QLogicaeCppCore
{        
	WindowsEnvironmentVariableEnumManager&
		WindowsEnvironmentVariableEnumManager
			::singleton = 
				SingletonManager
					::get_singleton<WindowsEnvironmentVariableEnumManager>();	


	
	WindowsEnvironmentVariableEnumManager
		::WindowsEnvironmentVariableEnumManager() :
			AbstractClass<WindowsEnvironmentVariableEnumManagerConfigurations>()
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

    WindowsEnvironmentVariableEnumManager
		::~WindowsEnvironmentVariableEnumManager()
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
        WindowsEnvironmentVariableEnumManager
			::construct()
    {
        try
        {			
			if
			(
				configurations
					.is_runtime_execution_disabled_for_utility_handling()
			)
			{
				return
					false;
			}

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
        WindowsEnvironmentVariableEnumManager
			::destruct()
    {
        try
        {		
			if
			(
				configurations
					.is_runtime_execution_disabled_for_utility_handling()
			)
			{
				return
					false;
			}

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
		WindowsEnvironmentVariableEnumManager
			::convert_enum_to_string(
				const WindowsEnvironmentVariable&
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
				case (WindowsEnvironmentVariable::USER):
				{
					return
						"USER";
				}
				case (WindowsEnvironmentVariable::SYSTEM):
				{
					return
						"SYSTEM";
				}
				case (WindowsEnvironmentVariable::NONE):
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
		WindowsEnvironmentVariableEnumManager
			::convert_enum_to_string()
	{
		return
			convert_enum_to_string(
				configurations
					.type
			);
	}

	WindowsEnvironmentVariable
		WindowsEnvironmentVariableEnumManager
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
					WindowsEnvironmentVariable
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
				value == "USER"
			)
			{
				return
					WindowsEnvironmentVariable
						::USER;
			}
			else if
			(
				value == "SYSTEM"
			)
			{
				return
					WindowsEnvironmentVariable
						::SYSTEM;
			}		
			else if
			(
				value == "NONE"
			)
			{
				return
					WindowsEnvironmentVariable
						::NONE;
			}
			else
			{
				return
					WindowsEnvironmentVariable
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
				WindowsEnvironmentVariable
					::NONE;
        }
	}

	WindowsEnvironmentVariable
		WindowsEnvironmentVariableEnumManager
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
