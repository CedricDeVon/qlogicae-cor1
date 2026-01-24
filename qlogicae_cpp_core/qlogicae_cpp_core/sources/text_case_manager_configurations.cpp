#include "pch.hpp"

#include "../includes/text_case_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
	TextCaseManagerConfigurations
		TextCaseManagerConfigurations
			::initial_configurations =
				[]()
				{
					TextCaseManagerConfigurations
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
						.target_type =
							TextCase::NONE;
					
					return
						configurations;
				}();

	TextCaseManagerConfigurations
		TextCaseManagerConfigurations
			::default_configurations =
				TextCaseManagerConfigurations
					::initial_configurations;
}
