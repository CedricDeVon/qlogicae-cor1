#pragma once

#include "log_level.hpp"
#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "log_level_enum_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    class
		LogLevelEnumManager :
			public AbstractClass<LogLevelEnumManagerConfigurations>
    {
    public:
        static LogLevelEnumManager&
            singleton;

		LogLevelEnumManager();

		~LogLevelEnumManager();

		bool
			construct();

		bool
			destruct();

		std::string
			convert_enum_to_string(
				const LogLevel&
					value
			);

		std::string
			convert_enum_to_string();

		LogLevel
			convert_string_to_enum(
				const std::string&
					value
			);

		LogLevel
			convert_string_to_enum();
    };
}

