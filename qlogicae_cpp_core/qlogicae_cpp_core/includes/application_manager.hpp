#pragma once

#include "error_manager.hpp"
#include "singleton_manager.hpp"

namespace QLogicaeCppCore
{
    class ApplicationManager
    {
    public:
        static ApplicationManager&
            singleton;

        ApplicationManager();

        ~ApplicationManager();

        bool
            construct();

        bool
            destruct();

        bool
            setup();

        bool
            reset();
    };
}
