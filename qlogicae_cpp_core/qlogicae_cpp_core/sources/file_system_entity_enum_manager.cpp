#include "pch.hpp"

#include "../includes/file_system_entity_enum_manager.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{        	
	FileSystemEntityEnumManager
		::FileSystemEntityEnumManager() :
			AbstractClass<FileSystemEntityEnumManagerConfigurations>()
    {
        
    }

	std::string
		FileSystemEntityEnumManager
			::convert_enum_to_string(
				const FileSystemEntity&
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
				case (FileSystemEntity::ALL):
				{
					return
						"ALL";
				}
				case (FileSystemEntity::FOLDER):
				{
					return
						"FOLDER";
				}
				case (FileSystemEntity::FILE):
				{
					return
						"FILE";
				}
				case (FileSystemEntity::NONE):
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
		FileSystemEntityEnumManager
			::convert_enum_to_string()
	{
		return
			convert_enum_to_string(
				configurations
					.type
			);
	}

	FileSystemEntity
		FileSystemEntityEnumManager
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
					FileSystemEntity
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
					FileSystemEntity
						::ALL;
			}
			else if
			(
				value == "FOLDER"
			)
			{
				return
					FileSystemEntity
						::FOLDER;
			}
			else if
			(
				value == "FILE"
			)
			{
				return
					FileSystemEntity
						::FILE;
			}
			else if
			(
				value == "NONE"
			)
			{
				return
					FileSystemEntity
						::NONE;
			}
			else
			{
				return
					FileSystemEntity
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
				FileSystemEntity
					::NONE;
        }
	}

	FileSystemEntity
		FileSystemEntityEnumManager
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

