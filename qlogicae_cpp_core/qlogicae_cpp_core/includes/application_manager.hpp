#pragma once

#include "value_cache.hpp"
#include "instance_manager.hpp"

namespace QLogicaeCppCore
{
    class ApplicationManager
    {
    public:
        static ApplicationManager&
            instance;

        ApplicationManager();

        ~ApplicationManager();

        ApplicationManager(
            const ApplicationManager& instance
        ) = delete;

        ApplicationManager(
            ApplicationManager&& instance
        ) noexcept = delete;

        ApplicationManager& operator = (
            ApplicationManager&& instance
            ) = delete;

        ApplicationManager& operator = (
            const ApplicationManager& instance
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
            setup();

        void
            _setup();

        bool
            reset();

        void
            _reset();
    };
}
