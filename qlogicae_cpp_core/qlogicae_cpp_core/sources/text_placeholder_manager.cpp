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
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling()
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
