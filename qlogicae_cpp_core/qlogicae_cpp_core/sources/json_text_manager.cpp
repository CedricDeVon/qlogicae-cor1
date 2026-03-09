#include "pch.hpp"

#include "../includes/json_text_manager.hpp"

namespace
	QLogicaeCppCore
{        
	JsonTextManager&
		JsonTextManager
			::singleton = 
				SingletonManager
					::get_singleton<JsonTextManager>();	


	
	JsonTextManager
		::JsonTextManager() :
			AbstractClass<JsonTextManagerConfigurations>()
    {
        
    }

	bool
		JsonTextManager
		::is_valid(
			const std::string&
				json_text
		)
	{
		rapidjson::Document document;

		return !document.Parse(json_text.c_str()).HasParseError();
	}

	bool
		JsonTextManager
		::is_key_path_valid(
			const std::string&
				json_text,
			const std::vector<std::variant<std::string, size_t>>&
				key_path
		)
	{
		rapidjson::Document document;

		if (document.Parse(json_text.c_str()).HasParseError())
		{
			return false;
		}

		rapidjson::Value* current = &document;

		for (const auto& key : key_path)
		{
			if (std::holds_alternative<std::string>(key))
			{
				if (!current->IsObject())
				{
					return false;
				}

				const std::string& k = std::get<std::string>(key);

				if (!current->HasMember(k.c_str()))
				{
					return false;
				}

				current = &(*current)[k.c_str()];
			}
			else
			{
				if (!current->IsArray())
				{
					return false;
				}

				size_t index = std::get<size_t>(key);

				if (index >= current->Size())
				{
					return false;
				}

				current = &(*current)[static_cast<rapidjson::SizeType>(index)];
			}
		}

		return true;
	}

	std::string
		JsonTextManager
		::get_raw_json(
			const std::string&
				json_text,
			const std::vector<std::variant<std::string, size_t>>&
				key_path
		)
	{
		rapidjson::Document document;

		if (document.Parse(json_text.c_str()).HasParseError())
		{
			return {};
		}

		rapidjson::Value* current = &document;

		for (const auto& key : key_path)
		{
			if (std::holds_alternative<std::string>(key))
			{
				if (!current->IsObject())
				{
					return {};
				}

				const std::string& k = std::get<std::string>(key);

				if (!current->HasMember(k.c_str()))
				{
					return {};
				}

				current = &(*current)[k.c_str()];
			}
			else
			{
				if (!current->IsArray())
				{
					return {};
				}

				size_t index = std::get<size_t>(key);

				if (index >= current->Size())
				{
					return {};
				}

				current = &(*current)[static_cast<rapidjson::SizeType>(index)];
			}
		}

		rapidjson::StringBuffer buffer;
		rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
		current->Accept(writer);

		return buffer.GetString();
	}

	std::string
		JsonTextManager
		::get_string(
			const std::string&
				json_text,
			const std::vector<std::variant<std::string, size_t>>&
				key_path
		)
	{
		rapidjson::Document document;

		if (document.Parse(json_text.c_str()).HasParseError())
		{
			return {};
		}

		rapidjson::Value* current = &document;

		for (const auto& key : key_path)
		{
			if (std::holds_alternative<std::string>(key))
			{
				if (!current->IsObject())
				{
					return {};
				}

				const std::string& k = std::get<std::string>(key);

				if (!current->HasMember(k.c_str()))
				{
					return {};
				}

				current = &(*current)[k.c_str()];
			}
			else
			{
				if (!current->IsArray())
				{
					return {};
				}

				size_t index = std::get<size_t>(key);

				if (index >= current->Size())
				{
					return {};
				}

				current = &(*current)[static_cast<rapidjson::SizeType>(index)];
			}
		}

		if (!current->IsString())
		{
			return {};
		}

		return std::string(current->GetString(), current->GetStringLength());
	}

	double
		JsonTextManager
		::get_double(
			const std::string&
				json_text,
			const std::vector<std::variant<std::string, size_t>>&
				key_path
		)
	{
		rapidjson::Document document;

		if (document.Parse(json_text.c_str()).HasParseError())
		{
			return 0.0;
		}

		rapidjson::Value* current = &document;

		for (const auto& key : key_path)
		{
			if (std::holds_alternative<std::string>(key))
			{
				if (!current->IsObject())
				{
					return 0.0;
				}

				const std::string& k = std::get<std::string>(key);

				if (!current->HasMember(k.c_str()))
				{
					return 0.0;
				}

				current = &(*current)[k.c_str()];
			}
			else
			{
				if (!current->IsArray())
				{
					return 0.0;
				}

				size_t index = std::get<size_t>(key);

				if (index >= current->Size())
				{
					return 0.0;
				}

				current = &(*current)[static_cast<rapidjson::SizeType>(index)];
			}
		}

		if (!current->IsNumber())
		{
			return 0.0;
		}

		return current->GetDouble();
	}

	bool
		JsonTextManager
		::get_boolean(
			const std::string&
				json_text,
			const std::vector<std::variant<std::string, size_t>>&
				key_path
		)
	{
		rapidjson::Document document;

		if (document.Parse(json_text.c_str()).HasParseError())
		{
			return false;
		}

		rapidjson::Value* current = &document;

		for (const auto& key : key_path)
		{
			if (std::holds_alternative<std::string>(key))
			{
				if (!current->IsObject())
				{
					return false;
				}

				const std::string& k = std::get<std::string>(key);

				if (!current->HasMember(k.c_str()))
				{
					return false;
				}

				current = &(*current)[k.c_str()];
			}
			else
			{
				if (!current->IsArray())
				{
					return false;
				}

				size_t index = std::get<size_t>(key);

				if (index >= current->Size())
				{
					return false;
				}

				current = &(*current)[static_cast<rapidjson::SizeType>(index)];
			}
		}

		if (!current->IsBool())
		{
			return false;
		}

		return current->GetBool();
	}

	std::nullptr_t
		JsonTextManager
		::get_null(
			const std::string&
				json_text,
			const std::vector<std::variant<std::string, size_t>>&
				key_path
		)
	{
		rapidjson::Document document;

		if (document.Parse(json_text.c_str()).HasParseError())
		{
			return nullptr;
		}

		rapidjson::Value* current = &document;

		for (const auto& key : key_path)
		{
			if (std::holds_alternative<std::string>(key))
			{
				if (!current->IsObject())
				{
					return nullptr;
				}

				const std::string& k = std::get<std::string>(key);

				if (!current->HasMember(k.c_str()))
				{
					return nullptr;
				}

				current = &(*current)[k.c_str()];
			}
			else
			{
				if (!current->IsArray())
				{
					return nullptr;
				}

				size_t index = std::get<size_t>(key);

				if (index >= current->Size())
				{
					return nullptr;
				}

				current = &(*current)[static_cast<rapidjson::SizeType>(index)];
			}
		}

		if (!current->IsNull())
		{
			return nullptr;
		}

		return nullptr;
	}

	std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyIndexHashHandler>
		JsonTextManager
		::is_key_path_valid(
			const std::string&
				json_text,
			const std::vector<std::vector<std::variant<std::string, size_t>>>&
				key_paths
		)
	{
		std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyIndexHashHandler> result;

		rapidjson::Document document;

		if (document.Parse(json_text.c_str()).HasParseError())
		{
			for (const auto& path : key_paths)
			{
				result.emplace(path, false);
			}
			return result;
		}

		for (const auto& path : key_paths)
		{
			rapidjson::Value* current = &document;
			bool valid = true;

			for (const auto& key : path)
			{
				if (std::holds_alternative<std::string>(key))
				{
					if (!current->IsObject())
					{
						valid = false;
						break;
					}

					const std::string& k = std::get<std::string>(key);

					if (!current->HasMember(k.c_str()))
					{
						valid = false;
						break;
					}

					current = &(*current)[k.c_str()];
				}
				else
				{
					if (!current->IsArray())
					{
						valid = false;
						break;
					}

					size_t index = std::get<size_t>(key);

					if (index >= current->Size())
					{
						valid = false;
						break;
					}

					current = &(*current)[static_cast<rapidjson::SizeType>(index)];
				}
			}

			result.emplace(path, valid);
		}

		return result;
	}

	std::unordered_map<std::vector<std::variant<std::string, size_t>>, std::string, JsonKeyIndexHashHandler>
		JsonTextManager
		::get_raw_json(
			const std::string&
				json_text,
			const std::vector<std::vector<std::variant<std::string, size_t>>>&
				key_paths
		)
	{
		std::unordered_map<std::vector<std::variant<std::string, size_t>>, std::string, JsonKeyIndexHashHandler> result;

		rapidjson::Document document;

		if (document.Parse(json_text.c_str()).HasParseError())
		{
			for (const auto& path : key_paths)
			{
				result.emplace(path, std::string{});
			}
			return result;
		}

		for (const auto& path : key_paths)
		{
			rapidjson::Value* current = &document;
			bool valid = true;

			for (const auto& key : path)
			{
				if (std::holds_alternative<std::string>(key))
				{
					if (!current->IsObject())
					{
						valid = false;
						break;
					}

					const std::string& k = std::get<std::string>(key);

					if (!current->HasMember(k.c_str()))
					{
						valid = false;
						break;
					}

					current = &(*current)[k.c_str()];
				}
				else
				{
					if (!current->IsArray())
					{
						valid = false;
						break;
					}

					size_t index = std::get<size_t>(key);

					if (index >= current->Size())
					{
						valid = false;
						break;
					}

					current = &(*current)[static_cast<rapidjson::SizeType>(index)];
				}
			}

			if (!valid)
			{
				result.emplace(path, std::string{});
				continue;
			}

			rapidjson::StringBuffer buffer;
			rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
			current->Accept(writer);

			result.emplace(path, buffer.GetString());
		}

		return result;
	}

	std::unordered_map<std::vector<std::variant<std::string, size_t>>, std::string, JsonKeyIndexHashHandler>
		JsonTextManager
		::get_string(
			const std::string&
				json_text,
			const std::vector<std::vector<std::variant<std::string, size_t>>>&
				key_paths
		)
	{
		std::unordered_map<std::vector<std::variant<std::string, size_t>>, std::string, JsonKeyIndexHashHandler> result;

		rapidjson::Document document;

		if (document.Parse(json_text.c_str()).HasParseError())
		{
			for (const auto& path : key_paths)
			{
				result.emplace(path, std::string{});
			}
			return result;
		}

		for (const auto& path : key_paths)
		{
			rapidjson::Value* current = &document;
			bool valid = true;

			for (const auto& key : path)
			{
				if (std::holds_alternative<std::string>(key))
				{
					if (!current->IsObject())
					{
						valid = false;
						break;
					}

					const std::string& k = std::get<std::string>(key);

					if (!current->HasMember(k.c_str()))
					{
						valid = false;
						break;
					}

					current = &(*current)[k.c_str()];
				}
				else
				{
					if (!current->IsArray())
					{
						valid = false;
						break;
					}

					size_t index = std::get<size_t>(key);

					if (index >= current->Size())
					{
						valid = false;
						break;
					}

					current = &(*current)[static_cast<rapidjson::SizeType>(index)];
				}
			}

			if (!valid || !current->IsString())
			{
				result.emplace(path, std::string{});
				continue;
			}

			result.emplace(
				path,
				std::string(current->GetString(), current->GetStringLength())
			);
		}

		return result;
	}

	std::unordered_map<std::vector<std::variant<std::string, size_t>>, double, JsonKeyIndexHashHandler>
		JsonTextManager
		::get_double(
			const std::string&
				json_text,
			const std::vector<std::vector<std::variant<std::string, size_t>>>&
				key_paths
		)
	{
		std::unordered_map<std::vector<std::variant<std::string, size_t>>, double, JsonKeyIndexHashHandler> result;

		rapidjson::Document document;

		if (document.Parse(json_text.c_str()).HasParseError())
		{
			for (const auto& path : key_paths)
			{
				result.emplace(path, 0.0);
			}
			return result;
		}

		for (const auto& path : key_paths)
		{
			rapidjson::Value* current = &document;
			bool valid = true;

			for (const auto& key : path)
			{
				if (std::holds_alternative<std::string>(key))
				{
					if (!current->IsObject())
					{
						valid = false;
						break;
					}

					const std::string& k = std::get<std::string>(key);

					if (!current->HasMember(k.c_str()))
					{
						valid = false;
						break;
					}

					current = &(*current)[k.c_str()];
				}
				else
				{
					if (!current->IsArray())
					{
						valid = false;
						break;
					}

					size_t index = std::get<size_t>(key);

					if (index >= current->Size())
					{
						valid = false;
						break;
					}

					current = &(*current)[static_cast<rapidjson::SizeType>(index)];
				}
			}

			if (!valid || !current->IsNumber())
			{
				result.emplace(path, 0.0);
				continue;
			}

			result.emplace(path, current->GetDouble());
		}

		return result;
	}

	std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyIndexHashHandler>
		JsonTextManager
		::get_boolean(
			const std::string&
				json_text,
			const std::vector<std::vector<std::variant<std::string, size_t>>>&
				key_paths
		)
	{
		std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyIndexHashHandler> result;

		rapidjson::Document document;

		if (document.Parse(json_text.c_str()).HasParseError())
		{
			for (const auto& path : key_paths)
			{
				result.emplace(path, false);
			}
			return result;
		}

		for (const auto& path : key_paths)
		{
			rapidjson::Value* current = &document;
			bool valid = true;

			for (const auto& key : path)
			{
				if (std::holds_alternative<std::string>(key))
				{
					if (!current->IsObject())
					{
						valid = false;
						break;
					}

					const std::string& k = std::get<std::string>(key);

					if (!current->HasMember(k.c_str()))
					{
						valid = false;
						break;
					}

					current = &(*current)[k.c_str()];
				}
				else
				{
					if (!current->IsArray())
					{
						valid = false;
						break;
					}

					size_t index = std::get<size_t>(key);

					if (index >= current->Size())
					{
						valid = false;
						break;
					}

					current = &(*current)[static_cast<rapidjson::SizeType>(index)];
				}
			}

			if (!valid || !current->IsBool())
			{
				result.emplace(path, false);
				continue;
			}

			result.emplace(path, current->GetBool());
		}

		return result;
	}

	std::unordered_map<std::vector<std::variant<std::string, size_t>>, std::nullptr_t, JsonKeyIndexHashHandler>
		JsonTextManager
		::get_null(
			const std::string&
				json_text,
			const std::vector<std::vector<std::variant<std::string, size_t>>>&
				key_paths
		)
	{
		std::unordered_map<std::vector<std::variant<std::string, size_t>>, std::nullptr_t, JsonKeyIndexHashHandler> result;

		rapidjson::Document document;

		if (document.Parse(json_text.c_str()).HasParseError())
		{
			for (const auto& path : key_paths)
			{
				result.emplace(path, nullptr);
			}
			return result;
		}

		for (const auto& path : key_paths)
		{
			rapidjson::Value* current = &document;
			bool valid = true;

			for (const auto& key : path)
			{
				if (std::holds_alternative<std::string>(key))
				{
					if (!current->IsObject())
					{
						valid = false;
						break;
					}

					const std::string& k = std::get<std::string>(key);

					if (!current->HasMember(k.c_str()))
					{
						valid = false;
						break;
					}

					current = &(*current)[k.c_str()];
				}
				else
				{
					if (!current->IsArray())
					{
						valid = false;
						break;
					}

					size_t index = std::get<size_t>(key);

					if (index >= current->Size())
					{
						valid = false;
						break;
					}

					current = &(*current)[static_cast<rapidjson::SizeType>(index)];
				}
			}

			result.emplace(path, nullptr);
		}

		return result;
	}

	bool
		JsonTextManager
			::is_valid()
	{
		return
			is_valid(
				configurations
					.json_text
			);
	}

	bool
		JsonTextManager
			::is_key_path_valid(
				const std::vector<std::variant<std::string, size_t>>&
					key_path
			)
	{
		return
			is_key_path_valid(
				configurations
					.json_text,
				key_path
			);
	}

	std::string
		JsonTextManager
			::get_raw_json(
				const std::vector<std::variant<std::string, size_t>>&
					key_path
			)
	{
		return
			get_raw_json(
				configurations
					.json_text,
				key_path
			);
	}

	std::string
		JsonTextManager
			::get_string(
				const std::vector<std::variant<std::string, size_t>>&
					key_path
			)
	{
		return
			get_string(
				configurations
					.json_text,
				key_path
			);
	}

	double
		JsonTextManager
			::get_double(
				const std::vector<std::variant<std::string, size_t>>&
					key_path
			)
	{
		return
			get_double(
				configurations
					.json_text,
				key_path
			);
	}

	bool
		JsonTextManager
			::get_boolean(
				const std::vector<std::variant<std::string, size_t>>&
					key_path
			)
	{
		return
			get_boolean(
				configurations
					.json_text,
				key_path
			);
	}

	std::nullptr_t
		JsonTextManager
			::get_null(
				const std::vector<std::variant<std::string, size_t>>&
					key_path
			)
	{
		return
			get_null(
				configurations
					.json_text,
				key_path
			);
	}


	std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyIndexHashHandler>
		JsonTextManager
			::is_key_path_valid(				
				const std::vector<std::vector<std::variant<std::string, size_t>>>&
					key_paths
			)
	{
		return
			is_key_path_valid(
				configurations
					.json_text,
				key_paths
			);
	}

	std::unordered_map<std::vector<std::variant<std::string, size_t>>, std::string, JsonKeyIndexHashHandler>
		JsonTextManager
			::get_raw_json(				
				const std::vector<std::vector<std::variant<std::string, size_t>>>&
					key_paths
			)
	{
		return
			get_raw_json(
				configurations
					.json_text,
				key_paths
			);
	}

	std::unordered_map<std::vector<std::variant<std::string, size_t>>, std::string, JsonKeyIndexHashHandler>
		JsonTextManager
			::get_string(				
				const std::vector<std::vector<std::variant<std::string, size_t>>>&
					key_paths
			)
	{
		return
			get_string(
				configurations
					.json_text,
				key_paths
			);
	}

	std::unordered_map<std::vector<std::variant<std::string, size_t>>, double, JsonKeyIndexHashHandler>
		JsonTextManager
			::get_double(				
				const std::vector<std::vector<std::variant<std::string, size_t>>>&
					key_paths
			)
	{
		return
			get_double(
				configurations
					.json_text,
				key_paths
			);
	}

	std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyIndexHashHandler>
		JsonTextManager
			::get_boolean(				
				const std::vector<std::vector<std::variant<std::string, size_t>>>&
					key_paths
			)
	{
		return
			get_boolean(
				configurations
					.json_text,
				key_paths
			);
	}

	std::unordered_map<std::vector<std::variant<std::string, size_t>>, std::nullptr_t, JsonKeyIndexHashHandler>
		JsonTextManager
			::get_null(				
				const std::vector<std::vector<std::variant<std::string, size_t>>>&
					key_paths
			)
	{
		return
			get_null(
				configurations
					.json_text,
				key_paths
			);
	}
}
