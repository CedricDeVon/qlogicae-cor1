#pragma once

#include "text_case.hpp"
#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
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

