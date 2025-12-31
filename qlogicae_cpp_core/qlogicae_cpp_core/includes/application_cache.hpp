#pragma once

#include "value_cache.hpp"
#include "instance_manager.hpp"

namespace QLogicaeCppCore
{
    class ApplicationCache
    {
    public:
        ApplicationCache();

        ~ApplicationCache();

        ApplicationCache(
            const ApplicationCache&
                instance
        ) = delete;

        ApplicationCache(
            ApplicationCache&&
                instance
        ) noexcept = delete;

        ApplicationCache&
            operator = (
                ApplicationCache&&
                    instance
            ) = delete;

        ApplicationCache&
            operator = (
                const ApplicationCache&
                    instance
            ) = delete;

        static ApplicationCache&
            instance;
        
        bool
            construct();

        void
            _construct();

        bool
            destruct();

        void
            _destruct();
    };
}
