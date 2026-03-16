#include "pch.hpp"

#include "../includes/email_security_enum_manager.hpp"

namespace
	QLogicae::Cor::V1
{        	
	EmailSecurityEnumManager
		::EmailSecurityEnumManager() :
			AbstractClass<EmailSecurityEnumManagerConfigurations>()
    {
        
    }

	std::string
		EmailSecurityEnumManager
			::convert_enum_to_string(
				const EmailSecurity&
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
				case (EmailSecurity::SSL):
				{
					return
						"SSL";
				}				
				case (EmailSecurity::NONE):
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
		EmailSecurityEnumManager
			::convert_enum_to_string()
	{
		return
			convert_enum_to_string(
				configurations
					.type
			);
	}

	EmailSecurity
		EmailSecurityEnumManager
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
					EmailSecurity
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
				value == "SSL"
			)
			{
				return
					EmailSecurity
						::SSL;
			}
			else if
			(
				value == "NONE"
			)
			{
				return
					EmailSecurity
						::NONE;
			}
			else
			{
				return
					EmailSecurity
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
				EmailSecurity
					::NONE;
        }
	}

	EmailSecurity
		EmailSecurityEnumManager
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
