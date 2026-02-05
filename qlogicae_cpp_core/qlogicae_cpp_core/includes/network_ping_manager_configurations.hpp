#pragma once

#include "abstract_configurations.hpp"
#include "network_ping_manager_response.hpp"

namespace
	QLogicaeCppCore
{
    struct
		NetworkPingManagerConfigurations :
			AbstractConfigurations<NetworkPingManagerConfigurations>
    {
	public:		
        std::string
			host_address =
				default_configurations
					.host_address;

        std::string
			name =
				default_configurations
					.name;
        
        std::function<void(const NetworkPingManagerResponse& response)>
			callback =
				default_configurations
					.callback;

		static NetworkPingManagerConfigurations
			initial_configurations;

		static NetworkPingManagerConfigurations
			default_configurations;

		NetworkPingManagerConfigurations();
    };
}
