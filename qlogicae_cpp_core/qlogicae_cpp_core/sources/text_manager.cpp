#include "pch.hpp"

#include "../includes/text_manager.hpp"

namespace
	QLogicaeCppCore
{
    TextManager&
        TextManager
			::singleton =
				SingletonManager
					::get_singleton<TextManager>();



    TextManager
		::TextManager() :
			AbstractClass<TextManagerConfigurations>()
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

	TextManager
		::~TextManager()
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
        TextManager
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
				!(sodium_init() < 0);
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
        TextManager
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
				(text.empty()) ?
					"" :
					absl::StrReplaceAll(
						text,
						dictionary
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

	std::string
		TextManager
			::replace_text_tokens(
				const std::string&
					text
			)
	{
		try
        {	
			return
				replace_text_tokens(
					text,
					configurations
						.replace_text_tokens_dictionary
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
				(text.empty()) ?
					std::vector<std::string>{} :
					absl::StrSplit(
						text,
						delimeter
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
				{};				
        }
	}

	std::vector<std::string>
		TextManager
			::split_text(
				const std::string&
					text
			)
	{
		try
        {		
			return
				split_text(
					text,
					configurations
						.split_text_delimeter
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
				{};				
        }
	}
}

