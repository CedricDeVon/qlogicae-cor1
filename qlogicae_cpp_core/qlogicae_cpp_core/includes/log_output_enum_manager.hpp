#pragma once

#include "log_output.hpp"
#include "abstract_class.hpp"
#include "log_output_enum_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
    class
		LogOutputEnumManager :
			public AbstractClass<LogOutputEnumManagerConfigurations>
    {
    public:
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

