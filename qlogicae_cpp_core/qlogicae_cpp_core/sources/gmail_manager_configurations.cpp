#include "pch.hpp"

#include "../includes/gmail_manager_configurations.hpp"

namespace QLogicaeCppCore
{
    bool
        GmailManagerConfigurations::initial_is_enabled =
            true;

    bool
        GmailManagerConfigurations::default_is_enabled =
            GmailManagerConfigurations::initial_is_enabled;

    bool
        GmailManagerConfigurations::cache_is_enabled =
            GmailManagerConfigurations::initial_is_enabled;

    GmailManagerConfigurations
        GmailManagerConfigurations::cache;
}
