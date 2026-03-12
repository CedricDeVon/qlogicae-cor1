#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
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
