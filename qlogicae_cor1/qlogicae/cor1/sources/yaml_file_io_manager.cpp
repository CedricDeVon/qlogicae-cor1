#include "pch.hpp"

#if QLOGICAE_COR1__BASE__HPP_CPP__IS_COMPILATION_CONDITIONS_ENABLED_TEMPLATE( \
		YamlFileIoManager \
	)

#include "../includes/yaml_file_io_manager.hpp"

namespace
	QLOGICAE_COR1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
    YamlFileIoManager
		::YamlFileIoManager() :
			QLOGICAE_COR1__BASE__HPP_CPP__ABSTRACT_CLASS_NAME<YamlFileIoManagerConfigurations>()
	{

	}

	static YAML::Node
	traverse_to_parent(
		YAML::Node root,
		const std::vector<std::variant<std::string, size_t>>& key_path
	)
	{
		if (!root.IsDefined() || key_path.empty())
			return YAML::Node(YAML::NodeType::Undefined);

		YAML::Node current = root;

		for (size_t i = 0; i + 1 < key_path.size(); ++i)
		{
			const auto& key = key_path[i];

			if (std::holds_alternative<std::string>(key))
			{
				const auto& k = std::get<std::string>(key);

				if (!current.IsMap())
					current = YAML::Node(YAML::NodeType::Map);

				if (!current[k])
					current[k] = YAML::Node();

				current = current[k];
			}
			else
			{
				size_t idx = std::get<size_t>(key);

				if (!current.IsSequence())
					current = YAML::Node(YAML::NodeType::Sequence);

				while (current.size() <= idx)
					current.push_back(YAML::Node());

				current = current[idx];
			}
		}

		return current;
	}

	static YAML::Node safe_traverse(
		const YAML::Node& node,
		const std::vector<std::variant<std::string, size_t>>& key_path
	)
	{
		if (!node.IsDefined() || key_path.empty())
			return YAML::Node(YAML::NodeType::Undefined);

		YAML::Node current = node;

		for (const auto& key : key_path)
		{
			if (!current.IsDefined())
				return YAML::Node(YAML::NodeType::Undefined);

			if (std::holds_alternative<std::string>(key))
			{
				if (!current.IsMap())
					return YAML::Node(YAML::NodeType::Undefined);

				const auto& k = std::get<std::string>(key);

				if (!current[k])
					return YAML::Node(YAML::NodeType::Undefined);

				current = current[k];
			}
			else
			{
				if (!current.IsSequence())
					return YAML::Node(YAML::NodeType::Undefined);

				size_t idx = std::get<size_t>(key);

				if (idx >= current.size())
					return YAML::Node(YAML::NodeType::Undefined);

				current = current[idx];
			}
		}

		return current;
	}

	static YAML::Node walk_root(YAML::Node& root,
		const std::vector<std::variant<std::string, size_t>>& key_path,
		bool create)
	{
		if (!root.IsDefined())
		{
			if (!create) return YAML::Node();
			root = YAML::Node(YAML::NodeType::Map);
		}

		YAML::Node current = root;

		for (size_t i = 0; i + 1 < key_path.size(); ++i)
		{
			const auto& key = key_path[i];

			if (std::holds_alternative<std::string>(key))
			{
				const auto& k = std::get<std::string>(key);

				if (!current.IsMap())
				{
					if (!create) return YAML::Node();
					current = YAML::Node(YAML::NodeType::Map);
				}

				if (!current[k] && create)
					current[k] = YAML::Node();

				current = current[k];
			}
			else
			{
				size_t idx = std::get<size_t>(key);

				if (!current.IsSequence())
				{
					if (!create) return YAML::Node();
					current = YAML::Node(YAML::NodeType::Sequence);
				}

				while (current.size() <= idx)
					current.push_back(YAML::Node());

				current = current[idx];
			}
		}

		return current;
	}



	YAML::Node YamlFileIoManager::load_yaml(const std::string& file_path)
	{
		if (file_path.empty())
			return YAML::Node(YAML::NodeType::Undefined);

		if (!std::filesystem::exists(file_path))
			return YAML::Node(YAML::NodeType::Undefined);

		try
		{
			return YAML::LoadFile(file_path);
		}
		catch (...)
		{
			return YAML::Node(YAML::NodeType::Undefined);
		}
	}

	bool YamlFileIoManager::save_yaml(
		const std::string& file_path,
		const YAML::Node& node
	)
	{
		if (file_path.empty())
			return false;

		try
		{
			std::ofstream out(file_path, std::ios::trunc);
			if (!out.is_open())
				return false;

			out << YAML::Dump(node);

			return !out.fail();
		}
		catch (...)
		{
			return false;
		}
	}

	YAML::Node YamlFileIoManager::traverse(
		YAML::Node node,
		const std::vector<std::variant<std::string, size_t>>& key_path
	)
	{
		return safe_traverse(node, key_path);
	}

	YAML::Node YamlFileIoManager::resolve_or_create(
		YAML::Node root,
		const std::vector<std::variant<std::string, size_t>>& key_path
	)
	{
		YAML::Node current = root;

		for (size_t i = 0; i < key_path.size(); ++i)
		{
			const auto& key = key_path[i];

			if (std::holds_alternative<std::string>(key))
			{
				if (!current.IsMap())
					current = YAML::Node(YAML::NodeType::Map);

				const auto& k = std::get<std::string>(key);

				if (!current[k])
					current[k] = YAML::Node();

				current = current[k];
			}
			else
			{
				if (!current.IsSequence())
					current = YAML::Node(YAML::NodeType::Sequence);

				size_t idx = std::get<size_t>(key);

				while (current.size() <= idx)
					current.push_back(YAML::Node());

				current = current[idx];
			}
		}

		return current;
	}

	bool YamlFileIoManager::is_valid(const std::string& file_path)
	{
		auto node = load_yaml(file_path);
		return node.IsDefined() && !node.IsNull();
	}

	bool YamlFileIoManager::is_key_path_valid(
		const std::string& file_path,
		const std::vector<std::variant<std::string, size_t>>& key_path
	)
	{
		if (file_path.empty() || key_path.empty())
			return false;

		auto root = load_yaml(file_path);
		auto node = safe_traverse(root, key_path);

		return node.IsDefined() && !node.IsNull();
	}

	std::string YamlFileIoManager::get_raw_yaml(
		const std::string& file_path,
		const std::vector<std::variant<std::string, size_t>>& key_path
	)
	{
		auto node = safe_traverse(load_yaml(file_path), key_path);

		if (!node.IsDefined())
			return "";

		return YAML::Dump(node);
	}

	std::string YamlFileIoManager::get_string(
		const std::string& file_path,
		const std::vector<std::variant<std::string, size_t>>& key_path
	)
	{
		auto node = safe_traverse(load_yaml(file_path), key_path);

		if (!node.IsDefined() || !node.IsScalar())
			return "";

		try { return node.as<std::string>(); }
		catch (...) { return ""; }
	}

	double YamlFileIoManager::get_double(
		const std::string& file_path,
		const std::vector<std::variant<std::string, size_t>>& key_path
	)
	{
		auto node = safe_traverse(load_yaml(file_path), key_path);

		if (!node.IsDefined() || !node.IsScalar())
			return 0.0;

		try { return node.as<double>(); }
		catch (...) { return 0.0; }
	}

	bool YamlFileIoManager::get_boolean(
		const std::string& file_path,
		const std::vector<std::variant<std::string, size_t>>& key_path
	)
	{
		auto node = safe_traverse(load_yaml(file_path), key_path);

		if (!node.IsDefined() || !node.IsScalar())
			return false;

		try { return node.as<bool>(); }
		catch (...) { return false; }
	}

	std::nullptr_t YamlFileIoManager::get_null(
		const std::string&,
		const std::vector<std::variant<std::string, size_t>>&
	)
	{
		return nullptr;
	}

	bool YamlFileIoManager::set_raw_yaml(
		const std::string& file_path,
		const std::vector<std::variant<std::string, size_t>>& key_path,
		const std::string& value
	)
	{
		if (file_path.empty() || key_path.empty())
			return false;

		YAML::Node root = load_yaml(file_path);

		if (!root.IsDefined() || root.IsNull())
			root = YAML::Node(YAML::NodeType::Map);

		YAML::Node current = root;

		for (size_t i = 0; i + 1 < key_path.size(); ++i)
		{
			const auto& key = key_path[i];

			if (std::holds_alternative<std::string>(key))
			{
				const auto& k = std::get<std::string>(key);

				if (!current.IsMap())
					current = YAML::Node(YAML::NodeType::Map);

				if (!current[k])
					current[k] = YAML::Node(YAML::NodeType::Map);

				current = current[k];
			}
			else
			{
				size_t idx = std::get<size_t>(key);

				if (!current.IsSequence())
					current = YAML::Node(YAML::NodeType::Sequence);

				while (current.size() <= idx)
					current.push_back(YAML::Node());

				current = current[idx];
			}
		}

		const auto& last = key_path.back();

		YAML::Node parsed;

		try
		{
			parsed = YAML::Load(value);
		}
		catch (...)
		{
			parsed = YAML::Node(value);
		}

		if (std::holds_alternative<std::string>(last))
		{
			current[std::get<std::string>(last)] = parsed;
		}
		else
		{
			size_t idx = std::get<size_t>(last);

			if (!current.IsSequence())
				current = YAML::Node(YAML::NodeType::Sequence);

			while (current.size() <= idx)
				current.push_back(YAML::Node());

			current[idx] = parsed;
		}

		return save_yaml(file_path, root);
	}

	bool YamlFileIoManager::set_string(
		const std::string& file_path,
		const std::vector<std::variant<std::string, size_t>>& key_path,
		const std::string& value
	)
	{
		return set_raw_yaml(file_path, key_path, value);
	}

	bool YamlFileIoManager::append_raw_yaml(
		const std::string& file_path,
		const std::vector<std::variant<std::string, size_t>>& key_path,
		const std::string& value
	)
	{
		if (file_path.empty() || key_path.empty())
			return false;

		YAML::Node root = load_yaml(file_path);

		if (!root.IsDefined() || root.IsNull())
			root = YAML::Node(YAML::NodeType::Map);

		YAML::Node current = root;

		for (size_t i = 0; i + 1 < key_path.size(); ++i)
		{
			const auto& key = key_path[i];

			if (std::holds_alternative<std::string>(key))
			{
				const auto& k = std::get<std::string>(key);

				if (!current.IsMap())
					current = YAML::Node(YAML::NodeType::Map);

				if (!current[k])
					current[k] = YAML::Node(YAML::NodeType::Map);

				current = current[k];
			}
			else
			{
				size_t idx = std::get<size_t>(key);

				if (!current.IsSequence())
					current = YAML::Node(YAML::NodeType::Sequence);

				while (current.size() <= idx)
					current.push_back(YAML::Node());

				current = current[idx];
			}
		}

		const auto& last = key_path.back();

		YAML::Node parsed;

		try
		{
			parsed = YAML::Load(value);
		}
		catch (...)
		{
			parsed = YAML::Node(value);
		}

		if (std::holds_alternative<std::string>(last))
		{
			auto target = current[std::get<std::string>(last)];

			if (!target.IsSequence())
				target = YAML::Node(YAML::NodeType::Sequence);

			target.push_back(parsed);
		}
		else
		{
			size_t idx = std::get<size_t>(last);

			if (!current.IsSequence())
				current = YAML::Node(YAML::NodeType::Sequence);

			while (current.size() <= idx)
				current.push_back(YAML::Node());

			auto target = current[idx];

			if (!target.IsSequence())
				target = YAML::Node(YAML::NodeType::Sequence);

			target.push_back(parsed);
		}

		return save_yaml(file_path, root);
	}

	bool YamlFileIoManager::append_string(
		const std::string& file_path,
		const std::vector<std::variant<std::string, size_t>>& key_path,
		const std::string& value
	)
	{
		if (file_path.empty() || key_path.empty())
			return false;

		YAML::Node root = load_yaml(file_path);

		if (!root.IsDefined() || root.IsNull())
			root = YAML::Node(YAML::NodeType::Map);

		YAML::Node parent = walk_root(root, key_path, true);

		const auto& last = key_path.back();

		if (std::holds_alternative<std::string>(last))
		{
			const auto& k = std::get<std::string>(last);

			if (!parent[k])
				parent[k] = YAML::Node(YAML::NodeType::Sequence);

			if (!parent[k].IsSequence())
				return false;

			parent[k].push_back(value);
		}
		else
		{
			size_t idx = std::get<size_t>(last);

			if (!parent.IsSequence())
				parent = YAML::Node(YAML::NodeType::Sequence);

			while (parent.size() <= idx)
				parent.push_back(YAML::Node());

			if (!parent[idx].IsSequence())
				parent[idx] = YAML::Node(YAML::NodeType::Sequence);

			parent[idx].push_back(value);
		}

		return save_yaml(file_path, root);
	}

	bool YamlFileIoManager::remove_value(
		const std::string& file_path,
		const std::vector<std::variant<std::string, size_t>>& key_path
	)
	{
		if (file_path.empty() || key_path.empty())
			return false;

		YAML::Node root = load_yaml(file_path);

		if (!root.IsDefined())
			return false;

		YAML::Node parent = traverse_to_parent(root, key_path);

		if (!parent.IsDefined())
			return false;

		const auto& last = key_path.back();

		if (std::holds_alternative<std::string>(last))
		{
			parent.remove(std::get<std::string>(last));
		}
		else
		{
			size_t idx = std::get<size_t>(last);

			if (parent.IsSequence() && idx < parent.size())
				parent.remove(idx);
		}

		return save_yaml(file_path, root);
	}

	bool YamlFileIoManager::is_valid() { return is_valid(configurations.file_path); }

	bool YamlFileIoManager::is_key_path_valid(const std::vector<std::variant<std::string, size_t>>& p)
	{
		return is_key_path_valid(configurations.file_path, p);
	}

	std::string YamlFileIoManager::get_raw_yaml(const std::vector<std::variant<std::string, size_t>>& p)
	{
		return get_raw_yaml(configurations.file_path, p);
	}

	std::string YamlFileIoManager::get_string(const std::vector<std::variant<std::string, size_t>>& p)
	{
		return get_string(configurations.file_path, p);
	}

	double YamlFileIoManager::get_double(const std::vector<std::variant<std::string, size_t>>& p)
	{
		return get_double(configurations.file_path, p);
	}

	bool YamlFileIoManager::get_boolean(const std::vector<std::variant<std::string, size_t>>& p)
	{
		return get_boolean(configurations.file_path, p);
	}

	std::nullptr_t YamlFileIoManager::get_null(const std::vector<std::variant<std::string, size_t>>& p)
	{
		return get_null(configurations.file_path, p);
	}

	bool YamlFileIoManager::set_raw_yaml(const std::vector<std::variant<std::string, size_t>>& p, const std::string& v)
	{
		return set_raw_yaml(configurations.file_path, p, v);
	}

	bool YamlFileIoManager::set_string(const std::vector<std::variant<std::string, size_t>>& p, const std::string& v)
	{
		return set_string(configurations.file_path, p, v);
	}

	bool YamlFileIoManager::append_raw_yaml(const std::vector<std::variant<std::string, size_t>>& p, const std::string& v)
	{
		return append_raw_yaml(configurations.file_path, p, v);
	}

	bool YamlFileIoManager::append_string(const std::vector<std::variant<std::string, size_t>>& p, const std::string& v)
	{
		return append_string(configurations.file_path, p, v);
	}

	bool YamlFileIoManager::remove_value(const std::vector<std::variant<std::string, size_t>>& p)
	{
		return remove_value(configurations.file_path, p);
	}
}

#endif
