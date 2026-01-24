#include "pch.hpp"

#include "../includes/text_error_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
	TextErrorManagerConfigurations
		TextErrorManagerConfigurations
			::initial_configurations =
				[]()
				{
					TextErrorManagerConfigurations
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

					configurations
						.is_specified_length_enabled =
							false;

					configurations
						.specified_length =
							128;

					configurations
						.title =
							"Exception";

					configurations
						.origin =
							"";

					configurations
						.separator =
							"-";
					

					return
						configurations;
				}();

	TextErrorManagerConfigurations
		TextErrorManagerConfigurations
			::default_configurations =
				TextErrorManagerConfigurations
					::initial_configurations;
}

