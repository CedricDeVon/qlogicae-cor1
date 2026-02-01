#include "pch.hpp"

#include "../includes/text_placeholder_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{	
	TextPlaceholderManagerConfigurations
		::TextPlaceholderManagerConfigurations() :
			AbstractConfigurations<TextPlaceholderManagerConfigurations>()
	{
		is_conditional_callback_enabled =
			true;

		conditional_callback =
			[](const std::string& text){ return text.empty(); };

		placeholder =
			"None";
	}

	TextPlaceholderManagerConfigurations
		TextPlaceholderManagerConfigurations
			::initial_configurations;

	TextPlaceholderManagerConfigurations
		TextPlaceholderManagerConfigurations
			::default_configurations =
				TextPlaceholderManagerConfigurations
					::initial_configurations;
}
