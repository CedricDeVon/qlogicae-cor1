#include "pch.hpp"

#include "../includes/error_manager.hpp"

namespace QLogicaeCppCore
{
    ErrorManager&
        ErrorManager::instance =
            ErrorManager::get_instance();

    fast_io::native_io_observer
        ErrorManager::fast_io_error_console_output_type =
            fast_io::err();
    
    fast_io::native_file
        ErrorManager::fast_io_native_file(
            "error.log",
            fast_io::open_mode::app
        );

    ErrorManager::ErrorManager()
    {
        
    }

    ErrorManager::~ErrorManager()
    {
        _destruct();
    }

    bool
        ErrorManager::construct(
            const ErrorManagerConfigurations&
                new_configurations
        )
    {
        ErrorManagerConfigurations::cache =
            new_configurations;

        _construct();

        return ValueCache::boolean_1;
    }

    bool
        ErrorManager::construct()
    {
        ErrorManagerConfigurations::cache =
            {};

        _construct();

        return ValueCache::boolean_1;
    }

    void
        ErrorManager::_construct()
    {
        try
        {               
            ErrorManagerConfigurations::cache_is_enabled =
                ErrorManagerConfigurations::cache.is_enabled;

            ErrorManagerConfigurations::cache_is_console_output_enabled =
                ErrorManagerConfigurations::cache.is_console_output_enabled;

            ErrorManagerConfigurations::cache_is_file_output_enabled =
                ErrorManagerConfigurations::cache.is_file_output_enabled;

            ErrorManagerConfigurations::cache_is_exception_throwing_enabled =
                ErrorManagerConfigurations::cache.is_exception_throwing_enabled;

            ErrorManagerConfigurations::cache_folder_output_path =
                ErrorManagerConfigurations::cache.folder_output_path;

            ErrorManagerConfigurations::cache_file_name =
                ErrorManagerConfigurations::cache.file_name;

            ErrorManagerConfigurations::cache_file_extension =
                ErrorManagerConfigurations::cache.file_extension;

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
        ErrorManager::destruct()
    {
        _destruct();

        return ValueCache::boolean_1;
    }

    void
        ErrorManager::_destruct()
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
        ErrorManager::setup()
    {
        _setup();

        return ValueCache::boolean_1;
    }

    void
        ErrorManager::_setup()
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
        ErrorManager::reset()
    {
        _reset();

        return ValueCache::boolean_1;
    }

    void
        ErrorManager::_reset()
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
        ErrorManager::handle(
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
        ErrorManager::handle(
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
        ErrorManager::_handle()
    {
        if (!ErrorManagerConfigurations::cache_is_enabled)
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

        if (ErrorManagerConfigurations::cache_is_console_output_enabled)
        {       
            fast_io::io::println(
                fast_io_error_console_output_type,
                ValueCache::string_1
            );
        }

        if (ErrorManagerConfigurations::cache_is_file_output_enabled)
        {
            fast_io::io::println(
                fast_io_native_file,
                ValueCache::string_1
            );
        }

        if (ErrorManagerConfigurations::cache_is_exception_throwing_enabled)
        {
            throw std::runtime_error(
                ValueCache::string_1
            );
        }
    }

    ErrorManager&
        ErrorManager::get_instance()
    {
        static ErrorManager
            instance;

        return instance;
    }
}
