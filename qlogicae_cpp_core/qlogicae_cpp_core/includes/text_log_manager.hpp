#pragma once

#include "log_level.hpp"
#include "log_format.hpp"
#include "time_format.hpp"
#include "time_manager.hpp"
#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "log_level_enum_manager.hpp"
#include "log_format_enum_manager.hpp"
#include "text_log_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{    
    class
		TextLogManager :
			public AbstractClass<TextLogManagerConfigurations>
    {
    public:        
        static TextLogManager&
            singleton;

		TextLogManager();

		std::string
			convert_text(
				const std::string&
					message,
				const LogLevel&
					log_level,
				const std::string&
					time_format,
				const LogFormat&
					log_format
			);

		std::string
			convert_text(
				const std::string&
					message,
				const LogLevel&
					log_level,
				const TimeFormat&
					time_format,
				const LogFormat&
					log_format
			);

		std::string
			convert_text(
				const std::string&
					message,
				const LogLevel&
					log_level,
				const std::string&
					time_format
			);

		std::string
			convert_text(
				const std::string&
					message,
				const LogLevel&
					log_level,
				const TimeFormat&
					time_format
			);

		std::string
			convert_text(
				const std::string&
					message,
				const LogLevel&
					log_level,
				const LogFormat&
					log_format
			);

		std::string
			convert_text(
				const std::string&
					message,
				const LogLevel&
					log_level
			);

		std::string
			convert_text(	
				const std::string&
					message
			);

		std::string
			convert_text();

    };    
}
