#pragma once

#include "time_format.hpp"
#include "enum_manager.hpp"
#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "time_format_enum_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    class
		TimeFormatEnumManager :
			public AbstractClass<TimeFormatEnumManagerConfigurations>
    {
    public:
        static TimeFormatEnumManager&
            singleton;

		TimeFormatEnumManager();

		~TimeFormatEnumManager();

		bool
			construct();

		bool
			destruct();

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


