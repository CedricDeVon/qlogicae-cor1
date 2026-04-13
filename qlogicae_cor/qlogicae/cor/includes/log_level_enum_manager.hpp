#pragma once

#include "log_level.hpp"
#include "abstract_class.hpp"
#include "log_level_enum_manager_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
    class
		LogLevelEnumManager :
			public QLOGICAE_COR_V1__BASE__HPP_CPP__ABSTRACT_CLASS_NAME<LogLevelEnumManagerConfigurations>
    {
    public:
		LogLevelEnumManager();

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
