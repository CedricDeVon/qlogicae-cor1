#include "pch.hpp"

#include "../includes/log_medium_enum_manager.hpp"

namespace
	QLogicaeCppCore
{        
	LogMediumEnumManager&
		LogMediumEnumManager
			::singleton = 
				SingletonManager
					::get_singleton<LogMediumEnumManager>();	


	
	LogMediumEnumManager
		::LogMediumEnumManager() :
			AbstractClass<LogMediumEnumManagerConfigurations>()
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

    LogMediumEnumManager
		::~LogMediumEnumManager()
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
        LogMediumEnumManager
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
        LogMediumEnumManager
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
		LogMediumEnumManager
			::convert_enum_to_string(
				const LogMedium&
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
				case (LogMedium::ALL):
				{
					return
						"ALL";
				}
				case (LogMedium::FILE):
				{
					return
						"FILE";
				}
				case (LogMedium::CONSOLE):
				{
					return
						"CONSOLE";
				}
				case (LogMedium::NONE):
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
		LogMediumEnumManager
			::convert_enum_to_string()
	{
		return
			convert_enum_to_string(
				configurations
					.type
			);
	}

	LogMedium
		LogMediumEnumManager
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
					LogMedium
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
				value == "ALL"
			)
			{
				return
					LogMedium
						::ALL;
			}
			else if
			(
				value == "FILE"
			)
			{
				return
					LogMedium
						::FILE;
			}
			else if
			(
				value == "CONSOLE"
			)
			{
				return
					LogMedium
						::CONSOLE;
			}			
			else if
			(
				value == "NONE"
			)
			{
				return
					LogMedium
						::NONE;
			}
			else
			{
				return
					LogMedium
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
				LogMedium
					::NONE;
        }
	}

	LogMedium
		LogMediumEnumManager
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
