#include "pch.hpp"

#include "../includes/exception_manager.hpp"

namespace QLogicaeCppCore
{
    ExceptionManager&
        ExceptionManager::instance =
            InstanceManager::instance.get_instance<ExceptionManager>();

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
        exception_configurations_input_cache_1 =
            new_configurations;

        _construct();

        return boolean_cache_1;
    }

    bool
        ExceptionManager::construct()
    {
        exception_configurations_input_cache_1 =
            exception_manager_configurations_default;

        _construct();

        return boolean_cache_1;
    }

    void
        ExceptionManager::_construct()
    {
        try
        {   
            boolean_cache_1 = true;
        }
        catch (...)
        {
            boolean_cache_1 = false;
        }        
    }

    bool
        ExceptionManager::destruct()
    {
        _destruct();

        return boolean_cache_1;
    }

    void
        ExceptionManager::_destruct()
    {
        try
        {              
            boolean_cache_1 = true;
        }
        catch (...)
        {
            boolean_cache_1 = false;
        }
    }

    bool
        ExceptionManager::handle(
            const std::string_view& title,
            const std::string_view& message
        )
    {
        string_view_cache_1 =
            title;

        string_view_cache_2 =
            message;

        _handle();

        return boolean_cache_1;
    }

    void
        ExceptionManager::_handle()
    {
        if (!ExceptionManagerConfigurations::is_enabled_cache)
        {
            boolean_cache_1 = true;

            return;
        }

        boolean_cache_1 = true;

        string_cache_1 =
            std::string(string_view_cache_1.data()) +
            " : " +
            string_view_cache_2.data();


        if (ExceptionManagerConfigurations::is_console_output_enabled_cache)
        {
            std::cout << string_cache_1 << "\n";
        }

        if (ExceptionManagerConfigurations::is_file_output_enabled_cache)
        {

        }

        if (ExceptionManagerConfigurations::is_exception_throwing_enabled_cache)
        {
            throw std::runtime_error(
                string_cache_1
            );
        }

    }
}
