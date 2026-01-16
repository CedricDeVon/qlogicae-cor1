#pragma once

#include "value_cache.hpp"
#include "instance_manager.hpp"

namespace QLogicaeCppCore
{
    class FileSystemManager
    {
    public:
        static FileSystemManager&
            instance;

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

        void
            _construct();

        bool
            destruct();

        void
            _destruct();

        bool
            setup();

        void
            _setup();

        bool
            reset();

        void
            _reset();

        size_t
            get_file_byte_size(            
                const std::string_view&
                    from_path
        );

        void
            get_file_byte_size();

        size_t
            get_folder_byte_size(            
                const std::string_view&
                    from_path,
                const bool&
                    is_recursive
        );

        void
            _get_folder_byte_size();

        std::string
            get_absolute_path(
                const std::string_view&
                    from_path
        );

        void
            _get_absolute_path();

        std::string
            get_relative_path(
                const std::string_view&
                    from_path,
                const std::string_view&
                    to_path
        );

        void
            _get_relative_path();

        std::string
            get_file_extension(
                const std::string_view&
                    from_path
        );

        void
            _get_file_extension();

        std::string
            get_file_stem(
                const std::string_view&
                    from_path
        );

        void
            _get_file_stem();

        std::vector<std::string>
            get_entity_paths(
                const std::string_view&
                    from_path,
                const bool&
                    is_recursive
        );

        void
            _get_entity_paths();

        std::vector<std::string>
            get_file_paths(
                const std::string_view&
                    from_path,
                const bool&
                    is_recursive
        );

        void
            _get_file_paths();

        std::vector<std::string>
            get_folder_paths(
                const std::string_view&
                    from_path,
                const bool&
                    is_recursive
        );

        void
            _get_folder_paths();

        bool
            is_path_found(
                const std::string_view&
                    from_path
        );

        void
            _is_path_found();

        bool
            is_entity(
                const std::string_view&
                    from_path
        );

        void
            _is_entity();

        bool
            is_file(
                const std::string_view&
                    from_path
        );

        void
            _is_file();

        bool
            is_folder(
                const std::string_view&
                    from_path
        );

        void
            _is_folder();

        bool
            is_entity_user_permission_level_valid(
                const std::string_view&
                    from_path,
                const std::filesystem::perms&
                    permission_level
        );

        void
            _is_entity_user_permission_level_valid();

        std::vector<std::string>
            find_files_by_pattern(
                const std::string_view&
                    from_path,
                const std::string_view&
                    pattern,
                const bool&
                    is_recursive
        );

        void
            _find_files_by_pattern();

        bool
            set_entity_read_status(
                const std::string_view&
                    from_path,
                const bool&
                    value
        );

        void
            _set_entity_read_status();

        bool
            set_entity_write_status(
                const std::string_view&
                    from_path,
                const bool&
                    value
        );

        void
            _set_entity_write_status();

        bool
            set_entity_visibility(
                const std::string_view&
                    from_path,
                const bool&
                    value
        );

        void
            _set_entity_visibility();

        bool
            create_folder(
                const std::string_view&
                    from_path
        );

        void
            _create_folder();

        bool
            copy_file(
                const std::string_view&
                    from_path,
                const std::string_view&
                    to_path
        );

        void
            _copy_file();

        bool
            copy_folder(
                const std::string_view&
                    from_path,
                const std::string_view&
                    to_path,
                const bool& is_recursive
        );

        void
            _copy_folder();

        bool
            move_entity(
                const std::string_view&
                    from_path,
                const std::string_view&
                    to_path
        );

        void
            _move_entity();

        bool
            move_file(
                const std::string_view&
                    from_path,
                const std::string_view&
                    to_path
        );

        void
            _move_file();

        bool
            move_folder(
                const std::string_view&
                    from_path,
                const std::string_view&
                    to_path
        );

        void
            _move_folder();

        bool
            rename_entity(
                const std::string_view&
                    from_path,
                const std::string_view&
                    name
        );

        void
            _rename_entity();

        bool
            rename_file(
                const std::string_view&
                    from_path,
                const std::string_view&
                    name
        );

        void
            _rename_file();

        bool
            rename_folder(
                const std::string_view&
                    from_path,
                const std::string_view&
                    name
        );

        void
            _rename_folder();

        bool
            remove_file(
                const std::string_view&
                    from_path
        );

        void
            _remove_file();

        bool
            remove_folder(
                const std::string_view&
                    from_path
        );

        void
            _remove_folder();

        bool
            remove_folder_sub_files(
                const std::string_view&
                    from_path,
                const bool&
                    is_recursive
        );

        void
            _remove_folder_sub_files();
    };
}
