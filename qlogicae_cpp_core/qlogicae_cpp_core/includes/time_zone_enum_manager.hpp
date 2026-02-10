#pragma once

#include "time_zone.hpp"
#include "enum_manager.hpp"
#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "time_zone_enum_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    class
		TimeZoneEnumManager :
			public AbstractClass<TimeZoneEnumManagerConfigurations>
    {
    public:
        static TimeZoneEnumManager&
            singleton;

		TimeZoneEnumManager();

		~TimeZoneEnumManager();

		bool
			construct();

		bool
			destruct();

		std::string
			convert_enum_to_string(
				const TimeZone&
					value
			);

		std::string
			convert_enum_to_string();

		TimeZone
			convert_string_to_enum(
				const std::string&
					value
			);

		TimeZone
			convert_string_to_enum();
    };
}


