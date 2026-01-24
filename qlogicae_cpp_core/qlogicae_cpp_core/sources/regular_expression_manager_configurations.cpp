#include "pch.hpp"

#include "../includes/regular_expression_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
	RegularExpressionManagerConfigurations
		RegularExpressionManagerConfigurations
			::initial_configurations =
				[]()
				{
					RegularExpressionManagerConfigurations
						configurations;

					configurations
						.pattern =
							"";

					return
						configurations;
				}();

	RegularExpressionManagerConfigurations
		RegularExpressionManagerConfigurations
			::default_configurations =
				RegularExpressionManagerConfigurations
					::initial_configurations;
}

