#include "pch.hpp"

#include "../includes/text_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{	
	TextManagerConfigurations
		::TextManagerConfigurations() :
			AbstractConfigurations<TextManagerConfigurations>()
	{
		replace_text_tokens_dictionary =
			{};

		split_text_delimeter =
			",";

		is_specified_length_enabled =
			false;

		specified_length =
			128;
	}

	TextManagerConfigurations
		TextManagerConfigurations
			::initial_configurations;

	TextManagerConfigurations
		TextManagerConfigurations
			::default_configurations =
				TextManagerConfigurations
					::initial_configurations;
}
