#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{
	struct
		TextPlaceholderManagerConfigurations :
			AbstractConfigurations<TextPlaceholderManagerConfigurations>
	{
	public:		
		bool
			is_conditional_callback_enabled =
				default_configurations.is_conditional_callback_enabled;

		std::function<bool(const std::string& text)>
			conditional_callback =
				default_configurations.conditional_callback;

		std::string
			placeholder =
				default_configurations.placeholder;

		static TextPlaceholderManagerConfigurations
			initial_configurations;

		static TextPlaceholderManagerConfigurations
			default_configurations;

		TextPlaceholderManagerConfigurations();
	};
}

