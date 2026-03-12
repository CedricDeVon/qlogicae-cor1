#include "pch.hpp"

#include "../includes/text_encoding_enum_manager.hpp"

namespace
	QLogicae::Cor::V1
{
    TextEncodingEnumManager
		::TextEncodingEnumManager() :
			AbstractClass<TextEncodingEnumManagerConfigurations>()
	{
		
	}

	std::string
		TextEncodingEnumManager
			::convert_enum_to_string(
				const TextEncoding&
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
				case (TextEncoding::BASE16):
				{
					return
						"BASE16";
				}
				case (TextEncoding::BASE32):
				{
					return
						"BASE32";
				}
				case (TextEncoding::BASE64):
				{
					return
						"BASE64";
				}
				case (TextEncoding::NONE):
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
		TextEncodingEnumManager
			::convert_enum_to_string()
	{
		return
			convert_enum_to_string(
				configurations
					.type
			);
	}

	TextEncoding
		TextEncodingEnumManager
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
					TextEncoding
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
				value == "BASE16"
			)
			{
				return
					TextEncoding
						::BASE16;
			}
			else if
			(
				value == "BASE32"
			)
			{
				return
					TextEncoding
						::BASE32;
			}
			else if
			(
				value == "BASE64"
			)
			{
				return
					TextEncoding
						::BASE64;
			}			
			else if
			(
				value == "NONE"
			)
			{
				return
					TextEncoding
						::NONE;
			}
			else
			{
				return
					TextEncoding
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
				TextEncoding
					::NONE;
        }
	}

	TextEncoding
		TextEncodingEnumManager
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
