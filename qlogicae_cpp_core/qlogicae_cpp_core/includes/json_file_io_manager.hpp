#pragma once

#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "key_index_hash_handler.hpp"
#include "json_key_index_hash_handler.hpp"
#include "json_file_io_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    class
		JsonFileIoManager :
			public AbstractClass<JsonFileIoManagerConfigurations>
    {
    public:		
        static JsonFileIoManager&
            singleton;

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
					key_path,
				rapidjson::Value&
					value
			);

		bool
			append_value_raw(
				const std::string&
					file_path,
				const std::vector<std::variant<std::string,size_t>>&
					key_path,
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

		template<typename Type> std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyIndexHashHandler>
			set_values_batch(
				const std::string&
					file_path,
				const std::unordered_map<std::vector<std::variant<std::string, size_t>>, Type, JsonKeyIndexHashHandler>&
					key_value_paths,
				const bool&
					append_mode
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyIndexHashHandler>
			is_key_path_valid(
				const std::string&
					file_path,
				const std::vector<std::vector<std::variant<std::string, size_t>>>&
					key_paths
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, std::string, JsonKeyIndexHashHandler>
			get_raw_json(
				const std::string&
					file_path,
				const std::vector<std::vector<std::variant<std::string, size_t>>>&
					key_paths
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, std::string, JsonKeyIndexHashHandler>
			get_string(
				const std::string&
					file_path,
				const std::vector<std::vector<std::variant<std::string, size_t>>>&
					key_paths
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, double, JsonKeyIndexHashHandler>
			get_double(
				const std::string&
					file_path,
				const std::vector<std::vector<std::variant<std::string, size_t>>>&
					key_paths
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyIndexHashHandler>
			get_boolean(
				const std::string&
					file_path,
				const std::vector<std::vector<std::variant<std::string, size_t>>>&
					key_paths
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, nullptr_t, JsonKeyIndexHashHandler>
			get_null(
				const std::string&
					file_path,
				const std::vector<std::vector<std::variant<std::string, size_t>>>&
					key_paths
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyIndexHashHandler>
			set_raw_json(
				const std::string&
					file_path,
				const std::unordered_map<std::vector<std::variant<std::string, size_t>>, std::string, JsonKeyIndexHashHandler>&
					key_value_paths
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyIndexHashHandler>
			set_string(
				const std::string&
					file_path,
				const std::unordered_map<std::vector<std::variant<std::string, size_t>>, std::string, JsonKeyIndexHashHandler>&
					key_value_paths
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyIndexHashHandler>
			set_double(
				const std::string&
					file_path,
				const std::unordered_map<std::vector<std::variant<std::string, size_t>>, double, JsonKeyIndexHashHandler>&
					key_value_paths
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyIndexHashHandler>
			set_boolean(
				const std::string&
					file_path,
				const std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyIndexHashHandler>&
					key_value_paths
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyIndexHashHandler>
			set_null(
				const std::string&
					file_path,
				const std::unordered_map<std::vector<std::variant<std::string, size_t>>, nullptr_t, JsonKeyIndexHashHandler>&
					key_value_paths
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyIndexHashHandler>
			append_raw_json(
				const std::string&
					file_path,
				const std::unordered_map<std::vector<std::variant<std::string, size_t>>, std::string, JsonKeyIndexHashHandler>&
					key_value_paths
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyIndexHashHandler>
			append_string(
				const std::string&
					file_path,
				const std::unordered_map<std::vector<std::variant<std::string, size_t>>, std::string, JsonKeyIndexHashHandler>&
					key_value_paths
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyIndexHashHandler>
			append_double(
				const std::string&
					file_path,
				const std::unordered_map<std::vector<std::variant<std::string, size_t>>, double, JsonKeyIndexHashHandler>&
					key_value_paths
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyIndexHashHandler>
			append_boolean(
				const std::string&
					file_path,
				const std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyIndexHashHandler>&
					key_value_paths
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyIndexHashHandler>
			append_null(
				const std::string&
					file_path,
				const std::unordered_map<std::vector<std::variant<std::string, size_t>>, nullptr_t, JsonKeyIndexHashHandler>&
					key_value_paths
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyIndexHashHandler>
			remove_value(
				const std::string&
					file_path,
				const std::vector<std::vector<std::variant<std::string, size_t>>>&
					key_paths
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

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, nullptr_t, JsonKeyIndexHashHandler>
			get_null(				
				const std::vector<std::vector<std::variant<std::string, size_t>>>&
					key_paths
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyIndexHashHandler>
			set_raw_json(				
				const std::unordered_map<std::vector<std::variant<std::string, size_t>>, std::string, JsonKeyIndexHashHandler>&
					key_value_paths
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyIndexHashHandler>
			set_string(				
				const std::unordered_map<std::vector<std::variant<std::string, size_t>>, std::string, JsonKeyIndexHashHandler>&
					key_value_paths
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyIndexHashHandler>
			set_double(				
				const std::unordered_map<std::vector<std::variant<std::string, size_t>>, double, JsonKeyIndexHashHandler>&
					key_value_paths
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyIndexHashHandler>
			set_boolean(				
				const std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyIndexHashHandler>&
					key_value_paths
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyIndexHashHandler>
			set_null(				
				const std::unordered_map<std::vector<std::variant<std::string, size_t>>, nullptr_t, JsonKeyIndexHashHandler>&
					key_value_paths
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyIndexHashHandler>
			append_raw_json(				
				const std::unordered_map<std::vector<std::variant<std::string, size_t>>, std::string, JsonKeyIndexHashHandler>&
					key_value_paths
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyIndexHashHandler>
			append_string(				
				const std::unordered_map<std::vector<std::variant<std::string, size_t>>, std::string, JsonKeyIndexHashHandler>&
					key_value_paths
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyIndexHashHandler>
			append_double(				
				const std::unordered_map<std::vector<std::variant<std::string, size_t>>, double, JsonKeyIndexHashHandler>&
					key_value_paths
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyIndexHashHandler>
			append_boolean(				
				const std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyIndexHashHandler>&
					key_value_paths
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyIndexHashHandler>
			append_null(				
				const std::unordered_map<std::vector<std::variant<std::string, size_t>>, nullptr_t, JsonKeyIndexHashHandler>&
					key_value_paths
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyIndexHashHandler>
			remove_value(				
				const std::vector<std::vector<std::variant<std::string, size_t>>>&
					key_paths
			);
    };

	template<typename Type>
		std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyIndexHashHandler>
			JsonFileIoManager
				::set_values_batch(
					const std::string&
						file_path,
					const std::unordered_map<std::vector<std::variant<std::string, size_t>>, Type, JsonKeyIndexHashHandler>&
						key_value_paths,
					const bool&
						append_mode
				)
	{
		std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyIndexHashHandler> results;
		
		try
		{
			fast_io::native_file_loader file(file_path);
			rapidjson::Document doc;
			doc.Parse(file.data(), file.size());
			if(doc.HasParseError())
			{
				for(const auto& [path, _] : key_value_paths)
					results[path] = false;
				return results;
			}

			for(const auto& [path, value] : key_value_paths)
			{
				rapidjson::Value node;
				if constexpr(std::is_same_v<Type, std::string>)
					node.SetString(value.c_str(), doc.GetAllocator());
				else if constexpr(std::is_same_v<Type, double>)
					node.SetDouble(value);
				else if constexpr(std::is_same_v<Type, bool>)
					node.SetBool(value);
				else if constexpr(std::is_same_v<Type, std::nullptr_t>)
					node.SetNull();
				else
					return results;

				bool success = false;
				if(append_mode)
				{
					rapidjson::Value* target = traverse_for_write(doc, path);
					if(target && target->IsArray())
					{
						rapidjson::Value copy;
						copy.CopyFrom(node, doc.GetAllocator());
						target->PushBack(copy, doc.GetAllocator());
						success = true;
					}
				}
				else
				{
					if(path.empty())
					{
						doc.CopyFrom(node, doc.GetAllocator());
						success = true;
					}
					else
					{
						rapidjson::Value* target = traverse_for_write(doc, path);
						if(target)
						{
							rapidjson::Value copy;
							copy.CopyFrom(node, doc.GetAllocator());
							*target = std::move(copy);
							success = true;
						}
					}
				}

				results[path] = success;
			}

			write_document(file_path, doc);
		}
		catch(const std::exception& ex)
		{
			for(const auto& [path, _] : key_value_paths)
				results[path] = false;
			handle_error_outputs(ex);
		}

		return results;
	}

}
