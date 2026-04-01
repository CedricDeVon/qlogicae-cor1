#pragma once

#include "text_case.hpp"
#include "abstract_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
	struct
		TextCaseEnumManagerConfigurations :
			AbstractConfigurations<TextCaseEnumManagerConfigurations>
	{
	public:
		TextCase
			type =
				TextCase
					::NONE;

		TextCaseEnumManagerConfigurations();
	};
}
