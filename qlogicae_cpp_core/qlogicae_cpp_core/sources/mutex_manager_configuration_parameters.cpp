#include "pch.hpp"

#include "../includes/mutex_manager_configuration_parameters.hpp"

namespace QLogicaeCppCore
{
    void*
        MutexManagerConfigurationParameters::initial_pointer =
            nullptr;

    std::string
        MutexManagerConfigurationParameters::initial_name =
            "static";



    std::string
        MutexManagerConfigurationParameters::default_name =
            MutexManagerConfigurationParameters::initial_name;

    void*
        MutexManagerConfigurationParameters::default_pointer =
            MutexManagerConfigurationParameters::initial_pointer;
}
