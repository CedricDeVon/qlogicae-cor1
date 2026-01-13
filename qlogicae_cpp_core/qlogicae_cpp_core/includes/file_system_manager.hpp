#pragma once

#include "error_manager.hpp"
#include "singleton_manager.hpp"
#include "file_system_manager_utilities.hpp"
#include "file_system_manager_configurations.hpp"

namespace QLogicaeCppCore
{
    class FileSystemManager
    {
    public:        
        static FileSystemManager&
            singleton;

        FileSystemManager();

        ~FileSystemManager();

        FileSystemManager(
            const FileSystemManager&
                instance
        ) = delete;

        FileSystemManager(
            FileSystemManager&&
                instance
        ) noexcept = delete;

        FileSystemManager& operator = (
            FileSystemManager&&
                instance
        ) = delete;

        FileSystemManager& operator = (
            const FileSystemManager&
                instance
        ) = delete;

        bool
            construct();

        bool
            destruct();

        bool
            setup(
                const FileSystemManagerConfigurations&
                    new_configurations
            );

        bool
            setup();

        bool
            reset();
        
        size_t
            get_file_byte_size(            
                const std::string_view&
                    origin_path
        );

        size_t
            get_folder_byte_size(            
                const std::string_view&
                    origin_path,
                const bool&
                    is_recursive
        );

        std::string
            get_absolute_path(
                const std::string_view&
                    origin_path
        );

        std::string
            get_relative_path(
                const std::string_view&
                    origin_path,
                const std::string_view&
                    target_path
        );

        std::string
            get_file_extension(
                const std::string_view&
                    origin_path
        );

        std::string
            get_file_stem(
                const std::string_view&
                    origin_path
        );

        std::vector<std::string>
            get_entity_paths(
                const std::string_view&
                    origin_path,
                const bool&
                    is_recursive
        );

        std::vector<std::string>
            get_file_paths(
                const std::string_view&
                    origin_path,
                const bool&
                    is_recursive
        );

        std::vector<std::string>
            get_folder_paths(
                const std::string_view&
                    origin_path,
                const bool&
                    is_recursive
        );

        bool
            is_path_found(
                const std::string_view&
                    origin_path
        );

        bool
            is_entity(
                const std::string_view&
                    origin_path
        );

        bool
            is_file(
                const std::string_view&
                    origin_path
        );

        bool
            is_folder(
                const std::string_view&
                    origin_path
        );

        bool
            is_entity_user_permission_level_valid(
                const std::string_view&
                    origin_path,
                const std::filesystem::perms&
                    permission_level
        );

        std::vector<std::string>
            find_files_by_pattern(
                const std::string_view&
                    origin_path,
                const std::string_view&
                    pattern,
                const bool&
                    is_recursive
        );

        bool
            set_entity_read_status(
                const std::string_view&
                    origin_path,
                const bool&
                    value
        );

        bool
            set_entity_write_status(
                const std::string_view&
                    origin_path,
                const bool&
                    value
        );

        bool
            set_entity_visibility(
                const std::string_view&
                    origin_path,
                const bool&
                    value
        );

        bool
            create_folder(
                const std::string_view&
                    origin_path
        );

        bool
            copy_file(
                const std::string_view&
                    origin_path,
                const std::string_view&
                    target_path
        );

        bool
            copy_folder(
                const std::string_view&
                    origin_path,
                const std::string_view&
                    target_path,
                const bool&
                    is_recursive
        );

        bool
            move_entity(
                const std::string_view&
                    origin_path,
                const std::string_view&
                    target_path
        );

        bool
            move_file(
                const std::string_view&
                    origin_path,
                const std::string_view&
                    target_path
        );

        bool
            move_folder(
                const std::string_view&
                    origin_path,
                const std::string_view&
                    target_path
        );

        bool
            rename_entity(
                const std::string_view&
                    origin_path,
                const std::string_view&
                    name
        );

        bool
            rename_file(
                const std::string_view&
                    origin_path,
                const std::string_view&
                    name
        );

        bool
            rename_folder(
                const std::string_view&
                    origin_path,
                const std::string_view&
                    name
        );

        bool
            remove_file(
                const std::string_view&
                    origin_path
        );

        bool
            remove_folder(
                const std::string_view&
                    origin_path
        );

        bool
            remove_folder_sub_files(
                const std::string_view&
                    origin_path,
                const bool&
                    is_recursive
        );
        
