#pragma once

#include "time_scale_unit.hpp"
#include "abstract_configurations.hpp"
#include "network_ping_manager_response.hpp"

namespace
	QLogicae::Cor::V1
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

		TimeScaleUnit
			time_scale_unit =
				default_configurations
					.time_scale_unit;

		std::chrono::milliseconds
			timeout =
				default_configurations
					.timeout;

		static NetworkPingManagerConfigurations
			initial_configurations;

		static NetworkPingManagerConfigurations
			default_configurations;

		NetworkPingManagerConfigurations();
    };
}
