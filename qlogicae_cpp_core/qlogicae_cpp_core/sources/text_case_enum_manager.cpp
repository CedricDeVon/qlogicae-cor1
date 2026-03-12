#include "pch.hpp"

#include "../includes/text_case_enum_manager.hpp"

namespace
	QLogicae::Cor::V1
{    
    TextCaseEnumManager
		::TextCaseEnumManager() :
			AbstractClass<TextCaseEnumManagerConfigurations>()
	{
				
	}

	std::string
		TextCaseEnumManager
			::convert_enum_to_string(
				const TextCase&
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
				case (TextCase::LOWERCASE):
				{
					return
						"LOWERCASE";
				}
				case (TextCase::UPPERCASE):
				{
					return
						"UPPERCASE";
				}
				case (TextCase::CAPITALIZE):
				{
					return
						"CAPITALIZE";
				}
				case (TextCase::TITLE):
				{
					return
						"TITLE";
				}
				case (TextCase::SENTENCE):
				{
					return
						"SENTENCE";
				}
				case (TextCase::NONE):
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
		TextCaseEnumManager
			::convert_enum_to_string()
	{
		return
			convert_enum_to_string(
				configurations
					.type
			);
	}

	TextCase
		TextCaseEnumManager
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
					TextCase
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
				value == "LOWERCASE"
			)
			{
				return
					TextCase
						::LOWERCASE;
			}
			else if
			(
				value == "UPPERCASE"
			)
			{
				return
					TextCase
						::UPPERCASE;
			}
			else if
			(
				value == "CAPITALIZE"
			)
			{
				return
					TextCase
						::CAPITALIZE;
			}
			else if
			(
				value == "TITLE"
			)
			{
				return
					TextCase
						::TITLE;
			}
			else if
			(
				value == "SENTENCE"
			)
			{
				return
					TextCase
						::SENTENCE;
			}			
			else if
			(
				value == "NONE"
			)
			{
				return
					TextCase
						::NONE;
			}
			else
			{
				return
					TextCase
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
				TextCase
					::NONE;
        }
	}

	TextCase
		TextCaseEnumManager
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
