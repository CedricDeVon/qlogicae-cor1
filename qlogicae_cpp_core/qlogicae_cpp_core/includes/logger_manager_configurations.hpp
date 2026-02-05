#pragma once

#include "log_level.hpp"
#include "log_medium.hpp"
#include "time_format.hpp"
#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{   
    struct
		LoggerManagerConfigurations :
			AbstractConfigurations<LoggerManagerConfigurations>
    {
	public:
		std::string
			name =
				"";
		
		bool
			is_output_override_enabled =
				false;
	
		bool
			is_format_override_enabled =
				false;

		bool
			is_fixed_output_length_override_enabled =
				false;
		
		size
			fixed_output_length_override =
				128;

		LogLevel
			level =
				LogLevel::INFO;

		LogMedium
			medium =
				LogMedium::ALL;

		TimeZone
			time_zone =
				TimeZone::UTC;

		TimeFormat
			time_format =
				TimeFormat::FULL_TIMESTAMP;

		bool
			is_console_output_enabled =
				true;
		
		bool
			is_console_output_format_enabled =
				true;
	
		bool
			is_fixed_console_output_length_override_enabled =
				false;
		
		size
			fixed_console_output_length_override =
				128;

		bool
			is_file_output_enabled =
				true;

		bool
			is_file_output_format_enabled =
				true;

		bool
			is_file_collectivization_output_enabled =
				true;

		bool
			is_file_collectivization_output_format_enabled =
				true;

		std::string
			relative_root_folder_path =
				"";

		std::string
			collectivization_output_file_name =
				"all.log";

		std::string
			collectivization_output_file_path =
				"";

		std::string
			collectivization_output_folder_path =
				"";		

		bool
			is_file_fragmentation_output_enabled =
				true;
		
		bool
			is_file_fragmentation_output_format_enabled =
				true;

		TimeFormat
			fragmentation_output_file_name_format =
				TimeFormat::DATE_DASHED;

		std::string
			fragmentation_output_folder_path =
				"";		

		std::string
			error_file_name =
				"error.log";

		std::string
			error_folder_path =
				"";

		std::string
			error_file_path =
				"";

		bool
			is_custom_file_output_enabled =
				true;

		bool
			is_custom_file_output_format_enabled =
				true;

		std::vector<std::string>
			custom_file_output_paths =
				{};

		static LoggerManagerConfigurations
			initial_configurations;

		static LoggerManagerConfigurations
			default_configurations;

		LoggerManagerConfigurations();
    };
}

