#pragma once

#include "abstract_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
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
