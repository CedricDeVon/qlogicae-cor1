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
						.is_feature_handling_enabled =
							true;
					
					configurations
						.is_error_handling_enabled =
							true;

					configurations
						.is_thread_safety_override_enabled =
							false;

					configurations
						.is_feature_handling_thread_safety_enabled =
							false;

					configurations
						.is_utility_handling_thread_safety_enabled =
							true;

					configurations
						.is_error_handling_thread_safety_enabled =
							true;

					return
						configurations;
				}();

	RegularExpressionManagerConfigurations
		RegularExpressionManagerConfigurations
			::default_configurations =
				RegularExpressionManagerConfigurations
					::initial_configurations;
}

