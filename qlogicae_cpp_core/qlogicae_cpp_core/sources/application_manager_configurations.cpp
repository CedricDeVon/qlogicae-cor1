#include "pch.hpp"

#include "../includes/application_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    ApplicationManagerConfigurations
		ApplicationManagerConfigurations
			::initial_configurations =
				[]()
				{
					ApplicationManagerConfigurations
						configurations;

					configurations
						.is_method_execution_enabled =
							true;
					
					configurations
						.is_error_handling_enabled =
							true;

					configurations
						.is_thread_safety_override_enabled =
							false;

					configurations
						.is_method_execution_thread_safety_enabled =
							true;

					configurations
						.is_error_handling_thread_safety_enabled =
							true;

					return
						configurations;
				}();

	ApplicationManagerConfigurations
		ApplicationManagerConfigurations
			::default_configurations =
				ApplicationManagerConfigurations
					::initial_configurations;
}
