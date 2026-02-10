#pragma once

#include "log_medium.hpp"
#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "log_medium_enum_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    class
		LogMediumEnumManager :
			public AbstractClass<LogMediumEnumManagerConfigurations>
    {
    public:
        static LogMediumEnumManager&
            singleton;

		LogMediumEnumManager();

		~LogMediumEnumManager();

		bool
			construct();

		bool
			destruct();

		std::string
			convert_enum_to_string(
				const LogMedium&
					value
			);

		std::string
			convert_enum_to_string();

		LogMedium
			convert_string_to_enum(
				const std::string&
					value
			);

		LogMedium
			convert_string_to_enum();
    };
}

