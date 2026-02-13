#include "pch.hpp"

#include "../includes/console_log_manager.hpp"

namespace
	QLogicaeCppCore
{        
	ConsoleLogManager&
		ConsoleLogManager
			::singleton = 
				SingletonManager
					::get_singleton<ConsoleLogManager>();	


	
	ConsoleLogManager
		::ConsoleLogManager() :
			AbstractClass<ConsoleLogManagerConfigurations>()
    {

    }

	bool
		ConsoleLogManager
			::log_formatted_text(
				const std::string&
					text,
				const LogLevel&
					log_level
			)
	{
		return
			log_raw_text(
				TextLogManager
					::singleton
						.convert_text(
							text,
							log_level
						)
			);
	}

	bool
		ConsoleLogManager
			::log_formatted_text(
				const std::string&
					text
			)
	{
		return
			log_formatted_text(
				text,
				configurations
					.log_level
			);
	}

	bool
		ConsoleLogManager
			::log_formatted_text()
	{
		return
			log_formatted_text(
				configurations
					.text,
				configurations
					.log_level
			);
	}
	
	bool
		ConsoleLogManager
			::log_raw_text(
				const std::string&
					text
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
						text
							.empty()
					)
				)
			)
			{
				return
					false;
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

			fast_io::io::print(
				fast_io::out(),
				text
			);

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
		ConsoleLogManager
			::log_raw_text()
	{
		return
			log_raw_text(
				configurations
					.text
			);
	}
}
