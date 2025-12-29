#pragma once

namespace QLogicaeCppCore
{
    struct MutexManagerConfigurations
    {
        std::string
            base_name =
                default_base_name;

        static std::string
            default_base_name;

        static std::string
            cache_base_name;

        static MutexManagerConfigurations
            cache;

    };
}
