#include "pch.hpp"

#include "../includes/mutex_manager_configurations.hpp"

namespace QLogicaeCppCore
{
    void*
        MutexManagerConfigurations::initial_pointer =
            nullptr;

    std::string
        MutexManagerConfigurations::initial_name =
            "static";



    std::string
        MutexManagerConfigurations::default_name =
            MutexManagerConfigurations::initial_name;

    void*
        MutexManagerConfigurations::default_pointer =
            MutexManagerConfigurations::initial_pointer;



    std::string
        MutexManagerConfigurations::cache_name =
            MutexManagerConfigurations::initial_name;

    void*
        MutexManagerConfigurations::cache_pointer =
            MutexManagerConfigurations::initial_pointer;



    MutexManagerConfigurations
        MutexManagerConfigurations::cache;
}
