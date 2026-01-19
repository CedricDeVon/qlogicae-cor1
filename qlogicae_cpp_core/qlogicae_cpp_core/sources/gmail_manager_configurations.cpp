#include "pch.hpp"

#include "../includes/gmail_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    GmailManagerConfigurations
		GmailManagerConfigurations
			::initial_configurations =
				[]()
				{
					GmailManagerConfigurations
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

	GmailManagerConfigurations
		GmailManagerConfigurations
			::default_configurations =
				GmailManagerConfigurations
					::initial_configurations;
}
