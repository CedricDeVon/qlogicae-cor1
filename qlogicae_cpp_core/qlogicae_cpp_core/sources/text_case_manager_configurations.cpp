#include "pch.hpp"

#include "../includes/text_case_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
	TextCaseManagerConfigurations
		::TextCaseManagerConfigurations() :
			AbstractConfigurations<TextCaseManagerConfigurations>()
	{
		is_specified_length_enabled =
			false;

		specified_length =
			128;

		target_type =
			TextCase::NONE;
	}

	TextCaseManagerConfigurations
		TextCaseManagerConfigurations
			::initial_configurations;

	TextCaseManagerConfigurations
		TextCaseManagerConfigurations
			::default_configurations =
				TextCaseManagerConfigurations
					::initial_configurations;
}
