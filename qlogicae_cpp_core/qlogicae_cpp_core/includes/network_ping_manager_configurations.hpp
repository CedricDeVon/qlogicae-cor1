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
				"1.1.1.1";

		TimeScaleUnit
			time_scale_unit =
				TimeScaleUnit
					::MILLISECONDS;

		std::chrono::milliseconds
			timeout =
				std::chrono::milliseconds { 1000 };

		NetworkPingManagerConfigurations();
    };
}
