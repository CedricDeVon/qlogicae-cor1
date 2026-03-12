#pragma once

#include "log_level.hpp"
#include "abstract_class.hpp"
#include "text_log_manager.hpp"
#include "file_log_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
    class
		FileLogManager :
			public AbstractClass<FileLogManagerConfigurations>
    {
    public:
		FileLogManager();

		~FileLogManager();

		bool
			destruct();

		bool
			reset();

		std::string
			get_file_output_path(
				const std::string&
					key
			);

		bool
			is_file_output_path_found(
				const std::string&
					key
			);

		bool
			set_file_output_path(
				const std::string&
					key,
				const std::function<std::string()>&
					value
			);

		bool
			remove_file_output_path(
				const std::string&
					key
			);
		
		bool
			log_formatted_text(
				const std::string&
					text,
				const LogLevel&
					log_level
			);

		bool
			log_formatted_text(
				const std::string&
					text
			);

		bool
			log_formatted_text();


		bool
			log_raw_text(
				const std::string&
					text
			);

		bool
			log_raw_text();
	};
}

