#include "pch.hpp"

#include "../includes/asynchronous_manager_configurations.hpp"

namespace QLogicaeCppCore
{
    bool
        AsynchronousManagerConfigurations::initial_is_enabled =
            true;

    bool
        AsynchronousManagerConfigurations::default_is_enabled =
            AsynchronousManagerConfigurations::initial_is_enabled;
}
