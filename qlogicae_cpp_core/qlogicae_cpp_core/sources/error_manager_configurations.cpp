#include "pch.hpp"

#include "../includes/error_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{    
	ErrorManagerConfigurations
		ErrorManagerConfigurations
			::initial_configurations =
				[]()
				{
					ErrorManagerConfigurations
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

					configurations
						.is_enable_output_override_enabled =
							false;

					configurations
						.is_console_output_enabled =
							true;

					configurations
						.is_file_output_enabled =
							false;

					configurations
						.is_gui_output_enabled =
							false;

					configurations
						.is_runtime_throw_output_enabled =
							true;

					configurations
						.is_asynchronous_output_enabled =
							false;

					configurations
						.is_asynchronous_console_output_enabled =
							false;

					configurations
						.is_asynchronous_file_output_enabled =
							false;

					configurations
						.is_asynchronous_gui_output_enabled =
							false;

					configurations
						.is_asynchronous_runtime_throw_output_enabled =
							false;

					configurations
						.default_title =
							"Exrror";

					configurations
						.title_message_separator =
							" - ";

					configurations
						.full_file_output_paths =
							{
							"errors.log"
						};

					return
						configurations;
				}();

	ErrorManagerConfigurations
		ErrorManagerConfigurations::default_configurations =
			ErrorManagerConfigurations::initial_configurations;
}
		