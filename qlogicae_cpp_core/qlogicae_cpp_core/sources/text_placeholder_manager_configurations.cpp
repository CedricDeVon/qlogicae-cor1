#include "pch.hpp"

#include "../includes/text_placeholder_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
	TextPlaceholderManagerConfigurations
		TextPlaceholderManagerConfigurations
			::initial_configurations =
				[]()
				{
					TextPlaceholderManagerConfigurations
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
						.is_conditional_callback_enabled =
							true;

					configurations
						.conditional_callback =
							[](const std::string& text){ return text.empty(); };

					configurations
						.placeholder =
							"None";

					return
						configurations;
				}();

	TextPlaceholderManagerConfigurations
		TextPlaceholderManagerConfigurations
			::default_configurations =
				TextPlaceholderManagerConfigurations
					::initial_configurations;
}

