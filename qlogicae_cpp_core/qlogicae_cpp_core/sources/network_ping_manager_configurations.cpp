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
        
		name =
			"default";        
        
		callback =
			[](const NetworkPingManagerResponse& response) {};
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
