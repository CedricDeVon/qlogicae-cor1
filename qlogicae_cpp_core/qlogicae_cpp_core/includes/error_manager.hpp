#pragma once

#include "singleton_manager.hpp"
#include "error_manager_configurations.hpp"

namespace QLogicaeCppCore
{
    class ErrorManager
    {
    public:        
        ErrorManager();

        ~ErrorManager();

        ErrorManager(
            const ErrorManager&
                instance
        ) = delete;

        ErrorManager(
            ErrorManager&&
                instance
        ) noexcept = delete;

        ErrorManager&
            operator = (
                ErrorManager&&
                    instance
            ) = delete;

        ErrorManager&
            operator = (
                const ErrorManager&
                    instance
            ) = delete;

        bool
            construct();

        bool
            destruct();

        bool
            setup(
                const ErrorManagerConfigurations&
                    new_configurations
            );

        bool
            setup();

        bool
            reset();

        bool
            handle(
                const std::string_view&
                    title,
                const std::string_view&
                    message
            );

        bool
            handle(
                const std::string_view&
                    message
            );

        bool
            handle(
                const std::exception&
                    exception
            );

        void
            _handle_asynchronously();

        void
            _handle_synchronously();

        void
            _construct();
        
        void
            _destruct();

        void
            _setup();

        void
            _reset();

        void
            _handle();
    };    

    inline static bool
        ErrorManager__cache_is_successful =
            false;

    inline static std::string
        ErrorManager__cache_error_log =
            "";

    inline static fast_io::native_io_observer
        ErrorManager__cache_fast_io_error_console_output_type =
            fast_io::err();
    
    inline static ErrorManager&
        ErrorManager__singleton =
            SingletonManager::get_singleton<ErrorManager>();
    

}
