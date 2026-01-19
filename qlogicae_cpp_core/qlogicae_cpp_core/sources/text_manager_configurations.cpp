#include "pch.hpp"

#include "../includes/text_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
	TextManagerConfigurations
		TextManagerConfigurations
			::initial_configurations =
				[]()
				{
					TextManagerConfigurations
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

	TextManagerConfigurations
		TextManagerConfigurations
			::default_configurations =
				TextManagerConfigurations
					::initial_configurations;
}

