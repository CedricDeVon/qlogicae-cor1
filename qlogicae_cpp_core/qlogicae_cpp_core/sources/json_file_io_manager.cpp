#include "pch.hpp"

#include "../includes/json_file_io_manager.hpp"

namespace
	QLogicaeCppCore
{        
	JsonFileIoManager&
		JsonFileIoManager
			::singleton = 
				SingletonManager
					::get_singleton<JsonFileIoManager>();	


	
	JsonFileIoManager
		::JsonFileIoManager() :
			AbstractClass<JsonFileIoManagerConfigurations>()
    {
        
    }

	rapidjson::Value*
		JsonFileIoManager
			::traverse(
				rapidjson::Document&
					document,
				const std::vector<std::variant<std::string, size_t>>&
					key_path
			)
	{
		rapidjson::Value* current = &document;

		for (const auto& key : key_path)
		{
			if (std::holds_alternative<std::string>(key))
			{
				const auto& name = std::get<std::string>(key);

				if (!current->IsObject())
					return nullptr;

				if (!current->HasMember(name.c_str()))
					return nullptr;

				current = &((*current)[name.c_str()]);
			}
			else
			{
				rapidjson::SizeType index =
					static_cast<rapidjson::SizeType>(
						std::get<size_t>(key)
						);

				if (!current->IsArray())
					return nullptr;

				if (index >= current->Size())
					return nullptr;

				current = &((*current)[index]);
			}
		}

		return current;
	}

	rapidjson::Value*
		JsonFileIoManager
			::traverse_for_write(
				rapidjson::Document&
					doc,
				const std::vector<std::variant<std::string,size_t>>&
					key_path
			)
	{
		rapidjson::Value* current = &doc;

		for(const auto& key : key_path)
		{
			if(std::holds_alternative<std::string>(key))
			{
				const auto& name = std::get<std::string>(key);

				if(!current->IsObject())
				{
					current->SetObject();
				}

				if(!current->HasMember(name.c_str()))
				{
					rapidjson::Value val;
					current->AddMember(
						rapidjson::Value(name.c_str(), doc.GetAllocator()),
						val,
						doc.GetAllocator()
					);
				}

				current = &((*current)[name.c_str()]);
			}
			else
			{
				rapidjson::SizeType index =
					static_cast<rapidjson::SizeType>(std::get<size_t>(key));

				if(!current->IsArray())
				{
					current->SetArray();
				}

				if(index >= current->Size())
				{
					while (current->Size() <= index)
						current->PushBack(rapidjson::Value(), doc.GetAllocator());
				}

				current = &((*current)[index]);
			}
		}

		return current;
	}

	bool
		JsonFileIoManager
			::write_document(
				const std::string&
					file_path,
				rapidjson::Document&
					doc
			)
	{
		try
        {
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling() ||				
				(
					configurations
						.is_edge_case_enabled_for_feature_handling() &&
					(
						file_path.empty() ||
						!std::filesystem::exists(file_path) ||
						std::filesystem::is_directory(file_path)
					)
				)
			)
			{
				return
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_feature_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}

			rapidjson::StringBuffer buffer;
			rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
			doc.Accept(writer);

			fast_io::obuf_file out(file_path);
			std::string text = buffer.GetString();

			fast_io::write(
				out,
				text.begin(),
				text.end()
			);

			return true;
        }
        catch
        (
			const std::exception&
                exception
        )
        {
            return
				handle_error_outputs(
					exception
				);
        }		
	}

	bool
		JsonFileIoManager
			::set_value_raw(
				const std::string&
					file_path,
				const std::vector<std::variant<std::string, size_t>>&
					key_path,
				rapidjson::Value&
					value
			)
	{		
		try
        {
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling() ||				
				(
					configurations
						.is_edge_case_enabled_for_feature_handling() &&
					(
						file_path.empty() ||
						!std::filesystem::exists(file_path) ||
						std::filesystem::is_directory(file_path) ||
						!key_path.empty()
					)
				)
			)
			{
				return
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_feature_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}

			fast_io::native_file_loader file(file_path);
			rapidjson::Document doc;
			doc.Parse(file.data(), file.size());
			if (doc.HasParseError())
				return false;

			if (key_path.empty())
			{
				doc.CopyFrom(value, doc.GetAllocator());
				return write_document(file_path, doc);
			}

			rapidjson::Value* current = traverse_for_write(doc, key_path);
			if (!current)
				return false;

			rapidjson::Value copy;
			copy.CopyFrom(value, doc.GetAllocator());
			*current = std::move(copy);

			return write_document(file_path, doc);
        }
        catch
        (
			const std::exception&
                exception
        )
        {
            return
				handle_error_outputs(
					exception
				);
        }
	}

	bool
		JsonFileIoManager
			::append_value_raw(
				const std::string&
					file_path,
				const std::vector<std::variant<std::string,size_t>>&
					key_path,
				rapidjson::Value&
					value
			)
	{
		try
        {
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling() ||				
				(
					configurations
						.is_edge_case_enabled_for_feature_handling() &&
					(
						file_path.empty() ||
						!std::filesystem::exists(file_path) ||
						std::filesystem::is_directory(file_path) ||
						!key_path.empty()
					)
				)
			)
			{
				return
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_feature_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}

			fast_io::native_file_loader file(file_path);
			rapidjson::Document doc;
			doc.Parse(file.data(), file.size());
			if (doc.HasParseError())
				return false;

			rapidjson::Value* current = traverse_for_write(doc, key_path);
			if (!current || !current->IsArray())
				return false;

			rapidjson::Value copy;
			copy.CopyFrom(value, doc.GetAllocator());
			current->PushBack(copy, doc.GetAllocator());

			return write_document(file_path, doc);
        }
        catch
        (
			const std::exception&
                exception
        )
        {
            return
				handle_error_outputs(
					exception
				);
        }
	}

	bool
		JsonFileIoManager
			::remove_value_internal(
				const std::string&
					file_path,
				const std::vector<std::variant<std::string,size_t>>&
					key_path
		)
	{
		try
        {
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling() ||				
				(
					configurations
						.is_edge_case_enabled_for_feature_handling() &&
					(
						file_path.empty() ||
						!std::filesystem::exists(file_path) ||
						std::filesystem::is_directory(file_path) ||
						key_path.empty()
					)
				)
			)
			{
				return
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_feature_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}

			fast_io::native_file_loader file(file_path);
			rapidjson::Document doc;
			doc.Parse(file.data(), file.size());
			if (doc.HasParseError())
				return false;

			rapidjson::Value* current = &doc;

			for (size_t i = 0; i + 1 < key_path.size(); ++i)
			{
				const auto& key = key_path[i];

				if (std::holds_alternative<std::string>(key))
				{
					const auto& name = std::get<std::string>(key);
					if (!current->IsObject() || !current->HasMember(name.c_str()))
						return false;
					current = &((*current)[name.c_str()]);
				}
				else
				{
					rapidjson::SizeType index =
						static_cast<rapidjson::SizeType>(std::get<size_t>(key));
					if (!current->IsArray() || index >= current->Size())
						return false;
					current = &((*current)[index]);
				}
			}

			const auto& last = key_path.back();

			if (std::holds_alternative<std::string>(last))
			{
				const auto& name = std::get<std::string>(last);
				if (!current->IsObject() || !current->HasMember(name.c_str()))
					return false;
				current->RemoveMember(name.c_str());
			}
			else
			{
				rapidjson::SizeType index =
					static_cast<rapidjson::SizeType>(std::get<size_t>(last));
				if (!current->IsArray() || index >= current->Size())
					return false;
				current->Erase(current->Begin() + index);
			}

			return write_document(file_path, doc);
        }
        catch
        (
			const std::exception&
                exception
        )
        {
            return
				handle_error_outputs(
					exception
				);
        }
	}

	bool
		JsonFileIoManager
			::is_valid(
				const std::string&
					file_path
			)
	{
		try
        {
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling() ||				
				(
					configurations
						.is_edge_case_enabled_for_feature_handling() &&
					(
						file_path.empty() ||
						!std::filesystem::exists(file_path) ||
						std::filesystem::is_directory(file_path)
					)
				)
			)
			{
				return
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_feature_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}

			fast_io::native_file_loader file(file_path);

			rapidjson::Document doc;
			doc.Parse(file.data(), file.size());

			return !doc.HasParseError();
        }
        catch
        (
			const std::exception&
                exception
        )
        {
            return
				handle_error_outputs(
					exception
				);
        }
	}

	bool
		JsonFileIoManager
			::is_key_path_valid(
				const std::string&
					file_path,
				const std::vector<std::variant<std::string, size_t>>&
					key_path
			)
	{
		try
        {
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling() ||				
				(
					configurations
						.is_edge_case_enabled_for_feature_handling() &&
					(
						file_path.empty() ||
						!std::filesystem::exists(file_path) ||
						std::filesystem::is_directory(file_path) ||
						!key_path.size()
					)
				)
			)
			{
				return
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_feature_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}

			fast_io::native_file_loader file(file_path);

			rapidjson::Document doc;
			doc.Parse(file.data(), file.size());

			if (doc.HasParseError())
				return false;

			return traverse(doc, key_path) != nullptr;
        }
        catch
        (
			const std::exception&
                exception
        )
        {
            return
				handle_error_outputs(
					exception
				);
        }
	}

	std::string
		JsonFileIoManager
			::get_raw_json(
				const std::string&
					file_path,
				const std::vector<std::variant<std::string, size_t>>&
					key_path
			)
	{
		try
        {
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling() ||				
				(
					configurations
						.is_edge_case_enabled_for_feature_handling() &&
					(
						file_path.empty() ||
						!std::filesystem::exists(file_path) ||
						std::filesystem::is_directory(file_path) ||
						!key_path.size()
					)
				)
			)
			{
				return
					"";
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_feature_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}

			fast_io::native_file_loader file(file_path);

			rapidjson::Document doc;
			doc.Parse(file.data(), file.size());

			if (doc.HasParseError())
				return {};

			auto* value = traverse(doc, key_path);
			if (!value)
				return {};

			rapidjson::StringBuffer buffer;
			rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
			value->Accept(writer);

			return buffer.GetString();
        }
        catch
        (
			const std::exception&
                exception
        )
        {
            return
				handle_error_outputs<std::string>(
					exception
				);
        }
	}

	std::string
		JsonFileIoManager
			::get_string(
				const std::string&
					file_path,
				const std::vector<std::variant<std::string, size_t>>&
					key_path
			)
	{
		try
        {
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling() ||				
				(
					configurations
						.is_edge_case_enabled_for_feature_handling() &&
					(
						file_path.empty() ||
						!std::filesystem::exists(file_path) ||
						std::filesystem::is_directory(file_path) ||
						!key_path.size()
					)
				)
			)
			{
				return
					"";
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_feature_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}

			fast_io::native_file_loader file(file_path);

			rapidjson::Document doc;
			doc.Parse(file.data(), file.size());

			if (doc.HasParseError())
				return {};

			auto* value = traverse(doc, key_path);
			if (!value || !value->IsString())
				return {};

			return value->GetString();
        }
        catch
        (
			const std::exception&
                exception
        )
        {
            return
				handle_error_outputs<std::string>(
					exception
				);
        }
	}

	double
		JsonFileIoManager
			::get_double(
				const std::string&
					file_path,
				const std::vector<std::variant<std::string, size_t>>&
					key_path
			)
	{
		try
        {
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling() ||				
				(
					configurations
						.is_edge_case_enabled_for_feature_handling() &&
					(
						file_path.empty() ||
						!std::filesystem::exists(file_path) ||
						std::filesystem::is_directory(file_path) ||
						!key_path.size()
					)
				)
			)
			{
				return
					0;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_feature_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}

			fast_io::native_file_loader file(file_path);

			rapidjson::Document doc;
			doc.Parse(file.data(), file.size());

			if (doc.HasParseError())
				return 0.0;

			auto* value = traverse(doc, key_path);
			if (!value || !value->IsNumber())
				return 0.0;

			return value->GetDouble();
        }
        catch
        (
			const std::exception&
                exception
        )
        {
            return
				handle_error_outputs<double>(
					exception
				);
        }
	}

	bool
		JsonFileIoManager
			::get_boolean(
				const std::string&
					file_path,
				const std::vector<std::variant<std::string, size_t>>&
					key_path
			)
	{
		try
        {
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling() ||				
				(
					configurations
						.is_edge_case_enabled_for_feature_handling() &&
					(
						file_path.empty() ||
						!std::filesystem::exists(file_path) ||
						std::filesystem::is_directory(file_path) ||
						!key_path.size()
					)
				)
			)
			{
				return
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_feature_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}

			fast_io::native_file_loader file(file_path);

			rapidjson::Document doc;
			doc.Parse(file.data(), file.size());

			if (doc.HasParseError())
				return false;

			auto* value = traverse(doc, key_path);
			if (!value || !value->IsBool())
				return false;

			return value->GetBool();
        }
        catch
        (
			const std::exception&
                exception
        )
        {
            return
				handle_error_outputs(
					exception
				);
        }
	}

	std::nullptr_t
		JsonFileIoManager
			::get_null(
				const std::string&
					file_path,
				const std::vector<std::variant<std::string, size_t>>&
					key_path
			)
	{
		try
        {
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling() ||				
				(
					configurations
						.is_edge_case_enabled_for_feature_handling() &&
					(
						file_path.empty() ||
						!std::filesystem::exists(file_path) ||
						std::filesystem::is_directory(file_path) ||
						!key_path.size()
					)
				)
			)
			{
				return
					nullptr;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_feature_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}

			fast_io::native_file_loader file(file_path);

			rapidjson::Document doc;
			doc.Parse(file.data(), file.size());

			if (doc.HasParseError())
				return nullptr;

			auto* value = traverse(doc, key_path);
			if (!value || !value->IsNull())
				return nullptr;

			return nullptr;
        }
        catch
        (
			const std::exception&
                exception
        )
        {
            return
				handle_error_outputs<std::nullptr_t>(
					exception
				);
        }
	}

	bool
		JsonFileIoManager
			::set_raw_json(
				const std::string&
					file_path,
				const std::vector<std::variant<std::string, size_t>>&
					key_path,
				const std::string&
					value
			)
	{
		try
        {
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling() ||				
				(
					configurations
						.is_edge_case_enabled_for_feature_handling() &&
					(
						file_path.empty() ||
						!std::filesystem::exists(file_path) ||
						std::filesystem::is_directory(file_path) ||
						!key_path.size()
					)
				)
			)
			{
				return
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_feature_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}

			rapidjson::Document temp;
			temp.Parse(value.c_str());
			if (temp.HasParseError())
				return false;

			return set_value_raw(file_path, key_path, temp);
        }
        catch
        (
			const std::exception&
                exception
        )
        {
            return
				handle_error_outputs(
					exception
				);
        }
	}

	bool
		JsonFileIoManager
			::set_string(
				const std::string&
					file_path,
				const std::vector<std::variant<std::string, size_t>>&
					key_path,
				const std::string&
					value
			)
	{
		try
        {
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling() ||				
				(
					configurations
						.is_edge_case_enabled_for_feature_handling() &&
					(
						file_path.empty() ||
						!std::filesystem::exists(file_path) ||
						std::filesystem::is_directory(file_path) ||
						!key_path.size()
					)
				)
			)
			{
				return
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_feature_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}

			rapidjson::Document temp;
			temp.SetString(value.c_str(), temp.GetAllocator());
			return set_value_raw(file_path, key_path, temp);
        }
        catch
        (
			const std::exception&
                exception
        )
        {
            return
				handle_error_outputs(
					exception
				);
        }
	}

	bool
		JsonFileIoManager
			::set_double(
				const std::string&
					file_path,
				const std::vector<std::variant<std::string, size_t>>&
					key_path,
				const double&
					value
			)
	{
		try
        {
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling() ||				
				(
					configurations
						.is_edge_case_enabled_for_feature_handling() &&
					(
						file_path.empty() ||
						!std::filesystem::exists(file_path) ||
						std::filesystem::is_directory(file_path) ||
						!key_path.size()
					)
				)
			)
			{
				return
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_feature_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}

			rapidjson::Document temp;
			temp.SetDouble(value);
			return set_value_raw(file_path, key_path, temp);
        }
        catch
        (
			const std::exception&
                exception
        )
        {
            return
				handle_error_outputs(
					exception
				);
        }
	}

	bool
		JsonFileIoManager
			::set_boolean(
				const std::string&
					file_path,
				const std::vector<std::variant<std::string, size_t>>&
					key_path,
				const bool&
					value
			)
	{
		try
        {
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling() ||				
				(
					configurations
						.is_edge_case_enabled_for_feature_handling() &&
					(
						file_path.empty() ||
						!std::filesystem::exists(file_path) ||
						std::filesystem::is_directory(file_path) ||
						!key_path.size()
					)
				)
			)
			{
				return
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_feature_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}

			rapidjson::Document temp;
			temp.SetBool(value);
			return set_value_raw(file_path, key_path, temp);
        }
        catch
        (
			const std::exception&
                exception
        )
        {
            return
				handle_error_outputs(
					exception
				);
        }
	}

	bool
		JsonFileIoManager
			::set_null(
				const std::string&
					file_path,
				const std::vector<std::variant<std::string, size_t>>&
					key_path,
				const std::nullptr_t&
					value
			)
	{
		try
        {
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling() ||				
				(
					configurations
						.is_edge_case_enabled_for_feature_handling() &&
					(
						file_path.empty() ||
						!std::filesystem::exists(file_path) ||
						std::filesystem::is_directory(file_path) ||
						!key_path.size()
					)
				)
			)
			{
				return
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_feature_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}

			rapidjson::Document temp;
			temp.SetNull();
			return set_value_raw(file_path, key_path, temp);
        }
        catch
        (
			const std::exception&
                exception
        )
        {
            return
				handle_error_outputs(
					exception
				);
        }
	}

	bool
		JsonFileIoManager
			::append_raw_json(
				const std::string&
					file_path,
				const std::vector<std::variant<std::string, size_t>>&
					key_path,
				const std::string&
					value
			)
	{
		try
        {
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling() ||				
				(
					configurations
						.is_edge_case_enabled_for_feature_handling() &&
					(
						file_path.empty() ||
						!std::filesystem::exists(file_path) ||
						std::filesystem::is_directory(file_path) ||
						!key_path.size()
					)
				)
			)
			{
				return
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_feature_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}

			rapidjson::Document temp;
			temp.Parse(value.c_str());
			if (temp.HasParseError())
				return false;

			return append_value_raw(file_path, key_path, temp);
        }
        catch
        (
			const std::exception&
                exception
        )
        {
            return
				handle_error_outputs(
					exception
				);
        }
	}

	bool
		JsonFileIoManager
			::append_string(
				const std::string&
					file_path,
				const std::vector<std::variant<std::string, size_t>>&
					key_path,
				const std::string&
					value
			)
	{
		try
        {
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling() ||				
				(
					configurations
						.is_edge_case_enabled_for_feature_handling() &&
					(
						file_path.empty() ||
						!std::filesystem::exists(file_path) ||
						std::filesystem::is_directory(file_path) ||
						!key_path.size()
					)
				)
			)
			{
				return
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_feature_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}

			rapidjson::Document temp;
			temp.SetString(value.c_str(), temp.GetAllocator());
			return append_value_raw(file_path, key_path, temp);
        }
        catch
        (
			const std::exception&
                exception
        )
        {
            return
				handle_error_outputs(
					exception
				);
        }
	}

	bool
		JsonFileIoManager
			::append_double(
				const std::string&
					file_path,
				const std::vector<std::variant<std::string, size_t>>&
					key_path,
				const double&
					value
			)
	{
		try
        {
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling() ||				
				(
					configurations
						.is_edge_case_enabled_for_feature_handling() &&
					(
						file_path.empty() ||
						!std::filesystem::exists(file_path) ||
						std::filesystem::is_directory(file_path) ||
						!key_path.size()
					)
				)
			)
			{
				return
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_feature_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}

			rapidjson::Document temp;
			temp.SetDouble(value);
			return append_value_raw(file_path, key_path, temp);
        }
        catch
        (
			const std::exception&
                exception
        )
        {
            return
				handle_error_outputs(
					exception
				);
        }
	}

	bool
		JsonFileIoManager
			::append_boolean(
				const std::string&
					file_path,
				const std::vector<std::variant<std::string, size_t>>&
					key_path,
				const bool&
					value
			)
	{
		try
        {
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling() ||				
				(
					configurations
						.is_edge_case_enabled_for_feature_handling() &&
					(
						file_path.empty() ||
						!std::filesystem::exists(file_path) ||
						std::filesystem::is_directory(file_path) ||
						!key_path.size()
					)
				)
			)
			{
				return
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_feature_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}

			rapidjson::Document temp;
			temp.SetBool(value);
			return append_value_raw(file_path, key_path, temp);
        }
        catch
        (
			const std::exception&
                exception
        )
        {
            return
				handle_error_outputs(
					exception
				);
        }
	}

	bool
		JsonFileIoManager
			::append_null(
				const std::string&
					file_path,
				const std::vector<std::variant<std::string, size_t>>&
					key_path,
				const std::nullptr_t&
					value
			)
	{
		try
        {
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling() ||				
				(
					configurations
						.is_edge_case_enabled_for_feature_handling() &&
					(
						file_path.empty() ||
						!std::filesystem::exists(file_path) ||
						std::filesystem::is_directory(file_path) ||
						!key_path.size()
					)
				)
			)
			{
				return
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_feature_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}

			rapidjson::Document temp;
			temp.SetNull();
			return append_value_raw(file_path, key_path, temp);
        }
        catch
        (
			const std::exception&
                exception
        )
        {
            return
				handle_error_outputs(
					exception
				);
        }
	}

	bool
		JsonFileIoManager
			::remove_value(
				const std::string&
					file_path,
				const std::vector<std::variant<std::string, size_t>>&
					key_path
			)
	{
		try
        {
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling() ||				
				(
					configurations
						.is_edge_case_enabled_for_feature_handling() &&
					(
						file_path.empty() ||
						!std::filesystem::exists(file_path) ||
						std::filesystem::is_directory(file_path) ||
						!key_path.size()
					)
				)
			)
			{
				return
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_feature_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}

			return remove_value_internal(file_path, key_path);
        }
        catch
        (
			const std::exception&
                exception
        )
        {
            return
				handle_error_outputs(
					exception
				);
        }
	}

	bool
		JsonFileIoManager
			::is_valid()
	{
		return
			is_valid(
				configurations
					.file_path
			);
	}

	bool
		JsonFileIoManager
			::is_key_path_valid(
				const std::vector<std::variant<std::string, size_t>>&
					key_path
			)
	{
		return
			is_key_path_valid(
				configurations
					.file_path,
				key_path
			);
	}

	std::string
		JsonFileIoManager
			::get_raw_json(
				const std::vector<std::variant<std::string, size_t>>&
					key_path
			)
	{
		return
			get_raw_json(
				configurations
					.file_path,
				key_path
			);
	}

	std::string
		JsonFileIoManager
			::get_string(
				const std::vector<std::variant<std::string, size_t>>&
					key_path
			)
	{
		return
			get_string(
				configurations
					.file_path,
				key_path
			);
	}

	double
		JsonFileIoManager
			::get_double(
				const std::vector<std::variant<std::string, size_t>>&
					key_path
			)
	{
		return
			get_double(
				configurations
					.file_path,
				key_path
			);
	}

	bool
		JsonFileIoManager
			::get_boolean(
				const std::vector<std::variant<std::string, size_t>>&
					key_path
			)
	{
		return
			get_boolean(
				configurations
					.file_path,
				key_path
			);
	}

	std::nullptr_t
		JsonFileIoManager
			::get_null(
				const std::vector<std::variant<std::string, size_t>>&
					key_path
			)
	{
		return
			get_null(
				configurations
					.file_path,
				key_path
			);
	}

	bool
		JsonFileIoManager
			::set_raw_json(
				const std::vector<std::variant<std::string, size_t>>&
					key_path,
				const std::string&
					value
			)
	{
		return
			set_raw_json(
				configurations
					.file_path,
				key_path,
				value
			);
	}

	bool
		JsonFileIoManager
			::set_string(
				const std::vector<std::variant<std::string, size_t>>&
					key_path,
				const std::string&
					value
			)
	{
		return
			set_string(
				configurations
					.file_path,
				key_path,
				value
			);
	}

	bool
		JsonFileIoManager
			::set_double(
				const std::vector<std::variant<std::string, size_t>>&
					key_path,
				const double&
					value
			)
	{
		return
			set_double(
				configurations
					.file_path,
				key_path,
				value
			);
	}

	bool
		JsonFileIoManager
			::set_boolean(
				const std::vector<std::variant<std::string, size_t>>&
					key_path,
				const bool&
					value
			)
	{
		return
			set_boolean(
				configurations
					.file_path,
				key_path,
				value
			);
	}

	bool
		JsonFileIoManager
			::set_null(
				const std::vector<std::variant<std::string, size_t>>&
					key_path,
				const std::nullptr_t&
					value
			)
	{
		return
			set_null(
				configurations
					.file_path,
				key_path,
				value
			);
	}

	bool
		JsonFileIoManager
			::append_raw_json(
				const std::vector<std::variant<std::string, size_t>>&
					key_path,
				const std::string&
					value
			)
	{
		return
			append_raw_json(
				configurations
					.file_path,
				key_path,
				value
			);
	}

	bool
		JsonFileIoManager
			::append_string(
				const std::vector<std::variant<std::string, size_t>>&
					key_path,
				const std::string&
					value
			)
	{
		return
			append_string(
				configurations
					.file_path,
				key_path,
				value
			);
	}

	bool
		JsonFileIoManager
			::append_double(
				const std::vector<std::variant<std::string, size_t>>&
					key_path,
				const double&
					value
			)
	{
		return
			append_double(
				configurations
					.file_path,
				key_path,
				value
			);
	}

	bool
		JsonFileIoManager
			::append_boolean(
				const std::vector<std::variant<std::string, size_t>>&
					key_path,
				const bool&
					value
			)
	{
		return
			append_boolean(
				configurations
					.file_path,
				key_path,
				value
			);
	}

	bool
		JsonFileIoManager
			::append_null(
				const std::vector<std::variant<std::string, size_t>>&
					key_path,
				const std::nullptr_t&
					value
			)
	{
		return
			append_null(
				configurations
					.file_path,
				key_path,
				value
			);
	}

	bool
		JsonFileIoManager
			::remove_value(
				const std::vector<std::variant<std::string, size_t>>&
					key_path
			)
	{
		return
			remove_value(
				configurations
					.file_path,
				key_path
			);
	}




	
	std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyHash>
		JsonFileIoManager
			::is_key_path_valid(
				const std::string& file_path,
				const std::vector<std::vector<std::variant<std::string, size_t>>>& key_paths
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
				for(const auto& path : key_paths)
					results[path] = false;
				return results;
			}

			for(const auto& path : key_paths)
				results[path] = (traverse(doc, path) != nullptr);
		}
		catch(const std::exception& ex)
		{
			for(const auto& path : key_paths)
				results[path] = false;
			handle_error_outputs(ex);
		}

		return results;
	}

	std::unordered_map<std::vector<std::variant<std::string, size_t>>, std::string, JsonKeyHash>
		JsonFileIoManager
			::get_raw_json(
				const std::string& file_path,
				const std::vector<std::vector<std::variant<std::string, size_t>>>& key_paths
			)
	{
		std::unordered_map<std::vector<std::variant<std::string, size_t>>, std::string, JsonKeyHash> results;

		try
		{
			fast_io::native_file_loader file(file_path);
			rapidjson::Document doc;
			doc.Parse(file.data(), file.size());
			if(doc.HasParseError())
			{
				for(const auto& path : key_paths)
					results[path] = "";
				return results;
			}

			for(const auto& path : key_paths)
			{
				rapidjson::Value* value = traverse(doc, path);
				if(!value)
					results[path] = "";
				else
				{
					rapidjson::StringBuffer buffer;
					rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
					value->Accept(writer);
					results[path] = buffer.GetString();
				}
			}
		}
		catch(const std::exception& ex)
		{
			for(const auto& path : key_paths)
				results[path] = "";
			handle_error_outputs(ex);
		}

		return results;
	}

	std::unordered_map<std::vector<std::variant<std::string, size_t>>, std::string, JsonKeyHash>
		JsonFileIoManager
			::get_string(
				const std::string& file_path,
				const std::vector<std::vector<std::variant<std::string, size_t>>>& key_paths
			)
	{
		std::unordered_map<std::vector<std::variant<std::string, size_t>>, std::string, JsonKeyHash> results;

		try
		{
			fast_io::native_file_loader file(file_path);
			rapidjson::Document doc;
			doc.Parse(file.data(), file.size());
			if(doc.HasParseError())
			{
				for(const auto& path : key_paths)
					results[path] = "";
				return results;
			}

			for(const auto& path : key_paths)
			{
				rapidjson::Value* value = traverse(doc, path);
				if(!value || !value->IsString())
					results[path] = "";
				else
					results[path] = value->GetString();
			}
		}
		catch(const std::exception& ex)
		{
			for(const auto& path : key_paths)
				results[path] = "";
			handle_error_outputs(ex);
		}

		return results;
	}

	std::unordered_map<std::vector<std::variant<std::string, size_t>>, double, JsonKeyHash>
		JsonFileIoManager
			::get_double(
				const std::string& file_path,
				const std::vector<std::vector<std::variant<std::string, size_t>>>& key_paths
			)
	{
		std::unordered_map<std::vector<std::variant<std::string, size_t>>, double, JsonKeyHash> results;

		try
		{
			fast_io::native_file_loader file(file_path);
			rapidjson::Document doc;
			doc.Parse(file.data(), file.size());
			if(doc.HasParseError())
			{
				for(const auto& path : key_paths)
					results[path] = 0.0;
				return results;
			}

			for(const auto& path : key_paths)
			{
				rapidjson::Value* value = traverse(doc, path);
				if(!value || !value->IsNumber())
					results[path] = 0.0;
				else
					results[path] = value->GetDouble();
			}
		}
		catch(const std::exception& ex)
		{
			for(const auto& path : key_paths)
				results[path] = 0.0;
			handle_error_outputs(ex);
		}

		return results;
	}

	std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyHash>
		JsonFileIoManager
			::get_boolean(
				const std::string& file_path,
				const std::vector<std::vector<std::variant<std::string, size_t>>>& key_paths
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
				for(const auto& path : key_paths)
					results[path] = false;
				return results;
			}

			for(const auto& path : key_paths)
			{
				rapidjson::Value* value = traverse(doc, path);
				if(!value || !value->IsBool())
					results[path] = false;
				else
					results[path] = value->GetBool();
			}
		}
		catch(const std::exception& ex)
		{
			for(const auto& path : key_paths)
				results[path] = false;
			handle_error_outputs(ex);
		}

		return results;
	}

	std::unordered_map<std::vector<std::variant<std::string, size_t>>, std::nullptr_t, JsonKeyHash>
		JsonFileIoManager
			::get_null(
				const std::string& file_path,
				const std::vector<std::vector<std::variant<std::string, size_t>>>& key_paths
			)
	{
		std::unordered_map<std::vector<std::variant<std::string, size_t>>, std::nullptr_t, JsonKeyHash> results;

		try
		{
			fast_io::native_file_loader file(file_path);
			rapidjson::Document doc;
			doc.Parse(file.data(), file.size());
			if(doc.HasParseError())
			{
				for(const auto& path : key_paths)
					results[path] = nullptr;
				return results;
			}

			for(const auto& path : key_paths)
			{
				rapidjson::Value* value = traverse(doc, path);
				if(!value || !value->IsNull())
					results[path] = nullptr;
				else
					results[path] = nullptr;
			}
		}
		catch(const std::exception& ex)
		{
			for(const auto& path : key_paths)
				results[path] = nullptr;
			handle_error_outputs(ex);
		}

		return results;
	}

	auto
		JsonFileIoManager::set_raw_json(
			const std::string&
				file_path,
			const std::unordered_map<std::vector<std::variant<std::string, size_t>>, std::string, JsonKeyHash>&
				key_value_paths
		) -> std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyHash>
	{
		return set_values_batch(file_path, key_value_paths, false);
	}

	auto
		JsonFileIoManager::set_string(
			const std::string&
				file_path,
			const std::unordered_map<std::vector<std::variant<std::string, size_t>>, std::string, JsonKeyHash>&
				key_value_paths
		) -> std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyHash>
	{
		return set_values_batch(file_path, key_value_paths, false);
	}

	auto
		JsonFileIoManager::set_double(
			const std::string&
				file_path,
			const std::unordered_map<std::vector<std::variant<std::string, size_t>>, double, JsonKeyHash>&
				key_value_paths
		) -> std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyHash>
	{
		return set_values_batch(file_path, key_value_paths, false);
	}

	auto
		JsonFileIoManager::set_boolean(
			const std::string&
				file_path,
			const std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyHash>&
				key_value_paths
		) -> std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyHash>
	{
		return set_values_batch(file_path, key_value_paths, false);
	}

	auto
		JsonFileIoManager::set_null(
			const std::string&
				file_path,
			const std::unordered_map<std::vector<std::variant<std::string, size_t>>, std::nullptr_t, JsonKeyHash>&
				key_value_paths
		) -> std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyHash>
	{
		return set_values_batch(file_path, key_value_paths, false);
	}

	auto
		JsonFileIoManager::append_raw_json(
			const std::string&
				file_path,
			const std::unordered_map<std::vector<std::variant<std::string, size_t>>, std::string, JsonKeyHash>&
				key_value_paths
		) -> std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyHash>
	{
		return set_values_batch(file_path, key_value_paths, true);
	}

	auto
		JsonFileIoManager::append_string(
			const std::string&
				file_path,
			const std::unordered_map<std::vector<std::variant<std::string, size_t>>, std::string, JsonKeyHash>&
				key_value_paths
		) -> std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyHash>
	{
		return set_values_batch(file_path, key_value_paths, true);
	}

	auto
		JsonFileIoManager::append_double(
			const std::string&
				file_path,
			const std::unordered_map<std::vector<std::variant<std::string, size_t>>, double, JsonKeyHash>&
				key_value_paths
		) -> std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyHash>
	{
		return set_values_batch(file_path, key_value_paths, true);
	}

	auto
		JsonFileIoManager::append_boolean(
			const std::string&
				file_path,
			const std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyHash>&
				key_value_paths
		) -> std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyHash>
	{
		return set_values_batch(file_path, key_value_paths, true);
	}

	auto
		JsonFileIoManager::append_null(
			const std::string&
				file_path,
			const std::unordered_map<std::vector<std::variant<std::string, size_t>>, std::nullptr_t, JsonKeyHash>&
				key_value_paths
		) -> std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyHash>
	{
		return set_values_batch(file_path, key_value_paths, true);
	}

	std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyHash>
		JsonFileIoManager
			::remove_value(
				const std::string&
					file_path,
				const std::vector<std::vector<std::variant<std::string, size_t>>>&
					key_paths
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
				for(const auto& path : key_paths)
					results[path] = false;
				return results;
			}

			for(const auto& path : key_paths)
			{
				if(path.empty())
				{
					results[path] = false;
					continue;
				}

				rapidjson::Value* current = &doc;
				bool success = true;

				for(size_t i = 0; i + 1 < path.size(); ++i)
				{
					const auto& key = path[i];

					if(std::holds_alternative<std::string>(key))
					{
						const auto& name = std::get<std::string>(key);
						if(!current->IsObject() || !current->HasMember(name.c_str()))
						{
							success = false;
							break;
						}
						current = &((*current)[name.c_str()]);
					}
					else
					{
						rapidjson::SizeType index = static_cast<rapidjson::SizeType>(std::get<size_t>(key));
						if(!current->IsArray() || index >= current->Size())
						{
							success = false;
							break;
						}
						current = &((*current)[index]);
					}
				}

				if(!success)
				{
					results[path] = false;
					continue;
				}

				const auto& last = path.back();
				if(std::holds_alternative<std::string>(last))
				{
					const auto& name = std::get<std::string>(last);
					if(!current->IsObject() || !current->HasMember(name.c_str()))
					{
						success = false;
					}
					else
					{
						current->RemoveMember(name.c_str());
					}
				}
				else
				{
					rapidjson::SizeType index = static_cast<rapidjson::SizeType>(std::get<size_t>(last));
					if(!current->IsArray() || index >= current->Size())
					{
						success = false;
					}
					else
					{
						current->Erase(current->Begin() + index);
					}
				}

				results[path] = success;
			}

			write_document(file_path, doc);
		}
		catch(const std::exception& ex)
		{
			for(const auto& path : key_paths)
				results[path] = false;

			handle_error_outputs(ex);
		}

		return results;
	}

	std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyHash>
		JsonFileIoManager
			::is_key_path_valid(				
				const std::vector<std::vector<std::variant<std::string, size_t>>>&
					key_paths
			)
	{
		return
			is_key_path_valid(
				configurations
					.file_path,
				key_paths
			);
	}

	std::unordered_map<std::vector<std::variant<std::string, size_t>>, std::string, JsonKeyHash>
		JsonFileIoManager
			::get_raw_json(				
				const std::vector<std::vector<std::variant<std::string, size_t>>>&
					key_paths
			)
	{
		return
			get_raw_json(
				configurations
					.file_path,
				key_paths
			);
	}

	std::unordered_map<std::vector<std::variant<std::string, size_t>>, std::string, JsonKeyHash>
		JsonFileIoManager
			::get_string(				
				const std::vector<std::vector<std::variant<std::string, size_t>>>&
					key_paths
			)
	{
		return
			get_string(
				configurations
					.file_path,
				key_paths
			);
	}

	std::unordered_map<std::vector<std::variant<std::string, size_t>>, double, JsonKeyHash>
		JsonFileIoManager
			::get_double(				
				const std::vector<std::vector<std::variant<std::string, size_t>>>&
					key_paths
			)
	{
		return
			get_double(
				configurations
					.file_path,
				key_paths
			);
	}

	std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyHash>
		JsonFileIoManager
			::get_boolean(				
				const std::vector<std::vector<std::variant<std::string, size_t>>>&
					key_paths
			)
	{
		return
			get_boolean(
				configurations
					.file_path,
				key_paths
			);
	}

	std::unordered_map<std::vector<std::variant<std::string, size_t>>, nullptr_t, JsonKeyHash>
		JsonFileIoManager
			::get_null(				
				const std::vector<std::vector<std::variant<std::string, size_t>>>&
					key_paths
			)
	{
		return
			get_null(
				configurations
					.file_path,
				key_paths
			);
	}

	std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyHash>
		JsonFileIoManager
			::set_raw_json(				
				const std::unordered_map<std::vector<std::variant<std::string, size_t>>, std::string, JsonKeyHash>&
					key_value_paths
			)
	{
		return
			set_raw_json(
				configurations
					.file_path,
				key_value_paths
			);
	}

	std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyHash>
		JsonFileIoManager
			::set_string(				
				const std::unordered_map<std::vector<std::variant<std::string, size_t>>, std::string, JsonKeyHash>&
					key_value_paths
			)
	{
		return
			set_string(
				configurations
					.file_path,
				key_value_paths
			);
	}

	std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyHash>
		JsonFileIoManager
			::set_double(				
				const std::unordered_map<std::vector<std::variant<std::string, size_t>>, double, JsonKeyHash>&
					key_value_paths
			)
	{
		return
			set_double(
				configurations
					.file_path,
				key_value_paths
			);
	}

	std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyHash>
		JsonFileIoManager
			::set_boolean(				
				const std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyHash>&
					key_value_paths
			)
	{
		return
			set_boolean(
				configurations
					.file_path,
				key_value_paths
			);
	}

	std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyHash>
		JsonFileIoManager
			::set_null(				
				const std::unordered_map<std::vector<std::variant<std::string, size_t>>, nullptr_t, JsonKeyHash>&
					key_value_paths
			)
	{
		return
			set_null(
				configurations
					.file_path,
				key_value_paths
			);
	}

	std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyHash>
		JsonFileIoManager
			::append_raw_json(				
				const std::unordered_map<std::vector<std::variant<std::string, size_t>>, std::string, JsonKeyHash>&
					key_value_paths
			)
	{
		return
			append_raw_json(
				configurations
					.file_path,
				key_value_paths
			);
	}

	std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyHash>
		JsonFileIoManager
			::append_string(				
				const std::unordered_map<std::vector<std::variant<std::string, size_t>>, std::string, JsonKeyHash>&
					key_value_paths
			)
	{
		return
			append_string(
				configurations
					.file_path,
				key_value_paths
			);
	}

	std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyHash>
		JsonFileIoManager
			::append_double(				
				const std::unordered_map<std::vector<std::variant<std::string, size_t>>, double, JsonKeyHash>&
					key_value_paths
			)
	{
		return
			append_double(
				configurations
					.file_path,
				key_value_paths
			);
	}

	std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyHash>
		JsonFileIoManager
			::append_boolean(				
				const std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyHash>&
					key_value_paths
			)
	{
		return
			append_boolean(
				configurations
					.file_path,
				key_value_paths
			);
	}

	std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyHash>
		JsonFileIoManager
			::append_null(				
				const std::unordered_map<std::vector<std::variant<std::string, size_t>>, nullptr_t, JsonKeyHash>&
					key_value_paths
			)
	{
		return
			append_null(
				configurations
					.file_path,
				key_value_paths
			);
	}

	std::unordered_map<std::vector<std::variant<std::string, size_t>>, bool, JsonKeyHash>
		JsonFileIoManager
			::remove_value(				
				const std::vector<std::vector<std::variant<std::string, size_t>>>&
					key_paths
			)
	{
		return
			remove_value(
				configurations
					.file_path,
				key_paths
			);
	}
}
