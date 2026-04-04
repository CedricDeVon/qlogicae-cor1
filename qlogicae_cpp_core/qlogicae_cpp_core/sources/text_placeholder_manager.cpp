#include "pch.hpp"

#include "../includes/text_placeholder_manager.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
    TextPlaceholderManager
		::TextPlaceholderManager() :
			AbstractClass<TextPlaceholderManagerConfigurations>()
	{
		
	}

	std::string
		TextPlaceholderManager
			::convert_text(
				const std::string&
					text,
				const std::string&
					placeholder
			)
	{
		try
        {		
			QLOGICAE_COR_V1__IMPLICIT__HPP_CPP__PRE_EXECUTION_GUARD_TEMPLATE
			(
				QLOGICAE_COR_V1__BASE__HPP_CPP__MUTEX_LAYER_1,
				QLOGICAE_COR_V1__BASE__HPP_CPP__EMPTY_EDGE_CASES
			);
		
			return
				(
					configurations
						.is_conditional_callback_enabled &&
					configurations
						.conditional_callback != nullptr &&
					configurations
						.conditional_callback(text)
				) ? placeholder : text;			
        }
        catch
        (
            QLOGICAE_COR_V1__BASE__HPP_CPP__TRY_CATCH_EXCEPTION_PARAMETER
        )
        {
			QLOGICAE_COR_V1__IMPLICIT__HPP_CPP__CATCH_CODE_TEMPLATE();
        }
	}	

	std::string
		TextPlaceholderManager
			::convert_text(
				const std::string&
					text
			)
	{
		return
			convert_text(
				text,
				configurations
					.placeholder
			);
	}		
}
