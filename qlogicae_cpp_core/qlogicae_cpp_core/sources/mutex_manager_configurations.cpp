#include "pch.hpp"

#include "../includes/mutex_manager_configurations.hpp"

namespace QLogicaeCppCore
{
    std::string
        MutexManagerConfigurations::default_base_name =
            "static";

    std::string
        MutexManagerConfigurations::cache_base_name =
            MutexManagerConfigurations::default_base_name;

    MutexManagerConfigurations
        MutexManagerConfigurations::cache;
}
