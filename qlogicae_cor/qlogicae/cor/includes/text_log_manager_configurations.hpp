#pragma once

#include "log_level.hpp"
#include "log_format.hpp"
#include "time_format.hpp"
#include "abstract_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
	struct
		TextLogManagerConfigurations :
			QLOGICAE_COR_V1__BASE__HPP_CPP__ABSTRACT_CONFIGURATIONS_NAME<TextLogManagerConfigurations>
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
