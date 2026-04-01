#pragma once

#include "text_case.hpp"
#include "abstract_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
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
