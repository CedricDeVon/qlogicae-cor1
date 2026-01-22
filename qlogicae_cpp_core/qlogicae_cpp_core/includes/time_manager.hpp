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

		template <typename Type> Type
			get_now();

		template <typename Type> Type
			get_nanosecond();

		template <typename Type> Type
			get_millisecond();

		template <typename Type> Type
			get_microsecond();

		template <typename Type> Type
			get_day();

		template <typename Type> Type
			get_hour();

		template <typename Type> Type
			get_year();

		template <typename Type> Type
			get_month();

		template <typename Type> Type
			get_second();

		template <typename Type> Type
			get_minute();

		std::string
			get_now(
				const TimeFormat&
					time_format
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

		std::tm
			get_time_zone();

		std::string
			pad3(
				int
					value
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

	template <typename Type>
	Type TimeManager::get_now()
	{
		try
		{
			auto ns = std::chrono::duration_cast<std::chrono::nanoseconds>(
				std::chrono::high_resolution_clock::now().time_since_epoch()
			).count();

			if constexpr (std::is_same_v<Type, double>)
				return static_cast<double>(ns);

			else if constexpr (std::is_same_v<Type, int64_t>)
				return static_cast<int64_t>(ns);

			else if constexpr (std::is_same_v<Type, std::string>)
				return absl::StrCat(ns);

			else if constexpr (std::is_same_v<Type, std::wstring>)
				return std::to_wstring(ns);

			else
				return static_cast<Type>(ns);
		}
		catch (const std::exception& ex)
		{
			handle_error_outputs(ex);
			return Type{};
		}
	}
	
	template <typename Type>
	Type TimeManager::get_nanosecond()
	{
		try
		{
			auto ns = std::chrono::duration_cast<std::chrono::nanoseconds>(
				std::chrono::system_clock::now().time_since_epoch()
			).count() % 1'000'000'000;

			if constexpr (std::is_same_v<Type, double>)
				return static_cast<double>(ns);

			else if constexpr (std::is_same_v<Type, int64_t>)
				return static_cast<int64_t>(ns);

			else if constexpr (std::is_same_v<Type, std::string>)
				return absl::StrCat(ns);

			else if constexpr (std::is_same_v<Type, std::wstring>)
				return std::to_wstring(ns);

			else
				return static_cast<Type>(ns);
		}
		catch (const std::exception& ex)
		{
			handle_error_outputs(ex);
			return Type{};
		}
	}

	template <typename Type>
	Type TimeManager::get_microsecond()
	{
		try
		{
			auto us = std::chrono::duration_cast<std::chrono::microseconds>(
				std::chrono::system_clock::now().time_since_epoch()
			).count() % 1'000'000;

			if constexpr (std::is_same_v<Type, double>)
				return static_cast<double>(us);

			else if constexpr (std::is_same_v<Type, int64_t>)
				return static_cast<int64_t>(us);

			else if constexpr (std::is_same_v<Type, std::string>)
				return absl::StrCat(us);

			else if constexpr (std::is_same_v<Type, std::wstring>)
				return std::to_wstring(us);

			else
				return static_cast<Type>(us);
		}
		catch (const std::exception& ex)
		{
			handle_error_outputs(ex);
			return Type{};
		}
	}

	template <typename Type>
	Type TimeManager::get_millisecond()
	{
		try
		{
			auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(
				std::chrono::system_clock::now().time_since_epoch()
			).count() % 1'000;

			if constexpr (std::is_same_v<Type, double>)
				return static_cast<double>(ms);

			else if constexpr (std::is_same_v<Type, int64_t>)
				return static_cast<int64_t>(ms);

			else if constexpr (std::is_same_v<Type, std::string>)
				return absl::StrCat(ms);

			else if constexpr (std::is_same_v<Type, std::wstring>)
				return std::to_wstring(ms);

			else
				return static_cast<Type>(ms);
		}
		catch (const std::exception& ex)
		{
			handle_error_outputs(ex);
			return Type{};
		}
	}

	template <typename Type>
	Type TimeManager::get_second()
	{
		try
		{
			auto sec = get_time_zone().tm_sec;
			if constexpr (std::is_same_v<Type, double>)
				return static_cast<double>(sec);

			else if constexpr (std::is_same_v<Type, int>)
				return static_cast<int>(sec);

			else if constexpr (std::is_same_v<Type, std::string>)
				return absl::StrCat(sec);

			else if constexpr (std::is_same_v<Type, std::wstring>)
				return std::to_wstring(sec);

			else
				return static_cast<Type>(sec);
		}
		catch (const std::exception& ex)
		{
			handle_error_outputs(ex);
			return Type{};
		}
	}

	template <typename Type>
	Type TimeManager::get_minute()
	{
		try
		{
			auto min = get_time_zone().tm_min;
			if constexpr (std::is_same_v<Type, double>)
				return static_cast<double>(min);

			else if constexpr (std::is_same_v<Type, int>)
				return static_cast<int>(min);

			else if constexpr (std::is_same_v<Type, std::string>)
				return absl::StrCat(min);

			else if constexpr (std::is_same_v<Type, std::wstring>)
				return std::to_wstring(min);

			else
				return static_cast<Type>(min);
		}
		catch (const std::exception& ex)
		{
			handle_error_outputs(ex);
			return Type{};
		}
	}

	template <typename Type>
	Type TimeManager::get_hour()
	{
		try
		{
			auto h = get_time_zone().tm_hour;
			if constexpr (std::is_same_v<Type, double>)
				return static_cast<double>(h);

			else if constexpr (std::is_same_v<Type, int>)
				return h;

			else if constexpr (std::is_same_v<Type, std::string>)
				return absl::StrCat(h);

			else if constexpr (std::is_same_v<Type, std::wstring>)
				return std::to_wstring(h);

			else
				return static_cast<Type>(h);
		}
		catch (const std::exception& ex)
		{
			handle_error_outputs(ex);
			return Type{};
		}
	}

	template <typename Type>
	Type TimeManager::get_day()
	{
		try
		{
			auto d = get_time_zone().tm_mday;
			if constexpr (std::is_same_v<Type, double>)
				return static_cast<double>(d);

			else if constexpr (std::is_same_v<Type, int>)
				return d;

			else if constexpr (std::is_same_v<Type, std::string>)
				return absl::StrCat(d);

			else if constexpr (std::is_same_v<Type, std::wstring>)
				return std::to_wstring(d);

			else
				return static_cast<Type>(d);
		}
		catch (const std::exception& ex)
		{
			handle_error_outputs(ex);
			return Type{};
		}
	}

	template <typename Type>
	Type TimeManager::get_month()
	{
		try
		{
			auto m = get_time_zone().tm_mon + 1;
			if constexpr (std::is_same_v<Type, double>)
				return static_cast<double>(m);

			else if constexpr (std::is_same_v<Type, int>)
				return m;

			else if constexpr (std::is_same_v<Type, std::string>)
				return absl::StrCat(m);

			else if constexpr (std::is_same_v<Type, std::wstring>)
				return std::to_wstring(m);

			else
				return static_cast<Type>(m);
		}
		catch (const std::exception& ex)
		{
			handle_error_outputs(ex);
			return Type{};
		}
	}

	template <typename Type>
	Type TimeManager::get_year()
	{
		try
		{
			auto y = get_time_zone().tm_year + 1900;
			if constexpr (std::is_same_v<Type, double>)
				return static_cast<double>(y);

			else if constexpr (std::is_same_v<Type, int>)
				return y;

			else if constexpr (std::is_same_v<Type, std::string>)
				return absl::StrCat(y);

			else if constexpr (std::is_same_v<Type, std::wstring>)
				return std::to_wstring(y);

			else
				return static_cast<Type>(y);
		}
		catch (const std::exception& ex)
		{
			handle_error_outputs(ex);
			return Type{};
		}
	}

}


/*

	void Time::now(
		Result<std::string>& result,
		const TimeFormat& format,
		const TimeZone& zone
	)
	{
		absl::Time now_time = absl::Now();
		absl::Duration since_epoch = now_time - absl::UnixEpoch();
		std::tm tm = _get_time_zone(zone);
		const char* fmt = UTILITIES.get_format_string(format);
		std::string str;

		switch (format)
		{
			case TimeFormat::UNIX:
			{
				str = absl::StrCat(absl::ToUnixSeconds(now_time));
				break;
			}
			case TimeFormat::ISO8601:
			case TimeFormat::SECOND_LEVEL_TIMESTAMP:
			case TimeFormat::HOUR_12:
			case TimeFormat::HOUR_24:
			case TimeFormat::DATE_DASHED:
			case TimeFormat::DATE_MDY_SLASHED:
			case TimeFormat::DATE_DMY_SLASHED:
			case TimeFormat::DATE_DMY_SPACED:
			case TimeFormat::DATE_VERBOSE:
			{
				str = _format_time(tm, fmt);
				break;
			}
			case TimeFormat::MILLISECOND_LEVEL_TIMESTAMP:
			{
				str = _format_time(tm, fmt) + "." +
					_format_millisecond_level(since_epoch, ":");
				break;
			}
			case TimeFormat::MICROSECOND_LEVEL_TIMESTAMP:
			{
				str = _format_time(tm, fmt) + "." +
					_format_microsecond_level(since_epoch, ":");
				break;
			}
			case TimeFormat::FULL_TIMESTAMP:
			{
				str = _format_time(tm, fmt) + "." +
					_format_nanosecond_level(since_epoch, ":");
				break;
			}
			case TimeFormat::FULL_DASHED_TIMESTAMP:
			{
				str = _format_time(tm, fmt) + "-" +
					_format_nanosecond_level(since_epoch, "-");
				break;
			}
			case TimeFormat::MILLISECOND_MICROSECOND_NANOSECOND:
			{
				int64_t ms = absl::ToInt64Milliseconds(since_epoch);
				int64_t us = absl::ToInt64Microseconds(since_epoch);
				int64_t ns = absl::ToInt64Nanoseconds(since_epoch);

				if (ms < 0 || us < 0 || ns < 0) {
					str = UTILITIES.TIME_FORMAT_INVALID;
					break;
				}

				str = absl::StrCat("ms: ", ms, ", us: ", us, ", ns: ", ns);
				break;
			}
			default:
			{
				str = UTILITIES.TIME_FORMAT_INVALID;
				break;
			}
		}

		result.set_to_good_status_with_value(str);
	}


	void Utilities::get_format_string(
		Result<const char*>& result,
		const TimeFormat& format
	)
	{
		switch (format)
		{
			case TimeFormat::ISO8601:
			{
				result.set_to_good_status_with_value(UTILITIES.TIME_FORMAT_ISO_8601);
				break;
			}
			case TimeFormat::FULL_TIMESTAMP:
			{
				result.set_to_good_status_with_value(UTILITIES.TIME_FORMAT_FULL_TIMESTAMP);
				break;
			}
			case TimeFormat::FULL_DASHED_TIMESTAMP:
			{
				result.set_to_good_status_with_value(UTILITIES.TIME_FORMAT_FULL_DASHED_TIMESTAMP);
				break;
			}
			case TimeFormat::HOUR_12:
			{
				result.set_to_good_status_with_value(UTILITIES.TIME_FORMAT_HOUR_12);
				break;
			}
			case TimeFormat::HOUR_24:
			{
				result.set_to_good_status_with_value(UTILITIES.TIME_FORMAT_HOUR_24);
				break;
			}
			case TimeFormat::DATE_DASHED:
			{
				result.set_to_good_status_with_value(UTILITIES.TIME_FORMAT_DATE_DASHED);
				break;
			}
			case TimeFormat::DATE_MDY_SLASHED:
			{
				result.set_to_good_status_with_value(UTILITIES.TIME_FORMAT_DATE_MDY_SLASHED);
				break;
			}
			case TimeFormat::DATE_DMY_SLASHED:
			{
				result.set_to_good_status_with_value(UTILITIES.TIME_FORMAT_DATE_DMY_SLASHED);
				break;
			}
			case TimeFormat::DATE_DMY_SPACED:
			{
				result.set_to_good_status_with_value(UTILITIES.TIME_FORMAT_DATE_DMY_SPACED);
				break;
			}
			case TimeFormat::DATE_VERBOSE:
			{
				result.set_to_good_status_with_value(UTILITIES.TIME_FORMAT_DATE_VERBOSE);
				break;
			}
			default:
			{
				result.set_to_good_status_with_value(UTILITIES.TIME_FORMAT_DATE_VERBOSE);
				break;
			}
		}
	}


	std::string_view Time::get_time_unit_full_name(
		const TimeScaleUnit& format
	)
	{
		try
		{
			Result<std::string> result;

			get_time_unit_full_name(
				result,
				format
			);

			return result.get_value();
		}
		catch (const std::exception& exception)
		{
			LOGGER.handle_exception_async(
				"QLogicaeCore::Time::get_time_unit_full_name()",
				exception.what()
			);

			return "";
		}
	}

	void Time::get_time_unit_full_name(
		Result<std::string>& result,
		const TimeScaleUnit& format
	)
	{
		switch (format)
		{
		case TimeScaleUnit::NANOSECONDS: result.set_to_good_status_with_value(UTILITIES.TIME_SCALE_UNIT_FULL_NAME_NANOSECONDS); break;
		case TimeScaleUnit::MICROSECONDS: result.set_to_good_status_with_value(UTILITIES.TIME_SCALE_UNIT_FULL_NAME_MICROSECONDS); break;
		case TimeScaleUnit::MILLISECONDS: result.set_to_good_status_with_value(UTILITIES.TIME_SCALE_UNIT_FULL_NAME_MILLISECONDS); break;
		case TimeScaleUnit::SECONDS: result.set_to_good_status_with_value(UTILITIES.TIME_SCALE_UNIT_FULL_NAME_SECONDS); break;
		case TimeScaleUnit::MINUTES: result.set_to_good_status_with_value(UTILITIES.TIME_SCALE_UNIT_FULL_NAME_MINUTES); break;
		case TimeScaleUnit::HOURS: result.set_to_good_status_with_value(UTILITIES.TIME_SCALE_UNIT_FULL_NAME_HOURS); break;
		case TimeScaleUnit::DAYS: result.set_to_good_status_with_value(UTILITIES.TIME_SCALE_UNIT_FULL_NAME_DAYS); break;
		case TimeScaleUnit::WEEKS: result.set_to_good_status_with_value(UTILITIES.TIME_SCALE_UNIT_FULL_NAME_WEEKS); break;
		case TimeScaleUnit::MONTHS: result.set_to_good_status_with_value(UTILITIES.TIME_SCALE_UNIT_FULL_NAME_MONTHS); break;
		case TimeScaleUnit::YEARS: result.set_to_good_status_with_value(UTILITIES.TIME_SCALE_UNIT_FULL_NAME_YEARS); break;
		default: result.set_to_good_status_with_value(UTILITIES.TIME_SCALE_UNIT_FULL_NAME_SECONDS); break;
		}
	}

	std::string_view Time::get_time_unit_abbreviation(
		const TimeScaleUnit& format
	)
	{
		try
		{
			Result<std::string> result;

			get_time_unit_abbreviation(
				result,
				format
			);

			return result.get_value();
		}
		catch (const std::exception& exception)
		{
			LOGGER.handle_exception_async(
				"QLogicaeCore::Time::get_time_unit_abbreviation()",
				exception.what()
			);

			return "";
		}
	}

	void Time::get_time_unit_abbreviation(
		Result<std::string>& result,
		const TimeScaleUnit& format
	)
	{
		switch (format)
		{
		case TimeScaleUnit::NANOSECONDS: result.set_to_good_status_with_value(UTILITIES.TIME_SCALE_UNIT_ABBREVIATION_NANOSECONDS); break;
		case TimeScaleUnit::MICROSECONDS: result.set_to_good_status_with_value(UTILITIES.TIME_SCALE_UNIT_ABBREVIATION_MICROSECONDS); break;
		case TimeScaleUnit::MILLISECONDS: result.set_to_good_status_with_value(UTILITIES.TIME_SCALE_UNIT_ABBREVIATION_MILLISECONDS); break;
		case TimeScaleUnit::SECONDS: result.set_to_good_status_with_value(UTILITIES.TIME_SCALE_UNIT_ABBREVIATION_SECONDS); break;
		case TimeScaleUnit::MINUTES: result.set_to_good_status_with_value(UTILITIES.TIME_SCALE_UNIT_ABBREVIATION_MINUTES); break;
		case TimeScaleUnit::HOURS: result.set_to_good_status_with_value(UTILITIES.TIME_SCALE_UNIT_ABBREVIATION_HOURS); break;
		case TimeScaleUnit::DAYS: result.set_to_good_status_with_value(UTILITIES.TIME_SCALE_UNIT_ABBREVIATION_DAYS); break;
		case TimeScaleUnit::WEEKS: result.set_to_good_status_with_value(UTILITIES.TIME_SCALE_UNIT_ABBREVIATION_WEEKS); break;
		case TimeScaleUnit::MONTHS: result.set_to_good_status_with_value(UTILITIES.TIME_SCALE_UNIT_ABBREVIATION_MONTHS); break;
		case TimeScaleUnit::YEARS: result.set_to_good_status_with_value(UTILITIES.TIME_SCALE_UNIT_ABBREVIATION_YEARS); break;
		default: result.set_to_good_status_with_value(UTILITIES.TIME_SCALE_UNIT_ABBREVIATION_SECONDS); break;
		}
	}

	TimeScaleUnit Time::get_time_unit_abbreviation(
		const std::string& format
	)
	{
		try
		{
			Result<TimeScaleUnit> result;

			get_time_unit_abbreviation(
				result,
				format
			);

			return result.get_value();
		}
		catch (const std::exception& exception)
		{
			LOGGER.handle_exception_async(
				"QLogicaeCore::Time::get_time_unit_abbreviation()",
				exception.what()
			);

			return TimeScaleUnit::NANOSECONDS;
		}
	}

	void Time::get_time_unit_abbreviation(
		Result<TimeScaleUnit>& result,
		const std::string& format
	)
	{
		if (UTILITIES.TIME_SCALE_UNIT_ABBREVIATION_STRINGS.contains(format))
			result.set_to_good_status_with_value(UTILITIES.TIME_SCALE_UNIT_ABBREVIATION_STRINGS.at(format));
		else
			result.set_to_good_status_with_value(TimeScaleUnit::NANOSECONDS);
	}

	double Time::convert_seconds(
		const double& time,
		const TimeScaleUnit& format
	)
	{
		try
		{
			Result<double> result;

			convert_seconds(
				result,
				time,
				format
			);

			return result.get_value();
		}
		catch (const std::exception& exception)
		{
			LOGGER.handle_exception_async(
				"QLogicaeCore::Time::convert_seconds()",
				exception.what()
			);

			return 0;
		}
	}

	void Time::convert_seconds(
		Result<double>& result,
		const double& time,
		const TimeScaleUnit& format
	)
	{
		switch (format)
		{
		case TimeScaleUnit::NANOSECONDS: result.set_to_good_status_with_value(time / UTILITIES.SECONDS_OVER_NANOSECONDS); break;
		case TimeScaleUnit::MICROSECONDS: result.set_to_good_status_with_value(time / UTILITIES.SECONDS_OVER_MICROSECONDS); break;
		case TimeScaleUnit::MILLISECONDS: result.set_to_good_status_with_value(time / UTILITIES.SECONDS_OVER_MILLISECONDS); break;
		case TimeScaleUnit::SECONDS: result.set_to_good_status_with_value(time); break;
		case TimeScaleUnit::MINUTES: result.set_to_good_status_with_value(time * UTILITIES.SECONDS_PER_MINUTE); break;
		case TimeScaleUnit::HOURS: result.set_to_good_status_with_value(time * UTILITIES.SECONDS_PER_HOUR); break;
		case TimeScaleUnit::DAYS: result.set_to_good_status_with_value(time * UTILITIES.SECONDS_PER_DAY); break;
		case TimeScaleUnit::WEEKS: result.set_to_good_status_with_value(time * UTILITIES.SECONDS_PER_WEEK); break;
		case TimeScaleUnit::MONTHS: result.set_to_good_status_with_value(time * UTILITIES.SECONDS_PER_MONTH); break;
		case TimeScaleUnit::YEARS: result.set_to_good_status_with_value(time * UTILITIES.SECONDS_PER_YEAR); break;
		default: result.set_to_good_status_with_value(time); break;
		}
	}

	double Time::convert_nanoseconds(
		const double& time,
		const TimeScaleUnit& format
	)
	{
		try
		{
			Result<double> result;

			convert_nanoseconds(
				result,
				time,
				format
			);

			return result.get_value();
		}
		catch (const std::exception& exception)
		{
			LOGGER.handle_exception_async(
				"QLogicaeCore::Time::convert_nanoseconds()",
				exception.what()
			);

			return 0;
		}
	}

	void Time::convert_nanoseconds(
		Result<double>& result,
		const double& time,
		const TimeScaleUnit& format
	)
	{
		switch (format)
		{
		case TimeScaleUnit::NANOSECONDS: result.set_to_good_status_with_value(time); break;
		case TimeScaleUnit::MICROSECONDS: result.set_to_good_status_with_value(time / UTILITIES.SECONDS_OVER_MILLISECONDS); break;
		case TimeScaleUnit::MILLISECONDS: result.set_to_good_status_with_value(time / UTILITIES.SECONDS_OVER_MICROSECONDS); break;
		case TimeScaleUnit::SECONDS: result.set_to_good_status_with_value(time / UTILITIES.SECONDS_OVER_NANOSECONDS); break;
		case TimeScaleUnit::MINUTES: result.set_to_good_status_with_value(time / (UTILITIES.SECONDS_OVER_NANOSECONDS * UTILITIES.SECONDS_PER_MINUTE)); break;
		case TimeScaleUnit::HOURS: result.set_to_good_status_with_value(time / (UTILITIES.SECONDS_OVER_NANOSECONDS * UTILITIES.SECONDS_PER_HOUR)); break;
		case TimeScaleUnit::DAYS: result.set_to_good_status_with_value(time / (UTILITIES.SECONDS_OVER_NANOSECONDS * UTILITIES.SECONDS_PER_DAY)); break;
		case TimeScaleUnit::WEEKS: result.set_to_good_status_with_value(time / (UTILITIES.SECONDS_OVER_NANOSECONDS * UTILITIES.SECONDS_PER_WEEK)); break;
		case TimeScaleUnit::MONTHS: result.set_to_good_status_with_value(time / (UTILITIES.SECONDS_OVER_NANOSECONDS * UTILITIES.SECONDS_PER_MONTH)); break;
		case TimeScaleUnit::YEARS: result.set_to_good_status_with_value(time / (UTILITIES.SECONDS_OVER_NANOSECONDS * UTILITIES.SECONDS_PER_YEAR)); break;
		default: result.set_to_good_status_with_value(time); break;
		}
	}

	std::string Time::_pad3(
		int value
	)
	{
		try
		{
			char buf[4];
			std::snprintf(buf, sizeof(buf), "%03d", value);

			return std::string(buf);
		}
		catch (const std::exception& exception)
		{
			LOGGER.handle_exception_async(
				"QLogicaeCore::Time::_pad3()",
				exception.what()
			);

			return "";
		}
	}

	std::string Time::_format_millisecond_level(
		absl::Duration since_epoch,
		const std::string& sep
	)
	{
		try
		{
			return absl::StrCat(
				_pad3(static_cast<int>(
					absl::ToInt64Milliseconds(since_epoch) % 1000)),
				sep
			);
		}
		catch (const std::exception& exception)
		{
			LOGGER.handle_exception_async(
				"QLogicaeCore::Time::_format_millisecond_level()",
				exception.what()
			);

			return "";
		}
	}

	std::string Time::_format_microsecond_level(
		absl::Duration since_epoch,
		const std::string& sep
	)
	{
		try
		{
			return absl::StrCat(
				_pad3(static_cast<int>(
					absl::ToInt64Milliseconds(since_epoch) % 1000)),
				sep,
				_pad3(static_cast<int>(
					absl::ToInt64Microseconds(since_epoch) % 1000)),
				sep
			);
		}
		catch (const std::exception& exception)
		{
			LOGGER.handle_exception_async(
				"QLogicaeCore::Time::_format_microsecond_level()",
				exception.what()
			);

			return "";
		}
	}

	std::string Time::_format_nanosecond_level(
		absl::Duration since_epoch,
		const std::string& sep
	)
	{
		try
		{
			return absl::StrCat(
				_pad3(static_cast<int>(
					absl::ToInt64Milliseconds(since_epoch) % 1000)),
				sep,
				_pad3(static_cast<int>(
					absl::ToInt64Microseconds(since_epoch) % 1000)),
				sep,
				_pad3(static_cast<int>(
					absl::ToInt64Nanoseconds(since_epoch) % 1000)));
		}
		catch (const std::exception& exception)
		{
			LOGGER.handle_exception_async(
				"QLogicaeCore::Time::_format_nanosecond_level()",
				exception.what()
			);

			return "";
		}
	}

	std::string Time::_format_time(
		const std::tm& tm,
		const char* fmt
	)
	{
		try
		{
			char buffer[64];
			if (std::strftime(buffer, sizeof(buffer), fmt, &tm))
			{
				return std::string(buffer);
			}

			return {};
		}
		catch (const std::exception& exception)
		{
			LOGGER.handle_exception_async(
				"QLogicaeCore::Time::_format_time()",
				exception.what()
			);

			return "";
		}
	}

	std::tm Time::_get_time_zone(
		const TimeZone& zone
	)
	{
		try
		{
			auto now = std::chrono::system_clock::now();
			std::time_t time = std::chrono::system_clock::to_time_t(now);

			std::tm tm{};
			if (zone == TimeZone::UTC)
			{
				gmtime_s(&tm, &time);
			}
			else
			{
				localtime_s(&tm, &time);
			}

			return tm;
		}
		catch (const std::exception& exception)
		{
			LOGGER.handle_exception_async(
				"QLogicaeCore::Time::_get_time_zone()",
				exception.what()
			);

			return {};
		}
		catch (...)
		{
			LOGGER.handle_exception_async(
				"QLogicaeCore::Time::_get_time_zone()",
				"Error"
			);

			return {};
		}
	}
*/


