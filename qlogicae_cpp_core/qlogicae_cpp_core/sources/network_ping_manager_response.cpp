#include "pch.hpp"

#include "../includes/network_ping_manager_response.hpp"

namespace
	QLogicaeCppCore
{
	NetworkPingManagerResponse
		::NetworkPingManagerResponse()
	{		
		round_trip_time_in_milliseconds =
			0;
	}

	NetworkPingManagerResponse
		NetworkPingManagerResponse
			::initial_configurations;

	NetworkPingManagerResponse
		NetworkPingManagerResponse
			::default_configurations =
				NetworkPingManagerResponse
					::initial_configurations;
}
