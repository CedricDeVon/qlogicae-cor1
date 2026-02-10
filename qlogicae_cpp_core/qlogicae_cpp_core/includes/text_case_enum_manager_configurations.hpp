#pragma once

#include "text_case.hpp"
#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{
	struct
		TextCaseEnumManagerConfigurations :
			AbstractConfigurations<TextCaseEnumManagerConfigurations>
	{
	public:
		TextCase
			type =
				default_configurations
					.type;

		static TextCaseEnumManagerConfigurations
			initial_configurations;

		static TextCaseEnumManagerConfigurations
			default_configurations;

		TextCaseEnumManagerConfigurations();
	};
}

