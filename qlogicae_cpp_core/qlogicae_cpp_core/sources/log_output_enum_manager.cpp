#include "pch.hpp"

#include "../includes/log_output_enum_manager.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{        	
	LogOutputEnumManager
		::LogOutputEnumManager() :
			AbstractClass<LogOutputEnumManagerConfigurations>()
    {
        
    }

	std::string
		LogOutputEnumManager
			::convert_enum_to_string(
				const LogOutput&
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
				case (LogOutput::ALL):
				{
					return
						"ALL";
				}
				case (LogOutput::FOREGROUND):
				{
					return
						"FOREGROUND";
				}
				case (LogOutput::BACKGROUND):
				{
					return
						"BACKGROUND";
				}
				case (LogOutput::NONE):
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
		LogOutputEnumManager
			::convert_enum_to_string()
	{
		return
			convert_enum_to_string(
				configurations
					.type
			);
	}

	LogOutput
		LogOutputEnumManager
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
					LogOutput
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
					LogOutput
						::ALL;
			}
			else if
			(
				value == "FOREGROUND"
			)
			{
				return
					LogOutput
						::FOREGROUND;
			}
			else if
			(
				value == "BACKGROUND"
			)
			{
				return
					LogOutput
						::BACKGROUND;
			}			
			else if
			(
				value == "NONE"
			)
			{
				return
					LogOutput
						::NONE;
			}
			else
			{
				return
					LogOutput
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
				LogOutput
					::NONE;
        }
	}

	LogOutput
		LogOutputEnumManager
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
