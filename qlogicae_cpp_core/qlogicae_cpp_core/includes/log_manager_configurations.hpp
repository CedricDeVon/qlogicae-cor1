#pragma once

#include "log_level.hpp"
#include "log_format.hpp"
#include "time_format.hpp"
#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{
	template <typename DerivedConfigurations> struct
		LogManagerConfigurations :
			AbstractConfigurations<DerivedConfigurations>
    {
	public:		
		bool
			is_output_override_enabled =
				DerivedConfigurations
					::default_configurations
						.is_output_override_enabled;

		bool
			is_output_enabled =
				DerivedConfigurations
					::default_configurations
						.is_output_enabled;

		LogLevel
			log_level =
				DerivedConfigurations
					::default_configurations
						.log_level;

		std::string
			text =
				DerivedConfigurations
					::default_configurations
						.text;

		LogManagerConfigurations();		
    };

	template <typename DerivedConfigurations>
		LogManagerConfigurations<DerivedConfigurations>
			::LogManagerConfigurations() :
					AbstractConfigurations<DerivedConfigurations>()
	{
		is_output_override_enabled =
			false;

		is_output_enabled =
			false;

		text =
			"";
	}
}
