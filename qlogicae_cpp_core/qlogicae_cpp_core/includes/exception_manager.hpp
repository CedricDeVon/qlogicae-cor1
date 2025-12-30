#pragma once

#include "value_cache.hpp"
#include "instance_manager.hpp"
#include "exception_manager_configurations.hpp"

namespace QLogicaeCppCore
{
    class ExceptionManager
    {
    public:
        ExceptionManager();

        ~ExceptionManager();

        ExceptionManager(
            const ExceptionManager&
                instance
        ) = delete;

        ExceptionManager(
            ExceptionManager&&
                instance
        ) noexcept = delete;

        ExceptionManager&
            operator = (
                ExceptionManager&&
                    instance
            ) = delete;

        ExceptionManager&
            operator = (
                const ExceptionManager&
                    instance
            ) = delete;

        static ExceptionManager&
            instance;

        static fast_io::native_io_observer
            fast_io_error_console_output_type;

        static fast_io::native_file
            fast_io_native_file;

        bool
            construct(
                const ExceptionManagerConfigurations&
                    new_configurations
            );

        bool
            construct();

        void
            _construct();

        bool
            destruct();

        void
            _destruct();

        bool
            handle(
                const std::string_view& title,
                const std::string_view& message
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
    };    
}
