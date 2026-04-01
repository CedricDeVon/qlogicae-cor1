#pragma once

#include "abstract_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
    struct
		ErrorManagerConfigurations :
			AbstractConfigurations<ErrorManagerConfigurations>
    {    
	public:		
		bool
			is_feature_thread_safety_handling_enabled =
				true;

		bool
			is_enable_output_override_enabled =
				false;

		bool
			is_console_output_enabled =
				true;

		bool
			is_file_output_enabled =
				false;

		bool
			is_gui_output_enabled =
				false;

		bool
			is_runtime_throw_output_enabled =
				true;

		bool
			is_asynchronous_output_enabled =
				false;

		bool
			is_asynchronous_console_output_enabled =
				false;

		bool
			is_asynchronous_file_output_enabled =
				false;

		bool
			is_asynchronous_gui_output_enabled =
				false;

		bool
			is_asynchronous_runtime_throw_output_enabled =
				false;

		std::string
			default_title =
				"Error";

		std::string
			title_message_separator =
				" - ";

		std::vector<std::string>
			full_file_output_paths =
				{
					"errors.log"
				};

		ErrorManagerConfigurations();
    };    
}
