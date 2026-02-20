#include "pch.hpp"

#include "../includes/text_log_manager.hpp"

namespace
	QLogicaeCppCore
{        
	TextLogManager&
		TextLogManager
			::singleton = 
				SingletonManager
					::get_singleton<TextLogManager>();	

	TextLogManager
		::TextLogManager() :
			AbstractClass<TextLogManagerConfigurations>()
    {
        
    }

	std::string
		TextLogManager
			::convert_text(
				const std::string&
					message,
				const LogLevel&
					log_level,
				const std::string&
					time_format,
				const LogFormat&
					log_format
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
						log_format == LogFormat::NONE
					)
				)
			)
			{
				return
					message;
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

			std::string 
				output;
	
			std::string
				log_level_text =
					LogLevelEnumManager
						::singleton
							.convert_enum_to_string(
								log_level
							);

			switch (log_format)
			{
				case (LogFormat::STANDARD):
				{
					output =
						(time_format.empty() ? "" : time_format + " - ") +
						(log_level_text.empty() ? "" : log_level_text + " - ") +
						message;

					break;
				}
				case (LogFormat::CUSTOM):
				{
					output =
						message;

					break;
				}
				case (LogFormat::NONE):
				{
					output =
						message;

					break;
				}
				default:
				{
					output =
						message;
			
					break;
				}
			}

			if
			(
				configurations
					.is_specified_length_enabled
			)
			{
				if (output.size() > configurations.specified_length)
					output.resize(configurations.specified_length);
				else if (output.size() < configurations.specified_length)
					output.append(configurations.specified_length - output.size(), ' ');
			}

			return
				output;
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
				message;
        }
	}

	std::string
		TextLogManager
			::convert_text(
				const std::string&
					message,
				const LogLevel&
					log_level,
				const TimeFormat&
					time_format,
				const LogFormat&
					log_format
			)
	{
		return
			convert_text(
				message,
				log_level,
				TimeManager
					::singleton
						.get_now(
							time_format
						),
				log_format
			);
	}

	std::string
		TextLogManager
			::convert_text(
				const std::string&
					message,
				const LogLevel&
					log_level,
				const TimeFormat&
					time_format
			)
	{
		return
			convert_text(
				message,
				log_level,
				time_format,
				configurations
					.log_format
			);
	}

	std::string
		TextLogManager
			::convert_text(
				const std::string&
					message,
				const LogLevel&
					log_level,
				const std::string&
					time_format
			)
	{
		return
			convert_text(
				message,
				log_level,
				time_format,
				configurations
					.log_format
			);
	}

	std::string
		TextLogManager
			::convert_text(
				const std::string&
					message,
				const LogLevel&
					log_level,
				const LogFormat&
					log_format
			)
	{
		return
			convert_text(
				message,
				log_level,
				configurations
					.time_format,
				log_format
			);
	}

	std::string
		TextLogManager
			::convert_text(
				const std::string&
					message,
				const LogLevel&
					log_level
			)
	{
		return
			convert_text(
				message,
				log_level,
				configurations
					.time_format,
				configurations
					.log_format
			);
	}

	std::string
		TextLogManager
			::convert_text(
				const std::string&
					message
			)
	{
		return
			convert_text(
				message,
				configurations
					.log_level,
				configurations
					.time_format,
				configurations
					.log_format
			);
	}

	std::string
		TextLogManager
			::convert_text()
	{
		return
			convert_text(
				configurations
					.message,
				configurations
					.log_level,
				configurations
					.time_format,
				configurations
					.log_format
			);
	}
}
