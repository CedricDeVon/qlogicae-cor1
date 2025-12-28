#include "pch.hpp"

#include "../includes/exception_manager.hpp"

namespace QLogicaeCppCore
{
    ExceptionManager&
        ExceptionManager::instance =
            InstanceManager::instance.get_instance<ExceptionManager>();

    std::string_view
        ExceptionManager::_string_view_input_cache_1 =
            "";

    std::string_view
        ExceptionManager::_string_view_input_cache_2 =
            "";

    std::string
        ExceptionManager::_string_temporary_cache_1 =
            "";

    bool
        ExceptionManager::_boolean_ouput_cache_1 =
            false;
 
    ExceptionManager::ExceptionManager()
    {
        _construct();
    }

    ExceptionManager::~ExceptionManager()
    {
        _destruct();
    }

    bool
        ExceptionManager::construct()
    {
        _construct();

        return _boolean_ouput_cache_1;
    }

    bool
        ExceptionManager::construct(
            const ExceptionManagerConfigurations&
                configurations
        )
    {
        _configurations =
            configurations;

        return construct();
    }

    void
        ExceptionManager::_construct()
    {
        try
        {
            _boolean_ouput_cache_1 = true;
        }
        catch (...)
        {
            _boolean_ouput_cache_1 = false;
        }        
    }

    bool
        ExceptionManager::destruct()
    {
        _destruct();

        return _boolean_ouput_cache_1;
    }

    void
        ExceptionManager::_destruct()
    {
        try
        {            
            _boolean_ouput_cache_1 = true;
        }
        catch (...)
        {
            _boolean_ouput_cache_1 = false;
        }               
    }

    bool
        ExceptionManager::handle(
            const std::string_view& title,
            const std::string_view& message
        )
    {
        _string_view_input_cache_1 =
            title;

        _string_view_input_cache_2 =
            message;

        _handle();

        return _boolean_ouput_cache_1;
    }

    void
        ExceptionManager::_handle()
    {
        if (!_configurations.is_enabled)
        {
            _boolean_ouput_cache_1 = true;

            return;
        }

        _string_temporary_cache_1 =
            std::string(_string_view_input_cache_1.data()) +
            " : " +
            _string_view_input_cache_2.data();

        if (_configurations.is_file_output_enabled)
        {
            _boolean_ouput_cache_1 = true;
        }

        if (_configurations.is_exception_throwing_enabled)
        {
            _boolean_ouput_cache_1 = true;
        }

        _boolean_ouput_cache_1 = true;
    }
}
