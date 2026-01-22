#include "pch.hpp"

#include "../includes/time_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
	TimeManagerConfigurations
		TimeManagerConfigurations
			::initial_configurations =
				[]()
				{
					TimeManagerConfigurations
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
						.time_zone =
							TimeZone::UTC;
					

					return
						configurations;
				}();

	TimeManagerConfigurations
		TimeManagerConfigurations
			::default_configurations =
				TimeManagerConfigurations
					::initial_configurations;
}

