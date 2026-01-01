#pragma once

#include "value_cache.hpp"
#include "instance_manager.hpp"

namespace QLogicaeCppCore
{
    class UtilitiesCache
    {
    public:
        static UtilitiesCache&
            instance;

        UtilitiesCache();

        ~UtilitiesCache();

        UtilitiesCache(
            const UtilitiesCache& instance
        ) = delete;

        UtilitiesCache(
            UtilitiesCache&& instance
        ) noexcept = delete;

        UtilitiesCache& operator = (
            UtilitiesCache&& instance
        ) = delete;

        UtilitiesCache& operator = (
            const UtilitiesCache& instance
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
