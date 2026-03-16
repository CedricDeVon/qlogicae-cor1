#include "pch.hpp"

#include "../includes/toml_file_io_manager.hpp"

namespace
	QLogicae::Cor::V1
{        	
	TomlFileIoManager
		::TomlFileIoManager() :
			AbstractClass<TomlFileIoManagerConfigurations>()
    {
        
    }

	bool
		TomlFileIoManager
			::is_key_found(
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
						std::filesystem::is_empty(file_path) ||
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
			for (const auto& key : key_path)
			{
				if (auto tbl = node->as_table())
				{
					node = tbl->get(key);
					if (!node)
						return false;
				}
				else
					return false;
			}

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
		TomlFileIoManager
			::remove_value(
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
						std::filesystem::is_empty(file_path) ||
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
			for (size_t i = 0; i < key_path.size() - 1; ++i)
			{
				if (auto tbl = node->as_table())
				{
					node = tbl->get(key_path[i]);
					if (!node)
						return false;
				}
				else
					return false;
			}

			if (auto tbl = node->as_table())
			{
				if (!tbl->contains(key_path.back()))
					return false;

				tbl->erase(key_path.back());
				return save_toml_table(file_path, doc);
			}

            return
				false;
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
		TomlFileIoManager
			::save_toml_table(
				const std::string&
					file_path,
				const toml::table&
					doc
			)
	{
		std::ofstream ofs(file_path, std::ios::trunc);
		if (!ofs) return false;
		ofs << doc;

		return true;
	}

	bool
		TomlFileIoManager
			::is_key_found(
				const std::vector<std::string>&
					key_path
			)
	{
		return
			is_key_found(
				configurations
					.file_path,
				key_path
			);
	}

	bool
		TomlFileIoManager
			::remove_value(
				const std::vector<std::string>&
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
}
