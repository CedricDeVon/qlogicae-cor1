#pragma once

#include "log_level.hpp"
#include "log_format.hpp"
#include "time_format.hpp"
#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
	template <typename DerivedConfigurations> struct
		LogManagerConfigurations :
			AbstractConfigurations<DerivedConfigurations>
    {
	public:		
		bool
			is_output_override_enabled =
				false;

		bool
			is_output_enabled =
				false;

		LogLevel
			log_level =
				LogLevel
					::INFO;

		std::string
			text =
				"Message";

		LogManagerConfigurations();		
    };

	template <typename DerivedConfigurations>
		LogManagerConfigurations<DerivedConfigurations>
			::LogManagerConfigurations() :
					AbstractConfigurations<DerivedConfigurations>()
	{
		
	}
}
