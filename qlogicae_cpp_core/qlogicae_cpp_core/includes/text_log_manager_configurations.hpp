#pragma once

#include "log_level.hpp"
#include "log_format.hpp"
#include "time_format.hpp"
#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
	struct
		TextLogManagerConfigurations :
			AbstractConfigurations<TextLogManagerConfigurations>
	{
	public:		
		bool
			is_specified_length_enabled =
				false;

		size_t
			specified_length =
				128;

		std::string
			message =
				"Log Message";

		LogLevel
			log_level =
				LogLevel
					::INFO;

		TimeFormat
			time_format =
				TimeFormat
					::FULL_TIMESTAMP;

		LogFormat
			log_format =
				LogFormat
					::STANDARD;

		TextLogManagerConfigurations();
	};
}

