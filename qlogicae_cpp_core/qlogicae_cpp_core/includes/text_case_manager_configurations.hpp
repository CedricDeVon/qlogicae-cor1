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
				default_configurations
					.is_specified_length_enabled;			

		size_t
			specified_length =
				default_configurations
					.specified_length;

		TextCase
			target_type =
				default_configurations
					.target_type;

		static TextCaseManagerConfigurations
			initial_configurations;

		static TextCaseManagerConfigurations
			default_configurations;

		TextCaseManagerConfigurations();
	};
}

