#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{
	struct
		RegularExpressionManagerConfigurations :
			AbstractConfigurations<RegularExpressionManagerConfigurations>
	{
	public:
		std::string
			pattern =
				default_configurations
					.pattern;

		static RegularExpressionManagerConfigurations
			initial_configurations;

		static RegularExpressionManagerConfigurations
			default_configurations;

		RegularExpressionManagerConfigurations();
	};
}
