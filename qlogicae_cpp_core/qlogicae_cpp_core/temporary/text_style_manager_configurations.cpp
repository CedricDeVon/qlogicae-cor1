#include "pch.hpp"

#include "../includes/text_style_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
	TextStyleManagerConfigurations
		TextStyleManagerConfigurations
			::initial_configurations =
				[]()
				{
					TextStyleManagerConfigurations
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

					return
						configurations;
				}();

	TextStyleManagerConfigurations
		TextStyleManagerConfigurations
			::default_configurations =
				TextStyleManagerConfigurations
					::initial_configurations;
}

