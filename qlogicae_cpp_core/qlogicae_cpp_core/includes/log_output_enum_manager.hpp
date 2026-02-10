#pragma once

#include "log_output.hpp"
#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "log_output_enum_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    class
		LogOutputEnumManager :
			public AbstractClass<LogOutputEnumManagerConfigurations>
    {
    public:
        static LogOutputEnumManager&
            singleton;

		LogOutputEnumManager();

		std::string
			convert_enum_to_string(
				const LogOutput&
					value
			);

		std::string
			convert_enum_to_string();

		LogOutput
			convert_string_to_enum(
				const std::string&
					value
			);

		LogOutput
			convert_string_to_enum();
    };
}

