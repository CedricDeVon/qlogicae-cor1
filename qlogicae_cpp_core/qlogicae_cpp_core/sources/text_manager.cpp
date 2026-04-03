#include "pch.hpp"

#include "../includes/text_manager.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
    TextManager
		::TextManager() :
			AbstractClass<TextManagerConfigurations>()
	{
		construct();		
	}

	TextManager
		::~TextManager()
	{
		destruct();		
	}
    
    bool
        TextManager
			::construct()
    {
        try
        {		
			if
			(
				configurations
					.is_runtime_execution_disabled_for_utility_handling()
			)
			{
				return
					false;
			}
	
			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_utility_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}			

			return
				!(sodium_init() > 1);
        }
        catch
        (
            QLOGICAE_COR_V1__BASE__HPP_CPP__TRY_CATCH_EXCEPTION_PARAMETER
        )
        {
			QLOGICAE_COR_V1__IMPLICIT__HPP_CPP__CATCH_CODE_TEMPLATE();
        }
    }

    bool
        TextManager
			::destruct()
    {
        try
        {		
			if
			(
				configurations
					.is_runtime_execution_disabled_for_utility_handling()
			)
			{
				return
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_utility_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}			

			return
				true;
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
		TextManager
			::replace_text_tokens(
				const std::string&
					text,
				const std::unordered_map<std::string, std::string>&
					dictionary
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
						text.empty() ||
						dictionary.size() == 0
					)
				)
			)
			{
				return
					text;
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
				absl::StrReplaceAll(
					text,
					dictionary
				);
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
		TextManager
			::replace_text_tokens(
				const std::string&
					text
			)
	{
		return
			replace_text_tokens(
				text,
				configurations
					.replace_text_tokens_dictionary
			);
	}

	std::vector<std::string>
		TextManager
			::split_text(
				const std::string&
					text,
				const std::string&
					delimeter
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
						text.empty()
					)
				)
			)
			{
				return
					{};
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
				absl::StrSplit(
					text,
					delimeter
				);
        }
        catch
        (
            QLOGICAE_COR_V1__BASE__HPP_CPP__TRY_CATCH_EXCEPTION_PARAMETER
        )
        {
			QLOGICAE_COR_V1__IMPLICIT__HPP_CPP__CATCH_CODE_TEMPLATE();				
        }
	}

	std::vector<std::string>
		TextManager
			::split_text(
				const std::string&
					text
			)
	{
		return
			split_text(
				text,
				configurations
					.split_text_delimeter
			);
	}
}

