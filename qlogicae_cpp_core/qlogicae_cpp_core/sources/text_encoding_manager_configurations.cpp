#include "pch.hpp"

#include "../includes/text_encoding_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
	TextEncodingManagerConfigurations
		TextEncodingManagerConfigurations
			::initial_configurations =
				[]()
				{
					TextEncodingManagerConfigurations
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
						.original_type =
							TextEncoding::NONE;

					configurations
						.target_type =
							TextEncoding::NONE;

					return
						configurations;
				}();

	TextEncodingManagerConfigurations
		TextEncodingManagerConfigurations
			::default_configurations =
				TextEncodingManagerConfigurations
					::initial_configurations;
}

