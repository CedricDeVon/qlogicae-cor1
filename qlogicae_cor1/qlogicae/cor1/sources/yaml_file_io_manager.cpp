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

    YAML::Node
        YamlFileIoManager
            ::load_yaml(
                const std::string&
                    file_path
            )
    {
        try
        {
            QLOGICAE_COR1__IMPLICIT__HPP_CPP__PRE_EXECUTION_GUARD_TEMPLATE(
                QLOGICAE_COR1__BASE__HPP_CPP__MUTEX_LAYER_2,
                file_path.empty()
            );

            return
                YAML::LoadFile(file_path);
        }
        catch
        (
            QLOGICAE_COR1__BASE__HPP_CPP__TRY_CATCH_EXCEPTION_PARAMETER
        )
        {
            QLOGICAE_COR1__IMPLICIT__HPP_CPP__CATCH_CODE_TEMPLATE();
        }
    }

    bool
        YamlFileIoManager
            ::save_yaml(
                const std::string&
                    file_path,
                const YAML::Node&
                    node
            )
    {        
        try
        {
            QLOGICAE_COR1__IMPLICIT__HPP_CPP__PRE_EXECUTION_GUARD_TEMPLATE(
                QLOGICAE_COR1__BASE__HPP_CPP__MUTEX_LAYER_2,
                file_path.empty()
            );

            std::ofstream file(file_path);

            file << node;

            return
                true;
        }
        catch
        (
            QLOGICAE_COR1__BASE__HPP_CPP__TRY_CATCH_EXCEPTION_PARAMETER
        )
        {
            QLOGICAE_COR1__IMPLICIT__HPP_CPP__CATCH_CODE_TEMPLATE();
        }
    }

    YAML::Node
        YamlFileIoManager
            ::traverse(
                YAML::Node
                    node,
                const std::vector<std::variant<std::string, size_t>>&
                    key_path
            )
    {        
        try
        {
            QLOGICAE_COR1__IMPLICIT__HPP_CPP__PRE_EXECUTION_GUARD_TEMPLATE(
                QLOGICAE_COR1__BASE__HPP_CPP__MUTEX_LAYER_2,
                key_path.empty()
            );

            for (const auto& key : key_path)
            {
                if (std::holds_alternative<std::string>(key))
                {
                    node = node[std::get<std::string>(key)];
                }
                else
                {
                    node = node[std::get<size_t>(key)];
                }

                if (!node)
                {
                    return
                        YAML::Node();
                }
            }

            return
                node;
        }
        catch
        (
            QLOGICAE_COR1__BASE__HPP_CPP__TRY_CATCH_EXCEPTION_PARAMETER
        )
        {
            QLOGICAE_COR1__IMPLICIT__HPP_CPP__CATCH_CODE_TEMPLATE();
        }
    }

    bool
        YamlFileIoManager
            ::is_valid(
            const std::string&
                file_path
        )
    {        
        try
        {
            QLOGICAE_COR1__IMPLICIT__HPP_CPP__PRE_EXECUTION_GUARD_TEMPLATE(
                QLOGICAE_COR1__BASE__HPP_CPP__MUTEX_LAYER_1,
                file_path.empty()
            );

            YAML::Node node = load_yaml(file_path);

            return
                static_cast<bool>(node);
        }
        catch
        (
            QLOGICAE_COR1__BASE__HPP_CPP__TRY_CATCH_EXCEPTION_PARAMETER
        )
        {
            QLOGICAE_COR1__IMPLICIT__HPP_CPP__CATCH_CODE_TEMPLATE();
        }
    }

    bool
        YamlFileIoManager
            ::is_key_path_valid(
                const std::string&
                    file_path,
                const std::vector<std::variant<std::string, size_t>>&
                    key_path
            )
    {        
        try
        {
            QLOGICAE_COR1__IMPLICIT__HPP_CPP__PRE_EXECUTION_GUARD_TEMPLATE(
                QLOGICAE_COR1__BASE__HPP_CPP__MUTEX_LAYER_1,
                file_path.empty()
            );

            YAML::Node root = load_yaml(file_path);
            YAML::Node node = traverse(root, key_path);

            return
                static_cast<bool>(node);
        }
        catch
        (
            QLOGICAE_COR1__BASE__HPP_CPP__TRY_CATCH_EXCEPTION_PARAMETER
        )
        {
            QLOGICAE_COR1__IMPLICIT__HPP_CPP__CATCH_CODE_TEMPLATE();
        }
    }

    std::string
        YamlFileIoManager
            ::get_raw_yaml(
                const std::string&
                    file_path,
                const std::vector<std::variant<std::string, size_t>>&
                    key_path
            )
    {        
        try
        {
            QLOGICAE_COR1__IMPLICIT__HPP_CPP__PRE_EXECUTION_GUARD_TEMPLATE(
                QLOGICAE_COR1__BASE__HPP_CPP__MUTEX_LAYER_1,
                file_path.empty()
            );

            YAML::Node root = load_yaml(file_path);
            YAML::Node node = traverse(root, key_path);

            return
                YAML::Dump(node);
        }
        catch
        (
            QLOGICAE_COR1__BASE__HPP_CPP__TRY_CATCH_EXCEPTION_PARAMETER
        )
        {
            QLOGICAE_COR1__IMPLICIT__HPP_CPP__CATCH_CODE_TEMPLATE();
        }
    }

    std::string
        YamlFileIoManager
            ::get_string(
                const std::string&
                    file_path,
                const std::vector<std::variant<std::string, size_t>>&
                    key_path
            )
    {        
        try
        {
            QLOGICAE_COR1__IMPLICIT__HPP_CPP__PRE_EXECUTION_GUARD_TEMPLATE(
                QLOGICAE_COR1__BASE__HPP_CPP__MUTEX_LAYER_1,
                file_path.empty()
            );

            return
                traverse(load_yaml(file_path), key_path).as<std::string>();
        }
        catch
        (
            QLOGICAE_COR1__BASE__HPP_CPP__TRY_CATCH_EXCEPTION_PARAMETER
        )
        {
            QLOGICAE_COR1__IMPLICIT__HPP_CPP__CATCH_CODE_TEMPLATE();
        }
    }

    double
        YamlFileIoManager
            ::get_double(
                const std::string&
                    file_path,
                const std::vector<std::variant<std::string, size_t>>&
                    key_path
            )
    {        
        try
        {
            QLOGICAE_COR1__IMPLICIT__HPP_CPP__PRE_EXECUTION_GUARD_TEMPLATE(
                QLOGICAE_COR1__BASE__HPP_CPP__MUTEX_LAYER_1,
                file_path.empty()
            );

            return
                traverse(load_yaml(file_path), key_path).as<double>();
        }
        catch
        (
            QLOGICAE_COR1__BASE__HPP_CPP__TRY_CATCH_EXCEPTION_PARAMETER
        )
        {
            QLOGICAE_COR1__IMPLICIT__HPP_CPP__CATCH_CODE_TEMPLATE();
        }
    }

    bool
        YamlFileIoManager
            ::get_boolean(
                const std::string&
                    file_path,
                const std::vector<std::variant<std::string, size_t>>&
                    key_path
            )
    {        
        try
        {
            QLOGICAE_COR1__IMPLICIT__HPP_CPP__PRE_EXECUTION_GUARD_TEMPLATE(
                QLOGICAE_COR1__BASE__HPP_CPP__MUTEX_LAYER_1,
                file_path.empty()
            );

            return
                traverse(load_yaml(file_path), key_path).as<bool>();
        }
        catch
        (
            QLOGICAE_COR1__BASE__HPP_CPP__TRY_CATCH_EXCEPTION_PARAMETER
        )
        {
            QLOGICAE_COR1__IMPLICIT__HPP_CPP__CATCH_CODE_TEMPLATE();
        }
    }

    std::nullptr_t
        YamlFileIoManager
            ::get_null(
                const std::string&
                    file_path,
                const std::vector<std::variant<std::string, size_t>>&
                    key_path
            )
    {        
        try
        {
            QLOGICAE_COR1__IMPLICIT__HPP_CPP__PRE_EXECUTION_GUARD_TEMPLATE(
                QLOGICAE_COR1__BASE__HPP_CPP__MUTEX_LAYER_1,
                file_path.empty()
            );

            return
                nullptr;
        }
        catch
        (
            QLOGICAE_COR1__BASE__HPP_CPP__TRY_CATCH_EXCEPTION_PARAMETER
        )
        {
            QLOGICAE_COR1__IMPLICIT__HPP_CPP__CATCH_CODE_TEMPLATE();
        }
    }

    bool
        YamlFileIoManager
            ::set_raw_yaml(
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
            QLOGICAE_COR1__IMPLICIT__HPP_CPP__PRE_EXECUTION_GUARD_TEMPLATE(
                QLOGICAE_COR1__BASE__HPP_CPP__MUTEX_LAYER_1,
                file_path.empty()
            );

            YAML::Node root = load_yaml(file_path);
            YAML::Node node = root;

            for (size_t i = 0; i < key_path.size() - 1; ++i)
            {
                const auto& key = key_path[i];

                if (std::holds_alternative<std::string>(key))
                {
                    node = node[std::get<std::string>(key)];
                }
                else
                {
                    node = node[std::get<size_t>(key)];
                }
            }

            const auto& last = key_path.back();

            YAML::Node new_node = YAML::Load(value);

            if (std::holds_alternative<std::string>(last))
            {
                node[std::get<std::string>(last)] = new_node;
            }
            else
            {
                node[std::get<size_t>(last)] = new_node;
            }

            save_yaml(file_path, root);

            return
                true;
        }
        catch
        (
            QLOGICAE_COR1__BASE__HPP_CPP__TRY_CATCH_EXCEPTION_PARAMETER
        )
        {
            QLOGICAE_COR1__IMPLICIT__HPP_CPP__CATCH_CODE_TEMPLATE();
        }
    }

    bool
        YamlFileIoManager
            ::set_string(
                const std::string&
                    file_path,
                const std::vector<std::variant<std::string, size_t>>&
                    key_path,
                const std::string&
                    value
            )
    {
        return
                set_raw_yaml(file_path, key_path, value);
    }

    bool
        YamlFileIoManager
            ::append_raw_yaml(
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
            QLOGICAE_COR1__IMPLICIT__HPP_CPP__PRE_EXECUTION_GUARD_TEMPLATE(
                QLOGICAE_COR1__BASE__HPP_CPP__MUTEX_LAYER_1,
                file_path.empty()
            );

            YAML::Node root = load_yaml(file_path);
            YAML::Node node = traverse(root, key_path);

            node.push_back(YAML::Load(value));

            save_yaml(file_path, root);

            return
                true;
        }
        catch
        (
            QLOGICAE_COR1__BASE__HPP_CPP__TRY_CATCH_EXCEPTION_PARAMETER
        )
        {
            QLOGICAE_COR1__IMPLICIT__HPP_CPP__CATCH_CODE_TEMPLATE();
        }
    }

    bool
        YamlFileIoManager
            ::append_string(
                const std::string&
                    file_path,
                const std::vector<std::variant<std::string, size_t>>&
                    key_path,
                const std::string&
                    value
            )
    {
        return
                append_raw_yaml(file_path, key_path, value);
    }

    bool
        YamlFileIoManager
            ::remove_value(
                const std::string&
                    file_path,
                const std::vector<std::variant<std::string, size_t>>&
                    key_path
            )
    {        
        try
        {
            QLOGICAE_COR1__IMPLICIT__HPP_CPP__PRE_EXECUTION_GUARD_TEMPLATE(
                QLOGICAE_COR1__BASE__HPP_CPP__MUTEX_LAYER_1,
                file_path.empty()
            );

            YAML::Node root = load_yaml(file_path);
            YAML::Node node = root;

            for (size_t i = 0; i < key_path.size() - 1; ++i)
            {
                const auto& key = key_path[i];

                if (std::holds_alternative<std::string>(key))
                {
                    node = node[std::get<std::string>(key)];
                }
                else
                {
                    node = node[std::get<size_t>(key)];
                }
            }

            const auto& last = key_path.back();

            if (std::holds_alternative<std::string>(last))
            {
                node.remove(std::get<std::string>(last));
            }
            else
            {
                node.remove(std::get<size_t>(last));
            }

            save_yaml(file_path, root);

            return
                true;
        }
        catch
        (
            QLOGICAE_COR1__BASE__HPP_CPP__TRY_CATCH_EXCEPTION_PARAMETER
        )
        {
            QLOGICAE_COR1__IMPLICIT__HPP_CPP__CATCH_CODE_TEMPLATE();
        }
    }

    bool
        YamlFileIoManager
            ::is_valid()
    {
        return
            is_valid(
                configurations.file_path
            );
    }

    bool
        YamlFileIoManager
            ::is_key_path_valid(
                const std::vector<std::variant<std::string, size_t>>&
                    key_path
            )
    {
        return
            is_key_path_valid(
                configurations.file_path,
                key_path
            );
    }

    std::string
        YamlFileIoManager
            ::get_raw_yaml(
                const std::vector<std::variant<std::string, size_t>>&
                    key_path
            )
    {
        return
            get_raw_yaml(
                configurations.file_path,
                key_path
            );
    }

    std::string
        YamlFileIoManager
            ::get_string(
                const std::vector<std::variant<std::string, size_t>>&
                    key_path
            )
    {
        return
            get_string(
                configurations.file_path,
                key_path
            );
    }

    double
        YamlFileIoManager
            ::get_double(
                const std::vector<std::variant<std::string, size_t>>&
                    key_path
            )
    {
        return
            get_double(
                configurations.file_path,
                key_path
            );
    }

    bool
        YamlFileIoManager
            ::get_boolean(
                const std::vector<std::variant<std::string, size_t>>&
                    key_path
            )
    {
        return
            get_boolean(
                configurations.file_path,
                key_path
            );
    }

    std::nullptr_t
        YamlFileIoManager
            ::get_null(
                const std::vector<std::variant<std::string, size_t>>&
                    key_path
            )
    {
        return
            get_null(
                configurations.file_path,
                key_path
            );
    }

    bool
        YamlFileIoManager
            ::set_raw_yaml(
                const std::vector<std::variant<std::string, size_t>>&
                    key_path,
                const std::string&
                    value
            )
    {
        return
            set_raw_yaml(
                configurations.file_path,
                key_path,
                value
            );
    }

    bool
        YamlFileIoManager
            ::set_string(
                const std::vector<std::variant<std::string, size_t>>&
                    key_path,
                const std::string&
                    value
            )
    {
        return
            set_string(
                configurations.file_path,
                key_path,
                value
            );
    }

    bool
        YamlFileIoManager
            ::append_raw_yaml(
                const std::vector<std::variant<std::string, size_t>>&
                    key_path,
                const std::string&
                    value
            )
    {
        return
            append_raw_yaml(
                configurations.file_path,
                key_path,
                value
            );
    }

    bool
        YamlFileIoManager
            ::append_string(
                const std::vector<std::variant<std::string, size_t>>&
                    key_path,
                const std::string&
                    value
            )
    {
        return
            append_string(
                configurations.file_path,
                key_path,
                value
            );
    }

    bool
        YamlFileIoManager
            ::remove_value(
                const std::vector<std::variant<std::string, size_t>>&
                    key_path
            )
    {
        return
            remove_value(
                configurations.file_path,
                key_path
            );
    }
}

#endif

