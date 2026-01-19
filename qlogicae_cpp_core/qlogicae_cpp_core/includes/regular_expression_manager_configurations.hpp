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
		static RegularExpressionManagerConfigurations
			initial_configurations;

		static RegularExpressionManagerConfigurations
			default_configurations;
	};
}
