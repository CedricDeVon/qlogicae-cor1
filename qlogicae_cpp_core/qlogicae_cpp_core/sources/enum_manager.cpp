#include "pch.hpp"

#include "../includes/enum_manager.hpp"

namespace
	QLogicaeCppCore
{        
	EnumManager&
		EnumManager
			::singleton = 
				SingletonManager
					::get_singleton<EnumManager>();	


	
	EnumManager
		::EnumManager() :
			AbstractClass<EnumManagerConfigurations>()
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

    EnumManager
		::~EnumManager()
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
        EnumManager
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
        EnumManager
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
				TextCaseManager
					::singleton
						.convert_text(
							value,
							target_text_case
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
				value;
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
            const std::exception&
                exception
        )
        {	
			handle_error_outputs(
				exception
			);

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

