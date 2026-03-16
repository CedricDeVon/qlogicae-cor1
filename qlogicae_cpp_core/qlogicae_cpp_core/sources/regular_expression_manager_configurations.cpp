#include "pch.hpp"

#include "../includes/regular_expression_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
	RegularExpressionManagerConfigurations
		::RegularExpressionManagerConfigurations() :
			AbstractConfigurations<RegularExpressionManagerConfigurations>()
	{
		pattern =
			"";
	}

	RegularExpressionManagerConfigurations
		RegularExpressionManagerConfigurations
			::initial_configurations;

	RegularExpressionManagerConfigurations
		RegularExpressionManagerConfigurations
			::default_configurations =
				RegularExpressionManagerConfigurations
					::initial_configurations;
}

