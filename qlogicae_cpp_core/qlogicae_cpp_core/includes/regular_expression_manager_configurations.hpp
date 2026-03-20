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
				"";

		RegularExpressionManagerConfigurations();
	};
}
