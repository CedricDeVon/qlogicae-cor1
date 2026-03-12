#pragma once

#include "abstract_class.hpp"
#include "json_file_io_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
    class
		JsonFileIoManager :
			public AbstractClass<JsonFileIoManagerConfigurations>
    {
    public:		
		boost::mutex
			feature_handling_mutex_2;

		boost::mutex
			feature_handling_mutex_3;

		JsonFileIoManager();

		bool
			is_valid(
				const std::string&
					file_path
			);

		bool
			is_key_path_valid(
				const std::string&
					file_path,
				const std::vector<std::variant<std::string, size_t>>&
					key_path
			);

		std::string
			get_raw_json(
				const std::string&
					file_path,
				const std::vector<std::variant<std::string, size_t>>&
					key_path
			);

		std::string
			get_string(
				const std::string&
					file_path,
				const std::vector<std::variant<std::string, size_t>>&
					key_path
			);

		double
			get_double(
				const std::string&
					file_path,
				const std::vector<std::variant<std::string, size_t>>&
					key_path
			);

		bool
			get_boolean(
				const std::string&
					file_path,
				const std::vector<std::variant<std::string, size_t>>&
					key_path
			);

		std::nullptr_t
			get_null(
				const std::string&
					file_path,
				const std::vector<std::variant<std::string, size_t>>&
					key_path
			);

		bool
			set_raw_json(
				const std::string&
					file_path,
				const std::vector<std::variant<std::string, size_t>>&
					key_path,
				const std::string&
					value
			);

		bool
			set_string(
				const std::string&
					file_path,
				const std::vector<std::variant<std::string, size_t>>&
					key_path,
				const std::string&
					value
			);

		bool
			append_raw_json(
				const std::string&
					file_path,
				const std::vector<std::variant<std::string, size_t>>&
					key_path,
				const std::string&
					value
			);

		bool
			append_string(
				const std::string&
					file_path,
				const std::vector<std::variant<std::string, size_t>>&
					key_path,
				const std::string&
					value
			);

		bool
			remove_value(
				const std::string&
					file_path,
				const std::vector<std::variant<std::string, size_t>>&
					key_path
			);

		bool
			is_valid();

		bool
			is_key_path_valid(
				const std::vector<std::variant<std::string, size_t>>&
					key_path
			);

		std::string
			get_raw_json(
				const std::vector<std::variant<std::string, size_t>>&
					key_path
			);

		std::string
			get_string(
				const std::vector<std::variant<std::string, size_t>>&
					key_path
			);

		double
			get_double(
				const std::vector<std::variant<std::string, size_t>>&
					key_path
			);

		bool
			get_boolean(
				const std::vector<std::variant<std::string, size_t>>&
					key_path
			);

		std::nullptr_t
			get_null(
				const std::vector<std::variant<std::string, size_t>>&
					key_path
			);

		bool
			set_raw_json(
				const std::vector<std::variant<std::string, size_t>>&
					key_path,
				const std::string&
					value
			);

		bool
			set_string(
				const std::vector<std::variant<std::string, size_t>>&
					key_path,
				const std::string&
					value
			);

		bool
			append_raw_json(
				const std::vector<std::variant<std::string, size_t>>&
					key_path,
				const std::string&
					value
			);

		bool
			append_string(
				const std::vector<std::variant<std::string, size_t>>&
					key_path,
				const std::string&
					value
			);

		bool
			remove_value(
				const std::vector<std::variant<std::string, size_t>>&
					key_path
			);

		rapidjson::Value*
			traverse(
				rapidjson::Document&
					document,
				const std::vector<std::variant<std::string, size_t>>&
					key_path
			);
    };
}
