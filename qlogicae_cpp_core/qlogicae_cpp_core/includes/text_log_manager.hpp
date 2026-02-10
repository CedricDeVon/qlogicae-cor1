#pragma once

#include "log_level.hpp"
#include "time_format.hpp"

#include "text_case.hpp"
#include "log_medium.hpp"
#include "log_output.hpp"
#include "log_format.hpp"

#include "time_manager.hpp"
#include "abstract_class.hpp"
#include "singleton_manager.hpp"
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
    };    
}

/*


		std::string
			convert_text(
				const std::string&
					time_format,
				const LogLevel&
					log_level,
				const std::string&
					message
			);

		std::string
			convert_text(
				const TimeFormat&
					time_format
				const LogLevel&
					log_level,
				const std::string&
					message
			);

*/ 