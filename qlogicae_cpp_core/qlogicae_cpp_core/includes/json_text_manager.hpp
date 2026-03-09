#pragma once

#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "json_key_index_hash_handler.hpp"
#include "json_text_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    class
		JsonTextManager :
			public AbstractClass<JsonTextManagerConfigurations>
    {
    public:		
        static JsonTextManager&
            singleton;

		JsonTextManager();

		bool
			is_valid(
				const std::string&
					json_text
			);

		bool
			is_key_path_valid(
				const std::string&
					json_text,
				const std::vector<std::variant<std::string, size_t>>&
					key_path
			);

		std::string
			get_raw_json(
				const std::string&
					json_text,
				const std::vector<std::variant<std::string, size_t>>&
					key_path
			);

		std::string
			get_string(
				const std::string&
					json_text,
				const std::vector<std::variant<std::string, size_t>>&
					key_path
			);

		double
			get_double(
				const std::string&
					json_text,
				const std::vector<std::variant<std::string, size_t>>&
					key_path
			);

		bool
			get_boolean(
				const std::string&
					json_text,
				const std::vector<std::variant<std::string, size_t>>&
					key_path
			);

		std::nullptr_t
			get_null(
				const std::string&
					json_text,
				const std::vector<std::variant<std::string, size_t>>&
					key_path
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyIndexHashHandler>
			is_key_path_valid(
				const std::string&
					json_text,
				const std::vector<std::vector<std::variant<std::string, size_t>>>&
					key_paths
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, std::string, JsonKeyIndexHashHandler>
			get_raw_json(
				const std::string&
					json_text,
				const std::vector<std::vector<std::variant<std::string, size_t>>>&
					key_paths
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, std::string, JsonKeyIndexHashHandler>
			get_string(
				const std::string&
					json_text,
				const std::vector<std::vector<std::variant<std::string, size_t>>>&
					key_paths
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, double, JsonKeyIndexHashHandler>
			get_double(
				const std::string&
					json_text,
				const std::vector<std::vector<std::variant<std::string, size_t>>>&
					key_paths
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyIndexHashHandler>
			get_boolean(
				const std::string&
					json_text,
				const std::vector<std::vector<std::variant<std::string, size_t>>>&
					key_paths
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, std::nullptr_t, JsonKeyIndexHashHandler>
			get_null(
				const std::string&
					json_text,
				const std::vector<std::vector<std::variant<std::string, size_t>>>&
					key_paths
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

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyIndexHashHandler>
			is_key_path_valid(				
				const std::vector<std::vector<std::variant<std::string, size_t>>>&
					key_paths
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, std::string, JsonKeyIndexHashHandler>
			get_raw_json(				
				const std::vector<std::vector<std::variant<std::string, size_t>>>&
					key_paths
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, std::string, JsonKeyIndexHashHandler>
			get_string(				
				const std::vector<std::vector<std::variant<std::string, size_t>>>&
					key_paths
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, double, JsonKeyIndexHashHandler>
			get_double(				
				const std::vector<std::vector<std::variant<std::string, size_t>>>&
					key_paths
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyIndexHashHandler>
			get_boolean(				
				const std::vector<std::vector<std::variant<std::string, size_t>>>&
					key_paths
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, std::nullptr_t, JsonKeyIndexHashHandler>
			get_null(				
				const std::vector<std::vector<std::variant<std::string, size_t>>>&
					key_paths
			);
    };
}
