#pragma once

#include "time_zone.hpp"
#include "time_format.hpp"
#include "abstract_class.hpp"
#include "time_scale_unit.hpp"
#include "singleton_manager.hpp"
#include "time_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    class
		TimeManager :
			public AbstractClass<TimeManagerConfigurations>
    {
    public:
		static TimeManager&
			singleton;

		TimeManager();

		~TimeManager();

		bool
			construct();

		bool
			destruct();

		double
			now();

		double
			nanosecond();

		double
			millisecond();

		double
			microsecond();

		double
			day(
				const TimeZone& time_zone =
					TimeZone::LOCAL
			);

		double
			hour(
				const TimeZone& time_zone =
					TimeZone::LOCAL
			);

		double
			year(
				const TimeZone& time_zone =
					TimeZone::LOCAL
			);

		double
			month(
				const TimeZone& time_zone =
					TimeZone::LOCAL
			);

		double
			second(
				const TimeZone& time_zone =
					TimeZone::LOCAL
			);

		double
			minute(
				const TimeZone& time_zone =
					TimeZone::LOCAL
			);

		std::string
			now(
				const TimeFormat&
					time_format,
				const TimeZone&
					time_zone =
						TimeZone::LOCAL
			);

		std::string
			get_time_unit_full_name(
				const TimeScaleUnit&
					format
			);

		std::string
			get_time_unit_abbreviation(
				const TimeScaleUnit&
					format
			);

		TimeScaleUnit
			get_time_unit_abbreviation(
				const std::string&
					format
			);

		double
			convert_seconds(
				const double&
					time,
				const TimeScaleUnit&
					format
			);

		double
			convert_nanoseconds(
				const double&
					time,
				const TimeScaleUnit&
					format
			);

		std::string
			pad3(
				int
					value
			);

		std::tm
			get_time_zone(
				const TimeZone&
					tz
			);

		std::string
			format_time(
				const std::tm&
					tm,
				const char*
					fmt
			);

		const char*
			get_format_string(
				const TimeFormat&
					time_format
			);

		std::string
			format_millisecond_level(
				absl::Duration
					since_epoch,
				const std::string&
					sep
			);

		std::string
			format_microsecond_level(
				absl::Duration
					since_epoch,
				const std::string&
					sep
			);

		std::string
			format_nanosecond_level(
				absl::Duration
					since_epoch,
				const std::string&
					sep
			);
	};
}
