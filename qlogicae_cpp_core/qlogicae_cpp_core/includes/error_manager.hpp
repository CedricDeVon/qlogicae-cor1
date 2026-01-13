#pragma once

#include "singleton_manager.hpp"
#include "error_manager_configurations.hpp"

namespace QLogicaeCppCore
{    
    class ErrorManager
    {
    public:   
        static bool
            cache_boolean_1;
            
        static boost::mutex
            cache_mutex_1;

        static std::string
            cache_error_log;

        static fast_io::native_io_observer
            cache_fast_io_error_console_output_type;

        static ErrorManager&
            singleton;



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
            construct(
                const ErrorManagerConfigurations&
                    configurations = {}
            );

        bool
            destruct(
                const ErrorManagerConfigurations&
                    configurations = {}
            );

        bool
            setup(
                const ErrorManagerConfigurations&
                    configurations = {}
            );

        bool
            reset(
                const ErrorManagerConfigurations&
                    configurations = {}
            );

        bool
            handle(
                const std::string_view&
                    title,
                const std::string_view&
                    message,
                const ErrorManagerConfigurations&
                    configurations = {}
            );

        bool
            handle(
                const std::string_view&
                    message,
                const ErrorManagerConfigurations&
                    configurations = {}
            );

        bool
            handle(
                const std::exception&
                    exception,
                const ErrorManagerConfigurations&
                    configurations = {}
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
            _handle();

        void
            _handle_asynchronously();

        void
            _handle_synchronously();
    };        
}
