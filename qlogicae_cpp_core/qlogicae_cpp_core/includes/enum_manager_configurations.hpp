#pragma once

#include "text_case.hpp"
#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{
	struct
		EnumManagerConfigurations :
			AbstractConfigurations<EnumManagerConfigurations>
	{
	public:	
		bool
			is_text_case_conversion_enabled =
				default_configurations
					.is_text_case_conversion_enabled;

		TextCase
			text_case =
				default_configurations
					.text_case;

		static EnumManagerConfigurations
			initial_configurations;

		static EnumManagerConfigurations
			default_configurations;

		EnumManagerConfigurations();
	};
}

