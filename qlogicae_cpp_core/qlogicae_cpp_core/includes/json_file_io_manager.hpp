#pragma once

#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "json_file_io_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
	struct VariantHash
	{
		size_t operator()(const std::variant<std::string, size_t>& v) const {
			return std::visit([](auto&& value) {
				using T = std::decay_t<decltype(value)>;
				if constexpr (std::is_same_v<T, std::string>)
					return std::hash<std::string>{}(value);
				else
					return std::hash<size_t>{}(value);
			}, v);
		}
	};

	struct JsonKeyHash
	{
		size_t operator()(const std::vector<std::variant<std::string, size_t>>& vec) const
		{
			size_t seed = 0;
			for (const auto& elem : vec) {
				seed ^= std::visit([](auto&& val) {
					return std::hash<std::decay_t<decltype(val)>>{}(val);
					}, elem) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
			}
			return seed;
		}
	};

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

		template<typename Type> std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyHash>
			set_values_batch(
				const std::string&
					file_path,
				const std::unordered_map<std::vector<std::variant<std::string, size_t>>, Type, JsonKeyHash>&
					key_value_paths,
				const bool&
					append_mode
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyHash>
			is_key_path_valid(
				const std::string&
					file_path,
				const std::vector<std::vector<std::variant<std::string, size_t>>>&
					key_paths
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, std::string, JsonKeyHash>
			get_raw_json(
				const std::string&
					file_path,
				const std::vector<std::vector<std::variant<std::string, size_t>>>&
					key_paths
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, std::string, JsonKeyHash>
			get_string(
				const std::string&
					file_path,
				const std::vector<std::vector<std::variant<std::string, size_t>>>&
					key_paths
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, double, JsonKeyHash>
			get_double(
				const std::string&
					file_path,
				const std::vector<std::vector<std::variant<std::string, size_t>>>&
					key_paths
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyHash>
			get_boolean(
				const std::string&
					file_path,
				const std::vector<std::vector<std::variant<std::string, size_t>>>&
					key_paths
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, nullptr_t, JsonKeyHash>
			get_null(
				const std::string&
					file_path,
				const std::vector<std::vector<std::variant<std::string, size_t>>>&
					key_paths
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyHash>
			set_raw_json(
				const std::string&
					file_path,
				const std::unordered_map<std::vector<std::variant<std::string, size_t>>, std::string, JsonKeyHash>&
					key_value_paths
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyHash>
			set_string(
				const std::string&
					file_path,
				const std::unordered_map<std::vector<std::variant<std::string, size_t>>, std::string, JsonKeyHash>&
					key_value_paths
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyHash>
			set_double(
				const std::string&
					file_path,
				const std::unordered_map<std::vector<std::variant<std::string, size_t>>, double, JsonKeyHash>&
					key_value_paths
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyHash>
			set_boolean(
				const std::string&
					file_path,
				const std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyHash>&
					key_value_paths
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyHash>
			set_null(
				const std::string&
					file_path,
				const std::unordered_map<std::vector<std::variant<std::string, size_t>>, nullptr_t, JsonKeyHash>&
					key_value_paths
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyHash>
			append_raw_json(
				const std::string&
					file_path,
				const std::unordered_map<std::vector<std::variant<std::string, size_t>>, std::string, JsonKeyHash>&
					key_value_paths
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyHash>
			append_string(
				const std::string&
					file_path,
				const std::unordered_map<std::vector<std::variant<std::string, size_t>>, std::string, JsonKeyHash>&
					key_value_paths
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyHash>
			append_double(
				const std::string&
					file_path,
				const std::unordered_map<std::vector<std::variant<std::string, size_t>>, double, JsonKeyHash>&
					key_value_paths
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyHash>
			append_boolean(
				const std::string&
					file_path,
				const std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyHash>&
					key_value_paths
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyHash>
			append_null(
				const std::string&
					file_path,
				const std::unordered_map<std::vector<std::variant<std::string, size_t>>, nullptr_t, JsonKeyHash>&
					key_value_paths
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyHash>
			remove_value(
				const std::string&
					file_path,
				const std::vector<std::vector<std::variant<std::string, size_t>>>&
					key_paths
			);
		
		std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyHash>
			is_key_path_valid(				
				const std::vector<std::vector<std::variant<std::string, size_t>>>&
					key_paths
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, std::string, JsonKeyHash>
			get_raw_json(				
				const std::vector<std::vector<std::variant<std::string, size_t>>>&
					key_paths
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, std::string, JsonKeyHash>
			get_string(				
				const std::vector<std::vector<std::variant<std::string, size_t>>>&
					key_paths
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, double, JsonKeyHash>
			get_double(				
				const std::vector<std::vector<std::variant<std::string, size_t>>>&
					key_paths
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyHash>
			get_boolean(				
				const std::vector<std::vector<std::variant<std::string, size_t>>>&
					key_paths
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, nullptr_t, JsonKeyHash>
			get_null(				
				const std::vector<std::vector<std::variant<std::string, size_t>>>&
					key_paths
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyHash>
			set_raw_json(				
				const std::unordered_map<std::vector<std::variant<std::string, size_t>>, std::string, JsonKeyHash>&
					key_value_paths
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyHash>
			set_string(				
				const std::unordered_map<std::vector<std::variant<std::string, size_t>>, std::string, JsonKeyHash>&
					key_value_paths
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyHash>
			set_double(				
				const std::unordered_map<std::vector<std::variant<std::string, size_t>>, double, JsonKeyHash>&
					key_value_paths
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyHash>
			set_boolean(				
				const std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyHash>&
					key_value_paths
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyHash>
			set_null(				
				const std::unordered_map<std::vector<std::variant<std::string, size_t>>, nullptr_t, JsonKeyHash>&
					key_value_paths
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyHash>
			append_raw_json(				
				const std::unordered_map<std::vector<std::variant<std::string, size_t>>, std::string, JsonKeyHash>&
					key_value_paths
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyHash>
			append_string(				
				const std::unordered_map<std::vector<std::variant<std::string, size_t>>, std::string, JsonKeyHash>&
					key_value_paths
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyHash>
			append_double(				
				const std::unordered_map<std::vector<std::variant<std::string, size_t>>, double, JsonKeyHash>&
					key_value_paths
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyHash>
			append_boolean(				
				const std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyHash>&
					key_value_paths
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyHash>
			append_null(				
				const std::unordered_map<std::vector<std::variant<std::string, size_t>>, nullptr_t, JsonKeyHash>&
					key_value_paths
			);

		std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyHash>
			remove_value(				
				const std::vector<std::vector<std::variant<std::string, size_t>>>&
					key_paths
			);
    };

	template<typename Type>
		std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyHash>
			JsonFileIoManager
				::set_values_batch(
					const std::string&
						file_path,
					const std::unordered_map<std::vector<std::variant<std::string, size_t>>, Type, JsonKeyHash>&
						key_value_paths,
					const bool&
						append_mode
				)
	{
		std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyHash> results;
		
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
