#include "pch.hpp"

#include "../includes/network_ping_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
	NetworkPingManagerConfigurations
		NetworkPingManagerConfigurations
			::initial_configurations =
				[]()
				{
					NetworkPingManagerConfigurations
						configurations;

					return
						configurations;
				}();

	NetworkPingManagerConfigurations
		NetworkPingManagerConfigurations
			::default_configurations =
				NetworkPingManagerConfigurations
					::initial_configurations;
}
