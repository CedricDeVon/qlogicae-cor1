#include "pch.hpp"

#include "../includes/file_system_manager.hpp"

namespace QLogicaeCppCore
{
    FileSystemManager&
        FileSystemManager::singleton =
            SingletonManager::get_singleton<FileSystemManager>();

    FileSystemManager::FileSystemManager()
    {
        try
        {
            _handle_construct();
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }        
    }

    FileSystemManager::~FileSystemManager()
    {
        try
        {
            _handle_destruct();
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }        
    }

    bool
        FileSystemManager::construct()
    {
        _handle_construct();

        return
            FileSystemManagerUtilities::cache_boolean_1;
    }

    bool
        FileSystemManager::destruct()
    {
        _handle_destruct();

        return
            FileSystemManagerUtilities::cache_boolean_1;
    }
    
    bool
        FileSystemManager::setup(
            const FileSystemManagerConfigurations&
                    new_configurations
        )
    {        
        FileSystemManagerConfigurations::cache =
            new_configurations;

        _handle_setup();

        return
            FileSystemManagerUtilities::cache_boolean_1;
    }

    bool
        FileSystemManager::setup()
    {
        FileSystemManagerConfigurations::cache =
            {};

        _handle_setup();

        return
            FileSystemManagerUtilities::cache_boolean_1;
    }
    
    bool
        FileSystemManager::reset()
    {
        _handle_reset();

        return
            FileSystemManagerUtilities::cache_boolean_1;
    }
        
    size_t
        FileSystemManager::get_file_byte_size(            
            const std::string_view&
                origin_path
    )
    {


        _handle_get_file_byte_size();

        return
            FileSystemManagerUtilities::cache_size_t_1;
    }

    size_t
        FileSystemManager::get_folder_byte_size(            
            const std::string_view&
                origin_path,
            const bool&
                is_recursive
    )
    {
        _handle_get_folder_byte_size();

        return
            FileSystemManagerUtilities::cache_size_t_1;
    }

    std::string
        FileSystemManager::get_absolute_path(
            const std::string_view&
                origin_path
    )
    {
        _handle_get_absolute_path();

        return
            FileSystemManagerUtilities::cache_string_1;
    }

    std::string
        FileSystemManager::get_relative_path(
            const std::string_view&
                origin_path,
            const std::string_view&
                target_path
    )
    {
        _handle_get_relative_path();

        return
            FileSystemManagerUtilities::cache_string_1;
    }

    std::string
        FileSystemManager::get_file_extension(
            const std::string_view&
                origin_path
    )
    {
        _handle_get_file_extension();

        return
            FileSystemManagerUtilities::cache_string_1;
    }

    std::string
        FileSystemManager::get_file_stem(
            const std::string_view&
                origin_path
    )
    {
        _handle_get_file_stem();

        return
            FileSystemManagerUtilities::cache_string_1;
    }

    std::vector<std::string>
        FileSystemManager::get_entity_paths(
            const std::string_view&
                origin_path,
            const bool&
                is_recursive
    )
    {
        _handle_get_entity_paths();

        return
            FileSystemManagerUtilities::cache_vector_string_1;
    }

    std::vector<std::string>
        FileSystemManager::get_file_paths(
            const std::string_view&
                origin_path,
            const bool&
                is_recursive
    )
    {
        _handle_get_file_paths();

        return
            FileSystemManagerUtilities::cache_vector_string_1;
    }

    std::vector<std::string>
        FileSystemManager::get_folder_paths(
            const std::string_view&
                origin_path,
            const bool&
                is_recursive
    )
    {
        _handle_get_folder_paths();

        return
            FileSystemManagerUtilities::cache_vector_string_1;
    }

    bool
        FileSystemManager::is_path_found(
            const std::string_view&
                origin_path
    )
    {
        _handle_is_path_found();

        return
            FileSystemManagerUtilities::cache_boolean_1;
    }

    bool
        FileSystemManager::is_entity(
            const std::string_view&
                origin_path
    )
    {
        _handle_is_entity();

        return
            FileSystemManagerUtilities::cache_boolean_1;
    }

    bool
        FileSystemManager::is_file(
            const std::string_view&
                origin_path
    )
    {
        _handle_is_file();

        return
            FileSystemManagerUtilities::cache_boolean_1;
    }

    bool
        FileSystemManager::is_folder(
            const std::string_view&
                origin_path
    )
    {
        _handle_is_folder();

        return
            FileSystemManagerUtilities::cache_boolean_1;
    }

    bool
        FileSystemManager::is_entity_user_permission_level_valid(
            const std::string_view&
                origin_path,
            const std::filesystem::perms&
                permission_level
    )
    {
        _handle_is_entity_user_permission_level_valid();

        return
            FileSystemManagerUtilities::cache_boolean_1;
    }

