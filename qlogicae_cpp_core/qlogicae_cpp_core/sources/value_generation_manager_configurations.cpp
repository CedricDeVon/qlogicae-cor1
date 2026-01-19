#include "pch.hpp"

#include "../includes/value_generation_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
	ValueGenerationManagerConfigurations
		ValueGenerationManagerConfigurations
			::initial_configurations =
				[]()
				{
					ValueGenerationManagerConfigurations
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

	ValueGenerationManagerConfigurations
		ValueGenerationManagerConfigurations
			::default_configurations =
				ValueGenerationManagerConfigurations
					::initial_configurations;
}
