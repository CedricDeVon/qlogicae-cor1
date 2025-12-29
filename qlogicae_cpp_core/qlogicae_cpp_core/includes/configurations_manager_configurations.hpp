#pragma once

#include "exception_manager_configurations.hpp"

namespace QLogicaeCppCore
{
    struct ConfigurationsManagerConfigurations
    {        
        ExceptionManagerConfigurations
            exception_manager_configurations =
                {};

        static ConfigurationsManagerConfigurations
            cache;
    };
}