    std::vector<std::string>
        FileSystemManager::find_files_by_pattern(
            const std::string_view&
                origin_path,
            const std::string_view&
                pattern,
            const bool&
                is_recursive
    )
    {
        _handle_find_files_by_pattern();

        return
            FileSystemManagerUtilities::cache_vector_string_1;
    }

    bool
        FileSystemManager::set_entity_read_status(
            const std::string_view&
                origin_path,
            const bool&
                value
    )
    {
        _handle_set_entity_read_status();

        return
            FileSystemManagerUtilities::cache_boolean_1;
    }

    bool
        FileSystemManager::set_entity_write_status(
            const std::string_view&
                origin_path,
            const bool&
                value
    )
    {
        _handle_set_entity_write_status();



        return
            FileSystemManagerUtilities::cache_boolean_1;
    }

    bool
        FileSystemManager::set_entity_visibility(
            const std::string_view&
                origin_path,
            const bool&
                value
    )
    {
        _handle_set_entity_visibility();

        return
            FileSystemManagerUtilities::cache_boolean_1;
    }

    bool
        FileSystemManager::create_folder(
            const std::string_view&
                origin_path
    )
    {
        _handle_create_folder();

        return
            FileSystemManagerUtilities::cache_boolean_1;
    }

    bool
        FileSystemManager::copy_file(
            const std::string_view&
                origin_path,
            const std::string_view&
                target_path
    )
    {
        _handle_copy_file();

        return
            FileSystemManagerUtilities::cache_boolean_1;
    }

    bool
        FileSystemManager::copy_folder(
            const std::string_view&
                origin_path,
            const std::string_view&
                target_path,
            const bool& is_recursive
    )
    {
        _handle_copy_folder();

        return
            FileSystemManagerUtilities::cache_boolean_1;
    }

    bool
        FileSystemManager::move_entity(
            const std::string_view&
                origin_path,
            const std::string_view&
                target_path
    )
    {
        _handle_move_entity();

        return
            FileSystemManagerUtilities::cache_boolean_1;
    }

    bool
        FileSystemManager::move_file(
            const std::string_view&
                origin_path,
            const std::string_view&
                target_path
    )
    {
        _handle_move_file();

        return
            FileSystemManagerUtilities::cache_boolean_1;
    }

    bool
        FileSystemManager::move_folder(
            const std::string_view&
                origin_path,
            const std::string_view&
                target_path
    )
    {
        _handle_move_folder();

        return
            FileSystemManagerUtilities::cache_boolean_1;
    }

    bool
        FileSystemManager::rename_entity(
            const std::string_view&
                origin_path,
            const std::string_view&
                name
    )
    {
        _handle_rename_entity();

        return
            FileSystemManagerUtilities::cache_boolean_1;
    }

    bool
        FileSystemManager::rename_file(
            const std::string_view&
                origin_path,
            const std::string_view&
                name
    )
    {
        _handle_rename_file();

        return
            FileSystemManagerUtilities::cache_boolean_1;
    }

    bool
        FileSystemManager::rename_folder(
            const std::string_view&
                origin_path,
            const std::string_view&
                name
    )
    {
        _handle_rename_folder();

        return
            FileSystemManagerUtilities::cache_boolean_1;
    }

    bool
        FileSystemManager::remove_file(
            const std::string_view&
                origin_path
    )
    {
        _handle_remove_file();

        return
            FileSystemManagerUtilities::cache_boolean_1;
    }

    bool
        FileSystemManager::remove_folder(
            const std::string_view&
                origin_path
    )
    {
        _handle_remove_folder();

        return
            FileSystemManagerUtilities::cache_boolean_1;
    }

    bool
        FileSystemManager::remove_folder_sub_files(
            const std::string_view&
                origin_path,
            const bool&
                is_recursive
    )
    {
        _handle_remove_folder_sub_files();

        return
            FileSystemManagerUtilities::cache_boolean_1;
    }


