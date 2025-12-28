#pragma once

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
        ) =
            delete;

        ConstantsManager(
            ConstantsManager&&
            instance
        ) noexcept =
            delete;

        ConstantsManager&
            operator = (
                ConstantsManager&&
                instance
                ) =
            delete;

        ConstantsManager&
            operator = (
                const ConstantsManager&
                instance
                ) =
            delete;

        static ConstantsManager&
            instance;

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
    };
}
