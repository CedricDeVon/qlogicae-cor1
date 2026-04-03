#include "pch.hpp"

#include "../includes/enum_manager.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{        	
	EnumManager
		::EnumManager() :
			AbstractClass<EnumManagerConfigurations>()
    {
        
    }

	std::string
		EnumManager
			::convert_enum_string(
				const std::string&
					value,
				const TextCase&
					original_text_case,
				const TextCase&
					target_text_case
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
						!configurations
							.is_text_case_conversion_enabled ||						
						value
							.empty() ||
						original_text_case == target_text_case
					)
				)
			)
			{
				return
					value;
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
				SingletonManager
					::get_singleton<TextCaseManager>()					
						.convert_text(
							value,
							target_text_case
						);
        }
        catch
        (
            QLOGICAE_COR_V1__BASE__HPP_CPP__TRY_CATCH_EXCEPTION_PARAMETER
        )
        {	
			QLOGICAE_COR_V1__EXPLICIT__HPP_CPP__CATCH_CODE_TEMPLATE
			(
				value
			);
        }
	}

	std::string
		EnumManager
			::convert_enum_string(
				const std::string&
					value,
				const TextCase&
					target_text_case
			)
	{
		return
			convert_enum_string(
				value,
				configurations
					.text_case,
				target_text_case				
			);
	}

	std::string
		EnumManager
			::convert_enum_string(
				const std::string&
					value
			)
	{
		return
			convert_enum_string(
				value,
				configurations
					.text_case,
				configurations
					.text_case
			);
	}

	std::string
		EnumManager
			::convert_default_enum_string(
				const std::string&
					value
			)
	{
		return
			convert_enum_string(
				value,
				TextCase
					::NONE,
				configurations
					.text_case
			);
	}

	std::string
		EnumManager
			::get_none_string(
				const TextCase&
					text_case
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
				switch (text_case)
				{
					case (TextCase::UPPERCASE):
					{
						return
							"NONE";
					}
					case (TextCase::LOWERCASE):
					{
						return
							"none";
					}
					case (TextCase::CAPITALIZE):
					{
						return
							"None";
					}
					default:
					{
						return
							"NONE";
					}
				}
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

			switch (text_case)
			{
				case (TextCase::UPPERCASE):
				{
					return
						"NONE";
				}
				case (TextCase::LOWERCASE):
				{
					return
						"none";
				}
				case (TextCase::CAPITALIZE):
				{
					return
						"None";
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
		EnumManager
			::get_none_string()
	{
		return
			get_none_string(
				configurations
					.text_case
			);
	}
}
