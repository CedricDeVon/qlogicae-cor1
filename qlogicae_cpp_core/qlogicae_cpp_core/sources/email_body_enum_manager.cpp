#include "pch.hpp"

#include "../includes/email_body_enum_manager.hpp"

namespace
	QLogicae::Cor::V1
{        	
	EmailBodyEnumManager
		::EmailBodyEnumManager() :
			AbstractClass<EmailBodyEnumManagerConfigurations>()
    {
        
    }

	std::string
		EmailBodyEnumManager
			::convert_enum_to_string(
				const EmailBody&
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
				case (EmailBody::HTML):
				{
					return
						"HTML";
				}
				case (EmailBody::PLAIN):
				{
					return
						"PLAIN";
				}
				case (EmailBody::NONE):
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
		EmailBodyEnumManager
			::convert_enum_to_string()
	{
		return
			convert_enum_to_string(
				configurations
					.type
			);
	}

	EmailBody
		EmailBodyEnumManager
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
					EmailBody
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
				value == "HTML"
			)
			{
				return
					EmailBody
						::HTML;
			}
			else if
			(
				value == "PLAIN"
			)
			{
				return
					EmailBody
						::PLAIN;
			}
			else if
			(
				value == "NONE"
			)
			{
				return
					EmailBody
						::NONE;
			}
			else
			{
				return
					EmailBody
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
				EmailBody
					::NONE;
        }
	}

	EmailBody
		EmailBodyEnumManager
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
