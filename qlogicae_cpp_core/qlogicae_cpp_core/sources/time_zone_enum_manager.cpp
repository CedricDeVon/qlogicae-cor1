#include "pch.hpp"

#include "../includes/time_zone_enum_manager.hpp"

namespace
	QLogicae::Cor::V1
{        	
	TimeZoneEnumManager
		::TimeZoneEnumManager() :
			AbstractClass<TimeZoneEnumManagerConfigurations>()
    {
        
    }

	std::string
		TimeZoneEnumManager
			::convert_enum_to_string(
				const TimeZone&
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
				case (TimeZone::UTC):
				{
					return
						"UTC";
				}
				case (TimeZone::LOCAL):
				{
					return
						"LOCAL";
				}
				case (TimeZone::NONE):
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
		TimeZoneEnumManager
			::convert_enum_to_string()
	{
		return
			convert_enum_to_string(
				configurations
					.type
			);
	}

	TimeZone
		TimeZoneEnumManager
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
					TimeZone
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
				value == "UTC"
			)
			{
				return
					TimeZone
						::UTC;
			}
			else if
			(
				value == "LOCAL"
			)
			{
				return
					TimeZone
						::LOCAL;
			}	
			else if
			(
				value == "NONE"
			)
			{
				return
					TimeZone
						::NONE;
			}
			else
			{
				return
					TimeZone
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
				TimeZone
					::NONE;
        }
	}

	TimeZone
		TimeZoneEnumManager
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
