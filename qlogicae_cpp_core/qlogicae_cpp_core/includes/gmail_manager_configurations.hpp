#pragma once

namespace QLogicaeCppCore
{
    struct GmailManagerConfigurations
    {
        bool
            is_enabled =
                default_is_enabled;

        static bool
            initial_is_enabled;

        static bool
            default_is_enabled;

        static bool
            cache_is_enabled;

        static GmailManagerConfigurations
            cache;
    };
}
