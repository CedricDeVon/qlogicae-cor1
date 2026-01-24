#include "pch.hpp"

#include "../includes/text_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
	TextManagerConfigurations
		TextManagerConfigurations
			::initial_configurations =
				[]()
				{
					TextManagerConfigurations
						configurations;

					configurations
						.replace_text_tokens_dictionary =
							{};

					configurations
						.split_text_delimeter =
							",";

					configurations
						.is_specified_length_enabled =
							false;

					configurations
						.specified_length =
							128;

					return
						configurations;
				}();

	TextManagerConfigurations
		TextManagerConfigurations
			::default_configurations =
				TextManagerConfigurations
					::initial_configurations;
}
