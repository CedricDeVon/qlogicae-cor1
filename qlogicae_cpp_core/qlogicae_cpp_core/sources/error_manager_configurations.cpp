#include "pch.hpp"

#include "../includes/error_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{    
	ErrorManagerConfigurations
		ErrorManagerConfigurations::initial_configurations =
		{
			.is_enable_output_override_enabled =
				false,

			.is_thread_safety_enabled =
				false,

			.is_console_output_enabled =
				true,

			.is_file_output_enabled =
				false,

			.is_gui_output_enabled =
				false,

			.is_runtime_throw_output_enabled =
				true,

			.is_asynchronous_output_enabled =
				false,

			.is_asynchronous_console_output_enabled =
				false,

			.is_asynchronous_file_output_enabled =
				false,

			.is_asynchronous_gui_output_enabled =
				false,

			.is_asynchronous_runtime_throw_output_enabled =
				false,

			.default_title =
				"Exrror",

			.title_message_separator =
				" - ",

			.full_file_output_paths =
				{
					"errors.log"
				},
		};

	ErrorManagerConfigurations
		ErrorManagerConfigurations::default_configurations =
			ErrorManagerConfigurations::initial_configurations;
}
		