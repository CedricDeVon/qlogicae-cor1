#include "pch.hpp"

#include "../includes/text_error_manager.hpp"

namespace
	QLogicaeCppCore
{
    TextErrorManager&
        TextErrorManager
			::singleton =
				SingletonManager
					::get_singleton<TextErrorManager>();



    TextErrorManager
		::TextErrorManager() :
			AbstractClass<TextErrorManagerConfigurations>()
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

	TextErrorManager
		::~TextErrorManager()
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
        TextErrorManager
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
        TextErrorManager
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
		TextErrorManager
			::convert_text(
				const std::string&
					origin,
				const std::string&
					message
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
			if (configurations.is_thread_safety_enabled_for_utility_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						utility_handling_mutex_1
					);
			}			

			if (configurations.is_specified_length_enabled)
			{
				std::string text;
				text.resize(configurations.specified_length);

				text = 
					configurations.title +
					(origin.empty() ? "" : (" at " + origin)) +
					" " +
					configurations.separator +
					" " +
					message;

				return
					text;
			}
			else

			{
				return
					configurations.title +
					(origin.empty() ? "" : (" at " + origin)) +
					" " +
					configurations.separator +
					" " +
					message;
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
				"";
        }
	}

	std::string
		TextErrorManager
			::convert_text(
				const std::string&
					message
			)
	{
		try
        {		
			return
				convert_text(
					message
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
				"";
        }
	}
}
