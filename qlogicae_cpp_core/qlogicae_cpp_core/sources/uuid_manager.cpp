#include "pch.hpp"

#include "../includes/uuid_manager.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
    UuidManager
		::UuidManager() :
			AbstractClass<UuidManagerConfigurations>()
	{
		
	}

	bool
		UuidManager
			::is_valid(
				const Uuid&
					type,
				const std::string&
					value
			)
	{
		try
		{
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling() ||				
				(
					configurations
						.is_edge_case_enabled_for_feature_handling() &&
					(
						type == Uuid::NONE ||
						value.empty()
					)
				)
			)
			{
				return
					false;
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

			switch (type)
			{
				case (Uuid::V4):
				{
					boost::uuids::string_generator
						generator;
					try
					{
						boost::uuids::uuid uuid =
							generator(value);

						return
							uuid.version() == boost::uuids::uuid::version_random_number_based;
					}
					catch (...)
					{
						return
							false;
					}
				}
				default:
				{
					return
						false;
				}
			}
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
		UuidManager
			::is_valid(
				const std::string&
					value
			)
	{
		return
			is_valid(
				configurations
					.type,
				value
			);
	}

	std::string
		UuidManager
			::generate_uuid(
				const Uuid&
					type
			)
	{
		try
		{
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling() ||				
				(
					configurations
						.is_edge_case_enabled_for_feature_handling() &&
					(
						type == Uuid::NONE
					)
				)
			)
			{
				return
					"";
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

			switch (type)
			{
				case (Uuid::V4):
				{
					return
						boost::uuids::to_string(
							boost::uuids::random_generator()()
						);
				}
				default:
				{
					return
						"";
				}
			}			
        }
        catch
        (
            const std::exception&
                exception
        )
        {			
			return
				handle_error_outputs<std::string>(
					exception
				);
        }
	}

	std::string
		UuidManager
			::generate_uuid()
	{		
		return
			generate_uuid(
				configurations
					.type					
			);
	}
}
