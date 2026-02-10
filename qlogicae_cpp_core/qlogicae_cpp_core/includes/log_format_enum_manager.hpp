#pragma once

#include "log_format.hpp"
#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "log_format_enum_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    class
		LogFormatEnumManager :
			public AbstractClass<LogFormatEnumManagerConfigurations>
    {
    public:
        static LogFormatEnumManager&
            singleton;

		LogFormatEnumManager();

		std::string
			convert_enum_to_string(
				const LogFormat&
					value
			);

		std::string
			convert_enum_to_string();

		LogFormat
			convert_string_to_enum(
				const std::string&
					value
			);

		LogFormat
			convert_string_to_enum();
    };
}

