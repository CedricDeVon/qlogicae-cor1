#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
	struct
		TextPlaceholderManagerConfigurations :
			AbstractConfigurations<TextPlaceholderManagerConfigurations>
	{
	public:		
		bool
			is_conditional_callback_enabled =
				true;

		std::function<bool(const std::string& text)>
			conditional_callback =
				[](const std::string& text){ return text.empty(); };

		std::string
			placeholder =
				"None";

		TextPlaceholderManagerConfigurations();
	};
}

