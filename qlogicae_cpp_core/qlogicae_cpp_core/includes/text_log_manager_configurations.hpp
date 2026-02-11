#pragma once

#include "log_level.hpp"
#include "log_format.hpp"
#include "time_format.hpp"
#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{
	struct
		TextLogManagerConfigurations :
			AbstractConfigurations<TextLogManagerConfigurations>
	{
	public:		
		bool
			is_specified_length_enabled =
				default_configurations
					.is_specified_length_enabled;

		size_t
			specified_length =
				default_configurations
					.specified_length;

		std::string
			message =
				default_configurations
					.message;

		LogLevel
			log_level =
				default_configurations
					.log_level;

		TimeFormat
			time_format =
				default_configurations
					.time_format;

		LogFormat
			log_format =
				default_configurations
					.log_format;

		static TextLogManagerConfigurations
			initial_configurations;

		static TextLogManagerConfigurations
			default_configurations;

		TextLogManagerConfigurations();
	};
}

