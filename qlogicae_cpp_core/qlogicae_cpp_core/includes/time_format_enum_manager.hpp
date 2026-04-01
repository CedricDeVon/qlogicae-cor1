#pragma once

#include "time_format.hpp"
#include "enum_manager.hpp"
#include "abstract_class.hpp"
#include "time_format_enum_manager_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
    class
		TimeFormatEnumManager :
			public AbstractClass<TimeFormatEnumManagerConfigurations>
    {
    public:
		TimeFormatEnumManager();

		std::string
			convert_enum_to_string(
				const TimeFormat&
					value
			);

		std::string
			convert_enum_to_string();

		TimeFormat
			convert_string_to_enum(
				const std::string&
					value
			);

		TimeFormat
			convert_string_to_enum();
    };
}
