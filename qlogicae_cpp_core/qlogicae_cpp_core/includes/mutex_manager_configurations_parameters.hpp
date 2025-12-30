#pragma once

#include "instance_manager.hpp"

namespace QLogicaeCppCore
{
    struct MutexManagerConfigurationsParameters
    {
        std::string
            base_name =
                default_base_name;

        static std::string
            initial_base_name;

        static std::string
            default_base_name;

        static MutexManagerConfigurationsParameters
            instance;
    };
}
