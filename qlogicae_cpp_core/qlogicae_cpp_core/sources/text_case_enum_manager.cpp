#include "pch.hpp"

#include "../includes/text_case_enum_manager.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
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
			QLOGICAE_COR_V1__EXPLICIT__HPP_CPP__PRE_EXECUTION_GUARD_TEMPLATE
			(
				"NONE",
				QLOGICAE_COR_V1__BASE__HPP_CPP__MUTEX_LAYER_1,
				QLOGICAE_COR_V1__BASE__HPP_CPP__EMPTY_EDGE_CASES
			);		

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
            QLOGICAE_COR_V1__BASE__HPP_CPP__TRY_CATCH_EXCEPTION_PARAMETER
        )
        {	
			QLOGICAE_COR_V1__EXPLICIT__HPP_CPP__CATCH_CODE_TEMPLATE
			(
				"NONE"
			);	
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
			QLOGICAE_COR_V1__EXPLICIT__HPP_CPP__PRE_EXECUTION_GUARD_TEMPLATE
			(
				TextCase::NONE,
				QLOGICAE_COR_V1__BASE__HPP_CPP__MUTEX_LAYER_1,
				QLOGICAE_COR_V1__BASE__HPP_CPP__EMPTY_EDGE_CASES
			);			

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
            QLOGICAE_COR_V1__BASE__HPP_CPP__TRY_CATCH_EXCEPTION_PARAMETER
        )
        {		
			QLOGICAE_COR_V1__EXPLICIT__HPP_CPP__CATCH_CODE_TEMPLATE
			(
				TextCase::NONE
			);				
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

