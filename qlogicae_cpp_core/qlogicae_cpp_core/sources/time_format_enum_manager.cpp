#include "pch.hpp"

#include "../includes/time_format_enum_manager.hpp"

namespace
	QLogicae::Cor::V1
{        
	TimeFormatEnumManager
		::TimeFormatEnumManager() :
			AbstractClass<TimeFormatEnumManagerConfigurations>()
    {
        
    }

	std::string
		TimeFormatEnumManager
			::convert_enum_to_string(
				const TimeFormat&
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
				case (TimeFormat::UNIX):
				{
					return
						"UNIX";
				}
				case (TimeFormat::ISO8601):
				{
					return
						"ISO8601";
				}
				case (TimeFormat::SECOND_LEVEL_TIMESTAMP):
				{
					return
						"SECOND_LEVEL_TIMESTAMP";
				}
				case (TimeFormat::MILLISECOND_LEVEL_TIMESTAMP):
				{
					return
						"MILLISECOND_LEVEL_TIMESTAMP";
				}
				case (TimeFormat::MICROSECOND_LEVEL_TIMESTAMP):
				{
					return
						"MICROSECOND_LEVEL_TIMESTAMP";
				}
				case (TimeFormat::FULL_TIMESTAMP):
				{
					return
						"FULL_TIMESTAMP";
				}
				case (TimeFormat::FULL_DASHED_TIMESTAMP):
				{
					return
						"FULL_DASHED_TIMESTAMP";
				}
				case (TimeFormat::HOUR_12):
				{
					return
						"HOUR_12";
				}
				case (TimeFormat::HOUR_24):
				{
					return
						"HOUR_24";
				}
				case (TimeFormat::MILLISECOND_MICROSECOND_NANOSECOND):
				{
					return
						"MILLISECOND_MICROSECOND_NANOSECOND";
				}
				case (TimeFormat::DATE_DASHED):
				{
					return
						"DATE_DASHED";
				}
				case (TimeFormat::DATE_MDY_SLASHED):
				{
					return
						"DATE_MDY_SLASHED";
				}
				case (TimeFormat::DATE_DMY_SLASHED):
				{
					return
						"DATE_DMY_SLASHED";
				}
				case (TimeFormat::DATE_DMY_SPACED):
				{
					return
						"DATE_DMY_SPACED";
				}
				case (TimeFormat::DATE_VERBOSE):
				{
					return
						"DATE_VERBOSE";
				}
				case (TimeFormat::NONE):
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
		TimeFormatEnumManager
			::convert_enum_to_string()
	{
		return
			convert_enum_to_string(
				configurations
					.type
			);
	}

	TimeFormat
		TimeFormatEnumManager
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
					TimeFormat
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
				value == "UNIX"
			)
			{
				return
					TimeFormat
						::UNIX;
			}
			else if
			(
				value == "ISO8601"
			)
			{
				return
					TimeFormat
						::ISO8601;
			}	
			else if
			(
				value == "SECOND_LEVEL_TIMESTAMP"
			)
			{
				return
					TimeFormat
						::SECOND_LEVEL_TIMESTAMP;
			}
			else if
			(
				value == "MILLISECOND_LEVEL_TIMESTAMP"
			)
			{
				return
					TimeFormat
						::MILLISECOND_LEVEL_TIMESTAMP;
			}	
			else if
			(
				value == "MICROSECOND_LEVEL_TIMESTAMP"
			)
			{
				return
					TimeFormat
						::MICROSECOND_LEVEL_TIMESTAMP;
			}
			else if
			(
				value == "FULL_TIMESTAMP"
			)
			{
				return
					TimeFormat
						::FULL_TIMESTAMP;
			}	
			else if
			(
				value == "FULL_DASHED_TIMESTAMP"
			)
			{
				return
					TimeFormat
						::FULL_DASHED_TIMESTAMP;
			}
			else if
			(
				value == "HOUR_12"
			)
			{
				return
					TimeFormat
						::HOUR_12;
			}	
			else if
			(
				value == "HOUR_24"
			)
			{
				return
					TimeFormat
						::HOUR_24;
			}
			else if
			(
				value == "MILLISECOND_MICROSECOND_NANOSECOND"
			)
			{
				return
					TimeFormat
						::MILLISECOND_MICROSECOND_NANOSECOND;
			}	
			else if
			(
				value == "DATE_DASHED"
			)
			{
				return
					TimeFormat
						::DATE_DASHED;
			}
			else if
			(
				value == "DATE_MDY_SLASHED"
			)
			{
				return
					TimeFormat
						::DATE_MDY_SLASHED;
			}	
			else if
			(
				value == "DATE_DMY_SLASHED"
			)
			{
				return
					TimeFormat
						::DATE_DMY_SLASHED;
			}
			else if
			(
				value == "DATE_DMY_SPACED"
			)
			{
				return
					TimeFormat
						::DATE_DMY_SPACED;
			}
			else if
			(
				value == "DATE_VERBOSE"
			)
			{
				return
					TimeFormat
						::DATE_VERBOSE;
			}
			else if
			(
				value == "NONE"
			)
			{
				return
					TimeFormat
						::NONE;
			}
			else
			{
				return
					TimeFormat
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
				TimeFormat
					::NONE;
        }
	}

	TimeFormat
		TimeFormatEnumManager
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
