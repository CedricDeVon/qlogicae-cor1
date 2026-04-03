#include "pch.hpp"

#include "../includes/log_format_enum_manager.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{        	
	LogFormatEnumManager
		::LogFormatEnumManager() :
			AbstractClass<LogFormatEnumManagerConfigurations>()
    {
        
    }

	std::string
		LogFormatEnumManager
			::convert_enum_to_string(
				const LogFormat&
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
				case (LogFormat::STANDARD):
				{
					return
						"STANDARD";
				}
				case (LogFormat::CUSTOM):
				{
					return
						"CUSTOM";
				}
				case (LogFormat::NONE):
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
		LogFormatEnumManager
			::convert_enum_to_string()
	{
		return
			convert_enum_to_string(
				configurations
					.type
			);
	}

	LogFormat
		LogFormatEnumManager
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
					LogFormat
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
				value == "STANDARD"
			)
			{
				return
					LogFormat
						::STANDARD;
			}	
			else if
			(
				value == "CUSTOM"
			)
			{
				return
					LogFormat
						::CUSTOM;
			}
						
			else if
			(
				value == "NONE"
			)
			{
				return
					LogFormat
						::NONE;
			}
			else
			{
				return
					LogFormat
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
				LogFormat::NONE
			);
        }
	}

	LogFormat
		LogFormatEnumManager
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


