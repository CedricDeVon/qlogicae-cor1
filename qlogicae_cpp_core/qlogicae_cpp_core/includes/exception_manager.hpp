#pragma once

#include "instance_manager.hpp"

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
        ) =
            delete;

        ExceptionManager(
            ExceptionManager&&
            instance
        ) noexcept =
            delete;

        ExceptionManager&
            operator = (
                ExceptionManager&&
                instance
                ) =
            delete;

        ExceptionManager&
            operator = (
                const ExceptionManager&
                instance
                ) =
            delete;

        static ExceptionManager&
            instance;

        static bool
            _boolean_ouput_cache_1;

        static std::string_view
            _string_view_ouput_cache_1; // title

        static std::string_view
            _string_view_ouput_cache_2; // message

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
