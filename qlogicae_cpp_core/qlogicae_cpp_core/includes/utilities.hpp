#pragma once

#include "instance_manager.hpp"

namespace QLogicaeCppCore
{
    class Utilities
    {
    public:
        Utilities();

        ~Utilities();

        Utilities(
            const Utilities&
            instance
        ) =
            delete;

        Utilities(
            Utilities&&
            instance
        ) noexcept =
            delete;

        Utilities&
            operator = (
                Utilities&&
                instance
                ) =
            delete;

        Utilities&
            operator = (
                const Utilities&
                instance
                ) =
            delete;

        static Utilities&
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
