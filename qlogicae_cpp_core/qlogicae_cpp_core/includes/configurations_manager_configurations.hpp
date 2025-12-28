#pragma once

#include "exception_manager_configurations.hpp"

namespace QLogicaeCppCore
{
    struct ConfigurationsManagerConfigurations
    {        
        ExceptionManagerConfigurations
            exception_manager_configurations =
                exception_manager_configurations_default;
    };

    inline static ConfigurationsManagerConfigurations
        configurations_manager_configurations_default;
}
