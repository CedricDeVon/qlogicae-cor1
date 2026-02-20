#include "pch.hpp"

#include "../includes/text_log_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{       
	TextLogManagerConfigurations
		::TextLogManagerConfigurations() :
			AbstractConfigurations<TextLogManagerConfigurations>()
	{
		is_specified_length_enabled =
			false;

		specified_length =
			128;

		message =
			"Log Message";

		log_level =
			LogLevel
				::INFO;

		time_format =
			TimeFormat
				::FULL_TIMESTAMP;

		log_format =
			LogFormat
				::STANDARD;
	}

	TextLogManagerConfigurations
		TextLogManagerConfigurations
			::initial_configurations;

	TextLogManagerConfigurations
		TextLogManagerConfigurations
			::default_configurations =
				TextLogManagerConfigurations
					::initial_configurations;
}

