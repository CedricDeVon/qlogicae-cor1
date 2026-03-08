#pragma once

#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "toml_file_io_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    class
		TomlFileIoManager :
			public AbstractClass<TomlFileIoManagerConfigurations>
    {
    public:		
        static TomlFileIoManager&
            singleton;

		TomlFileIoManager();

		bool
			is_key_found(
				const std::string&
					file_path,
				const std::vector<std::string>&
					key_path
			);

		template<typename ValueType> ValueType
			get_value(
				const std::string&
					file_path,
				const std::vector<std::string>&
					key_path
			);

		template<typename ValueType> bool
			set_value(
				const std::string&
					file_path,
				const std::vector<std::string>&
					key_path,
				const ValueType&
					value
			);

		template<typename ValueType> bool
			append_value(
				const std::string&
					file_path,
				const std::vector<std::string>&
					key_path,
				const ValueType&
					value
			);

		bool
			remove_value(
				const std::string&
					file_path,
				const std::vector<std::string>&
					key_path
			);

		bool
			is_key_found(
				const std::vector<std::string>&
					key_path
			);

		template<typename ValueType> ValueType
			get_value(
				const std::vector<std::string>&
					key_path
			);

		template<typename ValueType> bool
			set_value(
				const std::vector<std::string>&
					key_path,
				const ValueType&
					value
			);

		template<typename ValueType> bool
			append_value(
				const std::vector<std::string>&
					key_path,
				const ValueType&
					value
			);

		bool
			remove_value(
				const std::vector<std::string>&
					key_path
			);

		bool
			save_toml_table(
				const std::string&
					file_path,
				const toml::table&
					doc
			);
    };

	template<typename ValueType> ValueType
		TomlFileIoManager
			::get_value(
				const std::string&
					file_path,
				const std::vector<std::string>&
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
					ValueType{};
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

			toml::table doc;
			try { doc = toml::parse_file(file_path); }
			catch (...) { return ValueType{}; }

			toml::node* node = &doc;
			for (const auto& key : key_path)
			{
				if (auto tbl = node->as_table())
				{
					node = tbl->get(key);
					if (!node)
						return ValueType{};
				}
				else
					return ValueType{};
			}

			if constexpr (std::is_same_v<ValueType, std::string>)
			{
				if (auto val = node->value<std::string>())
					return *val;
			}
			else if constexpr (std::is_integral_v<ValueType>)
			{
				if (auto val = node->value<int64_t>())
					return static_cast<ValueType>(*val);
			}
			else if constexpr (std::is_floating_point_v<ValueType>)
			{
				if (auto val = node->value<double>())
					return static_cast<ValueType>(*val);
			}

            return ValueType{};
        }
        catch
        (
			const std::exception&
                exception
        )
        {
            return
				handle_error_outputs<ValueType>(
					exception
				);
        }
	}

	template<typename ValueType> bool
		TomlFileIoManager
			::set_value(
				const std::string&
					file_path,
				const std::vector<std::string>&
					key_path,
				const ValueType&
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

			toml::table doc;
			try { doc = toml::parse_file(file_path); }
			catch (...) { return false; }

			toml::node* node = &doc;
			for (size_t i = 0; i < key_path.size(); ++i)
			{
				const std::string& key = key_path[i];
				if (i + 1 == key_path.size())
				{
					if (auto tbl = node->as_table())
					{
						if constexpr (std::is_same_v<ValueType, std::string>)
							(*tbl)[key] = value;
						else if constexpr (std::is_integral_v<ValueType>)
							(*tbl)[key] = static_cast<int64_t>(value);
						else if constexpr (std::is_floating_point_v<ValueType>)
							(*tbl)[key] = static_cast<double>(value);
						else
							return false;
					}
					else
						return false;
				}
				else
				{
					if (auto tbl = node->as_table())
					{
						if (!tbl->contains(key))
							(*tbl)[key] = toml::table{};
						node = tbl->get(key);
					}
					else
						return false;
				}
			}

			return save_toml_table(file_path, doc);
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

	template<typename ValueType> bool
		TomlFileIoManager
			::append_value(
				const std::string&
					file_path,
				const std::vector<std::string>&
					key_path,
				const ValueType&
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

			toml::table doc;
			try { doc = toml::parse_file(file_path); }
			catch (...) { return false; }

			toml::node* node = &doc;
			for (size_t i = 0; i < key_path.size(); ++i)
			{
				const std::string& key = key_path[i];
				if (i + 1 == key_path.size())
				{
					if (auto tbl = node->as_table())
					{
						if (!tbl->contains(key))
							tbl->insert(key, toml::array{});
						if (auto arr = tbl->get(key)->as_array())
						{
							if constexpr (std::is_same_v<ValueType, std::string>)
								arr->push_back(value);
							else if constexpr (std::is_integral_v<ValueType>)
								arr->push_back(static_cast<int64_t>(value));
							else if constexpr (std::is_floating_point_v<ValueType>)
								arr->push_back(static_cast<double>(value));
							else
								return false;
						}
						else
							return false;
					}
					else
						return false;
				}
				else
				{
					if (auto tbl = node->as_table())
					{
						if (!tbl->contains(key))
							(*tbl)[key] = toml::table{};
						node = tbl->get(key);
					}
					else
						return false;
				}
			}

			return
				save_toml_table(file_path, doc);
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

	template<typename ValueType> ValueType
		TomlFileIoManager
			::get_value(
				const std::vector<std::string>&
					key_path
			)
	{
		return
			get_value(
				configurations
					.file_path,
				key_path
			);	
	}

	template<typename ValueType> bool
		TomlFileIoManager
			::set_value(
				const std::vector<std::string>&
					key_path,
				const ValueType&
					value
			)
	{
		return
			set_value(
				configurations
					.file_path,
				key_path,
				value
			);	
	}

	template<typename ValueType> bool
		TomlFileIoManager
			::append_value(
				const std::vector<std::string>&
					key_path,
				const ValueType&
					value
			)
	{
		return
			append_value(
				configurations
					.file_path,
				key_path,
				value
			);	
	}
}
