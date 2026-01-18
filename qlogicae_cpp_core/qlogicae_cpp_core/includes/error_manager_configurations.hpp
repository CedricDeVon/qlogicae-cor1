#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{    
    struct
		ErrorManagerConfigurations :
			AbstractConfigurations<ErrorManagerConfigurations>
    {        
		bool
			is_enable_output_override_enabled =
				default_configurations
					.is_enable_output_override_enabled;

		bool
			is_console_output_enabled =
				default_configurations
					.is_console_output_enabled;

		bool
			is_file_output_enabled =
				default_configurations
					.is_file_output_enabled;

		bool
			is_gui_output_enabled =
				default_configurations
					.is_gui_output_enabled;

		bool
			is_runtime_throw_output_enabled =
				default_configurations
					.is_runtime_throw_output_enabled;

		bool
			is_asynchronous_output_enabled =
				default_configurations
					.is_asynchronous_output_enabled;

		bool
			is_asynchronous_console_output_enabled =
				default_configurations
					.is_asynchronous_console_output_enabled;

		bool
			is_asynchronous_file_output_enabled =
				default_configurations
					.is_asynchronous_file_output_enabled;

		bool
			is_asynchronous_gui_output_enabled =
				default_configurations
					.is_asynchronous_gui_output_enabled;

		bool
			is_asynchronous_runtime_throw_output_enabled =
				default_configurations
					.is_asynchronous_runtime_throw_output_enabled;

		std::string
			default_title =
				default_configurations
					.default_title;

		std::string
			title_message_separator =
				default_configurations
					.title_message_separator;

		std::vector<std::string>
			full_file_output_paths =
				default_configurations
					.full_file_output_paths;



		static ErrorManagerConfigurations
			initial_configurations;

		static ErrorManagerConfigurations
			default_configurations;
    };    
}
 