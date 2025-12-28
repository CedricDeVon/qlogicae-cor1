#pragma once

namespace QLogicaeCppCore
{
    struct AsynchronousManagerConfigurations
    {
        inline static bool
            is_enabled_default =
                true;

        bool
            is_enabled =
                is_enabled_default;

        inline static bool
            is_enabled_cache =
                is_enabled_default;
    };

    inline static AsynchronousManagerConfigurations
        asynchronous_manager_configurations_default;
}