    void
        FileSystemManager::_handle_construct()
    {
        try
        {
            FileSystemManagerUtilities::cache_boolean_1 =
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        FileSystemManager::_handle_destruct()
    {
        try
        {
            FileSystemManagerUtilities::cache_boolean_1 =
                true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        FileSystemManager::_handle_setup()
    {
        try
        {
            FileSystemManagerUtilities::singleton
                ._handle_setup();
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        FileSystemManager::_handle_reset()
    {
        try
        {
            FileSystemManagerUtilities::singleton
                ._handle_reset();
        }
        catch
        (
            const std::exception&
                exception
        )
        {
            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        FileSystemManager::_handle_get_file_byte_size()
    {
        try
        {
            
        }
        catch
        (
            const std::exception&
                exception
        )
        {            
            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        FileSystemManager::_handle_get_folder_byte_size()
    {
        try
        {
            
        }
        catch
        (
            const std::exception&
                exception
        )
        {            
            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        FileSystemManager::_handle_get_absolute_path()
    {
        try
        {
            
        }
        catch
        (
            const std::exception&
                exception
        )
        {            
            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        FileSystemManager::_handle_get_relative_path()
    {
        try
        {
            
        }
        catch
        (
            const std::exception&
                exception
        )
        {            
            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        FileSystemManager::_handle_get_file_extension()
    {
        try
        {
            
        }
        catch
        (
            const std::exception&
                exception
        )
        {            
            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        FileSystemManager::_handle_get_file_stem()
    {
        try
        {
            
        }
        catch
        (
            const std::exception&
                exception
        )
        {            
            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        FileSystemManager::_handle_get_entity_paths()
    {
        try
        {
            
        }
        catch
        (
            const std::exception&
                exception
        )
        {            
            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        FileSystemManager::_handle_get_file_paths()
    {
        try
        {
            
        }
        catch
        (
            const std::exception&
                exception
        )
        {            
            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        FileSystemManager::_handle_get_folder_paths()
    {
        try
        {
            
        }
        catch
        (
            const std::exception&
                exception
        )
        {            
            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        FileSystemManager::_handle_is_path_found()
    {
        try
        {
            
        }
        catch
        (
            const std::exception&
                exception
        )
        {            
            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        FileSystemManager::_handle_is_entity()
    {
        try
        {
            
        }
        catch
        (
            const std::exception&
                exception
        )
        {            
            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        FileSystemManager::_handle_is_file()
    {
        try
        {
            
        }
        catch
        (
            const std::exception&
                exception
        )
        {            
            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        FileSystemManager::_handle_is_folder()
    {
        try
        {
            
        }
        catch
        (
            const std::exception&
                exception
        )
        {            
            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        FileSystemManager::_handle_is_entity_user_permission_level_valid()
    {
        try
        {
            
        }
        catch
        (
            const std::exception&
                exception
        )
        {            
            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        FileSystemManager::_handle_find_files_by_pattern()
    {
        try
        {
            
        }
        catch
        (
            const std::exception&
                exception
        )
        {            
            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        FileSystemManager::_handle_set_entity_read_status()
    {
        try
        {
            
        }
        catch
        (
            const std::exception&
                exception
        )
        {            
            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        FileSystemManager::_handle_set_entity_write_status()
    {
        try
        {
            
        }
        catch
        (
            const std::exception&
                exception
        )
        {            
            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        FileSystemManager::_handle_set_entity_visibility()
    {
        try
        {
            
        }
        catch
        (
            const std::exception&
                exception
        )
        {            
            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        FileSystemManager::_handle_create_folder()
    {
        try
        {
            
        }
        catch
        (
            const std::exception&
                exception
        )
        {            
            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        FileSystemManager::_handle_copy_file()
    {
        try
        {
            
        }
        catch
        (
            const std::exception&
                exception
        )
        {            
            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        FileSystemManager::_handle_copy_folder()
    {
        try
        {
            
        }
        catch
        (
            const std::exception&
                exception
        )
        {            
            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        FileSystemManager::_handle_move_entity()
    {
        try
        {
            
        }
        catch
        (
            const std::exception&
                exception
        )
        {            
            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        FileSystemManager::_handle_move_file()
    {
        try
        {
            
        }
        catch
        (
            const std::exception&
                exception
        )
        {            
            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        FileSystemManager::_handle_move_folder()
    {
        try
        {
            
        }
        catch
        (
            const std::exception&
                exception
        )
        {            
            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        FileSystemManager::_handle_rename_entity()
    {
        try
        {
            
        }
        catch
        (
            const std::exception&
                exception
        )
        {            
            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        FileSystemManager::_handle_rename_file()
    {
        try
        {
            
        }
        catch
        (
            const std::exception&
                exception
        )
        {            
            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        FileSystemManager::_handle_rename_folder()
    {
        try
        {
            
        }
        catch
        (
            const std::exception&
                exception
        )
        {            
            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        FileSystemManager::_handle_remove_file()
    {
        try
        {
            
        }
        catch
        (
            const std::exception&
                exception
        )
        {            
            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        FileSystemManager::_handle_remove_folder()
    {
        try
        {
            
        }
        catch
        (
            const std::exception&
                exception
        )
        {            
            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }

    void
        FileSystemManager::_handle_remove_folder_sub_files()
    {
        try
        {
            
        }
        catch
        (
            const std::exception&
                exception
        )
        {            
            ErrorManager::cache_error_log =
                exception.what();

            ErrorManager::singleton
                ._handle();
        }
    }
}
