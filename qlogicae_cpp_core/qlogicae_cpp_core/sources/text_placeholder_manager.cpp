#include "pch.hpp"

#include "../includes/text_placeholder_manager.hpp"

namespace
	QLogicaeCppCore
{
    TextPlaceholderManager&
        TextPlaceholderManager
			::singleton =
				SingletonManager
					::get_singleton<TextPlaceholderManager>();



    TextPlaceholderManager
		::TextPlaceholderManager() :
			AbstractClass<TextPlaceholderManagerConfigurations>()
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

	TextPlaceholderManager
		::~TextPlaceholderManager()
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
        TextPlaceholderManager
			::construct()
    {
        try
        {			
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
        TextPlaceholderManager
			::destruct()
    {
        try
        {		
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
					configurations.is_conditional_callback_enabled &&
					configurations.conditional_callback != nullptr &&
					configurations.conditional_callback(text)
				) ? placeholder : text;			
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
		TextPlaceholderManager
			::convert_text(
				const std::string&
					text
			)
	{
		try
        {		
			return
				convert_text(
					text,
					configurations.placeholder
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
