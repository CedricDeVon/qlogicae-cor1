#include "pch.hpp"

#include "../includes/log_level_enum_manager.hpp"

namespace
	QLogicaeCppCore
{        
	LogLevelEnumManager&
		LogLevelEnumManager
			::singleton = 
				SingletonManager
					::get_singleton<LogLevelEnumManager>();	


	
	LogLevelEnumManager
		::LogLevelEnumManager() :
			AbstractClass<LogLevelEnumManagerConfigurations>()
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

    LogLevelEnumManager
		::~LogLevelEnumManager()
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
        LogLevelEnumManager
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
        LogLevelEnumManager
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
		LogLevelEnumManager
			::convert_enum_to_string(
				const LogLevel&
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
				case (LogLevel::ALL):
				{
					return
						"ALL";
				}
				case (LogLevel::INFO):
				{
					return
						"INFO";
				}
				case (LogLevel::DEBUG):
				{
					return
						"DEBUG";
				}
				case (LogLevel::WARNING):
				{
					return
						"WARNING";
				}
				case (LogLevel::SUCCESS):
				{
					return
						"SUCCESS";
				}
				case (LogLevel::CRITICAL):
				{
					return
						"CRITICAL";
				}			
				case (LogLevel::ERROR_TYPE):
				{
					return
						"ERROR_TYPE";
				}
				case (LogLevel::HIGHLIGHTED_INFO):
				{
					return
						"HIGHLIGHTED_INFO";
				}
				case (LogLevel::NONE):
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
		LogLevelEnumManager
			::convert_enum_to_string()
	{
		return
			convert_enum_to_string(
				configurations
					.type
			);
	}

	LogLevel
		LogLevelEnumManager
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
					LogLevel
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
					LogLevel
						::ALL;
			}
			else if
			(
				value == "INFO"
			)
			{
				return
					LogLevel
						::INFO;
			}			
			else if
			(
				value == "DEBUG"
			)
			{
				return
					LogLevel
						::DEBUG;
			}
			else if
			(
				value == "WARNING"
			)
			{
				return
					LogLevel
						::WARNING;
			}			
			else if
			(
				value == "SUCCESS"
			)
			{
				return
					LogLevel
						::SUCCESS;
			}
			else if
			(
				value == "CRITICAL"
			)
			{
				return
					LogLevel
						::CRITICAL;
			}			
			else if
			(
				value == "ERROR_TYPE"
			)
			{
				return
					LogLevel
						::ERROR_TYPE;
			}
			else if
			(
				value == "HIGHLIGHTED_INFO"
			)
			{
				return
					LogLevel
						::HIGHLIGHTED_INFO;
			}			
			else
			{
				return
					LogLevel
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
				LogLevel
					::NONE;
        }
	}

	LogLevel
		LogLevelEnumManager
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
