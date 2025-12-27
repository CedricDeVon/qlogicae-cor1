#include "pch.hpp"

#include "../includes/exception_manager.hpp"

namespace QLogicaeCppCore
{
    ExceptionManager&
        ExceptionManager::instance =
            InstanceManager::instance.get_instance<ExceptionManager>();

    bool
        ExceptionManager::_boolean_ouput_cache_1 =
            false;

    std::string_view
        ExceptionManager::_string_view_ouput_cache_1 =
            "";

    std::string_view
        ExceptionManager::_string_view_ouput_cache_2 =
            "";
 
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
        try
        {
            _construct();
        }
        catch (...)
        {
            _boolean_ouput_cache_1 = false;
        }

        return _boolean_ouput_cache_1;
    }

    void
        ExceptionManager::_construct()
    {
        _boolean_ouput_cache_1 = true;
    }

    bool
        ExceptionManager::destruct()
    {
        try
        {
            _destruct();
        }
        catch (...)
        {
            _boolean_ouput_cache_1 = false;
        }

        return _boolean_ouput_cache_1;
    }

    void
        ExceptionManager::_destruct()
    {
        _boolean_ouput_cache_1 = true;
    }

    bool
        ExceptionManager::handle(
            const std::string_view& title,
            const std::string_view& message
        )
    {
        try
        {
            _string_view_ouput_cache_1 =
                title;

            _string_view_ouput_cache_2 =
                message;

            _handle();
        }
        catch (...)
        {
            _boolean_ouput_cache_1 = false;
        }

        return _boolean_ouput_cache_1;
    }

    void
        ExceptionManager::_handle()
    {
        std::string exception_message =
            std::string(_string_view_ouput_cache_1.data()) +
            " : " +
            _string_view_ouput_cache_2.data();

        std::cout << exception_message << "\n";

        _boolean_ouput_cache_1 = true;
    }
}
