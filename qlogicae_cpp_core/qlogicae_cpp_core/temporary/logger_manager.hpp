#pragma once

#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "logger_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    class
		LoggerManager :
			public AbstractClass<LoggerManagerConfigurations>
    {
    public:
		boost::mutex
			feature_handling_mutex_2;
		
		static LoggerManager&
			singleton;

		LoggerManager();

		~LoggerManager();

		bool
			construct();

		bool
			destruct();

		bool
			log_text(
				const std::string&
					text,
				const LogMedium&
					medium,
				const TimeFormat&
					time_format
			);

		bool
			log_text(
				const std::string&
					text,
				const LogMedium&
					medium
			);

		bool
			log_text(
				const std::string&
					text,
				const TimeFormat&
					time_format
			);

		bool
			log_text(
				const std::string&
					text
			);

		bool
			log_via_console_output_text(
				const std::string&
					text,
				const TimeFormat&
					time_format
			);

		bool
			log_via_console_output_text(
				const std::string&
					text
			);

		bool
			log_via_file_output_text(
				const std::string&
					text,
				const TimeFormat&
					time_format
			);

		bool
			log_via_file_output_text(
				const std::string&
					text
			);
	};
}
