#include "pch.hpp"

#include "../includes/exception_manager.hpp"

namespace QLogicaeCppCore
{
    ExceptionManager&
        ExceptionManager::instance =
            InstanceManager::instance.get_instance<ExceptionManager>();

    fast_io::native_io_observer
        ExceptionManager::fast_io_error_console_output_type =
            fast_io::err();
    
    fast_io::native_file
        ExceptionManager::fast_io_native_file(
            ExceptionManagerConfigurations::cache_folder_output_path
                + "\\"
                + ExceptionManagerConfigurations::cache_file_name
                + ExceptionManagerConfigurations::cache_file_extension,
            fast_io::open_mode::app
        );

    ExceptionManager::ExceptionManager()
    {
        
    }

    ExceptionManager::~ExceptionManager()
    {
        _destruct();
    }

    bool
        ExceptionManager::construct(
            const ExceptionManagerConfigurations&
                new_configurations
        )
    {
        ExceptionManagerConfigurations::cache =
            new_configurations;

        _construct();

        return ValueCache::boolean_1;
    }

    bool
        ExceptionManager::construct()
    {
        ExceptionManagerConfigurations::cache =
            {};

        _construct();

        return ValueCache::boolean_1;
    }

    void
        ExceptionManager::_construct()
    {
        try
        {               
            ExceptionManagerConfigurations::cache_is_enabled =
                ExceptionManagerConfigurations::cache.is_enabled;

            ExceptionManagerConfigurations::cache_is_console_output_enabled =
                ExceptionManagerConfigurations::cache.is_console_output_enabled;

            ExceptionManagerConfigurations::cache_is_file_output_enabled =
                ExceptionManagerConfigurations::cache.is_file_output_enabled;

            ExceptionManagerConfigurations::cache_is_exception_throwing_enabled =
                ExceptionManagerConfigurations::cache.is_exception_throwing_enabled;

            ExceptionManagerConfigurations::cache_folder_output_path =
                ExceptionManagerConfigurations::cache.folder_output_path;

            ExceptionManagerConfigurations::cache_file_name =
                ExceptionManagerConfigurations::cache.file_name;

            ExceptionManagerConfigurations::cache_file_extension =
                ExceptionManagerConfigurations::cache.file_extension;

            ValueCache::boolean_1 =
                true;
        }
        catch (...)
        {
            ValueCache::boolean_1 =
                false;
        }        
    }

    bool
        ExceptionManager::destruct()
    {
        _destruct();

        return ValueCache::boolean_1;
    }

    void
        ExceptionManager::_destruct()
    {
        try
        {              
            ValueCache::boolean_1 =
                true;
        }
        catch (...)
        {
            ValueCache::boolean_1 =
                false;
        }
    }

    bool
        ExceptionManager::handle(
            const std::string_view& title,
            const std::string_view& message
        )
    {
        ValueCache::string_view_1 =
            title;

        ValueCache::string_view_2 =
            message;

        _handle();

        return ValueCache::boolean_1;
    }

    bool
        ExceptionManager::handle(
            const std::exception& exception
        )
    {
        ValueCache::string_view_1 =
            typeid(exception).name();

        ValueCache::string_view_2 =
            exception.what();

        _handle();

        return ValueCache::boolean_1;
    }

    void
        ExceptionManager::_handle()
    {
        if (!ExceptionManagerConfigurations::cache_is_enabled)
        {
            ValueCache::boolean_1 =
                false;

            return;
        }

        ValueCache::boolean_1 =
            true;

        ValueCache::string_1.reserve(128);

        ValueCache::string_1 =
            std::string(ValueCache::string_view_1.data()) +
            " - " +
            ValueCache::string_view_2.data();

        if (ExceptionManagerConfigurations::cache_is_console_output_enabled)
        {       
            fast_io::io::println(
                fast_io_error_console_output_type,
                ValueCache::string_1
            );
        }

        if (ExceptionManagerConfigurations::cache_is_file_output_enabled)
        {
            fast_io::io::println(
                fast_io_native_file,
                ValueCache::string_1
            );
        }

        if (ExceptionManagerConfigurations::cache_is_exception_throwing_enabled)
        {
            throw std::runtime_error(
                ValueCache::string_1
            );
        }
    }
}
