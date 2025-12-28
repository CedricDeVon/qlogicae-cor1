#pragma once

namespace QLogicaeCppCore
{
    struct MutexManagerConfigurations
    {
        inline static std::string
            base_name_default =
                "static";

        std::string
            base_name =
                base_name_default;

        inline static std::string
            base_name_cache =
                base_name_default;
    };

    inline static MutexManagerConfigurations
        mutex_manager_configurations_default;
}
