#pragma once

#include "text_case.hpp"
#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
	struct
		EnumManagerConfigurations :
			AbstractConfigurations<EnumManagerConfigurations>
	{
	public:	
		bool
			is_text_case_conversion_enabled =
				true;

		TextCase
			text_case =
				TextCase
					::UPPERCASE;

		EnumManagerConfigurations();
	};
}

