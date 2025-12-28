#pragma once

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

        static std::string_view
            _string_view_input_cache_1; // exception title

        static std::string_view
            _string_view_input_cache_2; // exception message

        static std::string
            _string_temporary_cache_1;

        static bool
            _boolean_ouput_cache_1; // is_successful

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

        void
            _handle();
    };
}
