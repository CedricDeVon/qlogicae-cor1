#include "pch.hpp"

#include "../includes/results_status_enum_manager.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{        	
	ResultsStatusEnumManager
		::ResultsStatusEnumManager() :
			AbstractClass<ResultsStatusEnumManagerConfigurations>()
    {

	}        

	std::string
		ResultsStatusEnumManager
			::convert_enum_to_string(
				const ResultsStatus&
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
				case (ResultsStatus::GOOD):
				{
					return
						"GOOD";
				}
				case (ResultsStatus::BAD):
				{
					return
						"BAD";
				}
				case (ResultsStatus::INFO):
				{
					return
						"INFO";
				}
				case (ResultsStatus::DEBUG):
				{
					return
						"DEBUG";
				}
				case (ResultsStatus::WARNING):
				{
					return
						"WARNING";
				}
				case (ResultsStatus::EXCEPTION):
				{
					return
						"EXCEPTION";
				}
				case (ResultsStatus::ERROR_TYPE):
				{
					return
						"ERROR_TYPE";
				}
				case (ResultsStatus::NONE):
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
		ResultsStatusEnumManager
			::convert_enum_to_string()
	{
		return
			convert_enum_to_string(
				configurations
					.type
			);
	}

	ResultsStatus
		ResultsStatusEnumManager
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
					ResultsStatus
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
				value == "GOOD"
			)
			{
				return
					ResultsStatus
						::GOOD;
			}
			else if
			(
				value == "BAD"
			)
			{
				return
					ResultsStatus
						::BAD;
			}
			else if
			(
				value == "INFO"
			)
			{
				return
					ResultsStatus
						::INFO;
			}			
			else if
			(
				value == "DEBUG"
			)
			{
				return
					ResultsStatus
						::DEBUG;
			}
			else if
			(
				value == "WARNING"
			)
			{
				return
					ResultsStatus
						::WARNING;
			}
			else if
			(
				value == "EXCEPTION"
			)
			{
				return
					ResultsStatus
						::EXCEPTION;
			}			
			else if
			(
				value == "ERROR_TYPE"
			)
			{
				return
					ResultsStatus
						::ERROR_TYPE;
			}
			else if
			(
				value == "NONE"
			)
			{
				return
					ResultsStatus
						::NONE;
			}
			else
			{
				return
					ResultsStatus
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
				ResultsStatus
					::NONE;
        }
	}

	ResultsStatus
		ResultsStatusEnumManager
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
