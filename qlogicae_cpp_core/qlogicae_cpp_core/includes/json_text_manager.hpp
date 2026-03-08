#pragma once

#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "json_text_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    class
		JsonTextManager :
			public AbstractClass<JsonTextManagerConfigurations>
    {
    public:		
		std::string
			text;

        static JsonTextManager&
            singleton;

		JsonTextManager();

		std::string
			get_text(
				const std::string&
					file_path
			);

		bool
			set_text(
				const std::string&
					file_path,
				const std::string&
					value
			);

		std::string
			build_text(
				const std::string&
					file_path,
				const std::string&
					value
			);

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
			set_double(
				const std::string&
					file_path,
				const std::vector<std::variant<std::string, size_t>>&
					key_path,
				const double&
					value
			);

		bool
			set_boolean(
				const std::string&
					file_path,
				const std::vector<std::variant<std::string, size_t>>&
					key_path,
				const bool&
					value
			);

		bool
			set_null(
				const std::string&
					file_path,
				const std::vector<std::variant<std::string, size_t>>&
					key_path,
				const std::nullptr_t&
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
			append_double(
				const std::string&
					file_path,
				const std::vector<std::variant<std::string, size_t>>&
					key_path,
				const double&
					value
			);

		bool
			append_boolean(
				const std::string&
					file_path,
				const std::vector<std::variant<std::string, size_t>>&
					key_path,
				const bool&
					value
			);

		bool
			append_null(
				const std::string&
					file_path,
				const std::vector<std::variant<std::string, size_t>>&
					key_path,
				const std::nullptr_t&
					value
			);

		bool
			remove_value(
				const std::string&
					file_path,
				const std::vector<std::variant<std::string, size_t>>&
					key_path
			);

		std::string
			get_text();

		bool
			set_text(
				const std::string&
					value
			);

		std::string
			build_text(
				const std::string&
					value
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
			set_double(
				const std::vector<std::variant<std::string, size_t>>&
					key_path,
				const double&
					value
			);

		bool
			set_boolean(
				const std::vector<std::variant<std::string, size_t>>&
					key_path,
				const bool&
					value
			);

		bool
			set_null(
				const std::vector<std::variant<std::string, size_t>>&
					key_path,
				const std::nullptr_t&
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
			append_double(
				const std::vector<std::variant<std::string, size_t>>&
					key_path,
				const double&
					value
			);

		bool
			append_boolean(
				const std::vector<std::variant<std::string, size_t>>&
					key_path,
				const bool&
					value
			);

		bool
			append_null(
				const std::vector<std::variant<std::string, size_t>>&
					key_path,
				const std::nullptr_t&
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

		rapidjson::Value*
			traverse_for_write(
				rapidjson::Document&
					doc,
				const std::vector<std::variant<std::string,size_t>>&
					key_path
			);

		bool
			write_document(
				const std::string&
					file_path,
				rapidjson::Document&
					doc
			);

		bool
			set_value_raw(
				const std::string&
					file_path,
				const std::vector<std::variant<std::string, size_t>>&
					key_pat,
				rapidjson::Value&
					value
			);

		bool
			append_value_raw(
				const std::string&
					file_path,
				const std::vector<std::variant<std::string,size_t>>&
					key_pat,
				rapidjson::Value&
					value
			);

		bool
			remove_value_internal(
				const std::string&
					file_path,
				const std::vector<std::variant<std::string, size_t>>&
					key_path
			);
    };
}
