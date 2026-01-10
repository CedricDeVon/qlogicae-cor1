#pragma once

#include "error_manager.hpp"
#include "singleton_manager.hpp"

namespace QLogicaeCppCore
{
    class ApplicationManager
    {
    public:
        static bool
            cache_boolean_1;

        static ApplicationManager&
            singleton;

        ApplicationManager();

        ~ApplicationManager();

        ApplicationManager(
            const ApplicationManager&
                instance
        ) = delete;

        ApplicationManager(
            ApplicationManager&&
                instance
        ) noexcept = delete;

        ApplicationManager& operator = (
            ApplicationManager&&
                instance
        ) = delete;

        ApplicationManager& operator = (
            const ApplicationManager&
                instance
        ) = delete;

        bool
            construct();

        bool
            destruct();

        bool
            setup();

        bool
            reset();

        void
            _handle_construct();

        void
            _handle_destruct();

        void
            _handle_setup();

        void
            _handle_reset();
    };
}
