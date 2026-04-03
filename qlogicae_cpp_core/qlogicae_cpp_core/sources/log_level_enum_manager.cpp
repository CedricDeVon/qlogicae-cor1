#include "pch.hpp"

#include "../includes/log_level_enum_manager.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{        	
	LogLevelEnumManager
		::LogLevelEnumManager() :
			AbstractClass<LogLevelEnumManagerConfigurations>()
    {
        
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
            QLOGICAE_COR_V1__BASE__HPP_CPP__TRY_CATCH_EXCEPTION_PARAMETER
        )
        {		
			QLOGICAE_COR_V1__EXPLICIT__HPP_CPP__CATCH_CODE_TEMPLATE
			(
				LogLevel::NONE
			);
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
