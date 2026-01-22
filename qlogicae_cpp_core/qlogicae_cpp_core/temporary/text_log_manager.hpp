#pragma once

#include "log_level.hpp"
#include "time_format.hpp"
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

		~TextLogManager();

		bool
			construct();

		bool
			destruct();

		std::string
			convert_text(
				const std::string&
					text,
				const LogLevel&
					log_level,
				const TimeFormat&
					time_format
		);
    };    
}
