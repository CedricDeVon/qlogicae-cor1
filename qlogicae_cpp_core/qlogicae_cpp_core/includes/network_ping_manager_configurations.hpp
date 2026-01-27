#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{
    struct
		NetworkPingManagerConfigurations :
			AbstractConfigurations<NetworkPingManagerConfigurations>
    {
	public:			
		static NetworkPingManagerConfigurations
			initial_configurations;

		static NetworkPingManagerConfigurations
			default_configurations;
    };
}
