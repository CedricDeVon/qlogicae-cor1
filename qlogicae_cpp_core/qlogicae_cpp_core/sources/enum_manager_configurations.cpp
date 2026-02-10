#include "pch.hpp"

#include "../includes/enum_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{   
	EnumManagerConfigurations
		::EnumManagerConfigurations() :
			AbstractConfigurations<EnumManagerConfigurations>()
	{
		is_text_case_conversion_enabled =
			true;

		text_case =
			TextCase
				::UPPERCASE;
	}

	EnumManagerConfigurations
		EnumManagerConfigurations
			::initial_configurations;

	EnumManagerConfigurations
		EnumManagerConfigurations
			::default_configurations =
				EnumManagerConfigurations
					::initial_configurations;
}
