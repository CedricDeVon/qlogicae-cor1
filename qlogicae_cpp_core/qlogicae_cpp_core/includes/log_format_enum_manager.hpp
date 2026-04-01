#pragma once

#include "log_format.hpp"
#include "abstract_class.hpp"
#include "log_format_enum_manager_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
    class
		LogFormatEnumManager :
			public AbstractClass<LogFormatEnumManagerConfigurations>
    {
    public:
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