        size_t
            get_file_byte_size(            
                const FileSystemManagerConfigurations&
                    configurations
        );

        size_t
            get_folder_byte_size(            
                const FileSystemManagerConfigurations&
                    configurations
        );

        std::string
            get_absolute_path(
                const FileSystemManagerConfigurations&
                    configurations
        );

        std::string
            get_relative_path(
                const FileSystemManagerConfigurations&
                    configurations
        );

        std::string
            get_file_extension(
                const FileSystemManagerConfigurations&
                    configurations
        );

        std::string
            get_file_stem(
                const FileSystemManagerConfigurations&
                    configurations
        );

        std::vector<std::string>
            get_entity_paths(
                const FileSystemManagerConfigurations&
                    configurations
        );

        std::vector<std::string>
            get_file_paths(
                const FileSystemManagerConfigurations&
                    configurations
        );

        std::vector<std::string>
            get_folder_paths(
                const FileSystemManagerConfigurations&
                    configurations
        );

        bool
            is_path_found(
                const FileSystemManagerConfigurations&
                    configurations
        );

        bool
            is_entity(
                const FileSystemManagerConfigurations&
                    configurations
        );

        bool
            is_file(
                const FileSystemManagerConfigurations&
                    configurations
        );

        bool
            is_folder(
                const FileSystemManagerConfigurations&
                    configurations
        );

        bool
            is_entity_user_permission_level_valid(
                const FileSystemManagerConfigurations&
                    configurations
        );

        std::vector<std::string>
            find_files_by_pattern(
                const FileSystemManagerConfigurations&
                    configurations
        );

        bool
            set_entity_read_status(
                const FileSystemManagerConfigurations&
                    configurations
        );

        bool
            set_entity_write_status(
                const FileSystemManagerConfigurations&
                    configurations
        );

        bool
            set_entity_visibility(
                const FileSystemManagerConfigurations&
                    configurations
        );

        bool
            create_folder(
                const FileSystemManagerConfigurations&
                    configurations
        );

        bool
            copy_file(
                const FileSystemManagerConfigurations&
                    configurations
        );

        bool
            copy_folder(
                const FileSystemManagerConfigurations&
                    configurations
        );

        bool
            move_entity(
                const FileSystemManagerConfigurations&
                    configurations
        );

        bool
            move_file(
                const FileSystemManagerConfigurations&
                    configurations
        );

        bool
            move_folder(
                const FileSystemManagerConfigurations&
                    configurations
        );

        bool
            rename_entity(
                const FileSystemManagerConfigurations&
                    configurations
        );

        bool
            rename_file(
                const FileSystemManagerConfigurations&
                    configurations
        );

        bool
            rename_folder(
                const FileSystemManagerConfigurations&
                    configurations
        );

        bool
            remove_file(
                const FileSystemManagerConfigurations&
                    configurations
        );

        bool
            remove_folder(
                const FileSystemManagerConfigurations&
                    configurations
        );

        bool
            remove_folder_sub_files(
                const FileSystemManagerConfigurations&
                    configurations
        );

        void
            _handle_construct();

        void
            _handle_destruct();

        void
            _handle_setup();

        void
            _handle_reset();

        void
            _handle_get_file_byte_size();

        void
            _handle_get_folder_byte_size();

        void
            _handle_get_absolute_path();

        void
            _handle_get_relative_path();

        void
            _handle_get_file_extension();

        void
            _handle_get_file_stem();

        void
            _handle_get_entity_paths();

        void
            _handle_get_file_paths();

        void
            _handle_get_folder_paths();

        void
            _handle_is_path_found();

        void
            _handle_is_entity();

        void
            _handle_is_file();

        void
            _handle_is_folder();

        void
            _handle_is_entity_user_permission_level_valid();

        void
            _handle_find_files_by_pattern();

        void
            _handle_set_entity_read_status();

        void
            _handle_set_entity_write_status();

        void
            _handle_set_entity_visibility();

        void
            _handle_create_folder();

        void
            _handle_copy_file();

        void
            _handle_copy_folder();

        void
            _handle_move_entity();

        void
            _handle_move_file();

        void
            _handle_move_folder();

        void
            _handle_rename_entity();

        void
            _handle_rename_file();

        void
            _handle_rename_folder();

        void
            _handle_remove_file();

        void
            _handle_remove_folder();

        void
            _handle_remove_folder_sub_files();        
    };
}
