#pragma once

#include "value_cache.hpp"
#include "error_manager_configurations.hpp"

namespace QLogicaeCppCore
{
    class ErrorManager
    {
    public:
        static fast_io::native_io_observer
            fast_io_error_console_output_type;

        static fast_io::native_file
            fast_io_native_file;

        static ErrorManager&
            instance;

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

        void
            _construct();

        bool
            destruct();

        void
            _destruct();

        bool
            setup(
                const ErrorManagerConfigurations&
                    new_configurations
            );

        bool
            setup();

        void
            _setup();

        bool
            reset();

        void
            _reset();

        bool
            handle(
                const std::string_view&
                    title,
                const std::string_view&
                    message
            );

        bool
            handle(
                const std::string_view& message
            );

        bool
            handle(
                const std::exception& exception
            );

        void
            _handle();

        static ErrorManager&
            get_instance();
    };    
}
