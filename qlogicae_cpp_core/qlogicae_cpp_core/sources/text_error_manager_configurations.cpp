#include "pch.hpp"

#include "../includes/text_error_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{	
	TextErrorManagerConfigurations
		::TextErrorManagerConfigurations() :
			AbstractConfigurations<TextErrorManagerConfigurations>()
	{
		is_specified_length_enabled =
			false;

		specified_length =
			128;

		title =
			"Exception";

		origin =
			"";

		separator =
			"-";
	}

	TextErrorManagerConfigurations
		TextErrorManagerConfigurations
			::initial_configurations;

	TextErrorManagerConfigurations
		TextErrorManagerConfigurations
			::default_configurations =
				TextErrorManagerConfigurations
					::initial_configurations;
}

