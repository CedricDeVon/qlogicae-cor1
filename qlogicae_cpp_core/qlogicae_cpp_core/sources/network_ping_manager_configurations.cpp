#include "pch.hpp"

#include "../includes/network_ping_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
	NetworkPingManagerConfigurations
		::NetworkPingManagerConfigurations() :
			AbstractConfigurations<NetworkPingManagerConfigurations>()
	{				
		host_address =
			"1.1.1.1";

		time_scale_unit =
			TimeScaleUnit
				::MILLISECONDS;

		timeout =
			std::chrono::milliseconds { 1000 };
	}

	NetworkPingManagerConfigurations
		NetworkPingManagerConfigurations
			::initial_configurations;

	NetworkPingManagerConfigurations
		NetworkPingManagerConfigurations
			::default_configurations =
				NetworkPingManagerConfigurations
					::initial_configurations;
}
