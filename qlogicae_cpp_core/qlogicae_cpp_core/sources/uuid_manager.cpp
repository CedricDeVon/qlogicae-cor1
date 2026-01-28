#include "pch.hpp"

#include "../includes/uuid_manager.hpp"

namespace
	QLogicaeCppCore
{
	UuidManager&
        UuidManager
			::singleton =
				SingletonManager
					::get_singleton<UuidManager>();



    UuidManager
		::UuidManager() :
			AbstractClass<UuidManagerConfigurations>()
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

	UuidManager
		::~UuidManager()
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
        UuidManager
			::construct()
    {
        try
        {			
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
        UuidManager
			::destruct()
    {
        try
        {		
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
						boost::uuids::uuid uuid = generator(value);
						return uuid.version() == boost::uuids::uuid::version_random_number_based;
					}
					catch (...)
					{
						return false;
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
		try
		{
			return
				is_valid(
					configurations
						.type,
					value
				);
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
		UuidManager
			::generate_uuid(
				const Uuid&
					type
			)
	{
		try
		{
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
						boost::uuids::to_string(
							boost::uuids::random_generator()()
						);
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
				"";
        }
	}

	std::string
		UuidManager
			::generate_uuid()
	{		
		try
		{
			return
				generate_uuid(
					configurations
						.type					
				);
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
				"";
        }
	}
}
