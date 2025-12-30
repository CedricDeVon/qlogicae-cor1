#include "pch.hpp"

#include "../includes/mutex_manager_configurations_parameters.hpp"

namespace QLogicaeCppCore
{
    std::string
        MutexManagerConfigurationsParameters::initial_base_name =
            "static";

    std::string
        MutexManagerConfigurationsParameters::default_base_name =
            MutexManagerConfigurationsParameters::initial_base_name;

    MutexManagerConfigurationsParameters
        MutexManagerConfigurationsParameters::instance =
            {};
}
