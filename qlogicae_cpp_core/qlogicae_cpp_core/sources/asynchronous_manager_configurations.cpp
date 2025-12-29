#include "pch.hpp"

#include "../includes/asynchronous_manager_configurations.hpp"

namespace QLogicaeCppCore
{
    bool
        AsynchronousManagerConfigurations::default_is_enabled =
            true;

    bool
        AsynchronousManagerConfigurations::cache_is_enabled =
            AsynchronousManagerConfigurations::default_is_enabled;

}
