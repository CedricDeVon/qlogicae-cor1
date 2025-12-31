#pragma once

namespace QLogicaeCppCore
{
    struct AsynchronousManagerConfigurations
    {
        bool
            is_enabled =
                default_is_enabled;

        static bool
            initial_is_enabled;

        static bool
            default_is_enabled;
    };
}
