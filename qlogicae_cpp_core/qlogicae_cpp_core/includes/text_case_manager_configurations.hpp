#pragma once

#include "text_case.hpp"
#include "abstract_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
	struct
		TextCaseManagerConfigurations :
			AbstractConfigurations<TextCaseManagerConfigurations>
	{
	public:
		bool
			is_specified_length_enabled =
				false;			

		size_t
			specified_length =
				128;

		TextCase
			target_type =
				TextCase::NONE;

		TextCaseManagerConfigurations();
	};
}
