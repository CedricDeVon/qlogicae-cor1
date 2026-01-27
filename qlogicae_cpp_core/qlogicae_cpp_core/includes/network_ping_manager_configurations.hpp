#pragma once

#include "network_ping_response.hpp"
#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{
    struct
		NetworkPingManagerConfigurations :
			AbstractConfigurations<NetworkPingManagerConfigurations>
    {
	public:
		std::chrono::microseconds
			microseconds_per_callback =
				default_configurations.microseconds_per_callback;
        
        std::string
			host_address =
				default_configurations.host_address;
        
        bool
			is_listening =
				default_configurations.is_listening;

        std::string
			name =
				default_configurations.name;
        
        std::function<void(const NetworkPingResponse&)>
			callback =
				default_configurations.callback;



		static NetworkPingManagerConfigurations
			initial_configurations;

		static NetworkPingManagerConfigurations
			default_configurations;
    };
}
