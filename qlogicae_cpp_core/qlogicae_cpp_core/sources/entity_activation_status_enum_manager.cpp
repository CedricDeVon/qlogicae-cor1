#include "pch.hpp"

#include "../includes/entity_activation_status_enum_manager.hpp"

namespace
	QLogicae::Cor::V1
{        	
	EntityActivationStatusEnumManager
		::EntityActivationStatusEnumManager() :
			AbstractClass<EntityActivationStatusEnumManagerConfigurations>()
    {
        
    }

	std::string
		EntityActivationStatusEnumManager
			::convert_enum_to_string(
				const EntityActivationStatus&
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
				case (EntityActivationStatus::ACTIVE):
				{
					return
						"ACTIVE";
				}
				case (EntityActivationStatus::INACTIVE):
				{
					return
						"INACTIVE";
				}
				case (EntityActivationStatus::PENDING):
				{
					return
						"PENDING";
				}
				case (EntityActivationStatus::NONE):
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
		EntityActivationStatusEnumManager
			::convert_enum_to_string()
	{
		return
			convert_enum_to_string(
				configurations
					.type
			);
	}

	EntityActivationStatus
		EntityActivationStatusEnumManager
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
					EntityActivationStatus
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
				value == "ACTIVE"
			)
			{
				return
					EntityActivationStatus
						::ACTIVE;
			}
			else if
			(
				value == "INACTIVE"
			)
			{
				return
					EntityActivationStatus
						::INACTIVE;
			}
			else if
			(
				value == "PENDING"
			)
			{
				return
					EntityActivationStatus
						::PENDING;
			}
			else if
			(
				value == "NONE"
			)
			{
				return
					EntityActivationStatus
						::NONE;
			}
			else
			{
				return
					EntityActivationStatus
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
				EntityActivationStatus
					::NONE;
        }
	}

	EntityActivationStatus
		EntityActivationStatusEnumManager
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

