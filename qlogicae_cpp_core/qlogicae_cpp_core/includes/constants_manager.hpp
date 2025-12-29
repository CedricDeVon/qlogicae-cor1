#pragma once

#include "value_cache.hpp"
#include "instance_manager.hpp"

namespace QLogicaeCppCore
{
    class ConstantsManager
    {
    public:
        ConstantsManager();

        ~ConstantsManager();

        ConstantsManager(
            const ConstantsManager&
                instance
        ) = delete;

        ConstantsManager(
            ConstantsManager&&
                instance
        ) noexcept = delete;

        ConstantsManager&
            operator = (
                ConstantsManager&&
                    instance
            ) = delete;

        ConstantsManager&
            operator = (
                const ConstantsManager&
                    instance
            ) = delete;

        static ConstantsManager&
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
