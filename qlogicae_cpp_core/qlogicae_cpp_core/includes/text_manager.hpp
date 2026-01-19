#pragma once

#include "encoding.hpp"
#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "text_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    class
		TextManager :
			public AbstractClass<TextManagerConfigurations>
    {
    public:
		static TextManager&
			singleton;

		TextManager();

		~TextManager();

		bool
			construct();

		bool
			destruct();

		std::string
			convert_encoding(
				const std::string&
					value,
				const Encoding&
					original_encoding,
				const Encoding&
					target_encoding
			);

		std::string
			format(
				const std::string&
					value,
				const Encoding&
					original_encoding,
				const Encoding&
					target_encoding
			);
	};
}

/*

- null format
- format

		std::string color_type(
			const LogLevel& log_level
		);

		std::string to_na_format(
			const std::string& text = ""
		);

		std::string replace_tokens(
			const std::string& text,
			const std::unordered_map<std::string, std::string> dictionary
		);

		std::string to_none_format(
			const std::string& text = ""
		);

		std::vector<std::string> split(
			const std::string& text,
			const std::string& delimeters
		);

		std::string to_log_format(
			const std::string& text,
			const LogLevel& log_level,
			const size_t& length = 128
		);

		std::string to_log_format(
			const std::string& text,
			const LogLevel& log_level,
			const TimeFormat& time_format,
			const size_t& length = 128
		);

		std::string to_log_format(
			const std::string& name,
			const std::string& text,
			const LogLevel& log_level,
			const TimeFormat& time_format,
			const size_t& length = 128
		);

		std::string to_log_level_color_format(
			const std::string& text = "",
			const LogLevel& log_level = LogLevel::INFO,
			const size_t& length = 128
		);

		std::string to_result_message_format(
			const std::string& text = "",
			const ResultStatus& result_status = ResultStatus::INFO,
			const TimeFormat& time_format =
			TimeFormat::FULL_TIMESTAMP,
			const size_t& length = 128
		);

		std::string to_exception_text_format(
			const std::string& origin,
			const std::string& message
		);

		std::string to_uppercase(
			const std::string text
		);

		std::string to_lowercase(
			const std::string text
		);

		std::string to_capitalized(
			const std::string text
		);

		std::wstring to_uppercase(
			const std::wstring text
		);

		std::wstring to_lowercase(
			const std::wstring text
		);

		std::wstring to_capitalized(
			const std::wstring text
		);

		const char* to_uppercase(
			const char* text
		);

		const char* to_lowercase(
			const char* text
		);

		const char* to_capitalized(
			const char* text
		);

	constexpr std::string get_log_level_string(
		const LogLevel& level
	)
	{
		switch (level)
		{
			case LogLevel::ALL:
				return UTILITIES.LOG_LEVEL_INFO;

			case LogLevel::INFO:
				return UTILITIES.LOG_LEVEL_INFO;

			case LogLevel::DEBUG:
				return UTILITIES.LOG_LEVEL_DEBUG;

			case LogLevel::SUCCESS:
				return UTILITIES.LOG_LEVEL_SUCCESS;

			case LogLevel::WARNING:
				return UTILITIES.LOG_LEVEL_WARNING;

			case LogLevel::CRITICAL:
				return UTILITIES.LOG_LEVEL_CRITICAL;

			case LogLevel::EXCEPTION:
				return UTILITIES.LOG_LEVEL_EXCEPTION;

			case LogLevel::HIGHLIGHTED_INFO:
				return UTILITIES.LOG_LEVEL_HIGHLIGHTED_INFO;

			default:
				return UTILITIES.LOG_LEVEL_INFO;
		}
	}


*/ 
