#include "pch.hpp"

#include "../includes/text_case_enum_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
	TextCaseEnumManagerConfigurations
		::TextCaseEnumManagerConfigurations() :
			AbstractConfigurations<TextCaseEnumManagerConfigurations>()
	{
		type =
			TextCase
				::NONE;
	}

	TextCaseEnumManagerConfigurations
		TextCaseEnumManagerConfigurations
			::initial_configurations;

	TextCaseEnumManagerConfigurations
		TextCaseEnumManagerConfigurations
			::default_configurations =
				TextCaseEnumManagerConfigurations
					::initial_configurations;
}
