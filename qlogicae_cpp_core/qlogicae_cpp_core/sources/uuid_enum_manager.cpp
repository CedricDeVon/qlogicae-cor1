#include "pch.hpp"

#include "../includes/uuid_enum_manager.hpp"

namespace
	QLogicae::Cor::V1
{        	
	UuidEnumManager
		::UuidEnumManager() :
			AbstractClass<UuidEnumManagerConfigurations>()
    {
        
    }

	std::string
		UuidEnumManager
			::convert_enum_to_string(
				const Uuid&
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
				case (Uuid::V4):
				{
					return
						"V4";
				}
				case (Uuid::NONE):
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
		UuidEnumManager
			::convert_enum_to_string()
	{
		return
			convert_enum_to_string(
				configurations
					.type
			);
	}

	Uuid
		UuidEnumManager
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
					Uuid
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
				value == "V4"
			)
			{
				return
					Uuid
						::V4;
			}	
			else if
			(
				value == "NONE"
			)
			{
				return
					Uuid
						::NONE;
			}
			else
			{
				return
					Uuid
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
				Uuid
					::NONE;
        }
	}

	Uuid
		UuidEnumManager
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
